class Solution {
public:
    string::iterator in_track(string::iterator i,string::iterator j){
        while(i<j){
            if(*i==*j) return ++i;
            i++;
        }
        return (string::iterator)NULL;
    }
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int count=0;
        string::iterator i=s.begin();
        string::iterator j=s.begin();
        while(j!=s.end()){
            string::iterator tmp=in_track(i,j);
            if(tmp==(string::iterator)NULL){
                count++;
                res=max(count,res);
            }
            else{
                i=tmp;
                count=j-i+1;
            }
            //cout<<count<<endl;
            j++;
        }
        return res;
    }
};