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
    UserRecommendation(int _id=0,int _power=0):id(_id),power(_power){}
    int id;
    int power;

    void clear(){
        id=0;power=0;
    }
//    bool operator<(const UserRecommendation& s) const{
//        if(id==s.id){
//            return power<s.power;
//        }else{
//            return id<s.id;
//        }
//    }
    //for test
    bool operator<(const UserRecommendation& s) const{
        if(power==s.power){
            return id<s.id;
        }else{
            return power<s.power;
        }
    }
};
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_GLOBAL_H
