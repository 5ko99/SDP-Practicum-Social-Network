//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H

#include "Command.h"

class AddUserCommand: public Command {
public:
    AddUserCommand():Command(){
        commandType=AddUser;
    }
    AddUserCommand(std::vector<User> const & _users, std::string const & _args=""): Command(_users, _args){
        commandType= AddUser;
    }
    void execute(){
        std::cout<<"Added user! \n";
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
