#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<float> scale_values(vector<float> values);
float sumV(vector<float> values);
float truncate(float num);

int main() 
{
  

    vector<float> values;
    string raw_values;
    float num;
  
    while(getline(cin, raw_values))
    {
      istringstream num_line(raw_values);
      while(num_line >> num)
      {
        values.push_back(num);
      }

      vector<float> modfyValues = scale_values(values);

      for(int i = 0; i < (int)values.size() - 1; i++)
      {
        cout << modfyValues[i] << ' ';
      }
      cout << modfyValues[(int)values.size() - 1] << '\n';
      values.clear();
  }

  return 0;
}

vector<float> scale_values(vector<float> values)
{
  float row_sum = sumV(values);
  vector<float> scaledValues;

  for(int i = 0; i < (int)values.size(); i++)
  {
    float scale = values[i] / row_sum;
    float t_value = truncate(scale); 
    scaledValues.push_back(t_value);
  }

  return scaledValues;
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

// to round up to two decimal places
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

