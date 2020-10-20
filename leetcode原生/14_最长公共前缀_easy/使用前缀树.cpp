class Trie{
    public:
    bool isEnd=0;
    Trie* next[26];
    int count=0;
    Trie(){memset(next,0,sizeof(Trie*)*26);}
    void insert(string& str){
        Trie* p=this;
        for(int i=0;i<str.size();i++){
            if(p->next[str[i]-'a']) p=p->next[str[i]-'a'];
            else{
                p->count++;
                p->next[str[i]-'a']=new Trie();
                p=p->next[str[i]-'a'];
            }
        }
        p->isEnd=1;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie=new Trie();
        string res;
        for(string& str:strs){
            if(str.empty()) return res;
            trie->insert(str);
        }
        Trie* p=trie;
        while(p->count==1&&!p->isEnd){
            for(int i=0;i<26;i++){
                if(p->next[i]){
                    p=p->next[i];
                    res.push_back(i+'a');
                    break;
                }
            }
        }
        return res;
    }
};