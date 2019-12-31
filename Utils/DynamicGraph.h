//
// Created by petko on 19/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H

#include <vector>
#include "User.h"
#include <fstream>
#include "Global.h"
#include <string>
#include <cassert>
#include <algorithm>
#include <set>
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
    bool addEdge(int userA,int userB, int type){
        bool flag1=true,flag2;
        if(graph[userA][userB]==type && graph[userB][userA]==type) {
            return false;
        } else{
            if((graph[userA][userB]==0 || graph[userA][userB]==1) && (type==0 || type==1)) flag1=false;
            flag2 = ((graph[userA][userB] == 2 && graph[userB][userA] == 2) ||
                    (graph[userA][userB] == 3 && graph[userB][userA] == 3)
                    || (graph[userA][userB] == 4 && graph[userB][userA] == 4)) ==
                   !(type == 2 || type == 3 || type == 4);
            graph[userA][userB]= type;
            graph[userB][userA]=type;
        }
        return flag1&&flag2;
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

    bool getRecommendation(int id,std::set<UserRecommendation> & s, DynamicArray& data){
        //User don't have friends
        if(data[id].friends==0){
            findMostSocialUsers(s,id,data);
            return false;
        }
        //User have friends
        for(int i=0;i<graph[id].size();++i){
            if((graph[id][i]==2 || graph[id][i]==3 || graph[id][i]==4)&&i!=id){
                for(int j=0;j<graph.size();++j){
                    if((graph[j][i]==2 || graph[j][i]==3 || graph[j][i]==4)&&j!=id){
                        if(graph[id][j]==1){
                            UserRecommendation ur(j,graph[j][i]+graph[id][i]);
                                s.insert(ur);
                        }
                    }
                }
            }
        }
        return true;
    }
    void findMostSocialUsers(std::set<UserRecommendation> & arr, int id, DynamicArray& data){
        for(int i=0;i<data.size();++i){
            if(i==id) continue;
            auto ur=UserRecommendation(i,data[i].friends);
            arr.emplace(ur);
        }
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H
