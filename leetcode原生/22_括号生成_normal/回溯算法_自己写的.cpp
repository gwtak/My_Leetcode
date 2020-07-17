class Solution {
public:
    vector<string> res;
    void find_count(string track,int& left,int& right){
        for(int i=0;i<track.size();i++){
            if(track[i]=='(') left++;
            else right++;
        }
    }
    void helper(string track,int n){
        int left=0;
        int right=0;
        find_count(track,left,right);
        if(left<right||left>n) return;
        if(track.size()==(2*n)){
            res.push_back(track);
            return;
        }
        if(left==right){
            track.push_back('(');
            helper(track,n);
        }
        else{
            string tmp=track;
            track.push_back('(');
            helper(track,n);
            track=tmp;
            track.push_back(')');
            helper(track,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string track;
        helper(track,n);
        return res;
    }
};