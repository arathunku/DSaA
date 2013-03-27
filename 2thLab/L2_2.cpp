#include <iostream>
#include <string.h>

using namespace std;

struct Element{
  int key;
  Element *next;
};

struct List{
	Element *head;
  Element *tail;
};

void init(List& l){
  l.head = NULL;
  l.tail = NULL;
}

void insertHead(List& l, int x){
  Element *e = new Element();
  e -> key = x;
  if(l.head == NULL) {
    l.head = e;
    l.tail = l.head;
  } else {
    e->next = l.head;
    l.head = e;
  }
}

void deleteHead(List& l){
  if(l.head != NULL){
    Element *e = l.head;
    l.head = l.head -> next;
    if(e == l.tail) {
      l.tail = NULL;
    }
    delete e;
  }
}

void insertTail(List& l, int x){
  if(l.head == NULL){
    insertHead(l,x);
  } else {
    Element *e = new Element();
    e-> key = x;
    l.tail -> next = e;
    l.tail = e;
  }
}

void deleteTail(List& l){
  if(l.head != NULL){
    if(l.head == l.tail){
      deleteHead(l);
    } else {
      Element *e = l.tail;
      Element *p = l.head;
      while(p->next != l.tail) {
        p = p->next;
      }
      p->next = NULL;
      l.tail = p;
      delete e;
    }
  }
}
/*find first element in list l
with value and return its position (starting from 0). 
If there is no such element,return -1;*/
int findValue(List& l, int value){
  Element *e = l.head;
  int pos=0;
  while(e) {
    if(e->key == value) return pos;
    e = e->next;
    pos++;
  }
  return -1;
}

/*remove from list l
first element which is equal to value. 
If there is no such element, do nothing.*/
void deleteValue(List& l, int value){
  if(value == l.head->key) {deleteHead(l); return;}
  if(value == l.tail->key) {deleteTail(l); return;}
  Element *e = l.head;
  Element *p = l.head;
  while(e){
    if(e->key == value) {
      p -> next = e -> next;
      return;
    }
    p = e;
    e = e-> next;
  }
}
/*find in list l an element on specified position pos. 
Return a value on this position. If a position does not exist, return -9999*/
int atPosition(List& l, int pos){
  int i =0;
  Element *e = l.head;
  while(e){
    if(i == pos) return e->key;
    e = e-> next;
    i++;
  }
  return -9999;
}

void showListFromHead(List& l){
  if(l.head == NULL){
    cout << "\n";
  } else {
    Element *e = l.head;
    cout << e->key;
    e = e -> next;
    while(e){
      cout << " " << e->key;
      e = e -> next;
    }
    cout << "\n";
    e = NULL;
    delete e;
  }
}

void clearList(List& l){
  Element *e = l.head;
  while(e) {
    e = l.head -> next;
    delete l.head;
    l.head = e;
  }
  if(e != NULL) {delete e;}
  init(l);
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
	List *list;
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

		if(strcmp(command,"HA")==0)
			break;

		// zero-argument command
		if(strcmp(command,"DH")==0)
		{
			deleteHead(list[currentL]);
			continue;
		}
		if(strcmp(command,"DT")==0)
		{
			deleteTail(list[currentL]);
			continue;
		}

		if(strcmp(command,"SL")==0)
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

		if(strcmp(command,"DV")==0)
		{
			deleteValue(list[currentL],value);
			continue;
		}


		if(strcmp(command,"AT")==0)
		{
			int ret;
			ret=atPosition(list[currentL],value);
			cout << ret << endl;
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

		if(strcmp(command,"ST")==0)
		{
			list=new List[value];
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
		return 1;
	}
}
