class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> vec;
        int index = 0;
        
        computePartition(s, result, vec, 0);
        
        return result;
    }
    
    void computePartition(string s, vector<vector<string>>& result, vector<string>& vec, int start){
        
        if (start >= s.size())
        {
            result.push_back(vec);
            
        }
        
        for (int end = start; end < s.size(); end++){
            if(checkPalindrome(s, start, end)){
                vec.push_back(s.substr(start, end-start+1));
                computePartition(s, result, vec, end+1);
                vec.pop_back();            
            }
        }
    }
    
    bool checkPalindrome(string s, int start, int end){
        while (start < end){
            if (s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};