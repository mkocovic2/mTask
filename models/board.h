#include "workspace.h"

using CommandHandle = std::function<void(std::string)>; 
class Board : public IWorkspace{
public:
  Board(std::string name);  
  void HandleCommand(std::string command, std::string name) override; 

private:
  std::string name;
  std::string description;
  std::unordered_map<std::string, CommandHandle> commandHandler; 
  
  void Create(std::string boardName) override;
  void Destroy() override;
  void Update() override;
  void SelectBoard(std::string board_name);
  void DeselectBoard(std::string board_name);
};