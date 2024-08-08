class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long mini = nums[0];
        long long maxi = nums[0];
        long long ans = nums[0];

        for(int i = 1; i < n; i++) { //here we swap bcs if we multipky 2 -ve no. we get positive and we multiply +ve and -ve we get the -ve, so here mini is -ve number so they can affect our +ve value and thats why we swap so mini becomes maxi
            if(nums[i] < 0) {
                swap(maxi, mini); 
            }
            maxi = max(maxi * nums[i], (long long)nums[i]); 
            mini = min(mini * nums[i], (long long)nums[i]); 
            ans = max(ans, maxi);
        }
        return ans;
    }
};
