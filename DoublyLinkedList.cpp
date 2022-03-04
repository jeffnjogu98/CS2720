#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
} //constructor

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeType<T> *node;
  while (head != nullptr) {
    node = head;
    head = head->next;
    free(node);
  }
  tail = nullptr;
  head = nullptr;
} //deconstructor

template<class T>
void DoublyLinkedList<T>::insertItem(T &item) {
  NodeType<T> *tempNode = new NodeType<T>;
  tempNode->data = item;
  tempNode->next = nullptr;
  tempNode->back = nullptr;
  if (head == nullptr) {
    head = tempNode;
    tail = tempNode;
    return;
  }
  if (item < head->data) {
    tempNode->next = head;
    head->back = tempNode;
    head = tempNode;
    return;
  }
  if (item >= tail->data) {
    tail->next = tempNode;
    tempNode->back = tail;
    tail = tempNode;
    return;
  }
  NodeType<T> *t = head;
  while (t != nullptr && t->data < item) {
    t = t->next;
  }
  NodeType<T> *p = t->back;
  p->next = tempNode;
  tempNode->back = p;
  tempNode->next = t;
  t->back = tempNode;
} //insertItem

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) {
  NodeType<T> *node = head;
  while (node != nullptr) {
    if (node->data == item) {
      break;
    }
    node = node->next;
  }
  if (node != nullptr) {
    cout << "Item deleted!" << endl;
    if (node->next == nullptr && node->back == nullptr) {
      free(node);
      head = nullptr;
      tail = nullptr;
    } else if (node->back == nullptr) {
      head = head->next;
      head->back = nullptr;
      free(node);
    } else if (node->next == nullptr) {
      tail = tail->back;
      tail->next = nullptr;
      free(node);
    } else {
      NodeType<T> *a;
      NodeType<T> *b;
      a = node->back;
      b = node->next;
      a->next = b;
      b->back = a;
      free(node);
    }
    cout << "Item " << item << " deleted!" << endl;
  } else {
    cout << "Item is not in the list" << endl;
  }
} //DeleteItem


template<class T>
int DoublyLinkedList<T>::lengthIs() const {
  int length = 0;
  NodeType<T> *node = head;
  while (node != nullptr) {
    length++;
    node = node->next;
  }
  return length;
} //length

template<class T>
void DoublyLinkedList<T>::print() {
  if (head == nullptr)
    cout << "The List is empty!" << endl;
  else {
    NodeType<T> *node = head;
    while (node != nullptr) {
      cout << node->data << " ";
      node = node->next;
    }
  }
} //print

template<class T>
void DoublyLinkedList<T>::printReverse() {
  if (tail == nullptr)
    cout << "The List is empty!" << endl;
  else {
    NodeType<T> *node = tail;
    while (node != nullptr) {
      cout << node->data << " ";
      node = node->back;
    }
  }

} //printReverse

template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &lower, T &upper) {
  NodeType<T> *tempNode;
  if (head == NULL) {
    return;
  }
  if (head->data > upper) {
    return;
  }
  if (tail->data < lower) {
    return;
  }
  tempNode = head;
  while (tempNode != NULL && tempNode->data < lower) {
    tempNode = tempNode->next;
  }
  if (tempNode != NULL) {
    if (tempNode->back == NULL && tempNode->next == NULL) {
      head = NULL;
      tail = NULL;
      free(tempNode);
      return;
    } else if (tempNode->back == NULL) {
      head = head->next;
      head->back = NULL;
      free(tempNode);
      deleteSubsection(lower, upper);
      return;
    } else if (tempNode->next == NULL) {
      tail = tail->back;
      tail->next = NULL;
      free(tempNode);
      return;
    } else {
      NodeType<T> *p = tail;
      while (p != NULL && p->data > upper) {
	p = p->back;
      }
      if (p->next == tempNode) {
	return;
      } else {
	tempNode->back->next = p->next;
	if (p->next != NULL) {
	  p->next->back = tempNode->back;
	}
	NodeType<T> *t;
	while (tempNode != p) {
	  t = tempNode;
	  tempNode = tempNode->next;
	  free(t);
	}
	free(tempNode);
      }
      return;
    }
  }
} //DeleteSubselection

template<class T>
T DoublyLinkedList<T>::mode() {
  int a = 0;
  int b = 0;
  T mode = 0;
  if (head == nullptr) {
    return mode;
  }
  NodeType<T> *node = head->next;
  mode = head->data;
  T last = head->data;
  a = 1;
  b = 1;
  while (node != nullptr) {
    if (node->data == node->back->data) {
      b++;
    } else {
      if (b > a) {
	a = b;
	b = 1;
	mode = last;
      }
    }
    last = node->data;
    node = node->next;
  }

  return mode;
} //Mode

template<class T>
void DoublyLinkedList<T>::swapAlternate() {
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  NodeType<T> *tempHead = head->next, *temp;
  NodeType<T> **current = &head;

  while (*current && (*current)->next) {
    temp = (*current)->next;
    (*current)->next = (*current)->next->next;
    temp->next = *current;
    *current = temp;
    current = &((*current)->next->next);
  }

  head = tempHead;
} //swapAlternate

template
class DoublyLinkedList<int>;

template
class DoublyLinkedList<float>;

template
class DoublyLinkedList<std::string>;
