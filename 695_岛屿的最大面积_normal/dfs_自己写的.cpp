/*给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j){
        int count=0;
        if(grid[i][j]==0) return 0;
        grid[i][j]=0;
        if(i+1<grid.size()&&grid[i+1][j]) count=helper(grid,i+1,j);
        if(i>0&&grid[i-1][j]) count+=helper(grid,i-1,j);
        if(j+1<grid[0].size()&&grid[i][j+1]) count+=helper(grid,i,j+1);
        if(j>0&&grid[i][j-1]) count+=helper(grid,i,j-1);
        return count+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int length=grid.size();
        int width=grid[0].size();
        int res=0;
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                res=max(helper(grid,i,j),res);
            }
        }
        return res;
    }
};