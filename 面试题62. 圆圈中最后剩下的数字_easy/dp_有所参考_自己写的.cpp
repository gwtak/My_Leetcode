/*
n=5,m=3
0,1,2,3,4
3,4,0,1
1,3,4
1,3
3
dp关系式
F(0,m)=-1
F(1,m)=0
F(n,m)=(F(n-1,m)+m)%n
*/
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n==0) return -1;
        if(n==1) return 0;
        return (lastRemaining(n-1,m)+m)%n;
    }
};