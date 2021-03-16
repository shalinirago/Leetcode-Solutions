class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++){
            vector<int> ref = result.back();
            if (ref[1] >= intervals[i][0]){
                if (ref[1] < intervals[i][1]){
                    ref[1] = intervals[i][1];
                    result.pop_back();
                }
                else{
                    continue;
                }
            }
            else{
                ref = intervals[i];
            }
            result.push_back(ref);
        }
        return result;
    }
};