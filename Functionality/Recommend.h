//
// Created by petko on 22/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H

#include <iostream>
#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>
#include <vector>
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
void recommend(std::string const & name, DynamicArray& data, DynamicGraph& friendships){
    int id=findID(name,data);
    std::vector<User> recommendedUsers;
    if(id==-1){
        std::cerr<<"Wrong name! \n";
        return;
    }
    friendships.getRecommendation(id,recommendedUsers);
    std::cout<<"Recommendations: ";
    int i=1;
    for(auto user: recommendedUsers){
        std::cout<<i<<". "<<user.name<<'\n';
        i++;
    }
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
