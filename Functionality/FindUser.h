//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H

#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>
void findUser(const User & user, DynamicArray & data, DynamicGraph& friendships){
    std::string name=user.name;
    for(int i=0;i<data.size();i++){
        if(data[i].name==name){
            std::cout<<"User \n --- \n Name:"<<name<<"\n Age:"<<data[i].age<<'\n';
            //TODO: Remove bellow line
            std::cout<<"ID:"<<data[i].id<<std::endl;
            std::cout<<"Friends: ";
            friendships.getFriendsPrint(data[i].id,data);
            return;
        }
    }
    std::cerr<<"User not found! \n";
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H
