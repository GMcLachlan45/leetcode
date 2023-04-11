// Runtime 0ms
// Memory 6.1MB
class Solution {
       
public:
    int getMaximumGenerated(int n) {
        if(n < 2)
            return n;
        int max = 1;
        vector<int> arr = {0,1};
        for(int i = 2; i <= n; i++) {
            arr.push_back(
		(i%2 == 0) 
                ? arr[i / 2] 
                : arr[(i - 1) / 2] + arr[(i - 1) / 2 + 1]
	    );
            if(arr[i]>max)
                max = arr[i];
        }
        return max;
    }
};
