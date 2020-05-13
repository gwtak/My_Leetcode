/*输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000*/
class Solution {
public:
    int find_pos(vector<int>& arr,int low,int high){
        int val=arr[low];
        while(low<high){
            while(low<high&&arr[high]>=val){//使用等于号，是为了避免原地踏步，如3，1，2，3
                high--;
            }
            arr[low]=arr[high];
            while(low<high&&arr[low]<=val){
                low++;
            }
            arr[high]=arr[low];
        }
        arr[low]=val;
        return low;
    }
    void quick_sort(vector<int>& arr,int low,int high){
        if(low<high){
            int pos=find_pos(arr,low,high);//重点：若将此行写在if之前，会在find_pos内val=arr[low]处造成下标越界
            quick_sort(arr,low,pos-1);
            quick_sort(arr,pos+1,high);
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        quick_sort(arr,0,arr.size()-1);
        for(int i=0;i<k;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};