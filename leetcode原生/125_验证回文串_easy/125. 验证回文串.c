/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
bool isPalindrome(char * s){
    int i=0;
    int j=strlen(s)-1;
    while(i<j){
        if((s[i]<'A'&&s[i]>'9')||(s[i]>'Z'&&s[i]<'a')||s[i]>'z'||s[i]<'0'){
            i++;
            continue;
        }
        if((s[j]<'A'&&s[j]>'9')||(s[j]>'Z'&&s[j]<'a')||s[j]>'z'||s[j]<'0'){
            j--;
            continue;
        }
        if(((s[i]<='9'&&s[i]>='0')&&(s[j]<='Y'&&s[j]>='P'))||((s[j]<='9'&&s[j]>='0')&&(s[i]<='Y'&&s[i]>='P'))) return false;
        if((s[i]==s[j])||((s[i]-s[j])==32)||((s[j]-s[i])==32)){
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}