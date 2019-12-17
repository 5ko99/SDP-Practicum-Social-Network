//
// Created by petko on 16/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H

#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>
#include <vector>
#include "../Utils/DynamicArray.h"
bool checkNameFree(std::string const & name, DynamicArray& data){
    for(size_t i=0;i<data.size();i++){
        if(data[i].name==name){
            return false;
        }
    }
    return true;
}
void addUser(User & user, DynamicArray& data){
  if(checkNameFree(user.name,data)){
      data.pushBack(user);
      std::cout<<"User "<<user.name<<" created \n";
  }else{
      std::cerr<<"Name is taken \n";
  }
}
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H
