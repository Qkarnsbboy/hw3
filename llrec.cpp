#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    //1. base case --> list is empty
    if(head == nullptr){
        larger = nullptr;
        smaller = nullptr;
        return;
    }

    //2. iterate through to the end (tail recursion)
    llpivot(head->next, smaller, larger, pivot);

    //3. value is greater
    if(head->val > pivot){
        //check if larger is an empty list
        if(larger == nullptr){
            //set current node as head of larger
            larger = head;
        }
        else {
            head->next = larger; //set current node's next to point to previous larger
            larger = head; //set new node as head of larger
        }
    }
    else { //4. value is smaller
        //empty smaller list
        if(smaller == nullptr){
            //set current node as head of smaller
            smaller = head;
        }
        else{
            head->next = smaller; //current node's next to previous smaller
            smaller = head; //set current node as head of smaller
        }
        
    }

    //at end of recusion set head to nullptr
    head = nullptr;
}

