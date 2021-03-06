/*给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        for(int i=0;i<rowIndex+1;i++){
            last.clear();
            vector<int> tmp;
            for(int j=0;j<=i;j++){
                if(j==0||j==i) tmp.push_back(1);
                else tmp.push_back(last[j-1]+last[j]);
            }
            last=tmp;
        }
        return last;
    }
};