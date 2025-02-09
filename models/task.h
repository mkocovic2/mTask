#include <string>
#include <iostream>

#include "workspace.h"
class Task : IWorkspace {
public:
  Task();
  Task(std::string taskName);
  void printEntireTask();
  void setName(std::string taskName);
private:
  std::string taskName;
  std::string taskDescription;
  bool taskStatus;
  std::string taskDeadline;
};
