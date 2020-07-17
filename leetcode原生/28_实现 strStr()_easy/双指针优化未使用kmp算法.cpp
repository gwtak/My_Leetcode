class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int i=0,j=0;
        while(haystack[i]!='\0' && needle[j]!='\0'){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                i=i-j+1;
                j=0;
            }
        }
        if(needle[j]=='\0'){
            return i-j;
        }
        return -1;
    }
};