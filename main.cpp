#include <iostream>
#include <fstream>
#include <cstdlib>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  bool Uint = false;
  bool Ufloat = false;
  bool Ustring = false;
  
  DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
  DoublyLinkedList<string> *list2 = new DoublyLinkedList<string>();
  DoublyLinkedList<float> *list3 = new DoublyLinkedList<float>();

  /**  std::ifstream fin( argv[3]);
  int number;
  float decimal;
  string word;
  while (fin >> number) {
    list->insertItem(number);
  }
  while (fin >> number) {
    list2->insertItem(word);
  }
  while (fin >> number) {
    list3->insertItem(decimal);
  }
  */
  
  bool quit = false;

  bool prompt = false;
  while(!prompt) {
  cout << "Enter list type (i - int, f - float, s - std::string): ";
    char a;
    cin >> a;
    if (a == 'i') {
      Uint = true;
      prompt = true;
      std::ifstream fin( argv[3]);
      int number;
      while (fin >> number) {
	list->insertItem(number);
      }
    }

    else if (a == 'f') {
      Ufloat = true;
      prompt = true;
    }

    else if (a == 's') {
      Ustring = true;
      prompt = true;
    }
    else {
      cout << "command not found!" << endl;
    }
  }
  while(!quit) {
    cout << "insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)" << endl;
    cout <<"Enter a command: ";
    char c;
    cin >> c;
    switch(c) {
      
    case 'i': {
      cout << "Item to insert: ";
      if (Uint) {
	int a;
	cin >> a;
	list->insertItem(a);
	cout << "Modified List : ";
	list->print();

      }
      if (Ufloat) {
	float b;
        cin >> b;
        list3->insertItem(b);
	cout << "Modified List : ";
	list3->print();
      }
      if (Ustring) {
	string c;
        cin >> c;
        list2->insertItem(c);
	cout << "Modified List : ";
	list2->print();
      }
    }
      break;

    case 'd': {
      cout << "Item to delete:";
      if (Uint) {
	int b;
	cin >> b;
	list->deleteItem(b);
	cout << "Modified List : ";
	list->print();
      }
      if (Ufloat) {
	float a;
	cin >> a;
	list3->deleteItem(a);
	cout << "Modified List : ";
	list3->print();
      }
      if (Ustring) {
	string c;
	cin >> c;
	list2->deleteItem(c);
	cout << "Modified List : ";
	list2->print();
      }
    }
      break;

    case 'l': {
      if (Uint) {
	int length = list->lengthIs();
	cout << "The length is : " << length << endl;
      }
      if (Ufloat) {
	int length = list3->lengthIs();
	cout << "The length is : " << length << endl;
      }
      if (Ustring) {
	int length = list2->lengthIs();
	cout << "The length is : " << length << endl;
      }
      
    }
      break;

    case 'p': {
      if (Uint) {
	list->print();
      }
      if (Ufloat) {
	list3->print();
      }
      if (Ustring) {
	list2->print();
      }
    }
      break;

    case 'b':{
      if (Uint) {
	cout << "Enter lower bound:";
	int b;
	cin >> b;
	cout << "Enter upper bound:";
	int a;
	cin >> a;
	list->deleteSubsection(b, a);
	cout<<"Modified List : ";
	list->print();
      }
      if (Ufloat) {
	cout << "Enter lower bound:";
	float a;
	cin >> a;
	cout << "Enter upper bound:";
	float b;
	cin >> b;
	list3->deleteSubsection(a, b);
	cout<<"Modified List : ";
	list3->print();
      }
      if (Ustring) {
	cout << "Enter lower bound:";
	string c;
	cin >> c;
	cout << "Enter upper bound:";
	string d;
	cin >> d;
	list2->deleteSubsection(c, d);
	cout<<"Modified List : ";
	list2->print();
      }
    }
      break;

    case 'm': {
      if (Uint) {
	int mode = list->mode();
	cout << "Mode is : " << mode << endl;
      }
      if (Ufloat) {
	float mode = list3->mode();
	cout << "Mode is : " << mode << endl;
      }
      if (Ustring) {
	string mode = list2->mode();
	cout << "Mode is : " << mode << endl;
      }
    }
      break;

    case 'r': {
      if (Uint) {
	list->printReverse();
      }
      if (Ufloat) {
	list3->printReverse();
      }
      if (Ustring) {
	list2->printReverse();
      }

    }
      break;

    case 's': {
      if (Uint) {
	list->swapAlternate();
	cout << "Modified List : ";
	list->print();
      }
      if (Ufloat) {
	list3->swapAlternate();
	cout << "Modified List : ";
	list3->print();
      }
      if (Ustring) {
	list2->swapAlternate();
	cout << "Modified List : ";
	list2->print();
      }
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
    fin.close();
  }
}
