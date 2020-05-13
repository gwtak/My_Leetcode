class NumArray {
public:
    vector<int>res;
    NumArray(vector<int>& nums) {
        res = vector<int>(nums.size(), 0);
        if(nums.size() == 0)
            return ;
        res[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            res[i] = res[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return res[j];
        else
            return res[j] - res[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */