/*给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/text-justification
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int left=0;
        int right=0;
        while(right<words.size()){
            //cout<<1<<endl;
            int length=words[left].size();
            int count=1;
            while(length+count-1<=maxWidth){
                right++;
                count++;
                if(right>=words.size()) break;
                length+=words[right].size();
            }
            //cout<<2<<endl;
            if(right>=words.size()){
                string tmp;
                for(int i=left;i<right;i++){
                    tmp+=words[i];
                    tmp.push_back(' ');
                }
                while(tmp.size()<maxWidth) tmp.push_back(' ');
                while(tmp.size()>maxWidth) tmp.pop_back();
                //cout<<3<<endl;
                //cout<<tmp<<endl;
                res.push_back(tmp);
            }
            else if(length+count-1>maxWidth){
                count--;
                length-=words[right].size();
                string tmp;
                vector<int> space;
                if(count==1) space.push_back(maxWidth-length);
                else{
                    for(int i=0;i<count-1;i++) space.push_back(0);
                    int space_length=maxWidth-length;
                    while(space_length){
                        for(int i=0;i<count-1&&space_length;i++,space_length--) space[i]++; 
                    }
                }
                cout<<3<<endl;
                for(int i=left,j=0;i<right;i++,j++){
                    tmp+=words[i];
                    for(int k=0;j<space.size()&&k<space[j];k++) tmp.push_back(' ');
                }
                //cout<<4<<endl;
                //cout<<tmp<<endl;
                res.push_back(tmp);
                left=right;
            }
        }
        return res;
    }
};