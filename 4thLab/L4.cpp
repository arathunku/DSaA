#include <iostream>
#include <string.h>

using namespace std;

struct Element{
  int key;
  int value;
};

struct ElementLL{
  Element elem;
  ElementLL *next, *prev;
};
//14:27
// Two-way ordered cycled list with sentinel
struct List2W{
  ElementLL *sentinel;
};

void init(List2W& l){
  l.sentinel = new ElementLL();
  l.sentinel -> next = l.sentinel;
  l.sentinel -> prev = l.sentinel;
}

void insertElem(List2W & l, Element elem){
  ElementLL *e = new ElementLL();
  e -> elem = elem;
  ElementLL *i = l.sentinel;
  while(i->prev->elem.key > e->elem.key && i->prev != l.sentinel) {
    i = i->prev;
  }
  i->prev -> next = e;
  e -> next = i;
  e -> prev = i->prev;
  i -> prev = e;
}

bool findKey(List2W & l,int key, Element &elem){
  if(l.sentinel -> next == l.sentinel) return false;
  ElementLL *e = l.sentinel->next;
  while(e != l.sentinel){
    if(e->elem.key == key){
      elem = e->elem;
      return true;
    }
    e = e->next;
  }
  return false;
}

void removeAllKeys(List2W& l, int key){
  if(l.sentinel -> next == l.sentinel) return;
  ElementLL *e = l.sentinel-> next;
  while(e != l.sentinel){
    if(e->elem.key == key){
      e->prev -> next = e->next;
      e->next -> prev = e->prev;
      ElementLL *tmp = e;
      e = e->next;
      delete tmp;
    } else {
      e = e->next;
    }
  }
}

void showListFromHead(List2W& l){
  for(ElementLL *p = l.sentinel->next; p != l.sentinel; p = p->next){
    cout << p->elem.key << "(" << p->elem.value << "),";
  }
  cout << endl;

}

void showListFromTail(List2W& l){
  for(ElementLL *p = l.sentinel->prev; p != l.sentinel; p = p->prev){
    cout << p->elem.key << "(" << p->elem.value << "),";
  }
  cout << endl;
}

void clearList(List2W& l){
  for(ElementLL *tmp = l.sentinel->next; tmp != l.sentinel; tmp=l.sentinel->next){
    l.sentinel->next = l.sentinel->next->next;
    delete tmp;
  }
  init(l);
}

void addList(List2W& l1,List2W& l2){
  if(l1.sentinel -> next == l1.sentinel && l2.sentinel == l2.sentinel->next) return;
  if(l2.sentinel->next == l2.sentinel) return;
  if(l1.sentinel == l2.sentinel) return;
  if(l1.sentinel->next == l1.sentinel){
    ElementLL *e = l2.sentinel->next;
    while(e != l2.sentinel) {
      insertElem(l1, e->elem);
      e = e->next;
    }
    return;
  }
  ElementLL *e = l2.sentinel -> next;
  ElementLL *i = l1.sentinel;
  while(e != l2.sentinel){
    ElementLL *p = new ElementLL();
    p -> elem = e->elem;
    while(i->next->elem.key <= p->elem.key && i->next != l1.sentinel) {
      i = i->next;
    }
    p -> prev = i;
    p -> next = i->next;
    p -> next -> prev = i;
    i -> next = p;
    e=e->next;
  }
  clearList(l2);
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
    
    if(strcmp(command,"FK")==0)
    {
      Element elem;
      bool ret=findKey(list[currentL], value, elem);
      if(ret)
        cout << elem.key << ')' << elem.value << ')' << endl;
      else
        cout << "false" << endl;
      continue;
    }

    if(strcmp(command,"RK")==0)
    {
      removeAllKeys(list[currentL],value);
      continue;
    }


    if(strcmp(command,"CH")==0)
    {
      currentL=value;
      continue;
    }

    if(strcmp(command,"IE")==0)
    {
      int variable2;
      cin >> variable2;
      Element elem;
      elem.key=value;
      elem.value=variable2;
      insertElem(list[currentL],elem);
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
