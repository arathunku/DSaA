#include <iostream>
#include <string.h>
#include <time.h>

/*
clock_t tStart = clock();
printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC); 
*/
using namespace std;

void showArray(int array[], int size){
  for(int i=0;i<size;i++)
    cout << array[i] << ",";
  cout << endl;
}
void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
void insertSort(int array[], int size){
  int i,j,k,elem;
  for(i=size-2;i>=0;i--)
  {
    j=size-1;
    elem=array[i];
    while(j>i && array[j]>=elem)
      j--;
    for(k=i;k<j;k++)
      swap(array[k], array[k+1]);
    array[j]=elem;
    showArray(array,size);
  }
}

void bubbleSort(int array[], int size){
  if(size == 1 ) return;
  for(int i=0;i<size-1;i++){
    for(int j=size-1;j>i;j--){
      if(array[j] < array[j-1]){
        swap(array[j], array[j-1]);
      }
    }
    showArray(array, size);
  }
}

int * loadArray(int size){
  int *arr=new int[size];
  for(int i=0;i<size;i++){
    cin >> arr[i];
  }
  return arr;
}

int main(){
  const int commandSize=2;
  const int MAXLINE=100;
  char line[MAXLINE]; 
  char command[commandSize+1]; // for '\0'
  int size;
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

    // read next argument, one int value
    cin >> size;
    
    if(strcmp(command,"IS")==0)
    {
      cout << "insertSort" << endl;
      int *arr=loadArray(size);
      showArray(arr,size);
      insertSort(arr,size);
      continue;
    }

    if(strcmp(command,"BS")==0)
    {
      cout << "bubbleSort" << endl;
      int *arr=loadArray(size);
      showArray(arr,size);
      bubbleSort(arr,size);
      continue;
    }
    cout << "wrong argument in test: " << command << endl;
    return 1;
  }
}
