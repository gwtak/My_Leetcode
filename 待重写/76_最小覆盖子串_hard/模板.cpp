/*给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
string minWindow(string s, string t) {

	//输入参数有效性判断
	if (t.size() <= 0 || s.size() <= 0 || s.size() < t.size())
		return "";
	

	int hash[256] = { 0 };
	for (int i = 0; i < t.size(); i++)
		hash[t[i]]++;		//将模式串中的字母加入hash表

	int l = 0, count = t.size(), max = s.size() + 1;
	string result;
	
	for (int r = 0; r < s.size(); r++) {
		hash[s[r]]--;	//遍历主串s，去对消hash表中的t的元素

		if (hash[s[r]] >= 0)	//匹配上一个t中的字符
			count--;


		while (l < r && hash[s[l]] < 0) { //
			hash[s[l]]++; 
			l++;		//左移窗口
		}

		//更新结果：只有新的窗口的长度比max小，才有机会更新
		if (count == 0 && r - l + 1 < max) { //如果count ==0 ,说明刚好t中的字符全部匹配
			max = r - l + 1;
			result = s.substr(l, r-l + 1); 
		}
	}
	 
	return result;
}
};