#include <iostream>
#include <string>
#include <sstream>
#include "Functionality/Invoker.h"
#include "Commands/Command.h"
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
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
