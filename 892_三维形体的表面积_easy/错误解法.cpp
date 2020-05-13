class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int length=grid.size();
        int width=grid[0].size();
        int not_empty_sum=0;
        int length_max[length];
        int width_max[width];
        memset(length_max,0,sizeof(length_max));
        memset(width_max,0,sizeof(width_max));
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                if(grid[i][j]){
                    not_empty_sum++;
                    length_max[i]=max(length_max[i],grid[i][j]);
                    width_max[j]=max(width_max[j],grid[i][j]);
                }
            }
        }
        int length_max_sum=0;
        int width_max_sum=0;
        for(int i=0;i<length;i++){
            length_max_sum+=length_max[i];
        }
        for(int i=0;i<width;i++){
            width_max_sum+=width_max[i];
        }
        return length_max_sum*2+width_max_sum*2+not_empty_sum*2;
    }
};

//错误示例：[[1,1,1],[1,0,1],[1,1,1]]