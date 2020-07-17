class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[0] = 0;
        for(int i=1;i<=num;i++){
            //如果是奇数
            if(i & 1 == 1){
                res[i] = res[i-1] +1;
            }
            //如果是偶数
            else{
                res[i] = res[i/2];
            }
        }
        return res;
    }
};