class Solution {
public:
    void quick_sort(vector<string>& strs,int left,int right){
        if(left>=right) return;
        int low=left;
        int high=right;
        string str=strs[left];
        while(low<high){
            while(low<high&&(str+strs[high]<=strs[high]+str)) high--;//strs[low]+str+str[high]
            strs[low]=strs[high];
            while(low<high&&(str+strs[low]>=strs[low]+str)) low++;
            strs[high]=strs[low];
        }
        strs[low]=str;
        quick_sort(strs,left,low-1);
        quick_sort(strs,low+1,right);
    }
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(int x:nums) strs.push_back(to_string(x));
        /*
        for(int i=0;i<nums.size();i++){
            string tmp;
            while(nums[i]){//nums[i]==0时，无法转换
                tmp.push_back('0'+nums[i]%10);
                nums[i]/=10;
            }
            for(int i=0,j=tmp.size()-1;i<j;i++,j--){
                char c=tmp[i];
                tmp[i]=tmp[j];
                tmp[j]=c;
            }
            cout<<tmp<<endl;
            strs.push_back(tmp);
        }
        */
        quick_sort(strs,0,strs.size()-1);
        string res;
        for(string x:strs) res+=x;
        return res;
    }
};