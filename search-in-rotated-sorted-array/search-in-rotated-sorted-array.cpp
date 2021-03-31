class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return (nums[0] == target) ? 0:-1;
        
        int rotate_idx = find_pivot(nums, 0, nums.size()-1);
        
        if (rotate_idx == 0){
            return binarySearch(nums, 0, nums.size()-1, target);
        }
        
        if (nums[rotate_idx] == target){
            return rotate_idx;
        }
        else if (nums[0] > target){
            return binarySearch(nums, rotate_idx, nums.size()-1, target);
        }
                
        return binarySearch(nums, 0, rotate_idx, target);
        
    }
    
    
    int find_pivot(vector<int>& nums, int left, int right){
        if (nums[left] < nums[right]){
            return 0;
        }
        
        while (left <= right){
            int pivot = (left+right) / 2;
            
            if (nums[pivot] > nums[pivot+1]){
                return pivot+1;
            }
            else{
                if (nums[pivot] < nums[left]){
                    right = pivot-1;
                }
                else{
                    left = pivot+1;
                }
            }
        }
        
        return 0;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target){
        
        while (left <= right){
            int mid = (left+right)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
            
        }
        
        return -1;
    }
    
    
};


/*

[3,4,5,6,7,8,9,10,0,1,2] target = 2


* binary search:
*  

*/