#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

float meanV(vector<float> values);
float sumV(vector<float> values);
vector<float> get_Column(vector<vector<float>> matrix, int index);
float standard_deviation(vector<float> values);
float truncate(float num);

int main() 
{
  vector<vector<float>> values;
    string raw_values;
    float num;
    vector<vector<float>> standard_matrix;
  
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

    for(int i = 0; i < values.size(); i++)
    {
      vector<float> standard_Row;
      for(int j = 0; j < values.size(); j++)
      {
        float meanColumn = meanV(get_Column(values,j));
        float columnStdDev = standard_deviation(get_Column(values,j));
        standard_Row.push_back((values[i][j] - meanColumn) / columnStdDev);
      }
      standard_matrix.push_back(standard_Row);
    }

    for(int i = 0; i < standard_matrix.size(); i++)
    {
      for(int j = 0; j < standard_matrix.size() - 1; j++)
      {
        cout << truncate(standard_matrix[i][j]) << ' ';
      }
      cout << truncate(standard_matrix[i][standard_matrix.size() - 1]) << '\n';
    }

  return 0;
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

vector<float> get_Column(vector<vector<float>> matrix, int index)
{
  vector<float> column;
  for(int i = 0; i < matrix.size(); i++)
  {
    column.push_back(matrix[i][index]);
  }

  return column;

}

float standard_deviation(vector<float> values)
{
  float square_sum = 0.0;
  float mean = meanV(values);

  for (auto i = 0; i < values.size(); i++ ) 
  {
    square_sum += pow((values[i] - mean), 2);
  }

  return sqrt(square_sum/ (values.size() - 1)); // sample standard deviation

}

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

