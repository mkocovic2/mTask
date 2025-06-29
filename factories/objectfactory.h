#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>

#include "../models/board.h"
#include "../models/task.h"
#include "../models/workspace.h"

using ObjectType = std::function<IWorkspace*(std::string, std::string)>;

class ObjectFactory{
public: 
    ObjectFactory();
    void handleAction(std::string command, std::string type, std::string chosen_name);

private: 
    std::unordered_map<std::string, ObjectType> commandParse;
    IWorkspace* defineBoard(std::string name="");
    IWorkspace* defineTask(std::string name="");
};