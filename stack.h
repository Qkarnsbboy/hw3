#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <string>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
private:
    std::vector<T> myVec_;
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

};

//constructor
template <typename T>
Stack<T>::Stack(){

}

//destructor
template <typename T>
Stack<T>::~Stack(){
    //loop through and pop_back
    // typename std::vector<T>::iterator it;
    // for(it = myVec_.begin(); it != myVec_.end(); ++it){
    //     myVec_.pop_back();
    // }

}

//isEmpty
template <typename T>
bool Stack<T>::empty() const {
    return myVec_.empty();
}

//size
template <typename T>
size_t Stack<T>::size() const {
    return myVec_.size();
}

//push
template <typename T>
void Stack<T>::push(const T& item) {
    myVec_.push_back(item);
    return;
}

//pop
template <typename T>
void Stack<T>::pop() {
    //throw std::underflow_error if empty

    //check if empty
    if(myVec_.empty()){
        throw std::underflow_error("empty list!");
        return;
    }

    myVec_.pop_back();
    return;
}

//top
template <typename T>
const T& Stack<T>::top() const {
    //throw std::underflow_error if empty
    //check if empty
    if(myVec_.empty()){
        throw std::underflow_error("empty list!");
    }

    return myVec_.back();

}





#endif