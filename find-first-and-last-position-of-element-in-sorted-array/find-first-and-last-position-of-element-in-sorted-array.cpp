class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result (2, -1);
        if (nums.empty()){
            return result;
        }
        
        int left = 0, right = nums.size()-1;
        
        while (left <= right){
            int mid = left + (right - left)/2;
            
            if (nums[mid] == target){
                right = mid-1;
                result[0] = mid;                
            }
            
            else if (nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        left = 0, right = nums.size()-1;
        
        while (left <= right){
            int mid = left + (right - left)/2;
            
            if (nums[mid] == target){
                left = mid+1;
                result[1] = mid;                
            }
            
            else if (nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        return result;       
        
    }
};

/*
nums = [5, 7, 7, 8, 8, 8, 8, 8, 10] target = 8

mid = left+ (right-left/2) = 4, nums[mid] = 8







*/