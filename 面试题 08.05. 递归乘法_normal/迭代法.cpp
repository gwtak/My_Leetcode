class Solution {
public:
    int multiply(int A, int B) {
        int res=0;
        if(A<B){
            for(int i=0;i<A;i++){
                res+=B;
            }
        }
        else{
            for(int i=0;i<B;i++){
                res+=A;
            }
        }
        return res;
    }
};