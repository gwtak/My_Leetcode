/*字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void push(string &res,int count){
        vector<int> tmp;
        while(count){
            tmp.push_back(count%10);
            count/=10;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.push_back(tmp[i]+'0');
        }
    }
    string compressString(string S) {
        string res;
        int count=0;
        int i=0;
        int j=0;
        while(j<S.size()){
            if(S[i]==S[j]){
                count++;
                j++;
            }
            else{
                res.push_back(S[i]);
                push(res,count);
                i=j;
                count=0;
            }
        }
        res.push_back(S[i]);
        push(res,count);
        if(S.size()<=res.size()) return S;
        return res;
    }
};