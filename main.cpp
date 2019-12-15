#include <iostream>
#include <string>
int main() {
    std::string command;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true){
        std::getline(std::cin,command,' ');

    }
#pragma clang diagnostic pop
}
