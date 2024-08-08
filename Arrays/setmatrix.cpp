// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
        
//          int temp = 1;
//          for(int i = 1; i<nums.size(); i++){
//              if(nums[i] != nums[i-1]){
                 
//                  nums[temp] = nums[i];
//                  temp++;
//              }
//          }

//         return temp;
//     }
// };

// USING STL
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         auto it = unique(nums.begin(), nums.end());
//         nums.erase(it, nums.end());
        
//         return nums.size();
//     }
// };

// using two pointer
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
        
//         if (n <= 1) {
//             return n;
//         }

//         int k = 1;  // Position to insert the next unique element

//         for (int i = 1; i < n; ++i) {
//             // Two-pointer approach to check if the current element is different from the previous one
//             if (nums[i] != nums[k - 1]) {
//                 nums[k++] = nums[i];  // Insert the unique element at position k
//             }
//         }

//         return k;
//     }
// };
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> uniqueSet;
        int n = nums.size();
        int k = 0;  // Position to insert the next unique element

        for (int i = 0; i < n; ++i) {
            // Check if the current element is not present in the hash set
            if (uniqueSet.find(nums[i]) == uniqueSet.end()) {
                uniqueSet.insert(nums[i]);  // Insert the element into the hash set
                nums[k++] = nums[i];  // Insert the unique element at position k
            }
        }

        return k;
    }
};
