//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H

#include <iostream>
#include "Command.h"
#include "../Functionality/DeleteUser.h"
class DeleteCommand: public Command {
public:
    DeleteCommand(std::vector<std::string> const & _args){
        commandType= Delete;
        User _user(_args[1].c_str(),0,"");
        users.push_back(_user);
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships){
        deleteUser(users[0].name,arr,friendships);
    }
    ~DeleteCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H
