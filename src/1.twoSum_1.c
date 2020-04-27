#include <stdio.h>
#include <stdlib.h>

/*
 *暴力法解决,俩数之和
 *
 * */

/*  *nums-> 数组,  numsSize-> 数组长度,  target-> 要得到的目标, *returnSize 要返回数组的长度(在函数中赋值)  */
int *twoSum (int *nums,int numsSize,int target,int *returnSize){
	int i,j;
	(*returnSize)=2;
	int *returnArray=(int *)malloc(sizeof(int)*(*returnSize));
	returnArray[0]=-1;
	returnArray[1]=-1;
	
	for(i=0;i<numsSize;i++){
		for(j=i;j<numsSize;j++){
			if(nums[i]+nums[j]==target){
				returnArray[0]=i;
				returnArray[1]=j;
				break;
			}	
		}
	}	
	return returnArray;
}

int main(int argc, char *argv[])
{
	int nums[4]={2,7,11,15};	/*随机给出的数据*/
	int size;
	int *result=twoSum(nums, 4, 9, &size);
	for(int i=0;i<size;i++){
		printf("%d  ",result[i]);
	}
	free(result);
	return 0;
}

