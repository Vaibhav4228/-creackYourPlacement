class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>max_h;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                max_h.push(matrix[i][j]);
                if(max_h.size()>k)
                max_h.pop();
            }
        }
        return max_h.top();
    }
};