#include "../include/mtask/controller.h"

//We can direct the users command, and get more specific depending on what the command was.
void Controller::MainCommand(int argc, char *argv[]){
  std::string command = argv[1];
  std::string type = argv[2];
  std::string chosen_name = argv[3];
  
  ObjectFactory commandHandler;
  commandHandler.handleAction(command, type, chosen_name);
}