// Runtime 15ms
// Memory 12.4MB
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        short unsigned int threshold = arr.size()/4;
        short unsigned int count = 1;
        short unsigned int idx = 0;
        for(short unsigned int i = 1; count <= threshold; i++){
            if(arr[i] != arr[idx]){
                count = 1;
                idx = i;
            } else {
                count++;
            }
        }
        return arr[idx];
    }
};