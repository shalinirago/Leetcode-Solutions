class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left_sum = 0;
        
        for (auto x: nums){
            sum += x;    
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (left_sum == (sum-left_sum-nums[i])){
                return i;
            }
            left_sum += nums[i];
        }
        
        return -1;
    }
};

/*
[1, 7, 3, 6, 5, 6]

two pointers: while (start < end)
1,7,3             5,6
return index 6

[1, 2, 3]

1       3
return -1



*/