// Runtime 0ms
// Memory 6.6MB
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::string sStr;
        std::string tStr;
        for(char c : s){
            if(c !='#')
                sStr.push_back(c);
            else if(!sStr.empty())
                sStr.pop_back();
        }
        for(char c : t){
            if(c !='#')
                tStr.push_back(c);
            else if(!tStr.empty())
                tStr.pop_back();
        }
        return sStr == tStr;
    }
};
