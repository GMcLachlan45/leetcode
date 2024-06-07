// Runtime:  1098ms
// Memory: 479.9MB
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::set<std::string> dict(dictionary.begin(), dictionary.end());
        int word_start = 0;
        std::string ret;

        bool found = false;
        for(int i = 1; i < sentence.size(); i++) {
            if(sentence[i] == ' '){
                if(!found)
                    ret +=  sentence.substr(word_start, i-word_start) + ' ';
                else
                    ret += ' ';
                word_start = i+1;
                found = false;
            } else if(!found && dict.contains(sentence.substr(word_start, i-word_start))){
                ret +=  sentence.substr(word_start, i-word_start);
                found = true;
            }

        }
        if(!found)
            ret +=  sentence.substr(word_start, sentence.size()-word_start);

        return ret;
    }
};
