//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H

#include <iostream>
#include "Command.h"
class DelinkCommand: public Command {
    FriendshipType type;
public:
    DelinkCommand(std::vector<std::string> const & _args){
        commandType= Delink;
        User _user1(_args[1].c_str(),0,"");
        User _user2(_args[2].c_str(),0,"");
        users.push_back(_user1);
        users.push_back(_user2);
        type=delink;
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships){
        linkUsers(users[0].name,users[1].name,type,arr,friendships);
    }
    ~DelinkCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H
