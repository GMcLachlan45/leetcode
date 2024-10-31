#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
std::set<std::set<int>> powerSet(std::set<int> st){
    std::set<std::set<int>> ret;
    std::queue<std::set<int>> q;
    q.push({});
    while(ret.size() < std::pow(2, st.size())) {
        ret.insert(q.front());
        for(int x : st) {
            std::set<int> nextSet = q.front();
            if(x > (*nextSet.begin()) && !nextSet.count(x)){
                nextSet.insert(x);
                q.push(nextSet);
            }
        }
        q.pop();
    }
    return ret;
}

int main() {
    std::set<int> input = {1,2,3};

    std::cout<<"For the set"<<std::endl<<"{";
    for(int x : input)
        std::cout<<x <<", ";
    std::cout<< "}" <<std::endl<<"The power set is as follows:"<<std::endl<<"{"<<std::endl;
    for(std::set<int> st : powerSet(input)) {
        std::cout<<"\t{";
        for(int x : st)
            std::cout<<x <<", ";
        std::cout<<"},"<<std::endl;
    }
    std::cout<<"}"<<std::endl;

    input = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"For the set"<<std::endl<<"{";
    for(int x : input)
        std::cout<<x <<", ";
    std::cout<< "}" <<std::endl<<"The power set is as follows:"<<std::endl<<"{"<<std::endl;
    for(std::set<int> st : powerSet(input)) {
        std::cout<<"\t{";
        for(int x : st)
            std::cout<<x <<", ";
        std::cout<<"},"<<std::endl;
    }
    std::cout<<"}"<<std::endl;

    input = {};
    std::cout<<"For the set"<<std::endl<<"{";
    for(int x : input)
        std::cout<<x <<", ";
    std::cout<< "}" <<std::endl<<"The power set is as follows:"<<std::endl<<"{"<<std::endl;
    for(std::set<int> st : powerSet(input)) {
        std::cout<<"\t{";
        for(int x : st)
            std::cout<<x <<", ";
        std::cout<<"},"<<std::endl;
    }
    std::cout<<"}"<<std::endl;


}
