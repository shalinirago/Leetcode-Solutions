class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        int index = 0;
        
        computePermutations(S, result, index);
        
        return result;
    }
    
    void computePermutations(string s, vector<string>& result, int index){
        
        result.push_back(s);
        
        for (int i = index; i < s.size(); i++){
            if (isalpha(s[i])){
                if (islower(s[i])){
                    s[i] = toupper(s[i]);
                }
                else if (isupper(s[i])){
                    s[i] = tolower(s[i]);
                }
            }
            else{
                continue;
            }
            computePermutations(s, result, i+1);
            if (isalpha(s[i])){
                if (islower(s[i])){
                    s[i] = toupper(s[i]);
                }
                else if (isupper(s[i])){
                    s[i] = tolower(s[i]);
                }
            }
        }
    }
};