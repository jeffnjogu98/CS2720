#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T> struct
NodeType {
  T data;
  NodeType<T> *next;
  NodeType<T> *back;
};

template<class T>
class DoublyLinkedList {

 private:
  NodeType<T> *head;
  NodeType<T> *tail;

 public:
  /**
   * Constructor that builds the list
   */
  DoublyLinkedList();

  /**
   * Deconstructor that frees up the list making it empty
   */
  ~DoublyLinkedList();

  /**
   * Inserts an Item in the list
   */
  void insertItem(T &item);

  /**
   * Deletes an item in the list
   */
  void deleteItem(T &item);

  /**
   * Returns the length of the list
   */
  int lengthIs() const;

  /**
   * Prints the elements in the list from head to tail
   */
  void print();

  /**
   * Prints the elements in the list from tail to head
   */
  void printReverse();

  /**
   * Deletes a portion of the list
   */
  void deleteSubsection();

  /**
   * 
   */
  T mode();

  /**
   * Swaps elements in the list
   */
  void swapAlternate();
  
};

#endif
