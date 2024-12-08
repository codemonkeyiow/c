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
  
  return sum;
}

int main() {
  int nums[] = { 1, 2, 3, 2, 1 };
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int x = missingInteger(nums, numsSize);
  printf("%d\n", x);
  return 0;
}
