//
// Created by petko on 15/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_USER_H

#include <string>
class User {
private:
    std::string name;
    short age;
    int id;
    User(std::string const & _name, short _age):name(_name),age(_age){
        id=generateID();
    }
    int generateID(){
       srand(time(NULL)+std::stoi(name)+age);
       return rand();
    }
public:
    std::string getName() const{
        return name;
    }
    short getAge() const{
        return age;
    }
    int getID() const{
        return id;
    }
    void setName(std::string const & _name){
        name=_name;
    }
    void setAge(short _age){
        age=_age;
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_USER_H
