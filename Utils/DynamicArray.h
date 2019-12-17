//
// Created by petko on 17/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICARRAY_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICARRAY_H

#include <vector>
#include "../User.h"
#include <fstream>
#include "../Global.h"
#include <string>
class DynamicArray {
    std::vector<User> data;
public:
    DynamicArray(){
        std::ifstream users(path, std::ios::binary | std::ios::in);
        if (users) {
            User user;
            while (users.read((char *) &user, sizeof(User))) {
                data.push_back(user);
            }
        }
        users.close();
    }
    ~DynamicArray(){
        std::ofstream users(path,std::ios::binary|std::ios::out|std::ios::trunc);
        data.shrink_to_fit();
        for(int i=0;i<data.size();i++){
            data[i].id=i;
            users.write((char*) &data[i], sizeof(User));
        }
        users.close();
    }
    User& operator[](int pos){
        return data[pos];
    }
    void pushBack(User const & user){
        data.push_back(user);
    }
    size_t size(){
        return data.size();
    }
    void erase(int pos){
        data.erase(data.begin()+pos);
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICARRAY_H
