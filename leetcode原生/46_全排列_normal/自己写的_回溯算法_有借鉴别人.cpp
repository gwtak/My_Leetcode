class Solution {
public:
	vector<vector<int>> res;
    bool find_in_track(int num,vector<int>& track){
        for(int i=0;i<track.size();i++){
            if(track[i]==num) return 1;
        }
        return 0;
    }
    void helper(vector<int>& track,vector<int>& nums){
        if(track.size()==nums.size()) res.push_back(track);
        for(int i=0;i<nums.size();i++){
            vector<int> tmp=track;
            if(!find_in_track(nums[i],track)){
                track.push_back(nums[i]);
                helper(track,nums);
            }
            track=tmp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
		helper(track,nums);
        return res;
    }
};