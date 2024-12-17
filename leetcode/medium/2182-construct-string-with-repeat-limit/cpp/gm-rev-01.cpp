// Runtime: 3ms
// Memory: 24.9MB
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int count[26];
        for(char c : s)
            count[c-'a']++;
        int largestPtr = 25;
        int secondLargestPtr = 24;
        while(secondLargestPtr >= 0 && !count[secondLargestPtr])
            secondLargestPtr--;

        int idx = 0;
        while(secondLargestPtr >= 0) {
            for(int i = 0; count[largestPtr] && i < repeatLimit; i++) {
                s[idx++] = 'a' + largestPtr;
                count[largestPtr]--;
            }

            if(count[largestPtr]) {
                s[idx++] = 'a' + secondLargestPtr;
                count[secondLargestPtr]--;
            } else
                largestPtr = secondLargestPtr--;

            while(secondLargestPtr >= 0 && !count[secondLargestPtr])
                secondLargestPtr--;
        }

        for(int i = 0; count[largestPtr] && i < repeatLimit; i++) {
            s[idx++] = 'a' + largestPtr;
            count[largestPtr]--;
        }
        return s.substr(0, idx);
    }
};
