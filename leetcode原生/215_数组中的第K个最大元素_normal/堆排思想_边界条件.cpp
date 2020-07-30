class Solution {
public:
    void sink(vector<int>& nums,int left,int right){
        int parent=left;
        int child=left*2+1;
        if(child+1<right&&nums[child]>nums[child+1]) child++;
        if(child<right&&nums[child]<nums[parent]){
            int tmp=nums[parent];
            nums[parent]=nums[child];
            nums[child]=tmp;
            sink(nums,child,right);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=k/2-1;i>=0;i--){
            sink(nums,i,k);
        }
        //for(int x:nums) cout<<x<<endl;
        for(int i=k;i<nums.size();i++){
            if(nums[i]>nums[0]){
                int tmp=nums[0];
                nums[0]=nums[i];
                nums[i]=tmp;
                sink(nums,0,k);
            }
        }
        //for(int x:nums) cout<<x<<endl;
        return nums[0];
    }
};