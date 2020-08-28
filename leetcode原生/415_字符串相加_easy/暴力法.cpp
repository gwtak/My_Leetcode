/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i=num1.size()-1;
        int j=num2.size()-1;
        int flag=0;
        while(i>=0&&j>=0){
            int tmp=num1[i]+num2[j]-'0'-'0';
            if(flag){
                tmp++;
                flag=0;
            }
            if(tmp>=10){
                res.insert(res.begin(),tmp%10+'0');
                flag=1;
            }
            else{
                res.insert(res.begin(),tmp+'0');
                flag=0;
            }
            i--;
            j--;
        }
        while(i>=0){
            int tmp=num1[i]-'0';
            if(flag){
                tmp++;
                flag=0;
            }
            if(tmp>=10){
                res.insert(res.begin(),tmp%10+'0');
                flag=1;
            }
            else{
                res.insert(res.begin(),tmp+'0');
                flag=0;
            }
            i--;
        }
        while(j>=0){
            int tmp=num2[j]-'0';
            if(flag){
                tmp++;
                flag=0;
            }
            if(tmp>=10){
                res.insert(res.begin(),tmp%10+'0');
                flag=1;
            }
            else{
                res.insert(res.begin(),tmp+'0');
                flag=0;
            }
            j--;
        }
        if(flag) res.insert(res.begin(),1+'0');
        return res;
    }
};