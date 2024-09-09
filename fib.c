#include <stdio.h>
#include <stdlib.h>

int getFibonnaciRecursive(int nthNum) {
  if (nthNum <= 1) {
    return nthNum;
  } else {
    return (getFibonnaciRecursive(nthNum - 1) + getFibonnaciRecursive(nthNum - 2));
  }
}

int getFibonnaciIterative(int nthNum) {
  if (nthNum <= 1) {
    return nthNum;
  }

  int num1 = 0;

  int num2 = 1;

  int temp;

  for (int i = 2; i <= nthNum; i++) {
    temp = num1 + num2;

    num1 = num2;
    num2 = temp;
  }

  return num2;
}

int main(int argc, char* argv[]) {
  int initialNum;

  int fileNum;

  int nthNum;

  char recursionMethod;

  FILE *filePtr;

  char* fileName;

  int result;

  sscanf(argv[1], "%d", &initialNum);
  recursionMethod = *argv[2];
  fileName = argv[3];

  filePtr = fopen(fileName, "r");

  fscanf(filePtr, "%d", &fileNum);

  fclose(filePtr);

  nthNum = initialNum + fileNum - 1;

  if (recursionMethod == 'r') {
      printf("%d", getFibonnaciRecursive(nthNum));
  } else if (recursionMethod == 'i') {
      printf("%d", getFibonnaciIterative(nthNum));
  } else {
      return 0;
  }

  return 0;
}
