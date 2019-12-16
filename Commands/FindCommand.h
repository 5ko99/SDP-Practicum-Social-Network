//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_FINDCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_FINDCOMMAND_H

#include <iostream>
#include "Command.h"
class FindCommand: public Command {
public:
    FindCommand(std::vector<std::string> const & _args){
        commandType= Find;
        User _user1(_args[1],0,"");
        users.push_back(_user1);
    }
    void execute(){
        std::cout<<"Find user:"<<users[0].getName()<<std::endl;
    }
    ~FindCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_FINDCOMMAND_H
