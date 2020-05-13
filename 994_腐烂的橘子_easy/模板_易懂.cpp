class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int row = grid.size();
        int colum = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;
        int time = 0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<colum;j++) {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        if (count == 0)
            return 0;
        while (!q.empty()) {
            time++;
            for (int j=q.size();j>0;j--) {
                auto cur = q.front();
                q.pop();
                for (int k=0;k<4;k++) {
                    int x = cur.first + dirs[k][0];
                    int y = cur.second + dirs[k][1];
                    if (x<0 || x>row-1 || y<0 || y>colum-1 || grid[x][y] == 0)
                        continue;
                    if (grid[x][y] == 1) {
                        count--;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
                if (count == 0)
                    return time;
            }
        }
        return -1;
    }
};