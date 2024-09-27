#include <iostream>
#include <string>
#include <vector>
// Easy to follow O(N)/O(N) DP version
int waysToDecode(std::string msg) {
    if(msg.size()<2)
        return 1;

    std::vector<int> dp(msg.size()+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= msg.size(); i++) {
        if(msg[i-2] == '1' || msg[i-2] == '2') {
            dp[i] = dp[i-2] + ((msg[i-1] != '0') * dp[i-1]);
        } else
            dp[i] = dp[i-1];
    }
    return dp[msg.size()];
}

// O(N)/O(1) solution
int waysToDecodeOptimized(std::string msg) {
    if(msg.size()<2)
        return 1;

    int twoAgo = 1;
    int oneAgo = 1;
    for(int i = 1; i < msg.size(); i++) {
        int temp = 0;
        if(msg[i-1] == '1' || msg[i-1] == '2')
            temp += twoAgo;
        if(msg[i] != '0')
            temp += oneAgo;
        twoAgo = oneAgo;
        oneAgo = temp;
    }
    return oneAgo;
}

int main() {
    std::string input = "111111";
    std::cout << "For the input " << input << " there are " << waysToDecodeOptimized(input) << " ways to decode this message." << std::endl;

    input = "101110";
    std::cout << "For the input " << input<< " there are " << waysToDecodeOptimized(input) << " ways to decode this message." << std::endl;

    input = "4444";
    std::cout << "For the input " << input<< " there are " << waysToDecodeOptimized(input) << " ways to decode this message." << std::endl;

    input = "2242226";
    std::cout << "For the input " << input<< " there are " << waysToDecodeOptimized(input) << " ways to decode this message." << std::endl;

    input = "";
    std::cout << "For the input " << input<< " there are " << waysToDecodeOptimized(input) << " ways to decode this message." << std::endl;
}
