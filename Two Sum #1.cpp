class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            num = target - nums[i];
            
            if(hash.find(num) != hash.end())
            {
                result.push_back(hash[num]);
                result.push_back(i);
            }
            
            hash[nums[i]] = i;
        }
        
        return result;
    }
};