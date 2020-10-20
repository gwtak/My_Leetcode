/*给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int hash_all[26];
        int hash_tmp[26];
        memset(hash_all,0x7f,sizeof(hash_all));
        memset(hash_tmp,0,sizeof(hash_tmp));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                hash_tmp[words[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                hash_all[j]=min(hash_all[j],hash_tmp[j]);
            }
            memset(hash_tmp,0,sizeof(hash_tmp));
        }
        for(int i=0;i<26;i++){
            if(hash_all[i]!=0x7f7f7f7f){
                string tmp;
                tmp.push_back(i+'a');
                while(hash_all[i]--) res.push_back(tmp);
            }
        }
        return res;
    }
};