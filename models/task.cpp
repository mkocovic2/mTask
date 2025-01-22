#include "task.h"

task::task(){
  taskName = "";
  taskDescription = "";
  taskDeadline = "";
}

task::task(std::string taskName, std::string taskDescription, std::string taskDeadline){
  this->taskName = taskName;
  this->taskDescription = taskDescription;
  this->taskDeadline = taskDeadline;
}

void task::printEntireTask(){
  std::cout << this->taskName;
}

void task::setName(std::string taskName){
  this->taskName = taskName;
}
