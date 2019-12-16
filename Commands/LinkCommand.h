//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H

#include "Command.h"
#include <iostream>
class LinkCommand: public Command {
    std::string type;
public:
    LinkCommand(std::vector<std::string> const & _args){
        commandType= Link;
        User _user1(_args[1],0,"");
        User _user2(_args[2],0,"");
        users.push_back(_user1);
        users.push_back(_user2);
        type=_args[3];
    }
    void execute(){
        std::cout<<"Linked users:"<<users[0].getName()<<' '<<users[1].getName()<<" Type:"<<type<<std::endl;
    }
    ~LinkCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_LINKCOMMAND_H
