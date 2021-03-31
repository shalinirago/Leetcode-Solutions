class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        
        for (int i = 1; i <= A.size(); i++){
            for (int j = 1; j <= B.size(); j++){
                if (A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
};


/*
1   4  2
|    /\ --- but 2-2 crosses 4-4  
1  2   4

count = 0

* i, j: 
* if A[i] == B[j]:
*   if i == j 
    count++;
*   

2   5   1   2   5
    |     \     |
10  5   2   1   5   2
count = 3


1   3   7   1   7   5
|             \  
1   9   2   5   1
count = 2


*/