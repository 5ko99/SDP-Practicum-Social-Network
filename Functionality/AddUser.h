//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H

#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>

bool checkNameFree(std::string const & name){
    std::ifstream users(path);
    assert(users);
    std::string _name;
    while(users >> _name){
        if(_name == name){
            return false;
        }
        std::getline(users,_name);
    }
    users.close();
    return true;
}
void addUser(User const & user){
    if(checkNameFree(user.name)) {
        std::ofstream of(path, std::ios::app);
        assert(of);
        of << user.name << ' ' << user.age << ' ' << user.email << ' ' << std::endl;
        of.close();
        std::cout << "User " << user.name << " created \n";
    }else{
        std::cerr<<"Username "<<user.name<<" is taken! \n";
    }
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H
