class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_idx = nums.size()-1;
        for (int i = nums.size()-2; i >= 0; i--){
            if (i+nums[i] >= last_idx){
               last_idx = i;
            }
        }
        
        return last_idx == 0 ? true : false ;
    }
};