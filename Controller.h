#include <string>
#include <fstream>
#include <iostream>

class Controller{
public:
  void MainCommand(std::string command, std::string type);
  void CreateSelection(std::string type);
  void CreateBoard();
  void SelectBoard(std::string boardName);
};

