#include <string>
#include <iostream>

class ObjectFactory{
public: 
    void handleAction(std::string command, std::string type);
    void handleAction(std::string command, std::string type, std::string chosen_name);

    void createSelection(std::string type, std::string chosen_namer);
};