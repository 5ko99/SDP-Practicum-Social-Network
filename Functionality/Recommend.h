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
bool isIn(std::vector<UserRecommendation> & arr, int id){
    for(UserRecommendation j : arr)
        if(j.id == id) return true;
    return false;
}
void removeDuplicates(std::vector<UserRecommendation> & v){
   std::vector<UserRecommendation> result;
   int lastPower;
   for(auto & i : v){
       if(!isIn(result,i.id)){
            lastPower=i.power;
            result.push_back(i);
       }else{
           result.back().power+=lastPower;
       }
   }
   v=result;
}
void getUserNames(std::vector<UserRecommendation> & userRec,
                  DynamicArray& data,std::vector<std::string> & userNames){
    for(int i=0;i<userRec.size();i++){
        userNames.push_back(data[userRec[i].id].name);
    }
}
void recommend(std::string const & name, DynamicArray& data, DynamicGraph& friendships){
    const short maxRecommendations = 30;
    int id=findID(name,data);
    std::vector<UserRecommendation> recommendedUsers;
    if(id==-1){
        std::cerr<<"Wrong name! \n";
        return;
    }
    friendships.getRecommendation(id,recommendedUsers);
    sortByID(recommendedUsers);
    //Remove duplicates
    removeDuplicates(recommendedUsers);
    sortByPower(recommendedUsers);
    std::vector<std::string> userNames;
    getUserNames(recommendedUsers,data,userNames);
    std::cout<<"Recommendations: ";
    int n=0;
    for(auto i: userNames){
        std::cout<<i<<" ";
        n++;
        if(n==30) break;
    }
    std::cout<<'\n';
}



#endif //SDP_PRACTICUM_SOCIAL_NETWORK_RECOMMEND_H
