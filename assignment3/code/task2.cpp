#include <iostream>
#include <vector>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

unsigned int stoui(string x){
  unsigned long unsigLng= stoul(x);
  if(unsigLng > numeric_limits<unsigned int>::max()){
    cerr << "Unsigned Int out of range" << endl;
    
  }
  return unsigLng;
}


// Random integers generator from negative bionomiar distribution using Mersenne-Twister algorithm
vector<double> gen_nums(unsigned int seed, double p, unsigned int k, int n){
    mt19937_64 gen{seed};
    negative_binomial_distribution<int> dist(k, p);
    vector<double> vals;
    for (uint i = 0 ;i<n; i++){
      vals.push_back(dist(gen));
    }
    return vals;
}


// calculate the Mean 
long double computeMean(const vector<double>& vectr)
{
  long double mean = accumulate(vectr.begin(), vectr.end(), 0.0) / vectr.size();

  return mean;
}


// calculate the sample standard deviation
double sample_standardDeviation(const vector<double> vectr, double mean)
{
  double square_sum = 0.0;

  for(double value: vectr)
  {
    square_sum += pow((value - mean), 2);
  }
  return sqrt(square_sum / (vectr.size() - 1)); 
}


// Scaling function: scale element by computing log2(|x| + 1)
vector<double> vectorScaling(const vector<double>& vectr)
{
  vector<double> scaled_vector;

  for(double value : vectr)
  {
    scaled_vector.push_back(log2(abs(value) + 1));
  }

  return scaled_vector;
}


// Top element in the vector 
void topElements(string s, vector<double> vectr)
{
  sort(vectr.begin(), vectr.end(), greater<>());

  if(vectr.size() < 10){
    cout<<s<<" Top "<<vectr.size()<<" elements: ";
    int i;
    for(i = 0; i < vectr.size()-1; i++){
      cout<<vectr[i]<<", ";
    }
    cout<<vectr[i]<<endl;
  }
  else{
    cout<<s<<" Top 10 elements: ";
    int i;
    for(i = 0; i < 9; i++){
      cout<<vectr[i]<<", ";
    }
    cout<<vectr[9]<<endl;
  }

}


int main(int argc, const char* argv[]) 
{
  if(argc != 6)
  {
    cerr << "Invalid Argument: " << argv[0] << " 'n' 'm' 's' 'p' 'k' \n";
    return 1;
  }

  unsigned int n = stoi(argv[1]);
  unsigned int m = stoi(argv[2]);
  unsigned int s = stoui(argv[3]);
  double p = stod(argv[4]);
  unsigned int k = stoui(argv[5]);

  //V1 generation=====================================================================================================================
  vector<double> V1 = gen_nums(s, p, k, n);
 
  // V1 mean and sample standard deviation 
  double V1_mean = computeMean(V1); 
  double V1_stdDev = sample_standardDeviation(V1, V1_mean); 
    
  // vector scaling
  vector<double> scaled_V1 = vectorScaling(V1); 
  
  // V2 generation=====================================================================================================================
  vector<double> V2 = gen_nums(s*2, p, k, m);

 // V3 mean and sample standard deviation computation
  long double V2_mean = computeMean(V2);
  double V2_stdDev = sample_standardDeviation(V2, V2_mean);
  
  // V2 vector scaling
  vector<double> scaled_V2 = vectorScaling(V2);

  

  // Two-sample t-test=====================================================================================================================
  /// unscaled vector 
  double pooled_StdDev_U = sqrt(((pow(V1_stdDev, 2) * (n - 1)) + (pow(V2_stdDev, 2) * (m - 1))) / 
                          ((n + m) - 2));

  double unscaled_tStatistic = (V1_mean - V2_mean) / (pooled_StdDev_U * sqrt((1.0 / n) + (1.0 / m)));

  /// scaled vector 
  double pooled_StdDev_S = sqrt(((pow(sample_standardDeviation(scaled_V1, computeMean(scaled_V1)), 2) * (n - 1)) + 
                               (pow(sample_standardDeviation(scaled_V2, computeMean(scaled_V2)), 2) * (m - 1))) / 
                              ((n + m) - 2));

  double scaled_tStatistic = (computeMean(scaled_V1) - computeMean(scaled_V2)) / (pooled_StdDev_S * sqrt((1.0 / n) + (1.0 / m)));
  
  
  // Degree of freedom 
  unsigned int total_degFreedom = n + m - 2;
  
  //======================================================================================================================================
  //sequentially increasing integers 1 to n
  vector<int> intSeq(n);
  iota(intSeq.begin(), intSeq.end(), 1);

  //shuffeling interger sequence 
  mt19937_64 rangeShuffel{s*7};
  shuffle(intSeq.begin(), intSeq.end(), rangeShuffel);

  //multiplication of elements of V1 with interger sequence
  vector<double> multiply_scaled;
  for(auto i = 0; i < n; i++)
  {
    multiply_scaled.push_back(intSeq[i] * scaled_V1[i]);
  }

  // seperating the elements in the vector based on the instruction in the question
  // nearest even integers sorted in descending order, then nearest odd integers in ascending order
  vector<double> even, odd;
  for(int i =0 ; i<multiply_scaled.size(); i++)
  {
    int a = nearbyint(multiply_scaled[i]);
    if(a%2 == 0)
    {
      even.push_back(multiply_scaled[i]);
    }
    else
    {
      odd.push_back(multiply_scaled[i]);
    }
  }

  // sorting the seperated integers close to even and odd numbers 
  sort(even.begin(), even.end(), greater<>());
  sort(odd.begin(), odd.end());


  // ALL OUTPUTS==========================================================================================================================
  cout << "V1 Mean: " << setprecision(3) << V1_mean << endl;
  cout << "V1 Sample standard deviation: " << V1_stdDev <<  endl;
  // Top elements of first Vector
  topElements("V1", scaled_V1);
  cout << "V2 Mean: " << setprecision(3) << V2_mean << endl;
  cout << "V2 Sample standard deviation: " << setprecision(3) << V2_stdDev << endl;
  // Top elements of second vector
  topElements("V2", scaled_V2);
  cout << "\n" << endl;
  cout << "Comparing V1 and V2..." << endl;
  cout << "Unscaled t-statistic: " << setprecision(3) << unscaled_tStatistic << endl;
  cout << "Comparing log2 scaled V1 and V2..." << endl;
  cout << "Scaled t-statistic: " << setprecision(3) << scaled_tStatistic << endl;
  cout << "Total degrees of freedom: " << total_degFreedom << endl;
  cout << "\n" << endl;
  cout << "Sorted vector: ";

  for(auto x:even)
  {
    cout<< x <<", ";
  }
  for(int i = 0; i < odd.size()-1; i++)
  {
    cout << odd[i] << ", ";
  }
  cout << odd[odd.size() - 1] << endl;
  

  return 0;
}
