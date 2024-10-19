// Runtime: 0ms
// Memory: 7.6MB
class Solution {
public:
    char findKthBit(int n, int k) {
        std::stack<int> st;
        st.push(1);

        while(k > st.top())
            st.push(2*st.top() + 1);

        int flips = 0;
        while(k > 1) {
            if(k-1 == st.top())
                return (flips % 2 == 0) ? '1' : '0';
            if(k > st.top()) {
                flips++;
                k = 2*st.top() - k + 2;
            }
            st.pop();
        }
        return (flips % 2 == 0) ? '0' : '1';
    }
};
