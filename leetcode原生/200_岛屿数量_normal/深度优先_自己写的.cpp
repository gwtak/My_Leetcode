/*给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。*/


/***********************************************************
注意：给的参数是vector<vector<char>>,是char不是int
************************************************************/
class Solution {
public:
    void helper(vector<vector<char>>& grid,int i,int j){
        int length=grid.size();
        int width=grid[0].size();
        if((i>=0)&&(i<length)&&(j>=0)&&(j<width)&&(grid[i][j]=='1')){
            grid[i][j]=0;
            helper(grid,i-1,j);
            helper(grid,i+1,j);
            helper(grid,i,j-1);
            helper(grid,i,j+1);
        }
        else{
            return;
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int length=grid.size();
        int width=grid[0].size();
        int count=0;
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]=='1'){
                    helper(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};