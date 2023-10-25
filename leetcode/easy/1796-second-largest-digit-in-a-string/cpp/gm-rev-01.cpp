// Runtime 3ms
// Memory 6.7MB
class Solution {
public:
    int secondHighest(string s) {
        char largest = '/';
        char second_largest = '/';
        for(char x: s){
            if(x < 'A') {
                if(x > largest) {
                    second_largest = largest;
                    largest = x;
                } else if(x != largest && x > second_largest)
                    second_largest = x;
            }
        }
        return (int) (second_largest - '0');
    }
};
