void turn(int* nums,int start,int end){//反转6666
        while(start<end){
            int mid=nums[start];
            nums[start++]=nums[end];
            nums[end--]=mid;
        }
}
void rotate(int* nums, int numsSize, int k){
     k%=numsSize;
    turn(nums,0,numsSize-1);
    turn(nums,0,k-1);
    turn(nums,k,numsSize-1);
    
    return nums;
}

/*
例子[1,2,3,4,5,6,7]  k=3
[7,6,5,4,3,2,1]
[5,6,7,4,3,2,1]
[5,6,7,1,2,3,4]