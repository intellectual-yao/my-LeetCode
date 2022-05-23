int removeDuplicates(int* nums, int numsSize)
{
    for(int i = 0;i < numsSize - 1;i++)
    {
        if(nums[i] == nums[i + 1])      //如果前后数据相同，则删除之
        {
            for(int j = i;j < numsSize - 1;j++)
            {
                nums[j] = nums[j + 1];          //数组元素前移
            }
        i--;                //i在运算后要向前一位，以免出现重复元素未删除的情况
        numsSize--;         //数组长度减一
        }
    }
    return numsSize;
}
