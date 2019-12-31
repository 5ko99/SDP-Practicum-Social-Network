//
// Created by petko on 17/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DELETEUSER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DELETEUSER_H


#include "../Utils/User.h"
#include "../Utils/Global.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include "../Utils/DynamicArray.h"
void deleteUser(std::string const & name, DynamicArray& data, DynamicGraph& friendships){
    for(int i=0;i<data.size();i++){
        if(data[i].name==name){
            std::cout<<"User "<<name<<" has been deleted! \n";
            data.erase(i);
            friendships.removeUser(data[i].id);
            return;
        }
    }
    std::cerr<<"User not found! \n";
}
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DELETEUSER_H
