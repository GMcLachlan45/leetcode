#include <iostream>
#include <vector>
#include <algorithm>

long long waysToClimbStairs(int n) {
    std::vector<long long> dp(n+2);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }
    return dp[n];
}

long long climbStairsGivenJumps(int n, std::vector<int> jumps) {
    std::sort(jumps.begin(), jumps.end());
    std::vector<long long> dp(n+jumps[jumps.size()-1]);
    dp[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < jumps.size(); j++)
            dp[i+jumps[j]] += dp[i];
    return dp[n];
}

int main() {

    int n = 4;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    n = 8;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    n = 16;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    n = 32;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    n = 64;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    n = 128;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;

    // But we get overflows here lol
    n = 256;
    std::cout<< "The way to climb " << n <<" steps using only one or two steps is "<< waysToClimbStairs(n)<< std::endl;


    n = 4;
    std::vector<int> jumps = {1,2};
    std::cout<< "The number of ways to climb " << n <<" steps using jumps in [";
    for(int x : jumps)
        std::cout<< x<<" ";
    std::cout<<"] is "<< climbStairsGivenJumps(n, jumps)<< std::endl;

    n = 4;
    jumps = {1, 3, 5};
    std::cout<< "The number of ways to climb " << n <<" steps using jumps in [";
    for(int x : jumps)
        std::cout<< x<<" ";
    std::cout<<"] is "<< climbStairsGivenJumps(n, jumps)<< std::endl;

    n = 12;
    jumps = {1, 3, 5, 12};
    std::cout<< "The number of ways to climb " << n <<" steps using jumps in [";
    for(int x : jumps)
        std::cout<< x<<" ";
    std::cout<<"] is "<< climbStairsGivenJumps(n, jumps)<< std::endl;

}
