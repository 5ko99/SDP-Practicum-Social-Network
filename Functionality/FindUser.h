//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H

#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>
void findUser(std::string const & name){
    std::ifstream users(path);
    assert(users);
    std::string _name;
    while(users >> _name){
        if(_name == name){
            std::string age;
            users>>age;
            std::cout<<name<<' '<<age<<std::endl;
            return;
        }
        std::getline(users,_name);
    }
    users.close();
    std::cerr<<"User not found! \n";
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_FINDUSER_H
