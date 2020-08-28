class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string("");
        int len=INT_MAX;
        for(string x:strs) len=min(len,(int)x.size());
        int count=0;
        for(int i=0;i<len;i++){
            int flag=1;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[j-1][i]){
                    flag=0;
                    break;
                }
            }
            if(flag) count++;
            else break;
        }
        string res;
        for(int i=0;i<count;i++) res.push_back(strs[0][i]);
        return res;
    }
};