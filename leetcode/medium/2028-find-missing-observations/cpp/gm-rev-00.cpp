class Solution {o
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int allRollSum = mean * (rolls.size() + n);
        for(int roll : rolls)
            allRollSum -= roll;
        if(allRollSum > n*6 || allRollSum < n)
            return {};

        std::vector<int> missingRolls;
        while(n) {
            missingRolls.push_back(allRollSum/n);
            allRollSum -= allRollSum/n;
            n--;
        }
        return missingRolls;
    }
};
