//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
#include <string>
#include <sstream>

std::string path="../Data/users.txt";
extern std::vector<std::string> split(const std::string& strToSplit, char delim)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delim))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
