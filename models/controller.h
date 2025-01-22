#include <string>
#include <fstream>
#include <iostream>
#include "../json.hpp"

using json = nlohmann::json;

const std::string data_path = "data.json";
const std::string current_board = "current_board";

class Controller{
public:
  void MainCommand(std::string command, std::string type);
  void CreateSelection(std::string type);
  void CreateBoard();
  void SelectBoard(std::string boardName);
  void DeselectBoard(std::string boardName);
};

