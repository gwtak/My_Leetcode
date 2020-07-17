class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0x80000000 && divisor == -1) return 0x7fffffff;//如果是-2^31/-1,返回2^31-1，排除特殊情况
        int sign = 1;//标志结果是负号还是正号
        if ((dividend >0 && divisor <0) || (dividend <0 && divisor >0)) sign = -1;//确定结果是否有符号

        long dividend_l = dividend;
        long divisor_l = divisor;
/************************全都变为正数计算******************************/
        if (dividend_l <0) dividend_l = - dividend_l;
        if (divisor_l <0) divisor_l = - divisor_l;

        long curr_max_divisor = divisor_l;
        long curr_res = 1;
        long result = 0;
/*************************二分法*************************************/
		//指数增长
        while (curr_max_divisor + curr_max_divisor <= dividend_l) {
            curr_max_divisor += curr_max_divisor;
            curr_res += curr_res;
        }

        while(dividend_l >= divisor_l) {
            while(dividend_l < curr_max_divisor) {
                curr_max_divisor = curr_max_divisor >> 1;
                curr_res = curr_res >>1;
            }
            dividend_l -= curr_max_divisor;
            result += curr_res;
        }
        if (sign==1) return result;
        return -result;
    }
};