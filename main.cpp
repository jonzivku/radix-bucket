// Jon Zivku, jzivku, jonzivku@me.com, main.cpp
// Radix/Bucket Sort hybrid, A04
// Status: compiling/working/tested
/* love this sort, easily the most novel sort i've implemented so far. getting
   the ith digit of an integer in c++ is a pain. At first i tried
   (A[j]/pow(10,i)) % base, but pow returns a double, and it seems like any
   kind of casting is liable to instability, especially in this case, so instead
   I generated an array of powers of 10 to solve the problem. I went with using
   vector::clear() instead of overwriting so that I wouldn't need to keep track
   of vector indecies when emptying the buckets. Definitely had some fun
   problems to solve in this one. Found that my implementation ran in an ok
   amount of time, but generally was not faster than quickSort for the datasets
   I had. Would love to hear some techniques on optimizing this, or optimization
   in general.
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

void hybridSort(std::vector<int> &A, int size, int mag, int base);
// pre-cond: A: integer vector, with the following properties
//           size: size of A; mag: magnitude of elements in A;
//           base: base of the elements in A.
// postcond: A is sorted ascendingly.

int main(){  
  std::vector<int> sortMe;
  int temp;
  // fill the vector from console
  while(std::cin >> temp)
    sortMe.push_back(temp);  
  int size = sortMe.size();
  int mag = 9; // set the magnitude (digits per element)
  int base = 10; //set the base (only supported up to base-10)
  // call to sort
  hybridSort(sortMe, size, mag, base);
  // print values
  for(int i = 0; i < size; i++)
    std::cout << std::setfill('0') << std::setw(mag) << sortMe[i] << std::endl;
  return 0;
}

void hybridSort(std::vector<int> &A, int size, int mag, int base){
  std::vector<std::vector<int> > bucket(base);
  //power of 10s array, for getting the ith digit
  int *intPow10 = new int[mag];
  for(int i = 0; i < mag; i++){
    int temp = 1;
    for(int j = 0; j < i; j++)
      temp *= 10;
    intPow10[i] = temp;
  }
  // in a for loop, traverse A, putting each element in the correct vector,
  for(int i = 0; i < mag; i++){
    for(int j = 0; j < size; j++)
      bucket[(A[j]/intPow10[i]) % base].push_back(A[j]);
    // clear A
    A.clear();
    // return all elements to A, overwriting A, and clearing bucket[j]
    for(int j = 0; j < base; j++){
      int bucketSize = bucket[j].size();
      for(int k = 0; k < bucketSize; k++)
	A.push_back(bucket[j][k]);
      bucket[j].clear();
    }  
  }
  // start the for loop again for % n*10, until 
  delete [] intPow10;
}
