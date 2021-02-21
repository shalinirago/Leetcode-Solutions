class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> hash1;
        for (auto x: nums1)
        {
            hash1[x] += 1;
        }
        unordered_map<int, int> hash2;
        for (auto y: nums2)
        {
            hash2[y] += 1;
        }
        
        if (hash1.size() <= hash2.size())
        {
            result = findIntersection(hash1, hash2); 
        }
        else
            result = findIntersection(hash2, hash1);
        
        return result;
    }
    
    vector<int> findIntersection(unordered_map<int,int>& hash1, unordered_map<int,int>& hash2)
    {
        vector<int> result;
        int freq = 0;
        
        for (auto x: hash1)
        {
            if (hash2.find(x.first) != hash2.end())
            {
                freq = hash1[x.first] < hash2[x.first] ? hash1[x.first] : hash2[x.first];
                
                for (int i = 0; i < freq; i++)
                {
                    result.push_back(x.first);
                }
            }
        }
        
        return result;
    }
};