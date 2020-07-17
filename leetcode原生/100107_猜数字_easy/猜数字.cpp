class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int res=0;
        int i=0;
        vector<int>::iterator p=guess.begin();
        vector<int>::iterator q=answer.begin();
        while(p!=guess.end()){
            if((*p)==(*q)) res++;
            p++;
            q++;
        }
        return res;
    }
};