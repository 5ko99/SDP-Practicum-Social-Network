//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_USER_H

#include <string>

struct User {
    std::string name;
    short age;
    std::string email;
    User(std::string const & _name, short _age,std::string const & _email):name(_name),age(_age),email(_email){}
    std::string getName() const{
        return name;
    }
    short getAge() const{
        return age;
    }
    std::string getEmail() const{
        return email;
    }
    void setName(std::string const & _name){
        name=_name;
    }
    void setAge(short _age){
        age=_age;
    }
    void setEmail(std::string const & _email){
        email=_email;
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
