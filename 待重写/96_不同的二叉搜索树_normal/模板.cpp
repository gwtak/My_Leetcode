class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        return dp[n];
    }
};

/*
作者：jerry-peng
链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/xi-xiang-yi-xia-huan-shi-hen-jian-dan-de-by-jerry-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
