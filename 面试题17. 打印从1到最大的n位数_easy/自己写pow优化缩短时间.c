/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int size=1;
    for(int i=1;i<=n;i++){//自己写pow函数可以缩短运行时间
        size*=10;
    }
    size--;
    *returnSize=size;
    int* res=(int*)malloc(sizeof(int)*size);
    int i=1;
    while(i<=size){
        res[i-1]=i;
        res[size-1]=size;
        i++;
        size--;
    }
    return res;
}