#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> neighbours(vector<vector<int>> matrix, int vertex);
void bronKerbosch(vector<int> p, vector<int> r, vector<int> x, vector<vector<int>> mat);
vector<int> union_set(vector<int> x, vector<int> y);
vector<int> intersection_set(vector<int> x, vector<int> y);
vector<int> removeVertex(vector<int> x, int y);


int main(int argc, const char* argv[]) 
{
    vector<vector<int>> adjMatx;
    vector<int> row;
    
    string numLetter;
    getline(cin, numLetter);
    stringstream strstream(numLetter);
    string letter;

    while (strstream >> letter)
    {
        row.push_back(stoi(letter));
                
    }
    adjMatx.push_back(row);
    int n = row.size();
    row.clear();

    for(int i = 0; i < n - 1; i++)
    {
        string numLetter;
        getline(cin, numLetter);
        stringstream strstream(numLetter);
        string letter;

        while (strstream >> letter)
        {
            row.push_back(stoi(letter));
        }
        adjMatx.push_back(row);
        row.clear();
    }

    vector<int> p, r, x;

    for(int i = 0; i < n; i++)
    {
        p.push_back(i);
    }

    bronKerbosch(p, r, x, adjMatx);
    
    return 0;
}


vector<int> neighbours(vector<vector<int>> matrix, int vertex)
{
    vector<int> n;
    for(int i = 0; i < matrix[vertex].size(); i++)
    {
        if(matrix[vertex][i] == 1)
        {
            n.push_back(i);
        }
    }
    return n;
}


void bronKerbosch(vector<int> p, vector<int> r, vector<int> x, vector<vector<int>> mat)
{
    if((p.size() == 0) && (x.size() == 0))              
    {
        cout << "{" ;
        for(int i = 0; i < r.size() - 1; i ++)
        {
            cout << r[i] << ", ";
        }
        cout << r[r.size() - 1] << "}" << endl;

    }
    else
    {
        vector<int> p_ = p;

        for(int v : p_)
        {
            vector<int> vrtx{v};

            bronKerbosch(intersection_set(p, neighbours(mat, v)), union_set(r, vrtx), 
                                            intersection_set(x, neighbours(mat, v)), mat);
            

            p = removeVertex(p, v);
            x = union_set(x , vrtx);            
        }
    }

}


vector<int> union_set(vector<int> x, vector<int> y)
{
    vector<int> out_Un;
    for(int i : x)
    {
        out_Un.push_back(i);
    }
    for(int i : y)
    {
        int flag = 0;

        for(int j : out_Un)
        {
            if(j == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            out_Un.push_back(i);
        }
    }
    return out_Un;

}


vector<int> intersection_set(vector<int> x, vector<int> y)
{
    vector<int> out_In;

    for(int i : x)
    {
        for(int j : y)
        {
            if(i == j)
            {
                out_In.push_back(i);
                break;
            }
        }
    }
    
    return out_In;

}

vector<int> removeVertex(vector<int> x, int y)
{
    vector<int> out_Rmv;

    for(int i : x)
    {
        if(i != y)
        {
            out_Rmv.push_back(i);
        }
    }

    return out_Rmv;
}

