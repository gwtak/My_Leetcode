class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(32,INT_MAX);
        pre[0]=-1;
        const int N=s.size();
        int cur=0;
        int ans=0;
        for(int i=0;i<N;++i){
            switch(s[i]){
                case 'a':cur^=1;break;
                case 'e':cur^=2;break;
                case 'i':cur^=4;break;
                case 'o':cur^=8;break;
                case 'u':cur^=16;break;
                default:break;
            }
            if(pre[cur]==INT_MAX) pre[cur]=i;
            else ans=max(ans,i-pre[cur]);
        }
        return ans;
    }
};
/*
作者：mnizy
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solution/jian-dan-de-si-lu-by-mnizy/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
