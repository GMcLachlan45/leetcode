// Runtime: 4ms
// Memory: 8.7MB
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        int check[26];
        for(char c : s1)
            check[c-'a']++;

        int charsOff = 0;
        for(int i = 0; i < 26; i++)
            charsOff += (check[i] > 0);

        for(int i = 0; i < s1.size(); i++) {
            if(!check[s2[i]-'a'])
                charsOff++;
            check[s2[i]-'a']--;
            if(!check[s2[i]-'a'])
                charsOff--;
        }
        for(int i = s1.size(); i < s2.size(); i++) {
            if(charsOff == 0)
                return true;
            // Remove char at front of substr
            if(!check[s2[i - s1.size()]-'a'])
                charsOff++;
            check[s2[i - s1.size()]-'a']++;
            if(!check[s2[i - s1.size()]-'a'])
                charsOff--;

            // Add char at end of substr
            if(!check[s2[i]-'a'])
                charsOff++;
            check[s2[i]-'a']--;
            if(!check[s2[i]-'a'])
                charsOff--;

        }

        return charsOff == 0;

    }
};
