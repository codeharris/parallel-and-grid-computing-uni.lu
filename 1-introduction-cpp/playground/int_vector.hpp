#include <iostream>
#include <vector>


class IntVector {
  /* The number of elements currently in the array (as stored by the user). */
  size_t n;
  /* The capacity of the vector, which is the size of `values`. */
  size_t cap;
  int* values;

public:

  /* Default constructor */

  IntVector(): n(0), cap(0), values(nullptr){
    std::cout << "Default constructor called" << std::endl;
  }


  /* Copy constructor */

  IntVector(const IntVector& other): n(other.n), cap(other.cap), values(other.values) {
    
    std::cout << "Copy constructor called" << std::endl;
  }



  /* Destructor */

  /* allocate an array of size `n` filled with 0. */
  IntVector(size_t n): n(n), cap(n) {
    values = new int[cap]();

  };

//return current capacity
  size_t capacity() const{
    return cap;
  };

//return current size
  size_t size() const{
    return n;  
  };

  void resize(size_t n){

  };



  void reserve(size_t n);

  /* Add the value `v` at the back of the vector, reallocating if necessary. */
  void push_back(int v);

  /* Remove the last element of the array.
     Precondition: `size() != 0`. */
  void pop_back();

  int& back();
  const int& back() const;

  int& front();
  const int& front() const;

  int& operator[](size_t i);
  const int& operator[](size_t i) const;
};
