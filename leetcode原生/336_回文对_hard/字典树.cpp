/*
1、将所有单词插入字典树
2、将单词反转再进行比对
    反转后单词word_rev，字典树单词word_dic
    word_rev=word_dic，直接比对即可
    word_rev<word_dic，返回下个节点地址，判断剩余字符串是否为回文串
    word_rev>word_dic，返回剩余字符长度，判断剩余字符串是否为回文串
*/

//字典树
class Trie{
private:
    Trie* next[26];
    int isEnd=-1;
public:
    void Trie(){
        memset(next,0,sizeof(next));
    }
    
    void insert(string& word,int num){
        Trie* p=this;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']) p=p->next[word[i]-'a'];
            else{
                p->next[word[i]-'a']=new Trie();
                p=p->next[word[i]-'a'];
            }
        }
        p->isEnd=num;
    }
    
    Trie* check(string& word){
        Trie* p=this;
        for(int i=0;i<word.size();i++){
            if(!p->next[word[i]-'a']) return NULL;
            p=p->next[word[i]-'a'];
        }
        return p;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie head;
        for(string x:words) head.insert(x);
        for(int i=0;i<words.size();i++){
            
        }
    }
};