// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).
#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == val) {
            for(int j = i; j < numsSize - 1; j++) {
                if(nums[j+1] == val) continue;
                nums[j] = nums[j + 1];
            }
        } else {
            k++;
        }
    }

    return k;
}

int main() {
    int array[4] = { 3, 2, 2, 3 };
    int k = removeElement(array, 4, 3);
    printf("\n%d\n", k);
    return 0;
}
