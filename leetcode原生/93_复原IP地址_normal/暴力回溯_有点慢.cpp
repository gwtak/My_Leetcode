/*给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> res;
    bool is_legal(string str){
        vector<long long> nums;
        while(!str.empty()){
            nums.push_back(str.back()-'0');
            str.pop_back();
        }
        if(nums.back()==0&&nums.size()>1) return 0;
        int num=0;
        for(int i=nums.size()-1;i>=0;i--) num=num*10+nums[i];
        return num>=0&&num<=255;
    }
    void tracer(int cnt,int count,string& s,string path){
        if(cnt>=s.size()&&count==4){
            path.pop_back();
            res.push_back(path);
            return;
        }
        if(count>4) return;
        for(int i=cnt;i<s.size()&&is_legal(s.substr(cnt,i-cnt+1));i++){
            string tmp=path;
            path=path+s.substr(cnt,i-cnt+1)+".";
            tracer(i+1,count+1,s,path);
            path=tmp;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string path;
        tracer(0,0,s,path);
        return res;
    }
};