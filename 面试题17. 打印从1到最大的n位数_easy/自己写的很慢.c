/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    *returnSize=pow(10,n)-1;
    int size=*returnSize;
    int* res=(int*)malloc(sizeof(int)*size);
    int i=1;
    while(i<=size){
        res[i-1]=i;
        i++;
    }
    return res;
}