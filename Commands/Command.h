//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H

#include <vector>
#include "../User.h"
#include"../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
enum CommandType{
    AddUser,
    Exit,
    Delete,
    Link,
    Find,
    Ban,
    Delink,
    Recommend
};
class Command {
protected:
    std::vector<User> users;
    CommandType commandType;
public:
    Command(){};
    virtual ~Command(){};
    virtual void execute(DynamicArray&,DynamicGraph&)=0;
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_COMMAND_H
