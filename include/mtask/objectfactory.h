#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "board.h"
#include "task.h"
#include "workspace.h"

using ObjectType = std::function<IWorkspace *(std::string, std::string)>;

class ObjectFactory {
public:
  ObjectFactory();
  void handleAction(std::string command, std::string type,
                    std::string chosen_name);

private:
  std::unordered_map<std::string, ObjectType> commandParse;
  IWorkspace *defineBoard(std::string name = "");
  IWorkspace *defineTask(std::string name = "");
};
