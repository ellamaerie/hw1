#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){ // add to back
  // pushing to the front or back should NOT require moving any values.
  // when pushing to the front, only allocate a new Item if the current head Item
  // has no room before the first Item

  if (tail_ == nullptr){ // empty list
    tail_ = new Item();
    head_=tail_;
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
  }

  else if (tail_->last == ARRSIZE){ // full list
    Item* Node = new Item; 
    Node->val[0] = val;
    Node->last = 1; // [0,1] range
    Node->first = 0;
    Node->prev = tail_;
    tail_->next = Node;
    tail_ = Node;
  }
  
  else { // when there is space in the node list
    tail_->val[tail_->last] = val;
    tail_->last = tail_->last + 1; // update to whatever tail_'s last + 1;
  }
  size_ = size_ + 1;

}

void ULListStr::pop_back(){ // remove from back
  // deallocate an Item when the number of used values in its array reaches 0
  // there should not be "empty" nodes in the list... when no more array entries
  // of an Item are used, deallocate the Item

  tail_->last = tail_->last - 1;
  size_ = size_ - 1;

  if(tail_ ->first == tail_->last){
    Item* prev_tail = tail_;

    if(tail_->prev != nullptr){
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }
  else {
    head_ = nullptr;
    tail_ = nullptr;
  }
  delete prev_tail;
  }
}

void ULListStr::push_front(const std::string& val){

  if (empty()){ // checking if list is empty
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE -1;
    head_->last = ARRSIZE;
    head_->val [head_->first] = val;

  }
  else if (0 < head_->first){ // there is space
    head_->first = head_->first - 1;
    head_->val[head_->first] = val;
  }

  else { // currently no space avail in the front
    Item* Node = new Item();
    Node->first = ARRSIZE -1;
    Node->last = ARRSIZE;
    Node->val [Node->first] = val;
    Node->next = head_;
    head_->prev = Node;
    head_ = Node;
  }
  size_ = size_ + 1;
}

void ULListStr::pop_front(){
  head_->first = head_->first + 1;
  size_ = size_ - 1;

  if (head_->last == head_ ->first){
    Item* prev_head = head_;
      if (head_->next != nullptr){
        head_ = head_->next;
        head_->prev = nullptr; // because removing element --> must point to null
      }
      else {
        head_ = nullptr; 
        tail_ = nullptr;
      }
    delete prev_head;
  }
}

std::string const & ULListStr::back() const{
  return tail_ -> val [tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_ -> val [head_->first];
}

// O(n) runtime because traversering multiple nodes
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (size_ <= loc){

    return nullptr;
  }
  size_t offset = loc;
  Item* temp = head_;

  while (temp != nullptr){ // traverse until we find the loc. element
    size_t element_size = temp->last - temp->first;

    if (offset < element_size){

      return &temp ->val [temp->first + offset];
    }

    offset = offset - element_size;
    temp = temp->next;
  }
  return nullptr;
}

/*
void ULListStr::push_back(const std::string& val)
void ULListStr::pop_back()
void ULListStr::push_front(const std::string& val);
void ULListStr::pop_front();
std::string const & ULListStr::back() const;
std::string const & ULListStr::front() const;
std::string* getValAtLoc(size_t loc) const;
*/


// end of implemented code

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
