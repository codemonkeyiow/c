/* Smallest Missing Integer Greater Than Sequential Prefix Sum
* You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.
*/

#include <stdio.h>

int missingInteger(int* nums, int numsSize) {
  if(numsSize == 0) return 0;

  int sum = nums[0];
  for(int i = 1; i < numsSize; i++) {
    if(nums[i] == nums[i-1] + 1) {
      sum += nums[i];
    } else {
      break;
    }
  }
  
  // order the array
  for(int i = 0; i < numsSize - 1; i++) {
    for(int j = i + 1; j < numsSize; j++) {
      if(nums[i] > nums[j]) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
  }

  int isInArray = 0;
  int isLargest = 1;
  for(int i = 0; i < numsSize - 1; i++) {
    if(nums[i] == sum) isInArray = 1;
    if(nums[i] < sum) isLargest = 0;
    printf("%d ", nums[i]);
    if(nums[i] > sum) {
      if(nums[i + 1] != nums[i] + 1) {
        return nums[i] + 1;
      }
    }
  }

  if(isInArray == 1 && isLargest == 0) return sum;

  return nums[numsSize - 1] + 1;
}

int main() {
  int nums[] = { 3, 4, 5, 1, 12, 13, 14, 15 };
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int x = missingInteger(nums, numsSize);
  printf("\n%d\n", x);
  return 0;
}
