class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_ptr = 0;
        int sent_ptr = 0;
        int space_count = 0;
        while(sent_ptr < sentence.size()) {
            while(word_ptr < searchWord.size()) {
                if(sentence[sent_ptr] != searchWord[word_ptr])
                    break;
                sent_ptr++;
                word_ptr++;
            }
            if(word_ptr == searchWord.size())
                return space_count + 1;
            word_ptr = 0;
            while(sent_ptr < sentence.size() && sentence[sent_ptr++] != ' ');
            space_count++;
        }
        return -1;
    }
};
