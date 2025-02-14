#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <stdexcept>
#include <sstream>

using namespace std;

bool input_ErrorHandling(vector<string> chr, vector<int> sp, vector<int> ep);


int main(int argc, const char *argv[])
{
  string chromosomeFile;
  string fileName = argv[1];                        
  ifstream file(fileName);
  if(!file.is_open())
  {
    // exception to throw error if input file not found
    cerr << "File Not Found! : " << fileName << endl;
    return 1;
  }

  int distance = 0;
  string dist = argv[2];
  // Exception for non numerical distance value
  try
  {
    size_t sizeln;
    distance =  stoi(dist, &sizeln);
    if(sizeln < dist.size())
    {
      cerr << "Invalid Distance Value! : Non-numeric Distance Value Not Allowed." << endl;
      return 1;
    }

  } 
  catch(const invalid_argument& arggument)
  {
    cerr << "Invalid Distance Value! : Non-numeric Distance Value Not Allowed." << endl;
    return 1;
  }

  vector<string> chromosomes;
  vector<int> start_positions;
  vector<int> end_positions;
  vector<string> inputs;  
  
  while(getline(file, chromosomeFile)) 
  {
    inputs.push_back(chromosomeFile);
  }
  // to check for duplicated in the input
  vector<int> dup_chr_idx;
  for (int i = 0 ; i < inputs.size(); i++){
    for (int j = i+1; j < inputs.size(); j++){
      if(inputs[j] == inputs[i]){
        dup_chr_idx.push_back(j);
      }
    }
  }

  int flag = 0;
  vector<string> nonDuplicateInputs;
  for(int i = 0; i < inputs.size();i++){
    flag = 0;
    for (int j = 0; j < dup_chr_idx.size();j++){
      if (i == dup_chr_idx[j]){
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      nonDuplicateInputs.push_back(inputs[i]);
    }
  }

  vector<string> input_lines;
  for(auto i:nonDuplicateInputs){
    istringstream str(i);
    string s;

    while(str >> s){
      input_lines.push_back(s);
    }    
    chromosomes.push_back(input_lines[0]);
    start_positions.push_back(stoi(input_lines[1]));
    end_positions.push_back(stoi(input_lines[2]));
    input_lines.clear();
  }

  vector<double> mid_position ;
  bool chromosome_sorting = input_ErrorHandling(chromosomes, start_positions, end_positions);

  // to get the  middle distance value
  if (chromosome_sorting)
  {
     
    for(int i = 0; i < start_positions.size(); i++)
    {
      mid_position.push_back((start_positions[i] + end_positions[i]) / 2);
    }
    vector<int> clusters;
    int k = 1;

    // cluster sorting
    for(int i = 0; i < mid_position.size()-1; i ++)
    {
      clusters.push_back(k);
      if((chromosomes[i]!=chromosomes[i+1]) || ((abs(mid_position[i]-mid_position[i+1]))>=distance))
      {
        k++;
      }
    }

    clusters.push_back(k);
    vector<string> OutputLines;
    string out_line = "";
    ofstream output_chr_file(argv[3]);

    for (int i =0;i< clusters.size(); i++){
      output_chr_file << chromosomes[i] << "\t" << to_string(start_positions[i]) << "\t" << to_string(end_positions[i]) << "\t"
                << "cluster=" << to_string(clusters[i]) << "\n";
    }
    output_chr_file.close();
  }

  else
  {
    cerr << "Error" << endl;
    return 1;
  }
  return 0;
}


bool input_ErrorHandling(vector<string> chr, vector<int> sp, vector<int> ep)
{
  //chromosome order
  for (int i = 1; i<chr.size()-1; i++){
    if (chr[i] == "X"){
      if (chr[i+1] != "Y" && chr[i+1] != "X"){
        return false;
      }
    }

    else if (stoi(chr[i].substr(3)) < stoi(chr[i-1].substr(3)))
    {
      return false;
    }
  }
  // start end order
  for (int i = 1; i<chr.size(); i++){
    if (chr[i] == chr[i-1]){
      if (sp[i] < sp[i-1]){
        return false;
      }
    }
  }
  return true;
}

