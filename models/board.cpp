#include "board.h"

Board::Board(std::string name){
  this->name = name; 
  commandHandler["create"] = [this](std::string name){
    return this->Create(name);
  };
  commandHandler["select"] = [this](std::string name){
    return this->SelectBoard(name);
  };
}

void Board::HandleCommand(std::string command, std::string name){
  if(commandHandler.find(command) != commandHandler.end()){
    commandHandler[command](name);
  } else {
    throw std::invalid_argument(command + " is not a valid command");
  }
}

//Saves location of boards on the 'data.json' file
void Board::Create(std::string boardName){
  json data; 
  json new_data;

  new_data = {{"name", boardName}};
  
  data[boardName] = new_data;
  
  std::ofstream b_write(boardName + ".json");
  if(!b_write.is_open()){
    throw std::invalid_argument("File not found");
  }
  b_write << data;
  
  b_write.close();
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
    data["current_board"]["directory"] = data[board_name]["directory"];
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

}

void Board::Update(){
  
}