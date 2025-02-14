#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void traceback(string neucleotide_1, string neucleotide_2, vector<vector<int>> nw_table, int i, int j, string alignment1, string alignment2, vector<pair<string, string>>& alignments);

int main(int argc, const char *argv[])
{
  string neucleotide_1 = argv[1];              
  string neucleotide_2 = argv[2];
  vector<vector<int>> needleman_wunsch_table;
  needleman_wunsch_table.resize(neucleotide_1.size()+1);
  for(int i = 0 ; i < needleman_wunsch_table.size(); i++)
  {
    needleman_wunsch_table[i].resize(neucleotide_2.size()+1, 0);
  }
  //reward and penalty 
  int match = 1;
  int mismatch = -1;
  int gap = -1;

   
  /*  F(i,j) = max{[F(i-1, j-1)] + Sx(i)(j)} --> for match and mismatch.
      F(i,j) = max{F(i-1,j) + G} --> Vertical Gap(Y)
      F(i,j) = max{F(i,j-1) + G} --> Horizantal Gap(X); where G is gap penalty
      */
  for (int  i = 1 ; i < needleman_wunsch_table[0].size(); i++)
  {
    needleman_wunsch_table[0][i] = needleman_wunsch_table[0][i-1] + gap;
  }
  for (int i = 1; i < needleman_wunsch_table.size(); i++)
  {
    needleman_wunsch_table[i][0] = needleman_wunsch_table[i-1][0] + gap;
  }
  for (int i = 1 ; i < needleman_wunsch_table.size(); i++)
  {
    for(int j = 1; j < needleman_wunsch_table[0].size(); j++)
    {
      int diagonal = needleman_wunsch_table[i-1][j-1];
      int horizontal = needleman_wunsch_table[i][j-1]+gap;
      int vertical = needleman_wunsch_table[i-1][j]+gap;
      if(neucleotide_1[i-1] == neucleotide_2[j-1])
      {
        diagonal += match;
      }
      else
      {
        diagonal += mismatch;
      }
      int max_score = max({diagonal, horizontal, vertical});
      needleman_wunsch_table[i][j] = max_score;
    }
  }

  int best_score = needleman_wunsch_table[needleman_wunsch_table.size()-1][needleman_wunsch_table[0].size()-1];

  int i = needleman_wunsch_table.size()-1;
  int j = needleman_wunsch_table[0].size()-1;
  vector<pair<string, string>> alignments;
  string alignment1 = "";
  string alignment2 = "";
  traceback(neucleotide_1, neucleotide_2, needleman_wunsch_table, neucleotide_1.size(), neucleotide_2.size(), alignment1, alignment2, alignments);

  // display unique pair of seqences 
  cout << best_score << endl;
  for (auto i : alignments)
  {
    cout << i.first << endl;
    cout << i.second << endl << endl;
  }
  return 0;
}

// function for traceback
void traceback(string neucleotide_1, string neucleotide_2, vector<vector<int>> nw_table, int i, int j, string alignment1, string alignment2, vector<pair<string, string>>& alignments) {
    if (i == 0 && j == 0) {
        reverse(alignment1.begin(), alignment1.end());
        reverse(alignment2.begin(), alignment2.end());
        pair<string, string> newPair = {alignment1, alignment2}; 
        if (!(find(alignments.begin(), alignments.end(), newPair) != alignments.end()))
        {
          alignments.push_back(newPair);
        }
        return;
    }

    if (neucleotide_1[i - 1] == neucleotide_2[j - 1]) {
        traceback(neucleotide_1, neucleotide_2, nw_table, i - 1, j - 1, alignment1 + neucleotide_1[i - 1], alignment2 + neucleotide_2[j - 1], alignments);
    }

    if (nw_table[i][j] == nw_table[i - 1][j] - 1) {
        traceback(neucleotide_1, neucleotide_2, nw_table, i - 1, j, alignment1 + neucleotide_1[i - 1], alignment2 + "-", alignments);
    }

    if (nw_table[i][j] == nw_table[i][j - 1] - 1) {
        traceback(neucleotide_1, neucleotide_2, nw_table, i, j - 1, alignment1 + "-", alignment2 + neucleotide_2[j - 1], alignments);
    }

    if (nw_table[i][j] == nw_table[i - 1][j - 1] + ((neucleotide_1[i - 1] == neucleotide_2[j - 1]) ? 1 : -1)) {
        traceback(neucleotide_1, neucleotide_2, nw_table, i - 1, j - 1, alignment1 + neucleotide_1[i - 1], alignment2 + neucleotide_2[j - 1], alignments);
    }
}