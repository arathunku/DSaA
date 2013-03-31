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
  for (int i=1;i<size;i++) {
    int j = i;
    while (j > 0 && (array[j-1] > array[j])) {
      swap(array[j], array[j-1]);
      j--;
    }
    showArray(array, size);
  }
}

void bubbleSort(int array[], int size){
  bool swapped = true;
  int j = 0;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < size-j; i++) {
      if (array[i] > array[i+1]) {
        swap(array[i], array[i+1]);
        swapped = true;
      }
    }
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
