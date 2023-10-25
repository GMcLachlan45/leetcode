// Runtime 4ms
// Memory 10.4
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> s;
        for(int x: arr) {
            if(s.count(x * 2) || (x % 2 == 0 && s.count(x / 2)) )
                return true;
            s.insert(x); 
        }
        return false;
    }
};
