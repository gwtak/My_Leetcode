class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size()-k+1,0);
        for(int i=0;i<=nums.size()-k;i++){
            if(i==0||res[i-1]<i||nums[i+k-1]>nums[res[i-1]]){
                int tmp=INT_MIN;
                for(int j=i;j<i+k;j++){
                    if(nums[j]>=tmp){
                        tmp=nums[j];
                        res[i]=j;
                    }
                }
            }
            else{
                res[i]=res[i-1];
            }
        }
        for(int i=0;i<res.size();i++){
            res[i]=nums[res[i]];
            //cout<<res[i]<<endl;
        }
        return res;
    }
};