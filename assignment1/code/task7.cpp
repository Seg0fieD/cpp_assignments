#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cstring>




using namespace std;


int baseFrequency(string sequence, char nt);
string base_conversion(string sequence);



int main(int argc, char **ffname) 
{
  string ffline;                        // variable for input file 
  ifstream file(ffname[1]);                   
  int lineCount = 0;                            // total line counter
  string sequence = "";
  vector<string> vecSequence;
  

  // to take a input as a file to extract all the sequences from a FASTA file.
  while(getline(file, ffline)) 
  {
    // to check whether the line contain the valid sequences 
    if(ffline[0] == '>')
    {
      
      vecSequence.push_back(sequence);
      sequence = "";
    }

    else
    {
      sequence += ffline;
    }
    
    lineCount++; 

  }

  vecSequence.push_back(sequence);
  vecSequence.erase(vecSequence.begin());

  int seq_count = 0;
  int a_Count = 0;
  int c_Count = 0;
  int g_Count = 0;
  int u_Count = 0;
  int flag = 0;


  // iteration to check whether each sequence is a valid sequence or not, which shall contain the neucleotide 'A', 'T', 'G', 'C', 'U'
  for (int i =0 ; i< vecSequence.size(); i++)
  {
    for (int j =0; j< vecSequence[i].length(); j++)
    {
      if (vecSequence[i][j] != 'A' && vecSequence[i][j] != 'C'&& 
          vecSequence[i][j] != 'G'&& vecSequence[i][j] != 'T' && 
          vecSequence[i][j] != 'U'){
        flag = 1;
        break;
      }
    }

    if (flag == 1)
    {
      flag = 0;
    }
    else
    {
      seq_count += 1;
      g_Count += baseFrequency(vecSequence[i], 'G');
      a_Count += baseFrequency(vecSequence[i], 'A');
      c_Count += baseFrequency(vecSequence[i], 'C');
      u_Count += baseFrequency(vecSequence[i], 'U');
      u_Count += baseFrequency(vecSequence[i], 'T');
    } 
  }


  float total_BaseCout = g_Count + c_Count + a_Count + u_Count;

  vector<string> hairPins;

  for(int i = 0; i < vecSequence.size(); i ++)
  {
    string first_sequence = "";
    int flag = 0;
    int len = (int)vecSequence.size();
    int mid_HairPin = (len % 2 == 0) ? len/2 : (len - 1) / 2;
    vecSequence[i] = base_conversion(vecSequence[i]);

    // iteratin over the vecoteor containing the sequences to find the matching base pair to consider for hairpin sequence
    for(int j = 0; j < mid_HairPin-1; j++)
    {
      // storing the nucleotide as char to check whether the first nucleotide match with last nucleotide
      // similarly checking the second element matches with the second last element 
      char ch1 = vecSequence[i][j];                                  
      char ch2 = vecSequence[i][vecSequence[i].size()- 1 - j];     

      if((ch1 == 'G' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'G') ||
          (ch1 == 'A' && ch2 == 'U') || (ch1 == 'U' && ch2 == 'A'))     // to check if this base paring is valid in the sequences
        {
          first_sequence += ch1;
        }

        else
        {
          flag = 1;
          break;
        }
    }
    if(flag == 0)
    {
      hairPins.push_back(first_sequence);
    }
    first_sequence = "";
 
  }

  cout << "Lines: " << lineCount << endl;
  cout << "Sequences: " << seq_count << endl;
  cout << "GC content: "<< (g_Count + c_Count) / total_BaseCout << endl;
  cout << "A: "<< a_Count / total_BaseCout << endl;
  cout << "C: "<< c_Count / total_BaseCout << endl;
  cout << "G: "<< g_Count / total_BaseCout << endl;
  cout << "U: "<< u_Count / total_BaseCout << endl;

  // printing the hairpin sequence into a text file 
  ofstream Output_hairPin;
  Output_hairPin.open(ffname[2]);

  //iteration to push all the hairpin sequence into the outputfile
  for(int i = 0; i < hairPins.size(); i++)
  {
     Output_hairPin << hairPins[i] << '\n';
  }
  Output_hairPin.close();

  return 0;
}

 // to caluclate the nucleotide base frequency
int baseFrequency(string sequence, char nt)
{
  int nt_count = 0;
  for(int i = 0; i < sequence.size(); i++)
  {
    if(sequence[i] == nt)
    {
      nt_count += 1;
    }    
  }
  return nt_count;
}

// to convert the nucleotide 'T' to 'U'
string base_conversion(string sequence)
{
  for(int i = 0; i < sequence.length(); i++)
  {
    sequence[i] = toupper(sequence[i]);
  }

  replace(sequence.begin(), sequence.end(),'T','U');

  return sequence;
}


