/*给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void helper(int* hash,int* tmp){
        for(int i=0;i<26;i++){
            tmp[i]=hash[i];
        }
    }
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int hash[26];
        memset(hash,0,sizeof(hash));
        for(char x:chars){
            hash[x-'a']++;
        }
        int tmp[26];
        memset(tmp,0,sizeof(tmp));
        helper(hash,tmp);
        for(int i=0;i<words.size();i++){
            int flag=1;
            helper(hash,tmp);
            for(int j=0;j<words[i].size();j++){
                if(tmp[words[i][j]-'a']>0) tmp[words[i][j]-'a']--;
                else{
                    flag=0;
                    break;
                }
            }
            if(flag) res+=words[i].size();
        }
        return res;
    }
};