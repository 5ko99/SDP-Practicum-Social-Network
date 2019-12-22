//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H

#include "Command.h"
#include "../Functionality/Exit.h"
class ExitCommand:public Command {
public:
    ExitCommand():Command(){
        commandType=Exit;
    }
    void execute(DynamicArray& arr, DynamicGraph& friendships) override{
        exit(0,arr,friendships);
    }
    ~ExitCommand(){}
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_EXITCOMMAND_H
