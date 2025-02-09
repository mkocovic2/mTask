#include "objectfactory.h"

ObjectFactory::ObjectFactory(){
   commandParse["board"] = [this](std::string command, std::string name) -> IWorkspace* {
        return this->defineBoard(name);
    };
    commandParse["task"] = [this](std::string command, std::string name) -> IWorkspace* {
        return this->defineTask(name);
    };
}

void ObjectFactory::handleAction(std::string command, std::string type, std::string chosen_name){
    if(commandParse.find(type) != commandParse.end()){
        auto selected_obj = commandParse[type](command, chosen_name); 
        selected_obj->HandleCommand(command, chosen_name);
    } else {
        throw std::invalid_argument(type + " is not a valid type");
    }
}

IWorkspace* ObjectFactory::defineBoard(std::string name){
    return new Board(name);
}

IWorkspace* ObjectFactory::defineTask(std::string name){
    return new Task(name);
}