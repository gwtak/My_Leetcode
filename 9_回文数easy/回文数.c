int len(int x){
    int count=0;
    while(x>0){
        x=x/10;
        count++;
    }
    return count;
}

bool isPalindrome(int x){
    int y=x;
    if(x<0) return false;
    if(x<10) return true;
    int length=len(x);
    int half=length/2;
    for(int i=1;i<=half;i++){
        --length;
        if((x%10)!=(y/(int)pow(10,length))) return false;
        x=x/10;
        y=y%((int)pow(10,length));
    }
    return true;
}

