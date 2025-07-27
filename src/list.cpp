#include "../include/mtask/list.h"

List::List(std::string name) {
  this->name = name;
  commandHandler["create"] = [this](std::string name) {
    return this->Create(name);
  };
  commandHandler["update"] = [this](std::string name) {
    return this->Update();
  };
}

void List::HandleCommand(std::string command, std::string name) {
  if (commandHandler.find(command) != commandHandler.end()) {
    commandHandler[command](name);
  } else {
    throw std::invalid_argument(command + " this is not a valid command");
  }
}

void List::Create(std::string listName) {}

void List::Destroy() {}

void List::Update() {}
