#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "../../external/json/json.hpp"
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using json = nlohmann::json;
using g_commandHandle = std::function<void(std::string)>;

class IWorkspace {
public:
  virtual void HandleCommand(std::string command, std::string name) = 0;
  virtual void Create(std::string name) = 0;
  virtual void Destroy() = 0;
  virtual void Update() = 0;
  virtual ~IWorkspace() = default;

protected:
  std::string entityName;
  std::string entityDescription;
  std::unordered_map<std::string, g_commandHandle> commandHandler;
};

#endif
