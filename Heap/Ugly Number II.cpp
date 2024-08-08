class Solution {
public:

//   bool isUgly(int num){
//      if (num <= 0) return false;
//     while (num % 2 == 0) num /= 2;
//     while (num % 3 == 0) num /= 3;
//     while (num % 5 == 0) num /= 5;
//     return num == 1;
//   }
    int nthUglyNumber(int n) {
//         int count =0;
//         int current= 1;

//         while(count < n){
//             if(isUgly(current)){
//                 count++;
//             }
//             current++;
//         }

//         return current-1;
  priority_queue<long, vector<long>, greater<long>> minHeap;
    unordered_set<long> seen;

    minHeap.push(1);
    seen.insert(1);

    long uglyNumber = 1;

    for (int i = 0; i < n; i++) {
        uglyNumber = minHeap.top();
        minHeap.pop();

        if (i == n - 1) return uglyNumber;

        // Generate next ugly numbers by multiplying with 2, 3, and 5
        if (seen.find(uglyNumber * 2) == seen.end()) {
            minHeap.push(uglyNumber * 2);
            seen.insert(uglyNumber * 2);
        }
        if (seen.find(uglyNumber * 3) == seen.end()) {
            minHeap.push(uglyNumber * 3);
            seen.insert(uglyNumber * 3);
        }
        if (seen.find(uglyNumber * 5) == seen.end()) {
            minHeap.push(uglyNumber * 5);
            seen.insert(uglyNumber * 5);
        }
    }

    return uglyNumber;
        
    }
};