class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int res=0x80000000;
        vector<int>::iterator it=nums.begin();
        while(it!=nums.end()){
            if(sum<0){
                sum=*it;
            }
            else{
                sum+=*it;
            }
            res=max(sum,res);
            it++;
        }
        return res;
    }
};