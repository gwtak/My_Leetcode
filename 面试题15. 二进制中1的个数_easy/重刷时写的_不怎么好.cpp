class Solution {
public:
    int hammingWeight(uint32_t n){
        int res=0;
        long long tmp=pow(2,31);
        while(tmp){
            if(n!=n%tmp){
                res++;
                n%=tmp;
            }
            tmp/=2;
        }
        return res;
    }
};