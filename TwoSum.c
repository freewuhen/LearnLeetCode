/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
 int *re = (int *)malloc(sizeof(int)*2);
 int i = 0,j =0;
 int f = 0;
 for(;i < numsSize;i++)
 {
      re[0] = i;
      f = target - nums[i];
      for(j =0 ;j < numsSize; j++)
	{
	  if(nums[j] == f)
	  {
	    if(i == j) continue;//one num can only be  used once
	    re[1] = j;
	    return re;//found the two num
	  }	
	}	
 }   
  re[0] = -1;
  re[1] = -1;
  return re;// not found 
}
int main()
{
  int numsSize = 3;
  int nums[3] = {3,2,4};
  int target = 6;
  int *re = twoSum(nums,numsSize,target);
  printf("%d,",re[0]);
  printf("%d",re[1]);
  return 0;
}
