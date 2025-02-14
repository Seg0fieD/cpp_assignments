#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <iomanip>




using namespace std;


float medianV(vector<float> values);
float meanV(vector<float> values);
float sumV(vector<float> values);
float standard_deviation(vector<float> values);
float first_quartile(vector<float> values);
float third_quartile(vector<float> values);
float truncate(float num);

int main() 
{

    vector<float> values;
    string raw_values;
    float num;

    // to take in multiple line input
    while(getline(cin, raw_values))
    {
      istringstream num_line(raw_values);
      while(num_line >> num)
      {
        values.push_back(num);
      } 
   
    
      cout << truncate(medianV(values)) << ' ' <<  truncate(meanV(values)) << ' ' << truncate(sumV(values))  
              << ' ' << truncate(standard_deviation(values)) << ' '
              << truncate(first_quartile(values)) << ' ' << truncate(third_quartile(values)) << '\n';
      values.clear();
    }
   
  return 0;
}

float medianV(vector<float> values)
{
  int size = values.size();

  if(size == 0)
  {
    return 0;
  }

  else
  {
    sort(values.begin(), values.end());
    if (size % 2 == 0)
    {
      return truncate((values[size/2 -1 ] + values[size/2]) / 2);      
    }
    
    else
    {
      return truncate(values[size / 2]);

    }

  }


}

float meanV(vector<float> values)
{
  float mean_ofVector;
  

  if (values.empty())
  {
    return 0;
  }
  else
  {
    mean_ofVector = sumV(values) / values.size();
  }

  return mean_ofVector;
  
}

float sumV(vector<float> values)
{
  float sum_ofvector = 0.0;
  for(int i = 0; i < values.size(); i ++)
  {
    sum_ofvector += values[i];
  }

  return sum_ofvector;

}

float standard_deviation(vector<float> values)
{
  float square_sum = 0.0;
  float mean = meanV(values);

  for (auto i = 0; i < values.size(); i++ ) 
  {
    square_sum += pow((values[i] - mean), 2);
  }

  return sqrt(square_sum / (values.size() - 1)); // sample standard deviation

}

float first_quartile(vector<float> values)
{

  sort(values.begin() , values.end());

  vector<float> quartile1;                               // vector declaration for first quartile

  if(values.size() % 2 == 0)            // to check and fill the value in the Q1 vector through iteration
  {
     for(int i = 0; i < ((int)values.size() / 2); i++)
     {
      quartile1.push_back(values[i]);
     }
  }

  else{
    for(int j = 0; j < (((int)values.size() - 1) / 2); j++)
    {
      quartile1.push_back(values[j]);
    }
  }

  return medianV(quartile1);  
  
}

float third_quartile(vector<float> values)
{
  sort(values.begin() , values.end());

  vector<float> quartile3;                                       

  if(values.size() % 2 == 0)                                 
  {
     for(int i = ((int)values.size() / 2); i < (int)values.size() ; i++)
     {
      quartile3.push_back(values[i]);
     }
  }

  else{
    for(int j = ((int)values.size() / 2) + 1; j < (int)values.size(); j++)
    {
      quartile3.push_back(values[j]);
    }
  }

  return medianV(quartile3); 

}

// to round up to two decimal place for the output values
float truncate(float num)
{
  
  float val = (num * 1000.0) / floor(num *100.0);

  if(val == 10.0)
  {
    return num;
  }

  else 
  {
    return(round(num * 100) / 100);
  }
}


