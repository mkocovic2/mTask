#include "objectfactory.h"

void ObjectFactory::handleAction(std::string command, std::string type, std::string chosen_name){
    if(command == "create"){
        createSelection(type, chosen_name);
    } else if (command == "delete"){
        //...
    }
}

void ObjectFactory::createSelection(std::string type, std::string chosen_name){
    if(type == "board"){

    } else if(type == "list"){

    }
}
