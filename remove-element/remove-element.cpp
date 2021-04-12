class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
};


/*
nums = [0,1,2,2,3,0,4,2] val = 2
            | | |  
            3 0 4

0,1,4,2,3,0,2,2
0,1,4,0,3,2,2,2


*/