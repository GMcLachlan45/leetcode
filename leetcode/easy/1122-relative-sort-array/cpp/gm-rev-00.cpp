// Runtime: 4ms
// Memory: 9.6MB
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int cache[1001];
        for(int x : arr2) {
            cache[x] = 1001;
        }
        for(int x : arr1) {
            if(cache[x] > 0) {
                if(cache[x] == 1001)
                    cache[x] = 1;
                else
                    cache[x]++;
            } else
                cache[x]--;
        }

        int ptr = 0;
        std::vector<int> ret(arr1.size());
        for(int x : arr2) {
            while(cache[x]) {
                ret[ptr++] = x;
                cache[x]--;
            }
        }

        for(int i = 0; i <= 1000; i++) {
            while(cache[i]) {
                ret[ptr++] = i;
                cache[i]++;
            }
        }

        return ret;
    }
};
