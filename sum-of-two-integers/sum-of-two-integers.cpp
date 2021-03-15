class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a), y = abs(b);
        
        if (x < y)
            return getSum(b, a);
        
        int sign = a > 0 ? 1:-1;
        
        if (a * b >= 0){
        while (y != 0){
            int carry = (x & y);
            x = x^y;
            y = carry << 1;
        }
        }
        
        else{
        while (y != 0){
            int carry = ((~x) & y);
            x = x^y;
            y = carry << 1;
        }
            
        }
        
        return x*sign;
    }
};