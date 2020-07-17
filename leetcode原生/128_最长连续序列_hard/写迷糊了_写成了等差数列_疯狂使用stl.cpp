/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nums_set=set<int>(nums.begin(),nums.end());
        nums.assign(nums_set.begin(),nums_set.end());
        sort(nums.begin(),nums.end());
        if(nums.size()<=2) return nums.size();
        int res=0;
        int length=2;
        int tmp=0;
        for(int i=0,j=1;j<nums.size();i++,j++){
            if(tmp==nums[j]-nums[i]) length++;
            else{
                length=2;
                tmp=nums[j]-nums[i];
            }
            res=max(length,res);
            cout<<"nums[j]="<<nums[j]<<endl;
            cout<<"tmp="<<tmp<<endl;
            cout<<"length="<<length<<endl;
        }
        return res;
    }
};