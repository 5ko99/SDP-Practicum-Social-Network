//
// Created by petko on 22/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H

#include <iostream>
#include "../User.h"
#include "../Global.h"
#include <fstream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <set>
#include "../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
int findID(std::string const & name, DynamicArray& data){
    for(int i=0;i<data.size();i++) {
        if (data[i].name == name) {
            return data[i].id;
        }
    }
    return -1;
}
void swap(int i,int j, std::vector<UserRecommendation> & arr){
    UserRecommendation temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void sortByID(std::vector<UserRecommendation> & arr){
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id)
                swap(j, j + 1, arr);
        }
    }
}
void sortByPower(std::vector<UserRecommendation> & arr){
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].power < arr[j + 1].power)
                swap(j, j + 1, arr);
        }
    }
}
void getUserNames(std::set<UserRecommendation> & userRec,
                  DynamicArray& data,std::vector<std::string> & userNames){
    std::vector<UserRecommendation> rec;
    int n=0;
    rec.emplace_back(*userRec.begin());
    for(const auto& i: userRec){
        if(rec[n].id==i.id){
            if(rec[n].power<i.power){
                rec[n].power+=i.power;//sum all the powers
            }
        }else{
            ++n;
            rec.emplace_back(i);
        }
    }
    //TODO: not doing it this way in final
    sortByPower(rec);
    n=0;
    for(const auto& i:rec){
        if(n==30) return;
        userNames.emplace_back(data[i.id].name);
        n++;
    }
}
void recommend(std::string const & name, DynamicArray& data, DynamicGraph& friendships){
    int id=findID(name,data);
    if(id==-1){
        std::cerr<<"Wrong name! \n";
        return;
    }
    std::set<UserRecommendation> recommendedUsers;
    friendships.getRecommendation(id,recommendedUsers);
    std::vector<std::string> userNames;
    getUserNames(recommendedUsers,data,userNames);
    std::cout<<"Recommendations: ";
    for(const auto& i: userNames){
        std::cout<<i<<" ";
    }
    std::cout<<'\n';
}



#endif //SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
