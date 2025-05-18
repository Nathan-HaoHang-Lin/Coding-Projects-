/*
PSEUDO CODE 

boolean function prototype that takes two arguments 

Function isMember(integer array, integer value):

  if array equals sentinel 
    return false
  if arr at index 0 equals value 
    return true 
  
  return isMember function call passing array + 1 and value

Main:

  create var size
  get input for size 

  create array with size + 1 to account for sentinel value
  at array index of size + 1 set to sentinel value

  For i  starting at 0, i less than size, and incrememting i every iteration:
    get input for array [i]

  For i starting at 0, i less than or equal to 20, and incremmenting i:
    print i " is " call isMember(array, value) ternary conditional statement " in the array."

  return 0
*/

#include <iostream>

using namespace std;

//prototype

bool isMember(int arr[], int value);

//function to determine if value is in array 

bool isMember(int arr[], int value) {

    //base case to stop recursion

    if ( arr[0] == 9999 ) {
        return false;
    }

    if (arr[0] == value) {
        return true;
    }

    //move the first index up by one every iteration using pointer arithmetic 

    return isMember(arr + 1, value);
}

//main 

int main() {

    //grab size for array 
    int size;
    cin >> size;

    //create with size plus one to make room for the sentinel
    //we must use a sentinel because we need a terminating condition for the recursive function.
    
    int arr[size + 1];

    //initialize our sentinel 

    arr[size+1] = 9999; 

    //for loop to fill in the array 

    for (int i  = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    //for loop to pass in each of our values 0 through 20 
    
    for (int i = 0; i <= 20; i++) {
        cout << i << " is " << (isMember(arr, i) ? "found" : "not found") << " in the array." << endl;
    }

    return 0;
}
