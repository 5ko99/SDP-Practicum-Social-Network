//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H


#include <string>
#include "../Commands/Command.h"
#include "../Commands/AddUserCommand.h"
#include "../Commands/ExitCommand.h"
class Invoker {
public:
    Command* determinate(std::string const & command){
        if(command=="CREATE") return new AddUserCommand();
        if(command=="EXIT") return new ExitCommand();
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H
