//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_USER_H

#include <string>
//100 symbol max for name and email
const short SIZE=100;
void copyChar( char* dest,const char* data){
    for(size_t i=0;i<SIZE;i++){
        dest[i]=data[i];
    }
}
struct User {
    char name[100];
    short age;
    char email[100];
    int id;
    User(const char* _name, short _age,const char* _email,int _id=-1):age(_age),id(_id){
        copyChar(name,_name);
        copyChar(email,_email);
    }
    User():id(-1){}
    std::string getName() const{
        return name;
    }
    short getAge() const{
        return age;
    }
    std::string getEmail() const{
        return email;
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
