class Solution {
private:
     int getPos(char c) {
          if(c == 'Q')
               return 0;
          else if(c == 'W')
               return 1;
          else if(c == 'E')
               return 2;
          else
               return 3;
     }

public:

     int balancedString(string s) {
          // array representing occurrences of {Q,W,E,R}
          std::vector<int> occurences(4, -1 * (int) s.size()/4);
          for(char x : s) {
               occurences[getPos(x)]++;
          }

          int shortest_sequence = s.size();
          int b = 0;
          int e = 0;
          while(b < s.size()) {
               while(e < s.size() &&  (occurences[0] > 0 || occurences[1] > 0 || occurences[2] > 0 || occurences[3] > 0)) {
                    occurences[getPos(s[e])]--;
                    e++;
               }
               if(e < s.size() || (occurences[0] <= 0 && occurences[1] <= 0 && occurences[2] <= 0 && occurences[3] <= 0)) {
                    shortest_sequence = std::min(shortest_sequence, e-b);
                    occurences[getPos(s[b])]++;
                    b++;
               } else
                    break;
          }
          return shortest_sequence;
     }
};
