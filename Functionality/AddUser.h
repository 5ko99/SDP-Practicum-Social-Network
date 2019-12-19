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
bool checkNameFree(std::string const & name, DynamicArray& data, int& id){
    id=-1;
    for(size_t i=0;i<data.size();i++){
        id=data[i].id;
        if(data[i].name==name){
            return false;
        }
    }
    id++;
    return true;
}
void addUser(User & user, DynamicArray& data){
    int id;
  if(checkNameFree(user.name,data,id)){
      user.id=id;
      data.pushBack(user);
      std::cout<<"User "<<user.name<<" created \n";
  }else{
      std::cerr<<"Name is taken \n";
  }
}
#endif //SDP_PRACTICUM_SOCIAL_NETWORK_ADDUSER_H
