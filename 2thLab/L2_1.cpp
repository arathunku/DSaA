#include <iostream>
#include <string.h>

using namespace std;

  struct Queue{
    //TODO
    int *arr;
    int size;
    int pos;
  } ;
  bool isFull(Queue &q);
  void init(Queue& q, int size){
    //TODO
    q.arr=new int[size];
    q.size=size;
    q.pos=0;
  }

  void enqueue(Queue& q, int value){
    //TODO
    if(!isFull(q)) {
      q.arr[q.pos++] = value;
    }
  }

  void dequeue(Queue& q, int &value){
    //TODO
        if(q.pos != 0) {
            value=q.arr[0];
          for(int i=1; i<q.pos; i++) {
              q.arr[i-1]=q.arr[i];
          }
          q.pos--;
        }
  }

  bool isEmpty(Queue& q) {
    return q.pos==0;
  }

  bool isFull(Queue& q) {
        return q.pos==q.size;
  }
  void show(Queue& q){
    if(isEmpty(q))
    {
      cout << endl;
    } else {
        cout << q.arr[0];
        for(int i=1; i<q.pos; i++) {
          cout << ' '<< q.arr[i];
        }
        cout << endl;
    }
  }


void showBool(bool val) {
  if(val)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}

int main() {
  const int commandSize=2;
  const int MAXLINE=100;
  char line[MAXLINE];
  char command[commandSize+1]; // for '\0'
  Queue *queue;
  int currentQ=0;
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
    if(strcmp(command,"EM")==0) {
      showBool(isEmpty(queue[currentQ]));
      continue;
    }
    if(strcmp(command,"FU")==0) {
      showBool(isFull(queue[currentQ]));
      continue;
    }
    if(strcmp(command,"SH")==0) {
      show(queue[currentQ]);
      continue;
    }
    if(strcmp(command,"DE")==0) {
      int ret;
      dequeue(queue[currentQ],ret);
      cout << ret << endl;
      continue;
    }

    // read next argument, one int value
    cin >> value;

    if(strcmp(command,"ST")==0) {
      queue=new Queue[value];
      continue;
    }
    if(strcmp(command,"CH")==0) {
      currentQ=value;
      continue;
    }

    if(strcmp(command,"IN")==0) {
      init(queue[currentQ],value);
      continue;
    }

    if(strcmp(command,"EN")==0) {
      enqueue(queue[currentQ],value);
      continue;
    }
    return 0;
  }
}






