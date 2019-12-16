//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H


#include <string>
#include "../Commands/Command.h"
#include "../Commands/AddUserCommand.h"
#include "../Commands/ExitCommand.h"
#include "../Commands/DeleteCommand.h"
#include "../Commands/LinkCommand.h"
#include "../Commands/FindCommand.h"
#include "../Commands/BanCommand.h"
#include "../Commands/DelinkCommand.h"
#include "../Commands/RecommendCommand.h"
class Invoker {
public:
    Command* determinate(std::vector<std::string> args){
        std::string command = args[0];
        if(command=="create") return new AddUserCommand(args);
        if(command=="exit") return new ExitCommand();
        if(command=="delete") return  new DeleteCommand(args);
        if(command=="link") return new LinkCommand(args);
        if(command=="find") return new FindCommand(args);
        if(command=="ban") return new BanCommand(args);
        if(command=="delink") return new DelinkCommand(args);
        if(command=="recommend") return new RecommendCommand(args);
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H
