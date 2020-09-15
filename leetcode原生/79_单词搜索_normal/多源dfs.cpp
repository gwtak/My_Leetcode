/*给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool dfs(vector<vector<char>>& board,int row,int col,string& word,int cnt){
        if(cnt>=word.size()) return true;
        char tmp=board[row][col];
        board[row][col]='*';
        if(row-1>=0&&board[row-1][col]==word[cnt]&&dfs(board,row-1,col,word,cnt+1)){
            board[row][col]=tmp;
            return true;
        }
        if(row+1<board.size()&&board[row+1][col]==word[cnt]&&dfs(board,row+1,col,word,cnt+1)){
            board[row][col]=tmp;
            return true;
        }
        if(col-1>=0&&board[row][col-1]==word[cnt]&&dfs(board,row,col-1,word,cnt+1)){
            board[row][col]=tmp;
            return true;
        }
        if(col+1<board[0].size()&&board[row][col+1]==word[cnt]&&dfs(board,row,col+1,word,cnt+1)){
            board[row][col]=tmp;
            return true;
        }
        board[row][col]=tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        for(int i=0;i<word.size();i++){
            for(int j=0;j<board.size();j++){
                for(int k=0;k<board[j].size();k++){
                    if(board[j][k]==word[0]) res=res?res:dfs(board,j,k,word,1);
                }
            }
        }
        return res;
    }
};