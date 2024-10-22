// Runtime: 0ms
// Memory: 7.7MB
class Solution {
public:
    int maximumSwap(int num) {
        std::string st = std::to_string(num);

        int largestIdx[9];
        largestIdx[st.size() - 1] = st.size() - 1;
        for(int i = st.size()-2; i >= 0; i--)
            largestIdx[i] = (st[i] > st[largestIdx[i+1]]) ? i : largestIdx[i+1];
        for(int i = 0; i < 9; i++)
            if(i < largestIdx[i] && st[i] != st[largestIdx[i]]) {
                char temp = st[i];
                st[i] = st[largestIdx[i]];
                st[largestIdx[i]] = temp;
                break;
            }
        return std::stoi(st);
    }
};
