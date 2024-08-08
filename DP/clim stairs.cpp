class Solution {
public:
    // int climbStairs(int n) {
    //     //using recursion
    //     // if( n == 0 || n == 1) return 1;
    //     // return climbStairs(n-1) + climbStairs(n-2);
  ////using MEMOIZATION
//     int climbStairs(int n) {
    
//     dp.resize(n + 1, -1);

  
//     return memo(n);
// }

// int memo(int n) {
   
//     if (n == 0 || n == 1) return 1;


//     if (dp[n] != -1) return dp[n];

  
//     dp[n] = memo(n - 1) + memo(n - 2);

//     return dp[n];


//<-------TABULATION

// int climbStairs(int n){
//     if(n == 0 || n == 1) return 1;

//     vector<int> dp(n+1);
//     dp[0] = 1;
//     dp[1] = 1;
//     for(int i = 2; i<= n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n];
// }
    


//<------space optimization

int climbStairs(int n) {
    if(n==1 || n==1) return 1;

    int prev1 = 1;
    int prev2 = 1;

    int curr;

    for(int i = 2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;

}
};