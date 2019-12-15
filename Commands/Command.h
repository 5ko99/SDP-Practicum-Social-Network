//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H

#include <vector>
#include "../User.h"
enum CommandType{
    AddUser,
    Exit
};
class Command {
protected:
    std::vector<User> users;
    std::string args;
public:
    Command():users(nullptr),args(nullptr){}
    Command(std::vector<User> const & _users,std::string const & _args): users(_users)
    ,args(_args){}
    virtual ~Command()=0;
    virtual void execute()=0;
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
