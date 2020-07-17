class Solution {
public:
    void intervals_sort(vector<vector<int>>& intervals){
        for(int i=0;i<intervals.size();i++){
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[i][0]>intervals[j][0]){
                    intervals[i][0]^=intervals[j][0]^=intervals[i][0]^=intervals[j][0];
                    intervals[i][1]^=intervals[j][1]^=intervals[i][1]^=intervals[j][1];
                }
            }
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;
        intervals_sort(intervals);
        int last_left=intervals[0][0];
        int last_right=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(last_left<=intervals[i][1]&&last_right>=intervals[i][0]){
                last_left=min(last_left,intervals[i][0]);
                last_right=max(last_right,intervals[i][1]);
            }
            else{
                res.push_back(vector<int>{last_left,last_right});
                last_left=intervals[i][0];
                last_right=intervals[i][1];
            }
        }
        res.push_back(vector<int>{last_left,last_right});
        return res;
    }
};