class Solution {
public:
    //位运算：快速幂(厉害👍)
    double myPow(double x, int n) {
        double res=1;
        long num=n;
        if(num<0){
            x=1/x;
            num=-num;
        }
        while(num){
            if(num&1) res*=x;
            x*=x;
            num=num>>1;
        }
        return res;
    }
};