//
// Created by petko on 22/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_UNBANCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_UNBANCOMMAND_H

#include <iostream>
#include "../Utils/User.h"
#include "../Utils/Global.h"
#include <fstream>
#include <cassert>
#include <vector>
#include "../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
#include "Command.h"
#include "../Functionality/LinkUsers.h"

class UnbanCommand: public Command {
    FriendshipType type;
public:
    explicit UnbanCommand(std::vector<std::string> const & _args){
        commandType= Ban;
        User _user1(_args[1].c_str(),0,"");
        User _user2(_args[2].c_str(),0,"");
        users.push_back(_user1);
        users.push_back(_user2);
        type=unban;
    }
     void execute(DynamicArray& arr, DynamicGraph& friendships) override{
        linkUsers(users[0].name,users[1].name,type,arr,friendships);
    }
    ~UnbanCommand() override =default;
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_UNBANCOMMAND_H
