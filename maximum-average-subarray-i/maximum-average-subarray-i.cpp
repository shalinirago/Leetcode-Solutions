class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0, end = 0;
        double sum = 0; 
        double max_avg = INT_MIN;
        
        while (end < nums.size()){
            sum += nums[end];
            if (end-start+1 == k){
                double avg = static_cast<double>(sum/k);
                if (avg > max_avg){
                    max_avg = avg;
                }
                sum = sum-nums[start];
                start++;                
            }            
            end++;
        }
                
        return max_avg;
    }
};