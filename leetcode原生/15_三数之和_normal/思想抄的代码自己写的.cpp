/*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());//使用库来排序，有空重写
        if((nums[0]>0||nums[nums.size()-1]<0)) return res;
        int i=0;
        while(i<=nums.size()-3){
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]==0){
                    res.push_back({nums[i],nums[low],nums[high]});
                    int lowtmp=low;
                    int hightmp=high;
                    while(low<high&&nums[low]==nums[lowtmp]) low++;//跳过重复的数字
                    while(low<high&&nums[high]==nums[hightmp]) high--;
                }
                else if(nums[i]+nums[low]+nums[high]>0) high--;
                else if(nums[i]+nums[low]+nums[high]<0) low++;
            }
            int itmp=i;
            while(i<=nums.size()-3&&nums[i]==nums[itmp]) i++;//跳过重复的数字
        }
        return res;
    }
};