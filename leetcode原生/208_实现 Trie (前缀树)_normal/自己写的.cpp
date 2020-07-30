/*实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Trie {
public:
    /** Initialize your data structure here. */
    Trie* next[26];
    bool isEnd=0;
    //static Trie* head;//静态量在leetcode中被释放了，爆出heap-use-after-free错误
    Trie() {
        //if(!head) head=this;
        memset(next,0,sizeof(next));//必须要初始化指针，不然会在line 16，char 20报错
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p=this;
        for(int i=0;i<word.size();i++){
            if(!p->next[word[i]-'a']) p->next[word[i]-'a']=new Trie();
            p=p->next[word[i]-'a'];
        }
        p->isEnd=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p=this;
        for(int i=0;i<word.size();i++){
            if(!p->next[word[i]-'a']) return 0;
            p=p->next[word[i]-'a'];
        }
        if(p->isEnd) return 1;
        else return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trie* p=this;
        for(int i=0;i<word.size();i++){
            if(!p->next[word[i]-'a']) return 0;
            p=p->next[word[i]-'a'];
        }
        return 1;
    }
};

//Trie* Trie::head=NULL;//static成员变量要在类外初始化

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */