//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H

#include "Command.h"
#include <iostream>
#include "../Functionality/LinkUsers.h"
class LinkCommand: public Command {
    FriendshipType type;
    FriendshipType det(std::string type){
        if(type==""||type=="normal") return normal;
        if(type=="family") return family;
        if(type=="bestie") return bestie;
        std::cerr<<"Wrong friendship type! By default Normal! \n";
        return normal;
    }
public:
    LinkCommand(std::vector<std::string> const & _args){
        std::string _type;
        commandType= Link;
        User _user1(_args[1].c_str(),0,"");
        User _user2(_args[2].c_str(),0,"");
        users.push_back(_user1);
        users.push_back(_user2);
        //TODO: Fix if types doesn't exist!
        if(_args.size()>=4){
            _type=_args[3];
        }
        type=det(_type);
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships){
        linkUsers(users[0].name,users[1].name,type,arr,friendships);
    }
    ~LinkCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H
