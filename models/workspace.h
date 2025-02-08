#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <string>
#include <unordered_map>
#include <functional>
#include <fstream>
#include <iostream>
#include "../json.hpp"

using json = nlohmann::json;

class IWorkspace {
public:
    virtual void HandleCommand(std::string command, std::string name) = 0;
    virtual void Create() = 0;
    virtual void Destroy() = 0;
    virtual void Update() = 0;
    virtual ~IWorkspace() = default;
protected:
    std::string name;
    std::string dir;
};

#endif
