//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H

#include "Command.h"

class AddUserCommand: public Command {
public:
    AddUserCommand(std::vector<std::string> const & _args){
        commandType= AddUser;
        User _user(_args[1],stoi(_args[2]),_args[3]);
        users.push_back(_user);
    }
    void execute(){
        std::cout<<"Added user:"<<users[0].getName()<<' '<<users[0].getAge()<<' '<<users[0].getEmail()<<std::endl;
    }
    ~AddUserCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSERCOMMAND_H
