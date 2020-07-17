int subarraySum(int* nums, int numsSize, int k){
    int res=0;
    for(int i=0;i<numsSize;i++){
        int sum=0;
        for(int j=i;j<numsSize;j++){
            sum+=nums[j];
            if(sum==k) res++;
        }
    }
    return res;
}