#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{

  if (low > high) {
    // value not found
    return -1;
  }
  
  // find middle index
  int middle = (low + high) / 2;
  
  if (numbers[middle] == value) {
    return middle;
  }
  
  // if middle is greater than value, search the left side of the array
  if (numbers[middle] > value) {
    return search(numbers, low, middle - 1, value);
  }

  // if not, value has to be present in the right subarray
  // if middle is smaller than value, search the right side of the array
  if (numbers[middle] < value){
  return search(numbers, middle + 1, high, value);
  }

}

void printArray(int numbers[], int sz)
{
    int i;
    printf("Number array : ");
    for (i = 0;i<sz;++i)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, numInputs;
    char* str;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        average = 0;
        for (i = 0; i < countOfNums; i++)
        {
            fscanf(inFile," %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0)
        {
            printf("Item %d exists in the number array at index %d!\n",value, index);
        }
        else
        {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
}