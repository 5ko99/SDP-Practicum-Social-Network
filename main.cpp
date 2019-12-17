#include <iostream>
#include <string>
#include "Functionality/Invoker.h"
#include "Commands/Command.h"
#include "Global.h"
#include "Utils/DynamicArray.h"
int main() {
    Invoker i;
    std::string line;
    Command* command;
    std::vector<std::string> args;
    DynamicArray* data = new DynamicArray;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        std::getline(std::cin,line);
        args=split(line,' ');
        command=i.determinate(args);
        command->execute(*data);
    }
#pragma clang diagnostic pop
}
