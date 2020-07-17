class Solution {
public:
    string tmp;
    int findNthDigit(int n) {
        for(int num=tmp.size();tmp.size()<n+1;num++) tmp=tmp+to_string(num);
        return tmp[n]-'0';
    }
};