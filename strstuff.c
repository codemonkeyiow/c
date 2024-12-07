#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonDerpfix(char** strs, int strsSize) {
  char *ret = malloc(sizeof(char) * 200);
  int longest = 0;
  for(int i = 0; i < strsSize - 1; i++) {
    for(int j = i + 1; j < strsSize; j++) {
      printf("%s %s\n", strs[i], strs[j]);
      int matches = 0;
      int a = strlen(strs[i]);
      int b = strlen(strs[j]);
      int length = a < b ? a : b;
      for(int c = 0; c < length; c++) {
        if(strs[i][c] == strs[j][c]) {
          matches++;
        }
      }
      printf("matches %d longest %d\n", matches, longest);
      if(matches > longest) {
        longest = matches;
        for(int c = 0; c < matches; c++) {
          ret[c] = strs[i][c];
          printf("%c %c ", strs[i][c], ret[c]);
        }
        //ret[matches] = '\0';
      }
      printf("\n");
    }
  }
  return ret;
}

char* longestCommonPrefix(char** strs, int strsSize) {
  char *ret = malloc(sizeof(char) * 200);
  if(strsSize == 0) return ret;

  int shortestLen = strlen(strs[0]);
  int shortestIndex = 0;
  for(int i = 1; i < strsSize; i++) {
    if(strlen(strs[i]) < shortestLen) {
      shortestLen = strlen(strs[i]);
      shortestIndex = i;
    }
  }
  for(int c = 0; c < shortestLen; c++) {
    for(int i = 0; i < strsSize; i++) {
      if(strs[i][c] != strs[shortestIndex][c]) {
        ret[c] = '\0';
        return ret;
      }
    }
    ret[c] = strs[shortestIndex][c];
  }

  ret[shortestLen] = '\0';
  return ret;
}

int main() {
  //char *ret[] = {"flower", "flow", "flight" };
  char *ret[] = {"a"};
  int size = sizeof(ret) / sizeof(ret[0]);
  printf("size %d\n", size);
  char *k = longestCommonPrefix(ret,size);
  printf("%s\n", k);
  free(k);

  return 0;
}
