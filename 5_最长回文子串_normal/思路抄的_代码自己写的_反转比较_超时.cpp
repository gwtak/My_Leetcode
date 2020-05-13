/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string longestPalindrome(string s) {
        string rev;
        string res;
        for(int i=s.size()-1;i>=0;i--){
            rev.push_back(s[i]);
        }
        for(int i=0;i<rev.size();i++){
            int tmp_i=i;
            for(int j=0;j<s.size();j++){
                int tmp_j=j;
                int count=0;
                while(i<rev.size()&&j<s.size()&&rev[i]==s[j]){
                    count++;
                    i++;
                    j++;
                }
                if(i+j-count!=s.size()) count=0;//排除类似"aacdfcaa"的输入，避免输出aac
                i=tmp_i;
                j=tmp_j;
                if(count>res.size()){
                    string tmp;
                    for(int k=0;k<count;k++){
                        tmp.push_back(rev[k+tmp_i]);
                    }
                    res=tmp;
                }
            }
        }
        return res;
    }
};