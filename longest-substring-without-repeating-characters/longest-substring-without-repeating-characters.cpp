class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> window;
        int start = 0, end = 0;

        while (end < s.size()){
            char ch = s[end];
            if (window.find(ch) == window.end()){           //abca; end =3, start = 0; start = 1; wind = bca
                window.insert(ch);
                end++;
            }
            else{                
                window.erase(s[start]);
                start++;
            }
            max_length = max(max_length, end-start);
        }
        
        return max_length;
    }  
};