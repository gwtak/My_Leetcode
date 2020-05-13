class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    qu.push(pair<int, int>(i, j));
                }
            }
        }
        int n = grid.size();
        // 全是陆地或全是海洋，则返回-1
        if (qu.size() == n * n || qu.size() == 0) {
            return -1;
        }

        int step = 0;
        //cout<<"qsize = "<<qu.size()<<endl;

        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> pos = qu.front();
                qu.pop();
                int x = pos.first;
                int y = pos.second;
                //cout<<x<<" "<<y<<endl;

                // 上边
                if (y - 1 >= 0 && grid[x][y - 1] == 0) {
                    qu.push(pair<int, int>(x, y-1));
                    grid[x][y-1] = 1;
                }
                
                // 右边
                if (x + 1 < n && grid[x + 1][y] == 0) {
                    qu.push(pair<int, int>(x + 1, y));
                    grid[x+1][y] = 1;
                }

                // 下边
                if (y + 1 < n && grid[x][y + 1] == 0) {
                    qu.push(pair<int, int>(x, y + 1));
                    grid[x][y + 1] = 1;
                }

                // 左边
                if (x - 1 >= 0 && grid[x - 1][y] == 0) {
                    qu.push(pair<int, int>(x - 1, y));
                    grid[x - 1][y] = 1;
                }
            }
            step++;
            //cout<<"------"<<step<<"--------"<<endl;
        }

        return step - 1;

    }
};