class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mapt;
        
        for (auto x: t){
            mapt[x]++;
        }
        
        int count = 0;
        
        for (int i = 0; i < s.size(); i++){
            if (mapt.find(s[i]) == mapt.end() || mapt[s[i]] == 0){
                count++;                
            }
            else{
                mapt[s[i]]--;
            }
        }
        
        return count;
    }
};