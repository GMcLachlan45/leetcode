// Runtime: 80ms
// Memory: 63.6MB
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winCount = 0;
        k = std::min(k,(int) arr.size()+1);
        int opponent = 1;
        while (winCount < k) {
            if(arr[opponent]>arr[0]) {
                winCount = 0;
                int temp = arr[0];
                arr[0] = arr[opponent];
                arr[opponent]= temp;
            }
            winCount++;
            opponent = (opponent+1)%arr.size();
            if(opponent==0)
                opponent++;
        }
        return arr[0];
    }
};
