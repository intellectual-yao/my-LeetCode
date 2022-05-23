int maxSubArray(int* nums, int numsSize)
{
    int i, j, temp;
    int _Max = nums[0];         //首先假设最大值为数组第一个元素

    for (i = 0; i < numsSize; i++)
    {
        temp = 0;               //为了比较所有的子列和因此每次都要将临时数据置零
        for (j = i; j < numsSize; j++)      //计算每个连续的子列和
        {   
            temp += nums[j];
            if (temp > _Max)                //如果子列和大于最大值，就更新最大值
            {
                _Max = temp;
            }
        }
    }
    return _Max;
}
