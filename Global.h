//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
#include <string>
#include <sstream>

const std::string pathUsers="../Data/users.dat";
const std::string pathGraph="../Data/graph.dat";
enum FriendshipType{
    bestie,
    family,
    normal,
    ban,
    delink,
    unban
};
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
struct UserRecommendation{
    UserRecommendation():id(0),index(0),power(0){}
    int id;
    int index;
    int power;
};
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
