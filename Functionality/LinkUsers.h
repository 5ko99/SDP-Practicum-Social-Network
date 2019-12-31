//
// Created by petko on 21/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_LINKUSERS_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_LINKUSERS_H

#include <iostream>
#include "../Utils/User.h"
#include "../Utils/Global.h"
#include <fstream>
#include <cassert>
#include <vector>
#include "../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
int friendshipTypeToInt(FriendshipType type){
    if(type==ban)   return 0;
    if(type==delink||type==unban) return 1;
    if(type==normal) return 2;
    if(type==family) return 3;
    if(type==bestie) return 4;
}
void linkUsers(std::string const & user1,std::string const & user2,FriendshipType type, DynamicArray& data, DynamicGraph& friendships){
    if(user1==user2){
        std::cerr<<"Can't link user with himself! \n";
        return;
    }
    int id1=-1;
    int id2=-1;
    for(size_t i=0;i<data.size();i++){
        if(data[i].name==user1){
            id1=data[i].id;
            continue;
        }
        if(data[i].name==user2){
            id2=data[i].id;
            continue;
        }
        if(id1!=-1&&id2!=-1) break;
    }
    if(id1==-1||id2==-1){
        std::cerr<<"Invalid Users! \n";
        return;
    }
    if(friendships[id1][id2]==0 && type!=unban){
        std::cerr<<"Users are banned! \n";
        return;
    }
    int intType=friendshipTypeToInt(type);
    if(friendships.addEdge(id1,id2,intType)){
        if(intType==2||intType==3||intType==4){
          ++data[id1].friends;
          ++data[id2].friends;
        }else{
            --data[id1].friends;
            --data[id2].friends;
        }
    }
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_LINKUSERS_H
