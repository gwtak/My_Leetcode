class Solution {
public:
    void quick_sort(vector<int>& nums,int left,int right,int k){
        if(left>=right) return;//重点：不要忘，不然栈溢出
        int low=left;
        int high=right;
        int val=nums[low];
        while(low<high){
            while(low<high&&nums[high]<=val) high--;//重点：“<=”，从high开始
            nums[low]=nums[high];
            while(low<high&&nums[low]>=val) low++;
            nums[high]=nums[low];
        }
        nums[low]=val;
        if(low==k-1) return;
        quick_sort(nums,left,low-1,k);
        quick_sort(nums,low+1,right,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums,0,nums.size()-1,k);
        return nums[k-1];
    }
};