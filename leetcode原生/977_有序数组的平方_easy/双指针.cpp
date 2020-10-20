class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right&&nums[left]<0) left++;
        right=left;
        left--;
        vector<int> res;
        while(left>=0&&right<nums.size()){
            if(nums[left]*nums[left]<=nums[right]*nums[right]){
                res.push_back(nums[left]*nums[left]);
                left--;
            }
            else if(nums[left]*nums[left]>nums[right]*nums[right]){
                res.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        while(left>=0){
            res.push_back(nums[left]*nums[left]);
            left--;
        }
        while(right<nums.size()){
            res.push_back(nums[right]*nums[right]);
            right++;
        }
        return res;
    }
};