//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H

#include <iostream>
#include "Command.h"
class DelinkCommand: public Command {
public:
    DelinkCommand(std::vector<std::string> const & _args){
        commandType= Delink;
        User _user1(_args[1],0,"");
        User _user2(_args[2],0,"");
        users.push_back(_user1);
        users.push_back(_user2);
    }
    void execute(){
        std::cout<<"Delinked users:"<<users[0].getName()<<' '<<users[1].getName()<<std::endl;
    }
    ~DelinkCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DELINKCOMMAND_H
