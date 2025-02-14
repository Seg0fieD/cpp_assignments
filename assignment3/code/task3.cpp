#include "cxxopts.hpp"
#include "fstream"
#include "regex"
#include "filesystem"

namespace fs = std::filesystem; 

// Helper function to search all files and subdirectories recursilvely
std::vector<std::string> all_paths(std::string name){
  std::vector<std::string> path ;
  for(auto x : fs::directory_iterator(name)){
    if(!(fs::is_directory(x.path()))){                              //if my file is a directory
      path.push_back(x.path().string());                            //add file to a list of all paths
    }
    else{
      auto next_path = all_paths(x.path().string());                //else call to find subdirectory and file in a directory
      for(auto i : next_path){                                      
        path.push_back(i);                                          //add all paths found inside the directory to all paths    
      }
    }
  }
  return path;
}


// Helper function to print all possible patterns from files based on the filters
int print_regex(std::vector<std::regex> patterns, std::vector<std::string> fileNames, bool show_numbers, bool inv, bool is_dir){
  int k = 1;
  std::vector<std::string> unique_lines;
  std::vector<int> line_nums;                                   
  if (fileNames.size() > 1){                                                                // if I have more than one file
    for (auto file : fileNames){                                                  
      if(fs::is_directory(file) && !is_dir){                                                // Check if the file is a directory and directory flag is not activated
        std::cout<<"grep: "<<file<<": Is a directory"<<std::endl;                           // Print appropriate message          
        continue;
      }
      else if(fs::is_directory(file) && is_dir){                                            // Check if my file is a directory and directory flag is activated
        std::vector<std::string> p = all_paths(file);                                       // Find all subpaths and files  
        std::sort(p.begin(), p.end(), std::greater<>());                                    // Sort them reverse lexicographically    
        print_regex(patterns, p, show_numbers, inv, true);                                  // Call my helper function to print patterns from that list  
      }
      else{
      std::ifstream input(file);                                                            // Else if my file is not a directory
      for(std::string line; getline( input, line );){                                       // For each line in my file
        if(!input.is_open())
        {
          return 1;
        }
        for(auto pattern : patterns){                                                       // For each pattern in my patterns list
          if(inv ? !(std::regex_search(line, pattern)):(std::regex_search(line, pattern))){ // If my inverse flag is there choose non matching else matching
            int flag = 0;                                                                   // Flag to check whether my line is present in my "matched patterns"
            for (auto u : unique_lines){
              if (u == line){
                flag = 1;
                break;
              }
            }
            if(flag == 0){                                                                  // If my line is not present
              unique_lines.push_back(line);                                                 // Store the line as a matched pattern
              line_nums.push_back(k);                                                       // Also store its line number
            }
          }
          
        }
        k++;
              
      }
      k=1; 
      for(int i = 0 ; i< unique_lines.size(); i++){                                         // For each matched pattern
        if(show_numbers){                                                                   // If my flag for showing line numbers is active
          std::cout << file << ":" << line_nums[i] << ":" << unique_lines[i]<<std::endl;;   // Print the line with the file name and the line number
        }
        else{
          std::cout << file << ":" << unique_lines[i]<<std::endl;                           // Else print the line with just the file name
        }
      }                                                                                     // Completed checking all patterns in the file
      unique_lines.clear();                                                                 // Clear matched patterns to store new matches from next file
      line_nums.clear();                                                                    // Clear line numbers to store new line numbers from next file
      }
    }
  }
  else{
    std::string file = fileNames[0];                                                        // Now if I have one single file
    if(fs::is_directory(file) && !is_dir){                                                  // Check if the file is a directory and no -R flag
      std::cout<<"grep: "<<file<<": Is a directory"<<std::endl;                             // Print appropriate message
    }
    else if(fs::is_directory(file) && is_dir){                                              // If the file is a directory and there is -R flag
      std::vector<std::string> p = all_paths(file);                                         // Get the files and the subfolders
      std::sort(p.begin(), p.end(), std::greater<>());                                      // Sort them lexicographically 
      print_regex(patterns, p, show_numbers, inv, true);                                    // And find all patterns from the files and subfolders
    }
    else{                                                                                   // If the file is not a directory
      std::ifstream input(file);
      for(std::string line; getline(input, line);){                                         // For each line in the file
        if(!input.is_open())
        {
          return 1;
        }
        for (auto pattern : patterns){                                                      // For each pattern in the patterns list 
          if(inv ? !(std::regex_search(line, pattern)):(std::regex_search(line, pattern))){ // If my inverse flag is there find non matching else matching
            int flag = 0;                                                                   // Flag to check whether the matched line is already present
            for(auto u : unique_lines){
              if(u == line){
                flag = 1;
                break;
              }
            }
            if(flag == 0){                                                                    
              unique_lines.push_back(line);                                                  // If not present push the matched line
              line_nums.push_back(k);                                                        // Push the line number
            }
          }
        }
        k++;
      }
      for(int i = 0 ; i< unique_lines.size(); i++){                                          // For each matched line
          if(show_numbers){                                                                  // Check if I need to show line numbers 
            std::cout << ((file.find('/') != std::string::npos && is_dir)?file+":":"")<<line_nums[i] << ":" << unique_lines[i]<<std::endl;
                                                                                             // If my file was a path print the path with the line number and matched line
          }
          else{
            std::cout << ((file.find('/') != std::string::npos && is_dir)?file+":":"")<< unique_lines[i]<<std::endl; 
                                                                                             // If my file was a path print path with the matched line
          }
      }
    }
  }
  return 0;                                                                                   // Return if all cases executed succesfully
}
  


