// Runtime: 0ms
// Memory: 9.4MB
class Solution {
    std::unordered_map<std::string, std::vector<int>> cache;
    std::vector<int> helper(string expression) {
        if(cache[expression].size())
            return cache[expression];

        cache[expression] = {};
        int operatorPtr = 0;
        while(operatorPtr < expression.size() && std::isdigit(expression[++operatorPtr]));

        while(operatorPtr < expression.size()) {
            std::vector<int> lNums = helper(expression.substr(0, operatorPtr));
            for(int rNum : helper(expression.substr(operatorPtr+1, expression.size()-operatorPtr - 1))) {
                for(int lNum : lNums)
                    cache[expression].push_back(
                        (expression[operatorPtr] == '+')
                        ? lNum + rNum
                        : (
                            (expression[operatorPtr] == '-')
                            ? lNum -rNum
                           : lNum * rNum)
                        );
            }

            while(operatorPtr < expression.size() && std::isdigit(expression[++operatorPtr]));
        }

        return cache[expression];
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        // setup the cache with singletons
        int numBegin = 0;
        int numEnd = 0;
        while(numBegin < expression.size()) {
            while(numEnd < expression.size() && std::isdigit(expression[++numEnd]));
            cache[expression.substr(numBegin, numEnd-numBegin)] = {std::stoi(expression.substr(numBegin))};
            numBegin = ++numEnd;
        }

        return helper(expression);
    }
};
