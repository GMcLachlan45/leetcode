// Runtime 2ms
// Memory 7.7MB
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        std::vector<std::pair<char, int>> c_arr;
        int char_count = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i-1]) {
                c_arr.push_back({s[i-1], char_count});
                char_count = 1;
            } else
                char_count++;
        }
        c_arr.push_back({s[s.size()-1], char_count});

        int stretchy_count = 0;
        for(string word : words) {
            bool stretchy = true;
            int char_ptr = 0;
            char_count = 0;
            for(int i = 0; stretchy && i < word.size(); i++) {
                if(word[i] == c_arr[char_ptr].first) {
                    char_count++;
                    if(char_count > c_arr[char_ptr].second)
                        stretchy = false;
                } else {
                    if(c_arr[char_ptr].second < 3 && char_count != c_arr[char_ptr].second) {
                        stretchy = false;
                        break;
                    }
                    char_ptr++;
                    if(char_ptr < c_arr.size() && word[i] == c_arr[char_ptr].first){
                        char_count = 1;
                    } else {
                        stretchy = false;
                    }
                }
            }
            if (stretchy && char_ptr + 1 == c_arr.size() 
                && (c_arr[c_arr.size()-1].second >=3 || c_arr[c_arr.size()-1].second == char_count)
            )
                stretchy_count++;
        }
        return stretchy_count;
    }
};
