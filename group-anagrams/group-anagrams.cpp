class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, list<string>> hash;
        vector<vector<string>> result;
        
        if (strs.empty())
            return result;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].push_back(strs[i]);
        }
        
        for (auto x:hash)
        {
            vector<string> vec;
            list<string>::iterator it;
            for (it = x.second.begin(); it != x.second.end(); it++)
            {
                vec.push_back(*it);
            }
            
            result.push_back(vec);
        }
        
        return result;
        
    }
};