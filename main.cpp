#include <iostream>
#include <string>
#include "Functionality/Invoker.h"
#include "Commands/Command.h"
int main() {
    Invoker i;
    std::string commandS;
    Command* command;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        std::getline(std::cin,commandS);
        command=i.determinate(commandS);
        command->execute();
    }
#pragma clang diagnostic pop
}
