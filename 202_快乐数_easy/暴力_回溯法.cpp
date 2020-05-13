/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

 

示例：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool in_track(int tmp,vector<int> track){
        for(int i=0;i<track.size();i++){
            if(tmp==track[i]) return 1;
        }
        return 0;
    }
    bool isHappy(int n) {
        int tmp=0;
        vector<int> track;
        while(1){
            while(n){
                tmp+=(n%10)*(n%10);
                n/=10;
            }
            if(tmp==1) return 1;
            if(in_track(tmp,track)) return 0;
            else track.push_back(tmp);
            n=tmp;
            tmp=0;
        }
    }
};