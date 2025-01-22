#include <string>
#include <iostream>
class task{
public:
  task();
  task(std::string taskName, std::string taskDescription, std::string taskDeadline);
  void printEntireTask();
  void setName(std::string taskName);
private:
  std::string taskName;
  std::string taskDescription;
  std::string taskDeadline;
};
