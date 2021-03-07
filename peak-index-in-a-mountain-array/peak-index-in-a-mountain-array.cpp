class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peak = INT_MIN;
        int peak_idx = 0;
        
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > peak){
                peak = arr[i];
                peak_idx = i;
            }
        }
        
        return peak_idx;
    }
};