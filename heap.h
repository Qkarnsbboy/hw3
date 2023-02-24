#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  //heapify
  void heapify(int idx);

private:
  /// Add whatever helper functions and data members you need below

  //container
  std::vector<T> container;
  //aryness
  int m;
  //functor
  PComparator c;


};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  //store aryness
  this->m = m;

  //store Comparator
  this->c = c;
}

//destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return container[0];


}

//push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  //1. add to back of container
  container.push_back(item);

  //2. get size of container
  std::size_t index = container.size()-1;

  //3. trickle up
  while(index != 0){
    std::size_t parent_index = (index-1)/m;

    T& current = container[index];
    T& parent = container[parent_index];

    //use comparator to check if parent is "better" than current --> if true (skip)
    if(c(parent, current)){
      break;
    }
    //else swap parent and current
    std::swap(current, parent);
    //switch parent and current indexes
    index = parent_index;
  }

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //0. check if empty
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }

  //1. switch front and back
  container[0] = container[container.size()-1];

  //2. pop the back
  container.pop_back();

  //3. call heapify on top
  heapify(0);

}

//heapify
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx){
  ////unsigned int leftchild = (m*idx)+1;
  //1. exit case --> made it to leaf node
  /*
  if((unsigned)idx >= container.size()/m){
    return;
  }
  //int rightchild = std::min(m*idx+m, (int)container.size()-1);
  int child = (m*idx) + 1; //first child
  //2. get best child
  for(int i = 0; i < m; i++){
    int currentChild = (m*idx) + i+1;

    //if new child is "better" aka comparator returns true
    if(c(container[currentChild], container[child])){
      //make new child the best child
      child = currentChild;
    }
  }

  //3. if better than parent --> swap
  if(c(container[child], container[idx])){
    std::swap(container[idx],container[child]);
    //call recursive function to keep trickling down
    heapify(child);
  }
} */
unsigned int leftchild = (m*idx)+1;
  unsigned int best = leftchild;
  //1. exit case --> made it to leaf node
  if((unsigned)leftchild >= container.size()){
    return;
  }
  unsigned int rightchild = std::min(m*idx+m, (int)container.size()-1);

  int child = (m*idx) + 1; //first child
  //2. get best child
  for(unsigned int i = leftchild+1; i <= rightchild; i++){
    //int currentChild = (m*idx) + i+1;

    //if new child is "better" aka comparator returns true
    if(c(container[i], container[best])){
      //make new child the best child
      best = i;
    }
  }

  //3. if better than parent --> swap
  if(c(container[best], container[idx])){
    std::swap(container[idx],container[best]);
    //call recursive function to keep trickling down
    heapify(best);
  }
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return container.size();
}

//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return container.empty();
}


#endif

