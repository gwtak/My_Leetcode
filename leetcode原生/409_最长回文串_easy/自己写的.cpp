/*给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。*/
class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        int single_sum=0;
        int double_sum=0;
        int hash[58];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<s.size();i++){
            hash[s[i]-'A']++;
        }
        for(int i=0;i<58;i++){
            if(hash[i]/2) double_sum+=(hash[i]/2);
            if(hash[i]%2) single_sum++;
        }
        if(single_sum) res=2*double_sum+1;
        else res=2*double_sum;
        return res;
    }
};