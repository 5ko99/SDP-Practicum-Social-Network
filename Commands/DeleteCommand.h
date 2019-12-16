//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H

#include <iostream>
#include "Command.h"
class DeleteCommand: public Command {
public:
    DeleteCommand(std::vector<std::string> const & _args){
        commandType= Delete;
        User _user("",0,_args[1]);
        users.push_back(_user);
    }
    void execute(){
        std::cout<<"Delete user:"<<users[0].getEmail()<<std::endl;
    }
    ~DeleteCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DELETECOMMAND_H
