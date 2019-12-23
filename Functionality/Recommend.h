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
void sortRecommendations(std::vector<UserRecommendation> & arr){
    std::unordered_set<int> set;
    int n=arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].power < arr[j + 1].power && arr[j].index == arr[j + 1].index)
                swap(j, j + 1, arr);
        }
    }
}
void removeDuplicates(std::vector<UserRecommendation> & v){
    std::vector<UserRecommendation>::iterator itr = v.begin();
    std::unordered_set<int> s;
    int lastPower;
    for (auto curr = v.begin(); curr != v.end(); ++curr) {
        if (s.insert(curr->id).second){
            lastPower=curr->power;
            *itr++ = *curr;
        }else{
            itr->power+=lastPower;
        }

    }

    v.erase(itr, v.end());
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
    sortRecommendations(recommendedUsers);
    //Remove duplicates
    removeDuplicates(recommendedUsers);
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
