class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        int len = len_1 + len_2;
        int val1 = 0;
        int val2 = 0;

        if(len % 2 == 0){
            if(!findKInArrays(nums1, nums2, 0, len_1, 0, len_2, len/2, val1)&&
                !findKInArrays(nums1, nums2, 0, len_1, 0, len_2, len/2+1, val2)){
                 return (val1 + val2) / 2.0;   
            }
        }else{
            if(!findKInArrays(nums1, nums2, 0, len_1, 0, len_2, len/2+1, val1)){
                 return val1;   
            }
        }
        return 0;
    }

    int findKInArrays(vector<int>& nums1, vector<int>& nums2, 
                        int num1_begin, int num1_end, int num2_begin, int num2_end, 
                        int k, int& value){
        int num1_size = num1_end - num1_begin;
        int num2_size = num2_end - num2_begin;
        
        if(num1_size == 0){
            value = nums2[num2_begin + k-1];
            return 0;
        }

        if(num2_size == 0){
            value = nums1[num1_begin + k-1];
            return 0;
        }

        if(k < 1){
            return 1;
        }

        if(k == 1){
            value = nums1[num1_begin] < nums2[num2_begin] ? nums1[num1_begin] : nums2[num2_begin];
            return 0;
        }

        if(num1_size + num2_size == k){
            value = nums1[num1_end-1] > nums2[num2_end-1] ?  nums1[num1_end-1] : nums2[num2_end-1];
            return 0;
        }

        if(num1_size + num2_size < k){
            return  1;
        }

        int index1 = k/2;
        int index2 = k/2;
        if(index1 > num1_size){
            index1 = num1_size;
        }

        if(index2 > num2_size){
            index2 = num2_size;
        }
        
        if(nums1[index1 + num1_begin - 1] > nums2[index2 + num2_begin - 1]){
            findKInArrays(nums1, nums2, num1_begin, num1_end, num2_begin+index2,
                num2_end, k-index2, value);
        }else{
            findKInArrays(nums1, nums2, num1_begin+index1, num1_end, num2_begin,                      num2_end, k-index1, value);
        }
        return 0;
    }
};