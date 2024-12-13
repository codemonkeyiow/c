#include <stdio.h>
#include <math.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    float longest = 0.0;
    int longestIndex = 0;
    for(int i = 0; i < dimensionsSize; i++) {
        float len = sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
        if(len > longest) {
            longest = len;
            longestIndex = i;
        }
        else if(len == longest) {
            if(dimensions[i][0]*dimensions[i][1] > dimensions[longestIndex][0]*dimensions[longestIndex][1]) {
                longestIndex = i;
            }
        }
    }
    int area = dimensions[longestIndex][0] * dimensions[longestIndex][1];
    return area;
}

int main() {
  int dimensions[2][2] = {{9,3},{8,6}};
  int *dp = (int *)dimensions;
  int **dpp = &dp;
  int area = areaOfMaxDiagonal(dpp, 2, 0);
  printf("%d\n", area);
}
