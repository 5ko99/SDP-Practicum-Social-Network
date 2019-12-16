#include <iostream>
#include <string>
#include "Functionality/Invoker.h"
#include "Commands/Command.h"
#include "Global.h"
int main() {
    Invoker i;
    std::string line;
    Command* command;
    std::vector<std::string> args;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        std::getline(std::cin,line);
        args=split(line,' ');
        command=i.determinate(args);
        command->execute();
    }
#pragma clang diagnostic pop
}
