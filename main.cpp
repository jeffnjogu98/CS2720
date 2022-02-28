#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
  //  DoublyLinkedList<int> *int = new DoublyLinkedList<int>();
  //  DoublyLinkedList<string> *int = new DoublyLinkedList<string>();
  //  DoublyLinkedList<float> *int = new DoublyLinkedList<float>();

  DoublyLinkedList<int> *dll = new DoublyLinkedList<int>();

  bool quit = false;

  while(!quit){
    cout<<"insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)"<<endl;
    cout<<"Enter a command:";
    char c;
    cin>>c;
    switch(c){
    case 'i':{
      cout<<"Item to insert:";
      int d;
      cin>>d;
      dll->insertItem(d);
      cout<<"Modified List : ";
      dll->print();
    }break;

    case 'd':{
      cout<<"Item to delete:";
      int d;
      cin>>d;
      dll->deleteItem(d);
      cout<<"Modified List : ";
      dll->print();
    }break;

    case 'l':{
      int l = dll->lengthIs();
      cout<<"The length is : "<<l<<endl;
    }break;

    case 'p':{
      dll->print();
    }break;

    case 'b':{
      cout<<"Enter lower bound:";
      int l;
      cin>>l;
      cout<<"Enter upper bound:";
      int u;
      cin>>u;
      dll->deleteSubsection();
      cout<<"Modified List : ";
      dll->print();
    }break;

    case 'm':{
      int mod = dll->mode();
      cout<<"Mode is : "<<mod<<endl;
    }break;

    case 'r':{
      dll->printReverse();

    }break;

    case 's':{
      dll->swapAlternate();
      cout<<"Modified List : ";
      dll->print();
    }break;

    case 'q':{
      cout<<"Quitting program..."<<endl;
      quit = true;
    }break;

    default:{
      cout<<"Command not found!"<<endl;
    }
    }
    cout<<endl;
  }
}
