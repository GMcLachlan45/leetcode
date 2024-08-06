// Runtime; 65ms
// Memory: 24.8MB
class Solution {
public:
    int minimumPushes(string word) {
        int charCount[27];
        for(char c : word)
            charCount[c - 'a']++;
        std::sort(charCount, charCount+26, std::greater());

        int answer = 0;
        int i = 0;
        while(charCount[i])
            answer += charCount[i] * (i++/8 + 1);
        return answer;
    }
}
