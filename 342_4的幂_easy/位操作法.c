/*4的幂的二进制类似于100(4)，10000(16)，1000000(64)*/
bool isPowerOfFour(int num){
    if (num < 0 || num & (num-1)){//判断是否为2的倍数
        return false;
    }
    return num & 0x55555555;//判断奇位1  0x5=0101b
}