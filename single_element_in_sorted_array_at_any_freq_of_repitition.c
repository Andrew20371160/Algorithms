int find_single(int * arr, int size, int freq) {
    int low = 0;
    int high = size - 1;
    while (high > low) {
        int mid = low + (high - low) / 2;
      //at any frequency of repitition we must start checking where mid%ferq==0
      //meaning the start of a new repitition of an element
        if (mid % freq != 0) {
          //for example if mid  = 8 & freq = 3
          //mid must be divisible by 3 so mid -=mid%freq
          //where 6 = 8-8%3
            mid -= mid % freq;
        }
      //same example freq of 3 arr[mid] must be equal to arr[mid+3-1]
      //if true then we search in right half
        if (arr[mid] == arr[mid + freq - 1]) {
            low = mid + freq;
        } else {
            high = mid;
        }
    }
  //arr[low] == arr[high] anyway return what you want its just a convention 
    return arr[high];
}
