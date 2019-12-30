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

    void getRecommendation(int id,std::set<UserRecommendation> & s){
        for(unsigned i=0;i<graph[id].size();++i){
            if((graph[id][i]==2 || graph[id][i]==3 || graph[id][i]==4)&&i!=id){
                for(unsigned j=0;j<graph.size();++j){
                    if((graph[j][i]==2 || graph[j][i]==3 || graph[j][i]==4)&&j!=id){
                        if(graph[id][j]==1){
                            UserRecommendation ur(j,graph[j][i]+graph[id][i]);
                                s.insert(ur);
                        }
                    }
                }
            }
        }
    }
};


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_DYNAMICGRAPH_H
