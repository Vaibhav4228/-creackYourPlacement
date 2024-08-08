class Solution {
public:
//   int ans(int m, int n,  vector<vector<int>> &dp){
//       if (m == 1 || n == 1) {
//         return 1;
//     }
//     if( dp[m][n] != -1) return dp[m][n];

//     dp[m][n] = ans(m - 1, n, dp) + ans(m, n - 1, dp);

//     return dp[m][n];
//   }
    int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         return ans(m,n, dp);

        //using tabulation itrative apporch
       vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) { 
            for (int j = 1; j < n; ++j) { 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            }
        }

        return dp[m-1][n-1];

      
        
    }
};