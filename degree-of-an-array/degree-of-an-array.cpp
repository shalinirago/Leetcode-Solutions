class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> counts;
        unordered_map<int,int> left_idx;
        unordered_map<int,int> right_idx;
        
        for (int i = 0; i < nums.size(); i++){
            int x = nums[i];
            
            if (left_idx.find(x) == left_idx.end()){
                left_idx[x] = i;
            }
            right_idx[x] = i;
            counts[x]++;
        }
        int max_count = 0, val = 0, min_len = INT_MAX;
        
        for (auto x: counts){
            if (x.second >= max_count){
                max_count = x.second;
            }
        }
        
        for (auto x: counts){
            if (x.second == max_count){
                val = x.first;
                int len = right_idx[val] - left_idx[val] + 1;
                min_len = min(min_len, len);
            }
        }
        
        return min_len;
    }
};