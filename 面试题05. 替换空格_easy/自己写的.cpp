/*请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        if(s.empty()) return res;
        for(int i=0;i<=s.size()-1;i++){
            if(s[i]==' '){
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
                continue;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};