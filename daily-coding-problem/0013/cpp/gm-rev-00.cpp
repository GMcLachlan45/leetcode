#include <iostream>
#include <string>

int longestSubstringWithAtMostKChars(std::string s, int k) {
    if(k == 0)
        return 0;
    int occurences[128] = {};
    int charsUsed = 0;
    int front = 0;
    int back = 0;
    int ans = 0;
    while(back < s.size()) {
        while(back < s.size() && (charsUsed < k || occurences[s[back]] > 0))
            if(occurences[s[back++]]++ == 0)
                charsUsed++;
        if(back-front > ans)
            ans = back-front;
        if(--occurences[s[front++]] == 0)
            charsUsed--;
    }
    return ans;
}

int main() {
    std::string s = "abcba";
    int k = 2;
        std::cout<< "The length of the longest subtring with at most " << k << " distinct chars in the string " << s << " is " << longestSubstringWithAtMostKChars(s, k) << std::endl;

    s = "abcbabababababb";
    k = 1;
    std::cout<< "The length of the longest subtring with at most " << k << " distinct chars in the string " << s << " is " << longestSubstringWithAtMostKChars(s, k) << std::endl;

    s = "aaaaaaa";
    k = 26;
    std::cout<< "The length of the longest subtring with at most " << k << " distinct chars in the string " << s << " is " << longestSubstringWithAtMostKChars(s, k) << std::endl;

    s = "";
    k = 1;
    std::cout<< "The length of the longest subtring with at most " << k << " distinct chars in the string " << s << " is " << longestSubstringWithAtMostKChars(s, k) << std::endl;

    s = "oentuh oetuhet heotu eonthu ontehutonhtoehuneothuonettuehuthuetheueueueueueueueueuetheonuteohnothuontuhousathasasthhoet";
    k = 1;
    std::cout<< "The length of the longest subtring with at most " << k << " distinct chars in the string " << s << " is " << longestSubstringWithAtMostKChars(s, k) << std::endl;

}
