// Runtime: 3ms
// Memory: 14MB
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int answer = 0;
        for(std::string cmd : logs) {
            if(cmd[0] == '.') {
                if(cmd[1] == '.' && answer)
                    answer--;
            } else
                answer++;
        }
        return answer;
    }
};
