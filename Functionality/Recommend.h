//
// Created by petko on 22/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H

#include <iostream>
#include "../Utils/User.h"
#include "../Utils/Global.h"
#include <fstream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <set>
#include "../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
int findID(std::string const & name, DynamicArray& data){
    for(int i=0;i<data.size();i++) {
        if (data[i].name == name) {
            return data[i].id;
        }
    }
    return -1;
}
void getUserNames(std::set<UserRecommendation> & userRec,
                  DynamicArray& data,std::vector<std::string> & userNames){
    short maxRecommendations=30;
    std::set<UserRecommendation>::reverse_iterator rit;
    std::set<std::string> userNamesSet;
    for (rit=userRec.rbegin(); rit != userRec.rend(); ++rit){
        if(maxRecommendations==0) break;
        if(userNamesSet.insert(data[rit->id].name).second){//if is inserted
            userNames.emplace_back(data[rit->id].name); //input in order of reading from set->power
        }
        --maxRecommendations;
    }
}
void recommend(std::string const & name, DynamicArray& data, DynamicGraph& friendships){
    int id=findID(name,data);
    if(id==-1){
        std::cerr<<"Wrong name! \n";
        return;
    }
    std::set<UserRecommendation> recommendedUsers;
    friendships.getRecommendation(id,recommendedUsers,data);
    std::vector<std::string> userNames;
    getUserNames(recommendedUsers,data,userNames);
    std::cout<<"Recommendations: ";
    for(const auto& i: userNames){
        std::cout<<i<<" ";
    }
    std::cout<<'\n';
}



#endif //SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
