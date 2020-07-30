/*有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int res=INT_MIN;
    void tracer(vector<int> nums,int sum){
        if(nums.empty()) res=max(res,sum);
        for(int i=0;i<nums.size();i++){
            int tmp_sum=sum;
            int tmp=1;
            if(i-1>=0) tmp*=nums[i-1];
            if(i+1<nums.size()) tmp*=nums[i+1];
            tmp*=nums[i];
            sum+=tmp;
            vector<int> tmp_nums=nums;
            nums.erase(nums.begin()+i);
            tracer(nums,sum);
            nums=tmp_nums;
            sum=tmp_sum;
        }
    }
    int maxCoins(vector<int>& nums) {
        tracer(nums,0);
        return res;
    }
};