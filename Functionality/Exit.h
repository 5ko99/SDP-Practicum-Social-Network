//
// Created by petko on 22/12/2019.
//

#ifndef SDP_PRACTICUM_SOCIAL_NETWORK_EXIT_H
#define SDP_PRACTICUM_SOCIAL_NETWORK_EXIT_H

#include "../Utils/DynamicArray.h"
#include "../Utils/DynamicGraph.h"
void exit(int exitCode,DynamicArray& arr, DynamicGraph& friendships){
    delete &arr;
    delete &friendships;
    exit(exitCode);
}


#endif //SDP_PRACTICUM_SOCIAL_NETWORK_EXIT_H
