#include <string>
#include <iostream>
#include <vector>


int main(int argc, char* argv[]) {
    int n_1 = 1;
    int n_2 = 1;
    int ans = 0;
    while(n_2 < 4000000){
        if(n_2%2 == 0)
            ans += n_2;
        int sum = n_1 + n_2;
        n_1 = n_2;
        n_2 = sum;
    }
    std::cout << ans<<std::endl;
    return 0;
}
