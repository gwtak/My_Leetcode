/*给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class trie{
public:
    static trie* head;
    trie* next[26];
    bool isEnd=0;
    void insert(string str){
        trie* p=trie::head;
        if(!p) return;
        for(int i=0;i<str.size();i++){
            if(!p->next[str[i]-'a']) p->next[str[i]-'a']=new trie();
            p=p->next[str[i]-'a'];
        }
        p->isEnd=1;
    }
    //display()用于dfs查看字典树内全部值
    void display(trie* p=trie::head){
        for(int i=0;i<26;i++){
            if(p->next[i]){
                cout<<(char)(i+97)<<endl;
                display(p->next[i]);
            }
        }
    }
    bool check(){
        
    }
};

trie* trie::head=NULL;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        trie::head=new trie();
        for(int i=0;i<wordDict.size();i++){
            trie::head->insert(wordDict[i]);
        }
        //trie::head->display();
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                trie::trie->check();
            }
        }
        return 0;
    }
};