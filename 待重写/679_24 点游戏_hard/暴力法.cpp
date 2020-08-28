/*你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/24-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int judgePoint24_1(double a){
		return a-24>-1e-6 && a-24<1e-6;
	}
	int judgePoint24_2(double a,double b){
		return (judgePoint24_1(a+b)||
				judgePoint24_1(a*b)||
				judgePoint24_1(a-b)||
				judgePoint24_1(b-a)||
				judgePoint24_1(a/b)||
				judgePoint24_1(b/a));
	}
	int judgePoint24_3(double a,double b,double c){
		return (judgePoint24_2((b+c),a)||
				judgePoint24_2((b*c),a)||
				judgePoint24_2((b-c),a)||
				judgePoint24_2((c-b),a)||
				judgePoint24_2((b/c),a)||
				judgePoint24_2((c/b),a)||
				judgePoint24_2((a+c),b)||
				judgePoint24_2((a*c),b)||
				judgePoint24_2((a-c),b)||
				judgePoint24_2((c-a),b)||
				judgePoint24_2((a/c),b)||
				judgePoint24_2((c/a),b)||
				judgePoint24_2((a+b),c)||
				judgePoint24_2((a*b),c)||
				judgePoint24_2((a-b),c)||
				judgePoint24_2((b-a),c)||
				judgePoint24_2((a/b),c)||
				judgePoint24_2((b/a),c));
	}
	int judgePoint24_4(double a,double b,double c,double d){
		return (judgePoint24_3((c+d),a,b)||
				judgePoint24_3((c*d),a,b)||
				judgePoint24_3((c-d),a,b)||
				judgePoint24_3((d-c),a,b)||
				judgePoint24_3((c/d),a,b)||
				judgePoint24_3((d/c),a,b)||
				judgePoint24_3((b+d),a,c)||
				judgePoint24_3((b*d),a,c)||
				judgePoint24_3((b-d),a,c)||
				judgePoint24_3((d-b),a,c)||
				judgePoint24_3((b/d),a,c)||
				judgePoint24_3((d/b),a,c)||
				judgePoint24_3((b+c),a,d)||
				judgePoint24_3((b*c),a,d)||
				judgePoint24_3((b-c),a,d)||
				judgePoint24_3((c-b),a,d)||
				judgePoint24_3((b/c),a,d)||
				judgePoint24_3((c/b),a,d)||
				judgePoint24_3((a+d),b,c)||
				judgePoint24_3((a*d),b,c)||
				judgePoint24_3((a-d),b,c)||
				judgePoint24_3((d-a),b,c)||
				judgePoint24_3((a/d),b,c)||
				judgePoint24_3((d/a),b,c)||
				judgePoint24_3((a+c),b,d)||
				judgePoint24_3((a*c),b,d)||
				judgePoint24_3((a-c),b,d)||
				judgePoint24_3((c-a),b,d)||
				judgePoint24_3((a/c),b,d)||
				judgePoint24_3((c/a),b,d)||
				judgePoint24_3((a+b),c,d)||
				judgePoint24_3((a*b),c,d)||
				judgePoint24_3((a-b),c,d)||
				judgePoint24_3((b-a),c,d)||
				judgePoint24_3((a/b),c,d)||
				judgePoint24_3((b/a),c,d));
	}
    bool judgePoint24(vector<int>& nums) {
        double a=nums[0];
        double b=nums[1];
        double c=nums[2];
        double d=nums[3];
        return judgePoint24_4(a,b,c,d);
    }
};