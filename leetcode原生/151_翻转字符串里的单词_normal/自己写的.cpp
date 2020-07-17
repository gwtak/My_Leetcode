class Solution {
public:
    void do_push_work(string& res,string s,int i,int j){
        while(i<=j){
            res.push_back(s[i]);
            i++;
        }
        res.push_back(' ');
    }
    string reverseWords(string s) {
        string res;
        int low=s.size()-1;
        int high=s.size()-1;
        while(low>=0&&s[low]==' ') low--;
        high=low;
        while(low>=0){
            if(s[low]==' '){
                do_push_work(res,s,low+1,high);
                while(low>=0&&s[low]==' ') low--;
                high=low;
            }
            else low--;
        }
        do_push_work(res,s,low+1,high);
        string::iterator it=res.end();
        while(*(--it)==' '){
            res.erase(it);
        }
        return res;
    }
};