#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
  //  DoublyLinkedList<int> *int = new DoublyLinkedList<int>();
  //  DoublyLinkedList<string> *int = new DoublyLinkedList<string>();
  //  DoublyLinkedList<float> *int = new DoublyLinkedList<float>();

  bool quit = false;

  while(!quit) {
    cout << "Enter list type (i - int, f - float, s - std::string): ";
    char a;
    cin >> a;
    if (a == 'i') {
      DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
    }

    else if (a == 'f') {
      DoublyLinkedList<float> *list = new DoublyLinkedList<float>();
    }

    else if (a == 's') {
      DoublyLinkedList<string> *list = new DoublyLinkedList<string>();
    }
    
    cout << "insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)" << endl;
    cout <<"Enter a command: ";
    char c;
    cin >> c;
    switch(c) {
      
    case 'i': {
      cout << "Item to insert: ";
      int a;
      cin >> a;
      list->insertItem(a);
      cout << "Modified List : ";
      list->print();
    }
      break;

    case 'd': {
      cout << "Item to delete:";
      int b;
      cin >> b;
      list->deleteItem(b);
      cout << "Modified List : ";
      list->print();
    }
      break;

    case 'l': {
      int length = list->lengthIs();
      cout << "The length is : " << length << endl;
    }
      break;

    case 'p': {
      list->print();
    }
      break;

      /**
	 case 'b':{
	 cout << "Enter lower bound:";
	 int b;
	 cin >> b;
	 cout << "Enter upper bound:";
	 int a;
	 cin >> a;
	 list->deleteSubsection();
	 cout<<"Modified List : ";
	 list->print();
	 }
	 break;
      */

	 case 'm': {
	 int mode = list->mode();
	 cout << "Mode is : " << mode << endl;
	 }
	   break;

    case 'r': {
      list->printReverse();

    }
      break;

    case 's': {
      list->swapAlternate();
      cout << "Modified List : ";
      list->print();
    }
      break;

    case 'q': {
      cout << "Quitting program..." << endl;
      quit = true;
    }
      break;

    default: {
      cout << "Command not found!" << endl;
    }
    }
    cout << endl;
  }
}
