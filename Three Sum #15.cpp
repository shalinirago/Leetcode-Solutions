class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            
            left = i+1; right = nums.size()-1;
            
            while (left < right)
            {
                if (nums[i]+nums[left]+nums[right] == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    
                    while(left < right && nums[left-1] == nums[left]) left++;
                    while(left < right && nums[right+1] == nums[right]) right--;
                 }
                else if (nums[i]+nums[left]+nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
                
            }
            
        }
        return result;
        
    }
};