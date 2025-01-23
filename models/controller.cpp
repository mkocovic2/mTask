#include "controller.h"

//We can direct the users command, and get more specific depending on what the command was.
void Controller::MainCommand(int argc, char *argv[]){
  if(argc > 6){
    std::cerr << "Too many arguments used!";
  } else if(argc < 2){
    std::cerr << "Invalid amount of arguments";
  }



  std::string command = argv[1];
  std::string type = argv[2];
  std::string chosen_name = argv[3];
  
  ObjectFactory commandHandler;
  commandHandler.handleAction(chosen_name, type, chosen_name);
}
