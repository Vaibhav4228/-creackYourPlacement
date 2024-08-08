class Solution {
public:
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Function to check if a cell is within bounds
bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

   
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
    vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Starting point (0,0) with elevation as the initial time
    pq.push({grid[0][0], {0, 0}});
    minTime[0][0] = grid[0][0];

    while (!pq.empty()) {
        int t = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == n - 1) {
            return t; // Reached the bottom-right corner
        }

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isValid(nx, ny, n)) {
                int newTime = max(t, grid[nx][ny]);
                if (newTime < minTime[nx][ny]) {
                    minTime[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }
    }

    return -1;
        
    }
};