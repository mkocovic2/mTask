#include "workspace.h"

using CommandHandle = std::function<void(std::string)>; 
class Task : public IWorkspace {
public:
  Task(std::string taskName);
  void HandleCommand(std::string command, std::string name) override;

private:
  std::string taskName;
  std::string taskDescription;
  bool taskStatus;
  std::string taskDeadline;
  std::unordered_map<std::string, CommandHandle> commandHandler; 

  void Create(std::string taskName) override;
  void Destroy() override;
  void Update() override;
};