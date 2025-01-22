#include "controller.h"

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

//Saves location of boards on the 'data.json' file
void Controller::CreateBoard(){
  std::ifstream b_save(data_path);
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }

  std::string board_name;
  std::string board_dir;
  json data; 
  json new_data;

  b_save >> data;
  b_save.close();

  std::cout << "Name: ";
  std::cin >> board_name;
  std::cout << "Directory: ";
  std::cin >> board_dir;

  new_data = {{"name", board_name}, {"directory", board_dir} };
  
  data[board_name] = new_data;
  
  std::ofstream b_write(data_path);
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;
  
  b_write.close();
}

void Controller::SelectBoard(std::string board_name){
  std::ifstream b_save(data_path);
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }
  
  json data; 
  b_save >> data;
  b_save.close();

  if(data.contains(board_name) && data[board_name].is_object()){
    data[current_board]["name"] = board_name;
    data[current_board]["directory"] = data[board_name]["directory"];
  } else {
    std::cerr << "Board does not exist";
  }

  std::ofstream b_write(data_path);
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;

  b_write.close();
}

void Controller::DeselectBoard(std::string boardName){
  std::ifstream b_save(data_path);
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }

  json data;
  b_save >> data;

  if(data.contains(current_board) && data[current_board].is_object()){
    data[current_board]["name"] = "";
    data[current_board]["directory"] = "";
  }
  
  std::ofstream b_write(data_path);
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;
  b_write.close();
}