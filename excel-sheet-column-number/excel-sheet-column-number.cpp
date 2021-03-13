class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int mult = s.size()-1;
        
        for (int i = 0; i < s.size(); i++){
            if (mult > 0){
                res += pow(26, mult)*(s[i]-'A'+1);
                mult--;
            }
            else
                res += (s[i]-'A'+1);                
        }
        
        return res;
    }
};