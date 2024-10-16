// Runtime: 0ms
// Memory: 7.4MB
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // save which chars occur most & use a b c as max middle min
        char chars[3];
        int nums[3];
        if(a >= b && a >= c) {
            chars[0] = 'a';
            nums[0] = a;
            if(b >= c) {
                chars[1] = 'b';
                nums[1] = b;
                chars[2] = 'c';
                nums[2] = c;
            } else {
                chars[1] = 'c';
                nums[1] = c;
                chars[2] = 'b';
                nums[2] = b;
            }
        } else if (b >= a && b >= c) {
            chars[0] = 'b';
            nums[0] = b;
            if(a >= c) {
                chars[1] = 'a';
                nums[1] = a;
                chars[2] = 'c';
                nums[2] = c;
            } else {
                chars[1] = 'c';
                nums[1] = c;
                chars[2] = 'a';
                nums[2] = a;
            }
        } else {
            chars[0] = 'c';
            nums[0] = c;
            if(a >= b) {
                chars[1] = 'a';
                nums[1] = a;
                chars[2] = 'b';
                nums[2] = b;
            } else {
                chars[1] = 'b';
                nums[1] = b;
                chars[2] = 'a';
                nums[2] = a;
            }
        }

          std::string ans(a+b+c, chars[0]);
        int mid_or_min = 1;
        int i = 2;
        while(i < ans.size() && mid_or_min < 3) {
            if(nums[mid_or_min] == 0) {
                mid_or_min++;
                continue;
            }
            ans[i] = chars[mid_or_min];
            nums[mid_or_min]--;
            i += 3;
        }

        if(mid_or_min <3) {
            int j = 1;
            while(j < ans.size() && mid_or_min < 3) {
                if(nums[mid_or_min] == 0) {
                    mid_or_min++;
                    continue;
                }
                ans[j] = chars[mid_or_min];
                nums[mid_or_min]--;
                j += 3;
            }
        }

        if(i < ans.size())
            return ans.substr(0, i);
        return ans;
    }
};
