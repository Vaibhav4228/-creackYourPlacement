class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeros, ones, twos;
        zeros = ones = twos = 0;
        int i = 0;
        while(zeros--){
            nums[i]= 0;
            i++;
        }
        while(ones--){
            nums[i] = 1;
            i++;
        }
        while(twos--){
            nums[i] = 2;
            i++;
        }
       
    }
};

