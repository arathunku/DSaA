#include <iostream>
#include <string.h>

using namespace std;
//14:37
// TODO
struct Element{
  int key;
  Element *previous;
  Element *next;
};
// Two-way unordered cycled list
struct List2W{
  // TODO
  Element *head;
  Element *tail;
};

void wypisz(string s){
   //cout <<".\t"<< s << endl;
}
void init(List2W& l){
  l.head = NULL;
  l.tail = NULL;
}

void insertHead(List2W& l, int x){
  Element *e = new Element();
  e -> key = x;
  if(l.head == NULL){
    l.head = e;
    l.tail = e;
    l.head -> previous = e;
    l.head -> next = e;
    l.tail -> previous = e;
  } else {
    l.head -> previous = e;
    l.tail -> next = e;
    e -> next = l.head;
    e -> previous = l.tail;
    l.head = e;
  }
}

int deleteHead(List2W& l){
  // TODO
  if(l.head != NULL) {
    Element *p = l.head;
    if(l.head != l.tail) {
      l.head = l.head -> next;
      l.head -> previous = l.tail;
      l.tail -> next = l.head;
    } else {
      init(l);
      delete l.tail;
    }
    int value = p -> key;
    delete p;
    return value;
  }
  return -9999;
}

void insertTail(List2W& l, int x){
  if(l.head == NULL) {
    insertHead(l, x);
    return;
  }
  Element *e = new Element();
  e -> key = x;
  e -> next = l.head;
  e -> previous = l.tail;
  l.tail -> next = e;
  l.head -> previous = e;
  l.tail = e;
}

int deleteTail(List2W& l){
  if(l.tail != NULL) {
    if(l.tail == l.head) return deleteHead(l);
    Element *p = l.tail;
    l.tail = l.tail -> previous;
    l.tail -> next = l.head;
    l.head -> previous = l.tail;
    int value = p -> key;
    delete p;
    return value;
  }
  return -9999;
}

int findValue(List2W& l, int value){
  Element *e = l.head;
  if(e != NULL){
    int pos=0;
    if(e->key == value) return pos;
    e = e -> next;
    pos++;
    while(e != l.head) {
      if(e->key == value) return pos;
      e = e->next;
      pos++;
    }
  }
  return -1;
}

void removeAllValue(List2W& l, int value){
  if(l.head != NULL) {
    Element *p = l.head->next;
    while(p != l.tail && p != NULL){
      Element *temp = p;
      p = p->next;
      if(temp->key == value){
          temp -> previous -> next = temp -> next;
          temp -> next -> previous = temp -> previous;
          delete temp;
      }
    }
    if(l.tail != NULL) if(value == l.tail->key) {deleteTail(l);}
    if(l.head != NULL) if(value == l.head->key) {deleteHead(l);}
  }
}

void showListFromHead(List2W& l){
  if(l.head == NULL){
    cout << "\n";
  } else {
    Element *e = l.head;
    cout << e->key;
    e = e -> next;
    while(e != l.head){
      cout << " " << e->key;
      e = e -> next;
    }
    cout << "\n";
  }
}

void showListFromTail(List2W& l){
  if(l.tail == NULL){
    cout << "\n";
  } else {
    Element *e = l.tail;
    cout << e->key;
    e = e -> previous;
    while(e != l.tail){
      cout << " " << e->key;
      e = e -> previous;
    }
    cout << "\n";
  }
}

void clearList(List2W& l){
  Element *e = l.head;
  while(e != l.tail) {
    e = l.head -> next;
    delete l.head;
    l.head = e;
  }
  if(e == l.tail) {delete e;}
  init(l);
}

void addList(List2W& l1,List2W& l2) {
  if((l1.head == NULL) && (l2.head ==NULL)) {return;}
  if(l2.head == NULL) {return;}
  if(l1.head == NULL) {
    l1.head = l2.head;
    l1.tail = l2.tail;
    init(l2);
    return;
  }
  if(l1.head != l2.head) {
    l2.head -> previous = l1.tail;
    l1.tail -> next = l2.head;
    l1.tail = l2.tail;
    l2.tail -> next = l1.head;
    l1.head -> previous = l1.tail;
    init(l2);
  }
}

void showBool(bool val){
  if(val)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}

int main(){
  const int commandSize=2;
  const int MAXLINE=100;
  char line[MAXLINE]; 
  char command[commandSize+1]; // for '\0'
  List2W *list;
  int currentL=0;
  int value;
  command[commandSize]='\0';
  while(true){
    cin >> command[0];
    if(command[0]=='#')
    {
      cin.getline(line, MAXLINE);
      continue;
    }
    cin >> command[1];

    if(strcmp(command,"HA")==0){
      cout << "END OF EXECUTION" << endl;
      break;
    }
    // zero-argument command
    if(strcmp(command,"DH")==0)
    {
      int value=deleteHead(list[currentL]);
      cout << value << endl;
      continue;
    }
    if(strcmp(command,"DT")==0)
    {
      int value=deleteTail(list[currentL]);
      cout << value << endl;
      continue;
    }

    if(strcmp(command,"ST")==0)
    {
      showListFromTail(list[currentL]);
      continue;
    }

    if(strcmp(command,"SH")==0)
    {
      showListFromHead(list[currentL]);
      continue;
    }

    if(strcmp(command,"CL")==0)
    {
      clearList(list[currentL]);
      continue;
    }

    if(strcmp(command,"IN")==0)
    {
      init(list[currentL]);
      continue;
    }

    // read next argument, one int value
    cin >> value;
    
    if(strcmp(command,"FV")==0)
    {
      int ret;
      ret=findValue(list[currentL],value);
      cout << ret << endl;
      continue;
    }

    if(strcmp(command,"RV")==0)
    {
      removeAllValue(list[currentL],value);
      continue;
    }


    if(strcmp(command,"CH")==0)
    {
      currentL=value;
      continue;
    }

    if(strcmp(command,"IH")==0)
    {
      insertHead(list[currentL],value);
      continue;
    }

    if(strcmp(command,"IT")==0)
    {
      insertTail(list[currentL],value);
      continue;
    }

    if(strcmp(command,"GO")==0)
    {
      list=new List2W[value];
      continue;
    }

    if(strcmp(command,"AD")==0)
    {
      addList(list[currentL],list[value]);
      continue;
    }
    cout << "wrong argument in test: " << command << endl;
    return 1;
  }
}
