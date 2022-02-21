// Consider the list of elements in the array where the elements are sorted and duplicates are allowed. In order to find out the position of first and last occurrence of duplicate elements. The basic idea of divide and conquer approach is to divide the elements into similar subproblem and recursively solve them. This approach is better as compared to the brute force approach since the running time is reduced. Use the divide and conquer approach in order to find the first and last occurrences of elements in the problem

#include <iostream>
#include <vector>
#include <algorithm>

void sort(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    int first = 0;
    int last = n - 1;
    int mid = (first + last) / 2;
    while(first <= last){
        if(arr[mid] == arr[mid + 1]){
            first = mid + 1;
        }
        else if(arr[mid] == arr[mid - 1]){
            last = mid - 1;
        }
        else{
            break;
        }
        mid = (first + last) / 2;
    }
    std::cout << first << " " << last << std::endl;
}
//use divide and conquer to find the first and last duplicate elements
void firstOccurrence(){
    
}



int main() {

}