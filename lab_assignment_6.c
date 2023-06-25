int search(int numbers[], int low, int high, int value) {
  
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

