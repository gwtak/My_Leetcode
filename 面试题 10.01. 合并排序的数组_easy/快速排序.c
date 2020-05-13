int findpos(int* nums,int low,int high){
    int val=nums[low];
    while(low<high){
        while(low<high&&nums[high]>=val) high--;
        nums[low]=nums[high];
        while(low<high&&nums[low]<=val) low++;
        nums[high]=nums[low];
    }
    nums[low]=val;
    return low;
}

void quicksort(int* nums,int low,int high){
    int pos;
    if(low<high){
        pos=findpos(nums,low,high);//重点：若将此行写在if之前，会造成下标越界
        quicksort(nums,low,pos-1);
        quicksort(nums,pos+1,high);
    }
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for(int i=0;i<=n-1;i++){
        A[i+m]=B[i];
    }
    quicksort(A,0,ASize-1);
}