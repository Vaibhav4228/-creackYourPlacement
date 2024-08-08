// #include <bits/stdc++.h>
// using namespace std;

// class solution {
//   public:
//    int MaximizeTheCuts(int n, int x, int y, int z){
//     if(n == 0) return 0;

//     if(n <0) return -1;

//     int cutx = MaximizeTheCuts(n-x, x, y,z);
//     int cuty = MaximizeTheCuts(n-y, x,y,z);
//     int cutz = MaximizeTheCuts(n-z, x, y,z);

//     int maxii = max(max(cutx,cuty), cutz);

//     if(mMaximizeTheCuts == -1){
//       return -1;
//     }
//     return MaximizeTheCuts+1;
//    }

// };

// int main (){
//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     cin>>x>>y>>z;
//     solution obj;
//     cout<<obj.MaximizeTheCuts(n,x,y,z)<<endl;
//   }
// }

//using memo
// #include <iostream>
// #include <vector>
// #include <algorithm> // For std::max
// using namespace std;

// // Function to find the maximum number of segments using memoization
// int maxSegments(int n, int x, int y, int z, vector<int>& memo) {
//     // Base case: if n is 0, no more segments can be cut
//     if (n == 0) {
//         return 0;
//     }

//     // If n is negative, return a very negative value (invalid case)
//     if (n < 0) {
//         return -1;
//     }

//     // Check if the result is already computed and stored in memo
//     if (memo[n] != -1) {
//         return memo[n];
//     }

//     // Recursively try cutting segments of length x, y, and z
//     int cutX = maxSegments(n - x, x, y, z, memo);
//     int cutY = maxSegments(n - y, x, y, z, memo);
//     int cutZ = maxSegments(n - z, x, y, z, memo);

//     // Take the maximum of the cuts
//     int maxCuts = max(max(cutX, cutY), cutZ);

//     // If no valid cuts were found, store -1 (invalid case)
//     if (maxCuts == -1) {
//         memo[n] = -1;
//     } else {
//         memo[n] = maxCuts + 1;
//     }

//     return memo[n];
// }

// int main() {
//     int n, x, y, z;
//     cout << "Enter the length of the line segment (n): ";
//     cin >> n;
//     cout << "Enter the cut lengths (x, y, z): ";
//     cin >> x >> y >> z;

//     // Initialize memoization table with -1 (indicating uncomputed results)
//     vector<int> memo(n + 1, -1);

//     int result = maxSegments(n, x, y, z, memo);
    
//     if (result == -1) {
//         cout << "No segments can be cut." << endl;
//     } else {
//         cout << "Maximum number of segments: " << result << endl;
//     }

//     return 0;
// }


//using tabulations
#include<bits/stdc++.h>
using namespace std;

int maxSegment(int n, int x, int y, int z){
  vector<int>dp(n+1, -1){
    dp[0] = 0;
    for(int i =0; i<=n; i++){
      if(dp[i] != -1){
        if(i+x <= n) dp[i+x ] = max(dp[x+i], dp[i] + 1);
           if (i + y <= n) dp[i + y] = max(dp[i + y], dp[i] + 1);
            if (i + z <= n) dp[i + z] = max(dp[i + z], dp[i] + 1);
        }
    }

    // The result is stored in dp[n]
    return dp[n];
      
    }
  }



int main(){
  int n, x,y,z;
  cin>>n;
  cin>>x>>y>>z;

  int ans = maxSegment(n,x,y,z);

  cout << ans;

  return 0;
}