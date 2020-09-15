/*给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int count=1;
        int row=0;
        int col=0;
        while(count<=n*n){
            while(row>=0&&row<n&&col>=0&&col<n&&(!res[row][col])){
                res[row][col]=count;
                col++;
                count++;
            }
            col--;
            row++;
            while(row>=0&&row<n&&col>=0&&col<n&&(!res[row][col])){
                res[row][col]=count;
                row++;
                count++;
            }
            row--;
            col--;
            while(row>=0&&row<n&&col>=0&&col<n&&(!res[row][col])){
                res[row][col]=count;
                col--;
                count++;
            }
            col++;
            row--;
            while(row>=0&&row<n&&col>=0&&col<n&&(!res[row][col])){
                res[row][col]=count;
                row--;
                count++;
            }
            row++;
            col++;
        }
        return res;
    }
};