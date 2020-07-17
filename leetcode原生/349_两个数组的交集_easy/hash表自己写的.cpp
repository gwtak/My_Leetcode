/*给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int hash1[1000]={0};
        int hash2[1000]={0};
        vector<int> res;
        if(nums1.empty()||nums2.empty()) return res;
        for(int i=0;i<=nums1.size()-1;i++){
            hash1[nums1[i]]++;
        }
        for(int i=0;i<=nums2.size()-1;i++){
            hash2[nums2[i]]++;
        }
        for(int i=0;i<=999;i++){
            if(hash1[i]>0&&hash2[i]>0) res.push_back(i); 
        }
        return res;
    }
};