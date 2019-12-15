//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H

#include "Command.h"
class ExitCommand:public Command {
    CommandType commandType;
public:
    ExitCommand():commandType(Exit){}
    void execute() override{
        exit(0);
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
