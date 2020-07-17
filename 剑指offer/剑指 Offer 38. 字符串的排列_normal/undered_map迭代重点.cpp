/*输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> res;
    void tracer(unordered_map<char,int> hash,string tmp,int val){
        if(!val){
            res.push_back(tmp);
            return;
        }
        for(auto& x:hash){//重点：&
            if(x.second){
                x.second--;
                tmp.push_back(x.first);
                tracer(hash,tmp,val-1);
                tmp.pop_back();
                x.second++;
            }
        }
    }
    vector<string> permutation(string s) {
        unordered_map<char,int> hash;
        string tmp;
        for(int i=0;i<s.size();i++) hash[s[i]]++;
        tracer(hash,tmp,s.size());
        return res;
    }
};