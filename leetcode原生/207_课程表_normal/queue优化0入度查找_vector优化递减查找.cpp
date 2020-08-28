class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> vect(numCourses);//用于直接递减，避免循环查找
        vector<int> in(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            vect[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        queue<int> zero_queue;
        for(int i=0;i<numCourses;i++){
            if(!in[i]) zero_queue.push(i);
        }
        while(!zero_queue.empty()){
            int cnt=zero_queue.front();
            zero_queue.pop();
            for(int x:vect[cnt]){
                in[x]--;
                if(!in[x]) zero_queue.push(x);
            }
        }
        for(int x:in){
            if(x) return 0;
        }
        return 1;
    }
};