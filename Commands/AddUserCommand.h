//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H

#include "Command.h"

class AddUserCommand: public Command {
    CommandType commandType;
public:
    AddUserCommand(std::vector<User> const & _users , std::string const & _args): Command(_users, _args),
    commandType(AddUser){}
    void execute(){

    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