int main(int argc, char* argv[]) {
  cxxopts::Options options("MyProgram", "One line description of MyProgram");
  options.add_options()
  ("F", "Fixed String", cxxopts::value<bool>())
  ("f", "Multiple pattern present inside FILENAME", cxxopts::value<bool>())
  ("v","Non-matching lines", cxxopts::value<bool>())
  ("n", "Line number for match(s) occurred in the file", cxxopts::value<bool>())
  ("R", "Print file from sub-directories", cxxopts::value<bool>())
  ("i", "case insensitive", cxxopts::value<bool>())
  //("pattern", "pattern", cxxopts::value<std::string>())
  ("input", "input files", cxxopts::value<std::vector<std::string>>());

  options.parse_positional({"input"});
  auto result = options.parse(argc, argv);

  std::string reg = result["input"].as<std::vector<std::string>>()[0];                        // Store the first parameter after all flags separately
  std::vector<std::regex> pattern;
  std::vector<std::string> file_patterns;
  std::vector<std::string> file_names(result["input"].as<std::vector<std::string>>().begin()+1,result["input"].as<std::vector<std::string>>().end());
                                                                                              // Store all other strings to find the patterns in them
  bool show_line = false;                                                                     // flag for line number
  bool inv = false;                                                                           // flag for matching / non-matching
  bool is_dir = false;                                                                        // flag for parsing directories
  bool is_file = false;                                                                       // flag for knowing the first parameter after all flags is regex or file
  

  if(result["f"].as<bool>())                                                                  // if patterns are read from file                                
  {
    std::ifstream input(reg);
    if(!input.is_open())
    {
      return 1;
    }
    is_file = true;                                                                           // set flag to true
    for( std::string line; getline( input, line ); ){                                         // store each line from file in a vector
      // pattern.push_back(std::regex(line));
      file_patterns.push_back(line);
    }
    int k = 1;
    try{                                                                                      // check if any line in the file is an invalid regex
      std::regex r;
      for (auto x : file_patterns){
        r = std::regex(x);
        k++;
      }
    }
    catch(std::exception &e){
      std::cout<<"grep: "<<reg<<":"<<k<<": Invalid regular expression"<<std::endl;            // Show appropriate error message 
      return 1;
    }
  }  
  if(result["F"].as<bool>())                                                                  // If I need to treat my regex as a fixed string
    {
      if(file_patterns.size() > 0){                                                           // If I have obtained patterns from the file
        for (auto x : file_patterns){                                                         // For each pattern
          std::string esc_reg;
          for (char ch : x) {                                                                 //  For each character in my pattern
              if (ch == '\\' || ch == '.' || ch == '+' || ch == '*' || ch == '?' || ch == '(' || ch == ')' || ch == '[' ||
                  ch == ']' || ch == '{' || ch == '}' || ch == '^' || ch == '$') {            // If the character is a special character        
                  esc_reg += '\\';                                                            // Then add a / to escape the character
              }
              esc_reg += ch;
            }
          pattern.push_back(std::regex(esc_reg));                                             
        }
      }
      else{                                                                                    // Else if I have only one regex.....perform same actions on it
      std::string esc_reg;
      for (char ch : reg) {
          if (ch == '\\' || ch == '.' || ch == '+' || ch == '*' || ch == '?' || ch == '(' || ch == ')' || ch == '[' ||
              ch == ']' || ch == '{' || ch == '}' || ch == '^' || ch == '$') {
              esc_reg += '\\';
          }
          esc_reg += ch;
      }
      pattern.push_back(std::regex(esc_reg));
      }
    }
  if(result["v"].as<bool>())                                                                   // If I need to print non matching lines
  {
    inv = true;                                                                                // Set inverse flag to true
  }

  if(result["n"].as<bool>())                                                                   // If I need to show line numbers
  {
    show_line = true;                                                                          // Set the flag for line numbers to true
  }

  if(result["R"].as<bool>())                                                                   // If I need to read from directories
  {
    is_dir = true;                                                                             // Set the flag for directories to true
  }

  if(result["i"].as<bool>())                                                                   // If I need to match case insensitive
  {
    if(file_patterns.size()>0){                                                                // If I obtained patterns from a file
      for(auto x : file_patterns){
        pattern.push_back(std::regex(x, std::regex_constants::icase));                         // Convert each string from the file to icase regex
      }
    }
    else if(!is_file){                                                                         // Else if I didnt read from a file
      pattern.push_back(std::regex(reg, std::regex_constants::icase));                         // Convert the single string to icase regex
    }
  }
                                                                                               // Else if no flag is present
  if(pattern.size() == 0){                                                                     // If I havent proccessed any flags 
    if(file_patterns.size()>0){                                                                // If I received patterns from a file
      for(auto x : file_patterns){
        pattern.push_back(std::regex(x));                                                      // Convert all strings to a case sensitive regex
      }
    }
    else if(!is_file){                                                                         // If I didnt read from a file
      pattern.push_back(std::regex(reg));                                                      // Convert the single string to a case sensitive regex
    }
  }
  return print_regex(pattern, file_names, show_line, inv, is_dir);                             // Finally call helper function with all patterns, files and flags
}
