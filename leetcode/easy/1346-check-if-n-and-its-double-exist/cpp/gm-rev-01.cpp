class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> st;
        for(int x : arr) {
            if((x % 2 == 0 && st.count(x/2)) || st.count(x<<1))
                return true;
            st.insert(x);
        }
        return false;
    }
};
