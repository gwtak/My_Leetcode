/*给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash_s[26];
        int hash_t[26];
        memset(hash_s,0,sizeof(hash_s));
        memset(hash_t,0,sizeof(hash_t));
        for(char x:s) hash_s[x-'a']++;
        for(char x:t) hash_t[x-'a']++;
        //for(int i=0;i<26;i++) cout<<hash_s[i]<<","<<hash_t[i]<<endl;
        for(int i=0;i<26;i++){
            if(hash_s[i]!=hash_t[i]) return i+'a';
        }
        return 0;
    }
};