/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        int tmp=0x7fffffff;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(tmp>abs(nums[i]+nums[j]+nums[k]-target)){
                        tmp=abs(nums[i]+nums[j]+nums[k]-target);
                        res=nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return res;
    }
};