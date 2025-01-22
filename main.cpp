#include <iostream>
#include <string>
#include "models/controller.h"

int main (int argc, char *argv[]) {
  if(argc > 6){
    std::cerr << "Too many arguments used!";
    return 1; 
  } else if(argc < 2){
    std::cerr << "Invalid amount of arguments";
    return 1;
  }
 
  /*
  std::string c_board;
  std::fstream b_save("dir.env");
  
  if(b_save.is_open()){
    b_save >> c_board;
  } else{
    std::cerr << "'dir.env' has been destroyed or has been misplaced. Ensure this program is correctly installed!";
    return 1;
  }

  */
  Controller pipeline;
  std::string command = argv[1];
  std::string type = argv[2];

  pipeline.MainCommand(command, type);

  return 0;
}
