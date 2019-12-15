//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H

#include <vector>
#include "../User.h"
enum CommandType{
    AddUser,
    Exit,
    Null
};
class Command {
protected:
    std::vector<User> users;
    std::string args;
    CommandType commandType;
public:
    Command():users(),args(""),commandType(Null){}
    Command(std::vector<User> const & _users,std::string const & _args): users(_users)
    ,args(_args),commandType(Null){}
    //virtual ~Command()=0;
    virtual void execute()=0;
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
