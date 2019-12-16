//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_BANCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_BANCOMMAND_H

#include <iostream>
#include "Command.h"
class BanCommand: public Command {
public:
    BanCommand(std::vector<std::string> const & _args){
        commandType= Ban;
        User _user1(_args[1],0,"");
        User _user2(_args[2],0,"");
        users.push_back(_user1);
        users.push_back(_user2);
    }
    void execute(){
        std::cout<<"Banned users:"<<users[0].getName()<<' '<<users[1].getName()<<std::endl;
    }
    ~BanCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_BANCOMMAND_H
