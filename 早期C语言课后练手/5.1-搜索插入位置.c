int searchInsert(int* nums, int numsSize, int target)
{
    int i, j, count = 0;
    for(i = 0;i < numsSize - 1;i++)
    {
        if(nums[i] == target)       //寻找是否存在目标元素
            return i;
    }
    for(j = 0;j < numsSize - 1;j++)
    {
        if(target > nums[j])        //寻找插入位置
            count++;
    }
        if(target > nums[numsSize - 1]) //最后一位的话需要将位置加一
            count++;
    return count;   
}
