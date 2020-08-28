class Solution {
public:
    /*公式nums[i][j]=min(nums[i-1][j-1],nums[i-1][j],nums[i][j-1])+1*/
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> nums;
        for(int i=0;i<matrix.size();i++){
            vector<int> tmp;
            for(int j=0;j<matrix[i].size();j++){
                tmp.push_back(matrix[i][j]-'0');
            }
            nums.push_back(tmp);
        }
        int res=0;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<nums[i].size();j++){
                if(nums[i][j]) nums[i][j]=min(min(nums[i-1][j],nums[i][j-1]),nums[i-1][j-1])+1;
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                res=max(nums[i][j],res);
            }
        }
        return res*res;
    }
};