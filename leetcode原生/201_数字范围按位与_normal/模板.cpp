class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m<n){
            n&=(n-1);
        }
        return n;
    }
};
/*
作者：java_Lee
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/xue-guo-xian-duan-shu-de-du-zhi-dao-zhe-ge-cao-zuo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/