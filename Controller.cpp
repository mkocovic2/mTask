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
    std::cout << "Name: ";
    std::cin >> board_name;
    std::cout << "Directory: ";
    std::cin >> board_dir;

    b_save << board_name + "," + board_dir << std::endl ;

    b_save.close();
  }
}

void Controller::SelectBoard(std::string board_name){
  std::ifstream b_read("dir.env");
  std::string line;
  std::string sub_name;
  std::string sub_directory;
  unsigned int commaLocation;

  if(b_read.is_open()){
    while(std::getline(b_read, line)){
      commaLocation = line.find(',');
      sub_name = line.substr(0, commaLocation);
      if(board_name == sub_name){
        commaLocation++;
        sub_directory = line.substr(commaLocation);
        std::cout << sub_directory;
        break;
      }
    }
  } else {
    std::cerr << "dir.env file is missing";
  }

  std::ofstream b_write("current.env");

  if(b_write.is_open()){
    b_write << sub_directory;
  } else {
    std::cerr << "dir.env file is missing";
  }

}
