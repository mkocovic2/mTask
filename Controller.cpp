#include "Controller.h"

//We can direct the users command, and get more specific depending on what the command was.
void Controller::MainCommand(std::string command, std::string type){
  if(command == "create"){
    CreateSelection(type);
  } else if(command == "select"){
    SelectBoard(type);
  }
  else{
    std::cerr << "Invalid command";
  }
}

//Routes the 'create' command to this function, and selects the type of creation, (board, list, task)
void Controller::CreateSelection(std::string type){
  if(type == "board"){
    CreateBoard();
  }
  else{
    std::cerr << "Invalid type";
  }
}

void Controller::CreateBoard(){
  std::ofstream b_save("dir.env", std::ios::app);
  if(b_save.is_open()){
    std::string board_name;
    std::string board_dir;
    std::cout << "Please enter a name for your board: ";
    std::cin >> board_name;
    std::cout << "Please enter the directory you wish to save the board in: ";
    std::cin >> board_dir;

    b_save << board_name + "," + board_dir;

    b_save.close();
  }
}

void Controller::SelectBoard(std::string boardName){
  std::fstream b_save("dir.env");
  if(b_save.is_open()){
    //Implement getline function to find name.
    //Once a name is found, use a substring to retrieve the directory.
  }
}
