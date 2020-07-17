/*你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

 

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 

提示：

输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
1 <= numCourses <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        int in[numCourses];
        int out[numCourses];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<prerequisites.size();i++){
            in[prerequisites[i][0]]++;
            out[prerequisites[i][1]]++;
        }
        int flag=1;
        while(flag){
            flag=0;
            for(int i=0;i<numCourses;i++){
                if(in[i]==0){
                    flag=1;
                    res.push_back(i);
                    in[i]--;
                    for(int j=0;j<prerequisites.size();j++){
                        if(prerequisites[j][1]==i) in[prerequisites[j][0]]--;
                    }
                }
            }
        }
        if(res.size()==numCourses) return 1;
        else return 0;
    }
};