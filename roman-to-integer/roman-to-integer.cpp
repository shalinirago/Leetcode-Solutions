class Solution {
public:
    int convertToInt(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
                                
        }
            
        return 0;
    }

    int romanToInt(string s){
        int prev = convertToInt(s[s.size()-1]), curr = 0;
        int res = prev;
        
        for (int i = s.size()-2; i>= 0; i--){
            char ch = s[i];
            curr = convertToInt(ch);
            
            if (curr < prev){
                res -= curr;
            }
            else{
                res += curr;
            }
            
            prev = curr;
        }
        
        return res;
    }
        

};