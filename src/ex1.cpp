#include "ex1.hpp"
void pairwise_concatenate(std::list<std::list<int>>& list1,std::list<std::list<int>>& list2){
    auto it = list1.begin();
    for (auto it2 = list2.begin();it2 != list2.end();it2++){
        concatenate(*it,*it2);
        it++;
    } 
}


void pairwise_concatenate(std::list<std::list<int>>& list1,std::list<std::list<int>>&& list2){
    auto it = list1.begin();
    for (auto it2 = list2.begin();it2 != list2.end();it2++){
        concatenate(*it,std::move(*it2));
        it++;
    }
}