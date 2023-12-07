#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "../../../bin/input-reader.cpp"
#include <cctype>

class camelCardsHand {
private:
    int calculateLevel(std::string hand) {
        std::sort(hand.begin(), hand.end());
        int numberOfJ = 0;
        int ret = 0;
        int beginning = 0;
        if(hand[0] == '1')
            numberOfJ++;
        for(int i = 1; i < 5; i++) {
            if(hand[i] == '1')
                numberOfJ++;
            if(hand[i] != hand[beginning]) {
                ret += (i-beginning)*(i-beginning);
                beginning=i;
            }
        }
        ret += (5-beginning)*(5-beginning);
        // 25 is 5, 17 is 4, 13 is full house
        // 11 is 3, 9 is 2p, 7 is 2, 5 is 1
        if(numberOfJ>0 && numberOfJ <5) {
            if(ret== 17 || ret == 13)
                ret = 25;
            else if(ret == 11)
                ret = 17;
            else if(ret == 9)
                ret = (numberOfJ == 2) ? 17 : 13;
            else if(ret == 7)
                ret = 11;
            else
                ret = 7;
        }
        return ret;
    }
public:
    int level;
    std::string hand;
    int wager;
    camelCardsHand(std::string in, bool interesting) {
        hand ="";
        for(int i = 0; i < 5; i++) {
            if(in[i] == 'T')
                hand.push_back('a');
            else if(in[i] == 'J')
                hand.push_back((interesting) ? '1' : 'b');
            else if(in[i] == 'Q')
                hand.push_back('c');
            else if(in[i] == 'K')
                hand.push_back('d');
            else if(in[i] == 'A')
                hand.push_back('e');
            else
                hand.push_back(in[i]);
        }
        level = calculateLevel(hand);
        wager = std::stoi(in.substr(6,in.size()-6));
    }
};


int main(int argc, char* argv[]) {
    std::vector<camelCardsHand> input;
    std::vector<camelCardsHand> coolInput;
    for(std::string c : readInputs(argv[1])) {
        camelCardsHand hand(c, false);
        camelCardsHand coolHand(c, true);
        input.push_back(hand);
        coolInput.push_back(coolHand);
    }
    std::sort(input.begin(), input.end(), [](auto &left, auto &right) {
        if(left.level == right.level) {
            int i = 0;
            while(left.hand[i] == right.hand[i])
                i++;
            return left.hand[i] < right.hand[i];
        }
        return left.level < right.level;
    });
    std::sort(coolInput.begin(), coolInput.end(), [](auto &left, auto &right) {
        if(left.level == right.level) {
            int i = 0;
            while(left.hand[i] == right.hand[i])
                i++;
            return left.hand[i] < right.hand[i];
        }
        return left.level < right.level;
    });
    int winnings = 0;
    int coolWinnings = 0;
    for(int i = 0; i < input.size(); i++) {
        winnings += input[i].wager*(i+1);
        coolWinnings += coolInput[i].wager*(i+1);
    }
    // Passed
    std::cout<< "Solution 1: the total winnings are: " << winnings <<std::endl;
    // Passed
    std::cout<< "Solution 1: the total winnings with wildcards are: " << coolWinnings <<std::endl;


    return 0;

}
