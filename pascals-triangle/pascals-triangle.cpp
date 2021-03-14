class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;
        
        if (numRows != 0)
            result.push_back({1});
        
        for (int i = 1; i < numRows; i++){
            vector<int> vec(result[i-1].size()+1, 0);
            vec[0] = 1;
            vec[vec.size()-1] = 1;
            
            for (int j = 1; j <= vec.size()-2; j++){
                vec[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(vec);
        }
        
        return result;
   }
};