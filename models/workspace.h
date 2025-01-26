#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <functional>
#include "../json.hpp"

using json = nlohmann::json;

const std::string data_path = "data.json";
const std::string current_board = "current_board";

class IWorkspace {
public:
    virtual void HandleCommand(std::string command, std::string name);
    virtual void Create();
    virtual void Destroy();
    virtual void Update();
private:
  std::string name;
  std::string dir;
};