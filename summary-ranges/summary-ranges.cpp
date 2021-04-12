class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if (nums.empty()){
            return result;
        }
        string out = "";
            
        for (int i = 0; i < nums.size(); i++){
            if (i == 0){
                out = to_string(nums[i]);
                continue;
            }
            
            if (nums[i-1]+1 < nums[i]){
                if (nums[i-1] != stoi(out))
                    out += "->" + to_string(nums[i-1]);
                
                result.push_back(out);
                
                out = to_string(nums[i]);
            }
            
            else if (nums[i]-nums[i-1] == 1){
                if (i == nums.size()-1){
                    out += "->" + to_string(nums[i]);
                }
                else
                    continue;
            }            
        }
        
        result.push_back(out);
        
        return result;
    }
};