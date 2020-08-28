/*
n-m差多少，后面就有对应位置的比特位为0，比特位叠加，后面的比特位就连续为0

n-m的差值				比特位
1						0
2						00
3						00
4						000
5						000

8						0000

16						00000
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift=0;
        long long tmp=1;
        while(tmp<=(n-m)){
            tmp*=2;
            shift++;
        }
        //cout<<shift<<endl;
        return (0xffffffff<<shift)&n&m;
    }
};