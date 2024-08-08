class Solution {
public:
//solve using stack
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        //  stack<int> st;
        // int n = nums.size();
        
        // for (int i = 0; i < n; ++i) {
        //  
        //     while (!st.empty() && st.top() > nums[i] && (st.size() - 1 + (n - i) >= k)) {
        //         st.pop();
        //     }
           
        //     if (st.size() < k) {
        //         st.push(nums[i]);
        //     }
        // }
       
        // vector<int> ans;
        // while (!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
   
        // reverse(ans.begin(), ans.end());
        
        // return ans;

      

     
  int n = nums.size();
    

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
 
    vector<int> ans;
    int curr = -1;
    
  
    for (int i = 0; i < n; ++i) {
  
        pq.push({nums[i], i});
        while (!pq.empty() && pq.top()[1] <= curr) {
            pq.pop();
        }
        
        if (ans.size() < k) {
            ans.push_back(pq.top()[0]);
            curr = pq.top()[1];
            pq.pop();
        }
    }
    
    return ans;

        
    }
};