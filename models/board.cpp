#include "board.h"

Board::Board(std::string name){
  this->entityName = name; 
  commandHandler["create"] = [this](std::string name){
    return this->Create(name);
  };
  commandHandler["select"] = [this](std::string name){
    return this->SelectBoard(name);
  };
  commandHandler["deselect"] = [this](std::string name){
    return this->DeselectBoard(name);
  };
  commandHandler["delete"] = [this](std::string name){
    return this->Destroy();
  };
}

void Board::HandleCommand(std::string command, std::string name){
  if(commandHandler.find(command) != commandHandler.end()){
    commandHandler[command](name);
  } else {
    throw std::invalid_argument(command + " is not a valid command");
  }
}

void Board::Create(std::string boardName){
  json boardObject; // We need to create a JSON object save the users board.
  
  boardObject[boardName] = {{"name", boardName}}; // Users board is stored here, with the name. 
  
  //Create a JSON file for the board, it saves in the Boards directory
  std::ofstream b_write("Boards/" + boardName + ".json"); 
  if(!b_write.is_open()){
    throw std::invalid_argument("File cannot be created");
  }
  b_write << boardObject;
  b_write.close();

  json globalData;
  
  // Board name must be added to the list of boards.
  std::ifstream d_read("data.json");
  if(!d_read.is_open()){
    throw std::invalid_argument("Board couldn't be saved");
  }

  d_read >> globalData;
  globalData[boardName] = {{"name", boardName}};

  d_read.close();

  std::ofstream d_write("data.json");
  if(!d_write.is_open()){
    throw std::invalid_argument("Board couldn't be saved");
  }

  d_write << globalData;
  d_write.close();
}

void Board::SelectBoard(std::string board_name){
  std::ifstream b_save("data.json");
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }
  
  json data; 
  b_save >> data;
  b_save.close();

  if(data.contains(board_name) && data[board_name].is_object()){
    data["current_board"]["name"] = board_name;
    std::cout <<  data["current_board"]["name"];
  } else {
    std::cerr << "Board does not exist";
  }

  std::ofstream b_write("data.json");
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;

  b_write.close();
}

void Board::DeselectBoard(std::string boardName){
  std::ifstream b_save(boardName + ".json");
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }

  json data;
  b_save >> data;

  if(data.contains("current_board") && data["current_board"].is_object()){
    data["current_board"]["name"] = "";
    data["current_board"]["directory"] = "";
  }
  
  std::ofstream b_write("data.json");
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;
  b_write.close();
}

void Board::Destroy(){
  if(CheckFileExistence(board_file) && CheckJsonBoard()){
    return; 
  }
  const char* boardObject = board_file.c_str();
  if(std::remove(boardObject) == 0){
    std::cout << "done";
  } else {
    std::cout << "failed";
  }
}

//Checks if the board is located in the universal Board json file. 
bool Board::CheckJsonBoard(){
  std::ifstream b_save("data.json");
  if(!b_save.is_open()){
    throw std::invalid_argument("File not found");
  }
  
  json data; 
  b_save >> data;
  b_save.close();

  if(data.contains(this->entityName) && data[this->entityName].is_object()){
    return true; 
  } else {
    std::cerr << "Board does not exist";
    return false; 
  }

}

bool Board::CheckFileExistence(){
  std::string board_file = "Boards/" + entityName + ".json";
  std::ifstream b_read(file_location);
  if(!b_read.is_open()){
    b_read.close();
    return true;
  } else {
    return false; 
  }
}

void Board::Update(){
  
}
