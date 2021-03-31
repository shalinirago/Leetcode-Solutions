class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int count = 1, max_count = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]){
                count++;
            }
            else{
                if (count > max_count){
                max_count = count;
                }
                count = 1;
            }
        }
        
        return max(max_count, count);
    }
};