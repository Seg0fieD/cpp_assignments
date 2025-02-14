#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

float medianV(vector<float> values);
float meanV(vector<float> values);
float sumV(vector<float> values);
float first_quartile(vector<float> values);
float third_quartile(vector<float> values);
vector<float> get_Row(vector<vector<float>> matrix, int index);
vector<float> get_Column(vector<vector<float>> matrix, int index);
vector<float> get_Diagonal(vector<vector<float>> matrix);
vector<float> get_LowTriangle(vector<vector<float>> matrix);
void printValues(vector<float> values);
float truncate(float num);


int main() {

    vector<vector<float>> values;
    string raw_values;
    float num;

    // to take multiple line as input
    while(getline(cin, raw_values))
    {
      vector<float> row;
      istringstream num_line(raw_values);
      while(num_line >> num)
      {
        row.push_back(num);
      } 
      values.push_back(row);
    }
   
   // iteration to print mean, median, sum, first quartile and third quartile for each Row 
   for(int i = 0; i < values.size(); i++)
   {
    printValues(get_Row(values,i));
   }

    // iteration to print mean, median, sum, first quartile and third quartile for each Row 
   for(int i = 0; i < values.size(); i++)
   {
    printValues(get_Column(values,i));
   }

   printValues(get_Diagonal(values));
   printValues(get_LowTriangle(values));


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

float first_quartile(vector<float> values)
{

  sort(values.begin() , values.end());

  vector<float> quartile1;                                       // vector declaration for first quartile

  if(values.size() % 2 == 0)                                          // to check and fill the value in the Q1 vector through iteration
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

vector<float> get_Row(vector<vector<float>> matrix, int index)
{
  
  
  return matrix[index];

}

vector<float> get_Column(vector<vector<float>> matrix, int index)
{
  vector<float> column;
  for(int i = 0; i < matrix.size(); i++)
  {
    column.push_back(matrix[i][index]);
  }

  return column;

}

vector<float> get_Diagonal(vector<vector<float>> matrix)
{
  vector<float> diagonl;
  // to get the value of principal diagonal x = y
  for(int i = 0; i < matrix.size(); i++)
  {
    diagonl.push_back(matrix[i][i]);
  }

  return diagonl;  

}

vector<float> get_LowTriangle(vector<vector<float>> matrix)
{
  vector<float> lowTriangl;

  // iteration to get the value of lower triangle of the input matrix x > y
  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < i; j++)
    {
      lowTriangl.push_back(matrix[i][j]);
    }
  }

  return lowTriangl;

}

void printValues(vector<float> values)
{
  cout << truncate(medianV(values)) << ' ' <<  truncate(meanV(values)) << ' ' << truncate(sumV(values))  
            << ' ' << truncate(first_quartile(values)) << ' ' << truncate(third_quartile(values)) << '\n';
  

}

// to round up to two decimal place 
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
