// Runtime: 4ms
// Memory: 12.7MB
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        double quarter = arr.size()/4.0;
        int firstTime = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[firstTime] == arr[i]){
                if(i-firstTime + 1 > quarter)
                    break;
            } else
                firstTime = i;
        }
        return arr[firstTime];
    }
};
