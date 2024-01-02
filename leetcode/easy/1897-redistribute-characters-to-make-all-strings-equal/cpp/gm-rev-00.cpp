// Runtime: 28ms
// Memory: 12.47MB
class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    int charCount[26] = {0};
    for(std::string word :words) {
      for(char ch : word) 
	charCount[ch-'a']++;
    }
    for(int i = 0; i < 26; i++){
      if(charCount[i]%words.size())
	return false;
    }
    return true;
  }
};
