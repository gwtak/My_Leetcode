/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findpos(int* arr,int low,int high){
    int val=arr[low];
    while(low<high){
        while(low<high&&val<=arr[high]){
            high--;
        }
        arr[low]=arr[high];
        while(low<high&&arr[low]<=val){
            low++;
        }
        arr[high]=arr[low];
    }
    arr[low]=val;
    return low;
}
void quicksort(int* arr,int low,int high){
    int pos=0;
    if(low<high){
        pos=findpos(arr,low,high);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }  
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    quicksort(nums,0,numsSize-1);
    return nums;
}