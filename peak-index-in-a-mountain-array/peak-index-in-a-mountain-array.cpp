class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeak(arr, 0, arr.size()-1);
    }   
    
    int findPeak(vector<int>& arr, int left, int right){
        if (left == right)
            return left;
        
        int mid = (left+right)/2;
        if (arr[mid] > arr[mid+1]){
            return findPeak(arr, left, mid);
        }
        
        return findPeak(arr, mid+1, right);
    }
};