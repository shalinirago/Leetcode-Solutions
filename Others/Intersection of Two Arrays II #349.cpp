class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> freq1;
        for (auto x: nums1)
        {
            freq1[x] += 1;
        }
        
        for (int i = 0; i < nums2.size(); i++)
        {
            if (freq1.find(nums2[i]) != freq1.end() && find(result.begin(), result.end(), nums2[i]) == result.end())
                result.push_back(nums2[i]);
        }
        
        return result;
        
    }
};