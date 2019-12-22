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
#include "../Commands/UnbanCommand.h"
class Invoker {
public:
    Command* determinate(std::vector<std::string> args){
        std::string command = args[0];
        if(command=="create" && args.size()==4) return new AddUserCommand(args);
        if(command=="exit"&& args.size()==1) return new ExitCommand();
        if(command=="delete"&& args.size()==2) return  new DeleteCommand(args);
        if(command=="link" && (args.size()==3||args.size()==4)) return new LinkCommand(args);
        if(command=="find" && args.size()==2) return new FindCommand(args);
        if(command=="ban" && args.size()==3) return new BanCommand(args);
        if(command=="delink"&& args.size()==3) return new DelinkCommand(args);
        if(command=="unban"&& args.size()==3) return new UnbanCommand(args);
        if(command=="recommend"&& args.size()==2) return new RecommendCommand(args);
        std::cerr<<"Wrong command! \n";
        return nullptr;
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_INVOKER_H
