#include <iostream>
#include <vector>

using namespace std;

void printVal(int x, int y);
int nummer(int a, vector<int> cities, int k);

int main(int argc, const char* argv[]) 
{

  int n , k, l;
  n = k = l = 0;
  cin >> n >> k >> l;
  
  vector<int> cities;
  int x;
  for(int i = 0; i < n; i++)
  {
    cin >> x;
    cities.push_back(x);
  }

  printVal(nummer(1,cities,k),nummer(2, cities,l));

  return 0;
}



int nummer(int a, vector<int> cities, int k)
{
  int x;
  int flag = 0;
  for(int i = 0 ; i < k; i++)
  {
    if(cities[i] == a)
    {
      x = i;
      flag = 1;
    }
    
  }
  if(flag == 0)
  {
    
    return -1;
  }


  int count = 1;
  int i = x;

  while (true)
  {
    int j = i + (2*k) - 1;

    if((i + k - 1) >= cities.size() - 1)
    {
      break;
    }

    int flag = 0;

    for(int x = i+1; x <= j; x++)
    {
      if(cities[x] == a)
      {
        i = x;
        flag =1;
      }
    }

    if(flag == 0)
    {
      return -1;
    }
    count +=1;
    
  }
  return count;

}


void printVal(int x, int y)
{
  cout << "beamer:" << x << endl;
  cout << "cata:" << y << endl;
}