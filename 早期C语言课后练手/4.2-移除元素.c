int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)           //若为空，直接返回0
        return 0;
    for(int i = 0;i < numsSize - 1;i++)     
    {
        if(nums[i] == val)
        {
            for(int j = i;j < numsSize - 1;j++)
            {
                nums[j] = nums[j + 1];
            }
            i--;                //为了防止删除后重复元素没删除掉，故要将i回退一位
            numsSize--;         //移除元素之后数组长度要减一
        }
    }
    if(nums[numsSize - 1] == val)   //如果最后以为也是需要删除的元素，直接缩短数组长度即可
        numsSize--;
    return numsSize;
}
