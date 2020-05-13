int lengthOfLongestSubstring(char * s){
    int maxValue = 0; //最大长度
    int tempMaxValue = 0; // temp length 

    /* use sliding window */
    int slidingWindowHead = 0;//头部
    int slidingWindowRear = 0;//尾部
    int slidingWindowQueue[128] = {0}; //A：65；a：97存储字符对应的ASCII码

    int length = strlen(s);

    if(length == 0)
    {
        return 0; // null string
    }

    while(slidingWindowHead <= (length - 1))
    {
        if(slidingWindowQueue[ s[slidingWindowHead] ] != 0) //寻找相同字符
        {
            if(slidingWindowQueue[ s[slidingWindowHead] ] > slidingWindowRear) //忽略外部的字串
            {
                slidingWindowRear = slidingWindowQueue[ s[slidingWindowHead] ]; // 更新后面的滑动窗口
            }
        }

        tempMaxValue = slidingWindowHead - slidingWindowRear + 1; //等于滑动窗口长度

        if(tempMaxValue > maxValue) //更新最大长度
        {
            maxValue = tempMaxValue;
        }

        slidingWindowQueue[ s[slidingWindowHead] ] = slidingWindowHead + 1; //更新[string char <-> position]到队列
        slidingWindowHead++;
    }

    return maxValue;
}

作者：hua-jia-wang-tie-nan
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/chun-c-hua-dong-chuang-kou-by-hua-jia-wang-tie-nan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。