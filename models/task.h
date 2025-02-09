#include <string>
#include <iostream>

#include "workspace.h"
class Task : public IWorkspace {
public:
  Task();
  Task(std::string taskName);
  
  void printEntireTask();
  void setName(std::string taskName);

private:
  void HandleCommand(std::string command, std::string name) override;
  void Create() override;
  void Destroy() override;
  void Update() override;

  std::string taskName;
  std::string taskDescription;
  bool taskStatus;
  std::string taskDeadline;
};
