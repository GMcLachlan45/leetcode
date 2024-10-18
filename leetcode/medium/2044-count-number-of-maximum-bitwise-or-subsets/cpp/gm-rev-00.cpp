// Runtime: 60ms
// Memory: 20.1MB
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int total = 0;
        int largest = 0;
        int subset_size = 1;
        std::unordered_map<int,int> subsets;
        for(int num: nums) {
            subsets[num]++;
            largest |= num;
        }


        if(subsets[largest] == nums.size())
            total += subsets[largest];
        else // if largest = 2^x -1, then we need to add for some reason
            for(int pow_of_2 = 2; pow_of_2-1 <= largest; pow_of_2 <<= 1)
                if(pow_of_2 - 1 == largest)
                    total += subsets[largest];

        while(subset_size <= nums.size()) {
            std::unordered_map<int,int> next_subsets;
            for(int num : nums)
                for(std::pair<int,int> subset : subsets)
                    next_subsets[num | subset.first] += subset.second;

            for(std::pair<int,int> subset : subsets)
                next_subsets[subset.first] -= subset.second*subset_size;

            subset_size++;
            // divide how many times we multicounted
            auto it = next_subsets.begin();
            while (it != next_subsets.end()) {
                it->second /= subset_size;
                it++;
            }

            subsets = next_subsets;
            // add the number ef subsets with largest
            total += next_subsets[largest];
        }
        return total;
    }
};
