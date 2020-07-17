/*给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long absa=abs((long)dividend);
        long absb=abs((long)divisor);
        long tmp=absb;
        long i=0;
        while(absa>=absb){
            i++;
            absb+=tmp;
        }
        if(i>0x7fffffff) return 0x7fffffff;
        if(!((dividend&0x80000000)^(divisor&0x80000000))) return i;
        else return -i;
    }
};