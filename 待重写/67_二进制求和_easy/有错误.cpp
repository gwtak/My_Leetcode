/*给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
通过次数91,009提交次数171,830
在真实的面试中遇到过这道题？

是

否
贡献者

相关企业
相关标签
相似题目

题目列表

随机一题

上一题
67/1689

下一题

C++







1
class Solution {
2
public:
3
    int get_num(string a){
4
        int res=0;
        for(int i=a.size()-1,tmp=1;i>=0;i--,tmp*=2){
6
            res+=(a[i]-48)*tmp;
7
        }
8
        return res;
9
    }
10
    string int_to_str(int sum){
11
        string res;
12
        while(sum){
13
            res.push_back(sum%2+48);
14
            sum/=2;
15
        }
16
        for(int i=0,j=res.size()-1;i<j;i++,j--){
17
            res[i]^=res[j]^=res[i]^=res[j];
18
        }
19
        return res.empty()?string("0"):res;
20
    }
21
    string addBinary(string a, string b) {
22
        int a_num=get_num(a);
23
        int b_num=get_num(b);
24
        cout<<a_num<<endl;
25
        cout<<b_num<<endl;
26
        return int_to_str(a_num+b_num);
27
    }
28
};
测试用例
代码执行结果
调试器
Beta
已完成
执行用时：0 ms
输入
"0"
"0"
输出
"0"
差别


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int get_num(string a){
        int res=0;
        for(int i=a.size()-1,tmp=1;i>=0;i--,tmp*=2){
            res+=(a[i]-48)*tmp;
        }
        return res;
    }
    string int_to_str(int sum){
        string res;
        while(sum){
            res.push_back(sum%2+48);
            sum/=2;
        }
        for(int i=0,j=res.size()-1;i<j;i++,j--){
            res[i]^=res[j]^=res[i]^=res[j];
        }
        return res.empty()?string("0"):res;
    }
    string addBinary(string a, string b) {
        int a_num=get_num(a);
        int b_num=get_num(b);
        cout<<a_num<<endl;
        cout<<b_num<<endl;
        return int_to_str(a_num+b_num);
    }
};