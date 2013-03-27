#include<iostream>
#include<string.h>

using namespace std;

  typedef struct{
    //TODO
    int *arr;
        int size;
        int begin;
        int end;
  } Queue;

  void init(Queue& q, int size){
    //TODO
    q.begin=0;
    q.end=0;
    q.arr=new int[size+1];
    q.size=size+1;
  }

  void enqueue(Queue& q, int value){
    //TODO
    if((q.begin==0 && q.end==q.size-1) || (q.begin==q.end+1)) {
    } else {
            q.arr[q.end++]=value;
            if(q.end>=q.size) q.end=0;
    }
  }

  void dequeue(Queue& q, int &value){
    //TODO
        if(!(q.begin==q.end)) {
            value=q.arr[q.begin++];
            if(q.begin>=q.size)
                q.begin=0;
        }
  }

  bool isEmpty(Queue& q){
    return q.begin==q.end;
  }

  bool isFull(Queue& q){
        return (q.begin==0 && q.end==q.size-1) || (q.begin==q.end+1);
  }
  void show(Queue& q){
    //TODO
    //cout << "size" << q.size << "\n";
    int l=0;
    if(q.end > q.begin){
      l = q.end - q.begin+1;
    } else {
      l = q.size-q.begin+q.end+1;
    } 
    //cout << "l->" << l << endl;
    for(int i=q.begin;i<l;i++) {
            if(i > q.size) {
                cout << q.arr[i-q.size];
            } else {
                cout << q.arr[i];
            }
            if(i+1<l)cout << " ";
    }
    cout << "\n";
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






