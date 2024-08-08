class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }

        return -1; 
    }
};

  //2 using count
//    int cnt[len + 1] = {0}; // Initialize the array with zeros
// for (int i = 0; i < len; i++) {
//     cnt[nums[i]]++;
//     if (cnt[nums[i]] > 1) {
//         return nums[i];
//     }
// }

// return len;