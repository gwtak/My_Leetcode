/*设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-and-search-word-data-structure-design
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class WordDictionary {
public:
    /** Initialize your data structure here. */
    bool isEnd=0;
    WordDictionary* next[26];
    WordDictionary() {
        memset(next,0,sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* p=this;
        for(int i=0;i<word.size();i++){
            if(!p->next[word[i]-'a']) p->next[word[i]-'a']=new WordDictionary();
            p=p->next[word[i]-'a'];
        }
        p->isEnd=1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        //cout<<word<<endl;
        WordDictionary* p=this;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                string tmp_word;
                for(int k=i+1;k<word.size();k++){
                    tmp_word.push_back(word[k]);
                }
                for(int j=0;j<26;j++){
                    if(p->next[j]&&p->next[j]->search(tmp_word)) return 1;
                }
                return 0;
            }
            if(!p->next[word[i]-'a']) return 0;
            p=p->next[word[i]-'a'];
        }
        return p->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */