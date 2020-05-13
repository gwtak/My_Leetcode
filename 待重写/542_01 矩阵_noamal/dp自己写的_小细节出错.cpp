/*给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int length=matrix.size();
        int width=matrix[0].size();
        vector<vector<int>> dp_1(length,vector<int>(width,0));
        vector<vector<int>> dp_2(length,vector<int>(width,0));
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                int tmp_up=0;
                int tmp_left=0;
                if(matrix[i][j]){
                    if(i-1>=0) tmp_up=dp_1[i-1][j]+1;
                    else tmp_up=10000;
                    if(j-1>=0) tmp_left=dp_1[i][j-1]+1;
                    else tmp_left=10000;
                }
                dp_1[i][j]=min(tmp_up,tmp_left);
                //cout<<dp_1[i][j]<<endl;
            }
        }
        for(int i=length-1;i>=0;i--){
            for(int j=width-1;j>=0;j--){
                int tmp_down=0;
                int tmp_right=0;
                if(matrix[i][j]){
                    if(i+1<length) tmp_down=dp_2[i+1][j]+1;
                    else tmp_down=10000;
                    if(j+1<width) tmp_right=dp_2[i][j+1]+1;
                    else tmp_right=10000;
                }
                dp_2[i][j]=min(tmp_right,tmp_down);
                //cout<<dp_2[i][j]<<endl;
            }
        }
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                dp_1[i][j]=min(dp_1[i][j],dp_2[i][j]);
            }
        }
        return dp_1;
    }
};