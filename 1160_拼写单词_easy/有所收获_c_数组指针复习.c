void init(int* hash,int* tmp){
    for(int i=0;i<26;i++){
        tmp[i]=hash[i];
    }
}
int countCharacters(char** words, int wordsSize, char* chars){
    int res=0;
    int hash[26];
    int tmp[26];
    memset(hash,0,sizeof(hash));
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<strlen(chars);i++){
        hash[chars[i]-'a']++;
    }
    init(hash,tmp);
    for(int i=0;i<wordsSize;i++){
        int flag=1;
        init(hash,tmp);
        for(int j=0;j<strlen(words[i]);j++){
            if(tmp[words[i][j]-'a']>0) tmp[words[i][j]-'a']--;
            else{
                flag=0;
                break;
            }
        }
        if(flag) res+=strlen(words[i]);
    }
    return res;
}