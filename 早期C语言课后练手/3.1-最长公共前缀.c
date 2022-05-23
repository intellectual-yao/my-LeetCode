char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize == 0)       //若为空字符，直接返回即可
        return "";
    else
    {
        for(int j = 0;j < strlen(strs[0]);j++)      //以第一个字符长度为基准开始列向扫描
        {
            for(int i = 0;i < strsSize;i++)
            {
                if(strs[0][j] != strs[i][j])        //列数不变看行数
                {
                    strs[0][j] = '\0';          //如果不匹配，则将第一行的字符串的该位置字符变为空
                    break;
                }
            }
        }
    }
    return strs[0];         //最后返回第一行字符即为最小公共前缀
}
