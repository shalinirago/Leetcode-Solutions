class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(nums);
        
        for (int i = 0; i < result.size(); i++)
        {
            swap (result[i], result[getRand(i)]);
        }
        
        return result;
        
    }
    
    int getRand(int i)
    {
        return rand()%(i+1);
    }
    
private:
    vector<int> nums;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */