//
// Created by petko on 19/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H

#include <vector>
#include "../User.h"
#include <fstream>
#include "../Global.h"
#include <string>
#include <cassert>
#include <algorithm>
#include "DynamicArray.h"

class DynamicGraph {
private:
    std::vector<std::vector<int>> graph;
public:
    DynamicGraph(){
        std::ifstream file(pathGraph, std::ios::in);
        int i=0;
        char c;
        if(file){
           while(file.get(c)){
               if(graph.empty()) graph.emplace_back();
               if(c!='\n'){
                   graph[i].push_back(c-'0');
               }else{
                    graph.emplace_back();
                    i++;
               }
           }
        }
        file.close();
    }
    ~DynamicGraph(){
        std::ofstream graphFile(pathGraph,std::ios::trunc);
        assert(graphFile);
        for(size_t i=0;i<graph.size();i++){
            for(size_t j=0;j<graph[i].size();j++){
                graphFile<<graph[i][j];
            }
            if(i!=graph.size()-1)
                graphFile<<'\n';
        }
    }
    void addEdge(int userA,int userB, int type){
        graph[userA][userB]= type;
        graph[userB][userA]=type;
    }
    void removeEdge(int userA,int userB){
        graph[userA][userB]= 1;
        graph[userB][userA]= 1;
    }
    void removeUser(int user){
        //remove row
        if (graph.size() > user){
            graph.erase( graph.begin() + user );
        }
        //remove col
        for (size_t i = 0; i < graph.size(); ++i){
            if (graph[i].size() > user){
                graph[i].erase(graph[i].begin() + user);
            }
        }
    }
    void addUser(){
        int defaultValue=1;
        int defaultFriend=2;
        std::vector<int> temp;
        for(size_t i=0;i<=graph.size();++i){
            temp.push_back(defaultValue);
        }
        for(size_t i=0;i<graph.size();++i){
            graph[i].push_back(defaultValue);
        }
        graph.push_back(temp);
        graph[graph.size()-1][graph.size()-1]=defaultFriend;
    }
    const std::vector<int> operator[](int pos){
        return  graph[pos];
    }
    size_t size(){
        return graph.size();
    }
    void getFriendsPrint(int id, DynamicArray& arr){
        for(size_t i=0;i<graph.size();++i){
            if((graph[id][i]==2 || graph[id][i]==3 || graph[id][i]==4)&&i!=id){
                std::cout<<arr[i].name<<' ';
            }
        }
        std::cout<<'\n';
    }
    void getRecommendation(int id,std::vector<UserRecommendation> & arr){
        const short maxRecommendations = 30;
        std::vector<int> friends;
        getFriends(id,friends);
        if(friends.size()!=0){
            std::vector<std::vector<int>> friendFriends;
            findFriendFriends(friends, friendFriends);
            UserRecommendation temp;
            for(int i=0; i < friendFriends.size(); i++){
                for(int j=0; j < friendFriends[i].size(); j++){
                    if(arr.size()==maxRecommendations) return;
                    if(graph[id][friendFriends[i][j]] == 1){//We are not friends and we are not banned
                        temp.id=friendFriends[i][j];
                        temp.power=graph[id][i]+graph[i][j];//How good friend I am with my friend i and how good is he with his friend j
                        arr.push_back(temp);
                    }
                }
            }
        }else{
            findMostSocialUsers(arr,id);
        }

    }
    void findMostSocialUsers(std::vector<UserRecommendation> & arr, int id){
        UserRecommendation temp;
        for(size_t i=0;i<graph.size();++i) {
            if(i==id) continue;
            temp.id=i;
            for (size_t j = 0; j < graph[i].size(); ++j) {
                temp.power += graph[i][j];
            }
            arr.push_back(temp);
            temp.power=0;
        }
    }
    void findFriendFriends(std::vector<int> & friends, std::vector<std::vector<int>> & commonFriends){
        std::vector<int> temp;
        for(int i=0;i<friends.size();i++){
            getFriends(friends[i],temp);
            commonFriends.push_back(temp);
        }
    }
    void getFriends(int id,std::vector<int> & arr){
        arr.clear();
        for(size_t i=0;i<graph.size();++i){
            if((graph[id][i]==2 || graph[id][i]==3 || graph[id][i]==4)&&i!=id){
                arr.push_back(i);
            }
        }
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H
