//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMENDCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMENDCOMMAND_H

#include "Command.h"
#include <iostream>
#include "../Functionality/Recommend.h"

class RecommendCommand: public Command {
public:
    RecommendCommand(std::vector<std::string> const & _args){
        commandType= Recommend;
        User _user(_args[1].c_str(),0,"");
        users.push_back(_user);
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships){
        recommend(users[0].name,arr,friendships);
    }
    ~RecommendCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMENDCOMMAND_H
