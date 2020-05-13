class Solution {
public:
    int findpos(vector<int>& nums,int low,int high){
        int val=nums[low];
        while(low<high){
            while(low<high&&nums[high]>=val){
                high--;
            }
            nums[low]=nums[high];
            while(low<high&&nums[low]<=val){
                low++;
            }
            nums[high]=nums[low];
        }
        nums[low]=val;
        return low;
    }
    
    void quicksort(vector<int>& nums,int low,int high){
        int pos;
        if(low<high){
            pos=findpos(nums,low,high);
            quicksort(nums,low,pos-1);
            quicksort(nums,pos+1,high);
        }
    }
    
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2) return false;
        quicksort(nums,0,nums.size()-1);
        for(int i=0;i<=nums.size()-2;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};