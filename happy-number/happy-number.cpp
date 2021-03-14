class Solution {
public:
    unordered_map<int, int> hash;
    
    bool isHappy(int n) {        
        if (n == 1)
            return true;
        int sum = 0;
        
        while (n > 0){
            sum += pow(n%10, 2);
            n = n/10;
        }
        n = sum;
        
        if (hash[n])
            return false;
        else
            hash[n] = 1;
        
        return isHappy(n);
    }
    

};