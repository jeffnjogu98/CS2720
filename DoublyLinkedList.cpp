#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
} //constructor

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeType<T> *node;
  while(head != nullptr){
    node = head;
    head = head->next;
    free(node);
  }
  tail = nullptr;
  head = nullptr;
}

template <class T>
void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T> *node = new NodeType<T>;
  node->data = item;

  if (head == nullptr) {
    node->next = head;
    head->back = node;
    head = node;
    return;
  }

  if (item < head->data) {
    node->next = head;
    head = node;
    return;
  }

  if (item >= tail->data) {
    node->back = tail;
    tail->next = node;
    tail = node;
    return;
  }

  NodeType<T> *temp = head;
  while (temp && (item >= temp->data)) {
    temp = temp->next;
  }
  if (temp) {
    node->next = temp;
    node->back = temp->back;
    temp->back->next = node;
    temp->back = node;
    return;
  }
    
}

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T> *node = head;
  while(node != nullptr) {
    if(node->data == item) {
      break;
    }
    node = node->next;
  }
  if(node!= nullptr) {
    cout << "Item deleted!" << endl;
    if(node->next == nullptr && node->back == nullptr){
      free(node);
      head = nullptr;
      tail = nullptr;
    }
    else if(node->back == nullptr){
      head = head->next;
      head->back = nullptr;
      free(node);
    }
    else if(node->next== nullptr){
      tail = tail->back;
      tail->next= nullptr;
      free(node);
    }
    else{
      NodeType<T> *a;
      NodeType<T> *b;
      a = node->back;
      b = node->next;
      a->next = b;
      b->back = a;
      free(node);
    }
    cout << "Item " << item << " deleted!" << endl;
  }
  else{
    cout << "Item is not in the list" << endl;
  }
}

template <class T>
int DoublyLinkedList<T>::lengthIs() const {
  int length = 0;
  NodeType<T> *node = head;
  while(node != nullptr) {
    length++;
    node = node -> next;
  }
  return length;
}

template <class T>
void DoublyLinkedList<T>::print() {
  if (head == nullptr)
    cout << "The List is empty!" << endl;
  else {
    NodeType<T> *node = head;
    while(node != nullptr) {
      cout << node -> data << " ";
      node = node -> next;
    }
  }
}

template <class T>
void DoublyLinkedList<T>::printReverse() {
  if (tail == nullptr)
    cout << "The List is empty!" << endl;
  else {
    NodeType<T> *node = tail;
    while(node != nullptr) {
      cout << node -> data << " ";
      node = node -> back;
    }
  }

}

/**
template <class T>
void DoublyLinkedList<T>::deleteSubsection() {
  int lower;
  int upper;
  std::cout << "Enter lower bound: ";
  std::cin >> lower;
  std::cout << "Enter upper bound: ";
  std::cin >> upper;
  std::cout << "Original List: ";
  print();


  NodeType<T> *temp = head;
  while (temp != nullptr) {
    if (temp->next != nullptr) {
      std::cout << temp->data << " ";
    } else {
      std::cout << temp->data;
    }
    T value = atoi(temp->data);
    if (value <= lower || value >= upper) {
      deleteItem(temp->data);
    }
    temp = temp->next;
  }
  std::cout << std::endl;
}
*/

template <class T>
T DoublyLinkedList<T>::mode() {
  int a = 0;
  int b = 0;
  T mode = 0;
  if(head == nullptr){
    return mode;
  }
  NodeType<T> *node = head->next;
  mode = head->data;
  T last = head->data;
  a = 1;
  b = 1;
  while(node!= nullptr){
    if(node->data == node->back->data){
      b++;
    }
    else{
      if(b > a){
	a = b;
	b = 1;
	mode = last;
      }
    }
    last = node->data;
    node = node->next;
  }

  return mode;
}

template <class T>
void DoublyLinkedList<T>::swapAlternate() {
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  NodeType<T> *newHead = head->next, *temp;
  NodeType<T> **cur = &head;

  while (*cur && (*cur)->next) {
    temp = (*cur)->next;
    (*cur)->next = (*cur)->next->next;
    temp->next = *cur;
    *cur = temp;
    cur = &((*cur)->next->next);
  }

  head = newHead;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
