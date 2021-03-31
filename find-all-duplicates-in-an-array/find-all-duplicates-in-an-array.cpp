class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};

/*
* sort array
* if (nums[i] == nums[i+1])
    append to result

[1, 2, 2, 3, 3, 4, 7, 8]


*/