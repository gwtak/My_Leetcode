/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


int reverse(int x){
    int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
    long rs = 0;//用long类型判断溢出
    for(;x;rs = rs*10+x%10,x/=10);//逆序，正负通吃，不用单独考虑负值
    return rs>max||rs<min?0:rs;//超了最大值低于最小值就返回0
}