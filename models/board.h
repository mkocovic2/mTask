#include <string>
#include <fstream>
#include <iostream>
#include "../json.hpp"

using json = nlohmann::json;

const std::string data_path = "data.json";
const std::string current_board = "current_board";

class Board{
public:
  Board(std::string name, std::string dir);
  void MainCommand(std::string command, std::string type);
  void CreateSelection(std::string type);
  void CreateBoard();
  void SelectBoard(std::string board_name);
  void DeselectBoard(std::string boardName);
  
private:
  std::string name;
  std::string dir;
};