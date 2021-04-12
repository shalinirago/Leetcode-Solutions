class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int i = 1, count = 1, j = 0;
        
        for (int j = 1; j < nums.size(); j++){
            if (nums[j-1] != nums[j]){
                nums[i] = nums[j];
                i++;
                count = 1;
            }
            else{
                count++;
                if (count <= 2){
                    nums[i] = nums[j];
                    i++;
                }
            }
        }
        
        return i;
    }
};


/*
nums = [0,0,1,1,1,1,2,3,3] freq = 2

count = 1
i = 1,j=2


*/