class Solution {
public:
    int sum(int x,int y){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        while(y){
            sum+=y%10;
            y/=10;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        int res=0;
        vector<vector<int>> map(m,(vector<int>(n,0)));
        map[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(sum(i,j)<=k){
                    if(i-1>=0&&map[i-1][j]) map[i][j]=1;
                    if(j-1>=0&&map[i][j-1]) map[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]) res++;
            }
        }
        return res;
    }
};