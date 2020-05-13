/*字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


//与189题类似，链接：https://leetcode-cn.com/problems/rotate-array


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp;
        for(int i=0;i<=n-1;i++){
            tmp.push_back(s[i]);
        }
        for(int i=0;i<=s.size()-n-1;i++){
            s[i]=s[i+n];
        }
        for(int i=s.size()-n,j=0;i<=s.size()-1;i++,j++){
            s[i]=tmp[j];
        }
        return s;
    }
};