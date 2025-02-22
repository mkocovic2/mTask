#include "workspace.h"
#include <cstdio>
class Board : public IWorkspace{
public:
  Board(std::string name);  
  void HandleCommand(std::string command, std::string name) override; 

private:
  void Create(std::string boardName) override;
  void Destroy() override;
  void Update() override;
  void SelectBoard(std::string board_name);
  void DeselectBoard(std::string board_name);

  bool CheckFileExistence();
  bool CheckJsonBoard();
};
