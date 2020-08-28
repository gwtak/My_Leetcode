class Solution {
public:
    string addBinary(string a, string b) {
        int flag=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string res;
        while(i>=0&&j>=0){
            if(flag){
                if(a[i]=='1'&&b[j]=='1'){
                    res.push_back('1');
                }
                else if(a[i]=='1'||b[j]=='1'){
                    res.push_back('0');
                }
                else{
                    res.push_back('1');
                    flag=0;
                }
            }
            else{
                if(a[i]=='1'&&b[j]=='1'){
                    flag=1;
                    res.push_back('0');
                }
                else if(a[i]=='1'||b[j]=='1'){
                    res.push_back('1');
                }
                else{
                    res.push_back('0');
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(flag){
                if(a[i]=='1'){
                    res.push_back('0');
                }
                else{
                    res.push_back('1');
                    flag=0;
                }
            }
            else{
                res.push_back(a[i]);
            }
            i--;
        }
        while(j>=0){
            if(flag){
                if(b[j]=='1'){
                    res.push_back('0');
                }
                else{
                    res.push_back('1');
                    flag=0;
                }
            }
            else{
                res.push_back(b[j]);
            }
            j--;
        }
        if(flag) res.push_back('1');
        i=0;
        j=res.size()-1;
        while(i<j){
            char tmp=res[i];
            res[i]=res[j];
            res[j]=tmp;
            i++;
            j--;
        }
        return res;
    }
};