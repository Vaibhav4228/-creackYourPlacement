// Got TLE in this code 
// class Solution {
// public:
//     int knightDialer(int n) {
//         vector<std::vector<int>> adj = {
//             {4, 6},
//             {6, 8},
//             {7, 9},
//             {4, 8},
//             {3, 9, 0},
//             {},
//             {1, 7, 0},
//             {2, 6},
//             {1, 3},
//             {2, 4}
//         };
//         int result = 0;
//         for (int cell = 0; cell <= 9; cell++) {
//             result = (result + solve(n - 1, cell, adj)) % MOD;
//         }
//         return result;
//     }

// private:
//     const int MOD = 1e9 + 7;

//     int solve(int n, int cell, const vector<vector<int>>& adj) {
//         if (n == 0) return 1;
//         int ans = 0;
//         for (int nextCell : adj[cell]) {
//             ans = (ans + solve(n - 1, nextCell, adj)) % MOD;
//         }
//         return ans;
//     }
// };

//MEMO APPROCH 
class Solution {
public:
    
    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int t[5001][10];
    
    int solve(int n, int cell) {
        if(n == 0) {
            return 1;
        }
        
        if(t[n][cell] != -1) {
            return t[n][cell];
        }
        
        int result = 0;
        
        for(int &nextCell : adj[cell]) {
            result = (result + solve(n-1, nextCell)) % M; 
        }
        
        return t[n][cell] = result;
    }
    
    int knightDialer(int n) {
        int result = 0;
        memset(t, -1, sizeof(t));
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + solve(n-1, cell)) % M;
        }
        
        return result;
    }
};

//BOTTOM APPROCH
// class Solution {
// public:
    
//     int M = 1e9+7;
//     vector<vector<int>> adj = {
//         {4, 6},
//         {6, 8},
//         {7, 9},
//         {4, 8},
//         {3, 9, 0},
//         {},
//         {1, 7, 0},
//         {2, 6},
//         {1, 3},
//         {2, 4}
//     };
    
//     int knightDialer(int n) {
//         int result = 0;
        
//         //t[i][j] = number of ways to form a number of length i when I am currently at cell j
        
//         vector<vector<int>> t(n, vector<int>(10));
//         for(int cell = 0; cell < 10; cell++) {
//             t[0][cell] = 1; //for n == 0, we always returned 1
//         }
        
//         for(int i = 1; i < n; i++) { //This is length of number 
            
//             for(int cell = 0; cell <= 9; cell++) {    
//                 int ans = 0;
//                 for(int &nextCell : adj[cell]) {
                    
//                     ans = (ans + t[i-1][nextCell]) % M;
                    
//                 }
//                 t[i][cell] = ans;
                
//             }
            
//         }
        
        
//         for(int cell = 0; cell <= 9; cell++) {
//             result = (result + t[n-1][cell]) % M;
//         }
        
//         return result;
//     }
// };