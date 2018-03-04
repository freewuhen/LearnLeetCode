#include <stdio.h>
#include <math.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	if(nums1Size > nums2Size)
	{
		int *t = nums1;
		nums1 = nums2;
		nums2 = t;
		int temp = nums1Size;
		nums1Size = nums2Size;
		nums2Size = temp;
	}
	int left = 0,right = nums1Size,halflen = (nums1Size+nums2Size+1)/2;
	int i,j,maxleft = 0,minright = 0;
	while(left <= right)
	{
		i = (left+right)/2;
		j = halflen-i;
		if(i < right && nums2[j-1] > nums1[i])
		{
	        	left++;		
		}
		else if(i > left && nums1[i-1] > nums2[j])
		{
			right--;
		}
		else{if (i == 0) { maxleft = nums2[j-1]; }
                	else if (j == 0) { maxleft = nums1[i-1]; }
                	else { maxleft = nums1[i-1] >= nums2[j-1]?nums1[i-1]:nums2[j-1]; }
                	if ( (nums1Size+nums2Size) % 2 == 1 ) { return maxleft; }

          
                	if (i == nums1Size) { minright = nums2[j]; }
                	else if (j == nums2Size) { minright = nums1[i]; }
                	else { minright = nums2[j] <= nums1[i]?nums2[j]:nums1[i]; }
			
			return (minright+maxleft)/2.0;
		}
	}
	return 0.0;	
}
int main()
{
  int n1[2] = {1,3};
  int n2[1] = {2};
  double re = findMedianSortedArrays(n1,2,n2,1);
  printf("%f",re);
  return 0;
}
