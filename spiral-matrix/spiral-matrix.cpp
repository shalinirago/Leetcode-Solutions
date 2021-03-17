class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<bool>> visited(matrix.size(), vector<bool> (matrix[0].size(), false));
        
        if (matrix.empty())
            return result;
        
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        
        int row = 0, col = 0, dir = 0;
        
        for (int i = 0; i < matrix.size()*matrix[0].size(); i++){
            result.push_back(matrix[row][col]);
            visited[row][col] = true;
            
            int r = row+dr[dir];
            int c = col+dc[dir];
            
            if (r >= 0 && c >= 0 && r < matrix.size() && c < matrix[0].size() && !visited[r][c]){
                row = r;
                col = c;
            }
            else{
                dir = (dir+1)%4;
                row += dr[dir];
                col += dc[dir];
            }
        }
       return result; 
    }
};
