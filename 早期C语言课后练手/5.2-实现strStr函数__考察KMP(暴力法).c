/*          此代码逻辑没问题，但是在特（e）殊（xin）的测试用例的时候会运行超时
            故在改进版本先讲二者的数组长度计算出来，再利用长度参与运算
int strStr(char * haystack, char * needle)
{
    int i, j;
    int flag = 0;
    if(strlen(needle) == 0 && strlen(haystack) == 0)
        return 0;
    for(i = 0;i < strlen(haystack);i++)
    {
        flag = 0;
        for(j = 0;j < strlen(needle);j++)
        {
            if(haystack[i + j] != needle[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return i;
    }
    return -1;   
}*/
int strStr(char * haystack, char * needle)
{
    int i, j;
    int flag = 0;
    int hlen = strlen(haystack);
    int nlen = strlen(needle);         
    if(nlen == 0 && hlen == 0)      //如果两个长度均为0就返回0，否则返回-1
        return 0;
    for(i = 0;i < hlen;i++)
    {
        flag = 0;
        for(j = 0;j < nlen;j++)
        {
            if(haystack[i + j] != needle[j])        //当匹配出现不一样时，哨兵置1，直接开始下一轮匹配
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)               //当匹配完了以后哨兵没变化，因此此时的 i 就是所求的解
            return i;
    }
    return -1;   
}
