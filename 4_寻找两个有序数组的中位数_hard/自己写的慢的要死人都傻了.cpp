/*给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        if(!nums1.empty()){
            for(int i=0;i<=nums1.size()-1;i++){
                tmp.push_back(nums1[i]);
            }
        }
        if(!nums2.empty()){
           for(int i=0;i<=nums2.size()-1;i++){
                tmp.push_back(nums2[i]);
            } 
        }
        for(int i=0;i<=tmp.size()-1;i++){
            for(int j=i+1;j<=tmp.size()-1;j++){
                if(tmp[i]>tmp[j]){
                    tmp[i]=tmp[i]^tmp[j];
                    tmp[j]=tmp[i]^tmp[j];
                    tmp[i]=tmp[i]^tmp[j];
                }
            }
        }
        if(tmp.size()%2) return (double)tmp[tmp.size()/2];
        else return (double)((tmp[tmp.size()/2]+tmp[tmp.size()/2-1])/2.0);
    }
};