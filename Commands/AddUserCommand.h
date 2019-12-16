//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H

#include "Command.h"
#include "../Functionality/AddUser.h"

class AddUserCommand: public Command {
public:
    AddUserCommand(std::vector<std::string> const & _args){
        commandType= AddUser;
        User _user(_args[1],stoi(_args[2]),_args[3]);
        users.push_back(_user);
    }
    void execute(){
        addUser(users[0]);
    }
    ~AddUserCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
