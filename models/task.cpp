#include "task.h"

Task::Task(std::string taskName){
  this->taskName = taskName;
  commandHandler["create"] = [this](std::string name){
    return this->Create(name);
  };
  commandHandler["delete"] = [this](std::string name){
    return this->Destroy();
  };
  commandHandler["update"] = [this](std::string name){
    return this->Update();
  };
}

void Task::HandleCommand(std::string command, std::string name){
  if(commandHandler.find(command) != commandHandler.end()){
    commandHandler[command](name);
  } else {
    throw std::invalid_argument(command + " is not a valid command");
  }
}

void Task::Create(std::string taskName){

}

void Task::Destroy(){
  
}

void Task::Update(){
  
}

