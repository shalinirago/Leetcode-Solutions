class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        if (s.empty())
            return result;
        
        int start = 0, end = 0, max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int max_len = max(len1, len2);
            
            if (max_len > end-start)
            {
                start = i - (max_len-1)/2;
                end = i + (max_len)/2;
            }
        }
        
        result = s.substr(start, end-start+1);
        return result;
        
            
    }
    
    int expand(string s, int left, int right){
        if (s.empty() || left < 0 || right >= s.size())
        {
            return 0;
        }
        
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};