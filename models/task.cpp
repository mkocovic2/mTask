#include "task.h"

Task::Task(std::string taskName){
  this->taskName = taskName;
}

void Task::printEntireTask(){
  std::cout << this->taskName;
}

void Task::setName(std::string taskName){
  this->taskName = taskName;
}
