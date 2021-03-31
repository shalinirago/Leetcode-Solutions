class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        if (nums.empty()){
            return result;
        }
        
        
        int firstIdx = binarySearch(nums, target, true);
        if (firstIdx == nums.size() || nums[firstIdx] != target)
            return result;
        
        int secondIdx = binarySearch(nums, target, false);
        
        result[0] = firstIdx;
        result[1] = secondIdx-1;
        
        return result;
    }
    
    int binarySearch(vector<int>& nums, int target, bool left_side){
        int left = 0, right = nums.size();
        
        while (left < right){
            int mid = (left+right)/2;
            if (((nums[mid] == target) && left_side) || (nums[mid] > target)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        
        return left;
    }
};

/*
nums = [5, 7, 7, 8, 8, 8, 8, 8, 10] target = 8

mid = left+ (right-left/2) = 4, nums[mid] = 8







*/