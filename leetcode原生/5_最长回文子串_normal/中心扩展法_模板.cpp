class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int start = 0, length = 0;
        for(int i=0; i < s.size(); ) {
            if (s.size() - i <= length / 2) break;
            int j = i, k = i;
            // 去除重复数字
            while(k < s.size() - 1 && s[k] == s[k+1]) k++; 
            i = k+1;
            // 扩距离
            while(j > 0 && k < s.size() -1 && s[j-1] == s[k+1]) {
                k++;
                j--;
            }
            // k和j是当前的最左边和最右边的元素
            if(length < k - j + 1) {
                length = k - j + 1;
                start = j;
            }
        }
        return s.substr(start, length);
    }
};