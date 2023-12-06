// Runtime: 0ms
// Memory: 6.2MB
class Solution {
public:
    int totalMoney(int n) {
      int week = 0;
      int total = 0;
      for(int i = 1; i<=n; i++){
          total += i%7 + week;
          if(i%7 == 0){
            week++;
            total+=7;
          }
      }
      return total;
    }
};
