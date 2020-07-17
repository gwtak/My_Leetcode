/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int flag=1;
    *returnSize=digitsSize;
    int t=digitsSize;
    while(flag!=0){
        flag=0;
        if(digitsSize>0){//防止溢出
            if(++digits[digitsSize-1]>9) flag=1,digits[digitsSize-1]%=10,digitsSize--;
        }
        if(digitsSize==0){//最前面一位进位
            int *p=(int*)malloc(sizeof(int)*(t+1));
            p[0]=1;
            (*returnSize)++;
            for(int i=1;i<=t;i++){
                p[i]=0;
            }
            return p;
        }
    }
    return digits;
}