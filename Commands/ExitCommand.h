//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H

#include "Command.h"
class ExitCommand:public Command {
public:
    ExitCommand():Command(){
        commandType=Exit;
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships) override{
        delete &arr;
        delete &friendships;
        exit(0);
    }
    ~ExitCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
