#include "workspace.h"

using CommandHandle = std::function<void(std::string)>;
class List : public IWorkspace {
public:
  List(std::string name);
  void HandleCommand(std::string command, std::string name) override;

private:
  std::string name;
  std::string dir;
  std::string description;
  std::unordered_map<std::string, CommandHandle> commandHandler;

  void Create(std::string listName) override;
  void Destroy() override;
  void Update() override;
};
