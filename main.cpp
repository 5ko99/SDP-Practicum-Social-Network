#include <iostream>
#include <string>
#include "Functionality/Invoker.h"

int main() {
    Invoker i;
    std::string line;
    Command* command;
    std::vector<std::string> args;
    auto* data = new DynamicArray;
    auto* friendships= new DynamicGraph;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        std::getline(std::cin,line);
        args=split(line,' ');
        command=i.determinate(args);
        if(command!= nullptr) command->execute(*data,*friendships);
    }
#pragma clang diagnostic pop
}
