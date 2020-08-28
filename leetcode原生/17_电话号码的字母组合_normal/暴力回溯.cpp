/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> res;
    vector<string> words={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void tracer(vector<int>& nums,int cnt,string path){
        if(cnt>=nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<words[nums[cnt]].size();i++){
            path.push_back(words[nums[cnt]][i]);
            tracer(nums,cnt+1,path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return (vector<string>)NULL;
        vector<int> nums;
        for(char x:digits) nums.push_back(x-'0');
        string path;
        tracer(nums,0,path);
        return res;
    }
};