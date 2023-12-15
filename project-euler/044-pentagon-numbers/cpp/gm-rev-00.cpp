#include <unordered_set>
#include <set>
#include <iostream>
#include <vector>
int main(int argc, char* argv[]) {
    std::unordered_set<int> st;
    for(int n = 1; n < 10000; n++) {
        st.insert(n*(3*n-1)/2);
    }

    std::set<int> candidates;
    for(int Pk : st) {
        for(int Pn : st) {
            if(Pk!=Pn && st.count(Pk-Pn) && st.count(Pk+Pn)){
                candidates.insert(Pk-Pn*((Pk-Pn < 0)? -1: 1));
            }
        }
    }


    for(int P : candidates)
        std::cout<< "Using Brute force we found " <<P<<std::endl;
    return 0;
}
