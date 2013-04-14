#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib> 
#include <ctime> 
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
    //showArray(array,size);
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
    //showArray(array, size);
  }
}

void mergeSort(int arr[],int len);
void mergeArr(int tab[],int t[], int pocz, int sr, int kon)
{
  int i,j,q;
  for (i=pocz; i<=kon; i++) 
    t[i]=tab[i];
  
  i=pocz; j=sr+1; q=pocz;
  while (i<=sr && j<=kon) {
    if (t[i]<t[j])
      tab[q++]=t[i++];
    else
      tab[q++]=t[j++];
  }
  while (i<=sr) tab[q++]=t[i++];
}

void auxMergeSort(int arr[],int arrAux[], int nFrom, int nTo)
{
  if(nFrom<nTo) {
    int nCenter=(nFrom+nTo)/2;
    auxMergeSort(arr,arrAux,nFrom,nCenter);
    auxMergeSort(arr,arrAux,nCenter+1,nTo);
    mergeArr(arr,arrAux,nFrom,nCenter,nTo);
  }
}
void mergeSort(int arr[],int len)
{
  int *arr2=new int[len];
  auxMergeSort(arr,arr2,0,len-1);
  delete []arr2;
}

int * loadArray(int size){
  int *arr=new int[size];
  for(int i=0;i<size;i++){
    cin >> arr[i];
  }
  return arr;
}
void fillArray(int array[], int size){
  srand((unsigned)time(0));
  int random_integer; 
  for(int i=0; i<size; i++){ 
    random_integer = (rand()%100)+1; 
    array[i] = random_integer;
  }
}
float testBubble(int n) {
  int *array = new int[n];
  fillArray(array, n);
  clock_t tStart = clock();
  bubbleSort(array, n);
  return (float)((clock()-tStart)*1000/CLOCKS_PER_SEC);
  delete []array;
}
float testInsert(int n) {
  int *array = new int[n];
  fillArray(array, n);
  clock_t tStart = clock();
  insertSort(array, n);
  return (float)((clock()-tStart)*1000/CLOCKS_PER_SEC);
  delete []array;
}
float testMerge(int n) {
  int *array = new int[n];
  fillArray(array, n);
  clock_t tStart = clock();
  mergeSort(array, n);
  return (float)((clock()-tStart)*1000/CLOCKS_PER_SEC);
  delete []array;
}
int main(){
  //clock_t tStart = clock();
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  int test[] = {1};
  int n = sizeof(test)/sizeof(int);
  for(int i=0;i<n;i++){
    cout << "\t\t";
    cout << test[i];
  }
  cout << endl;
  cout << "bubbleSort:\t";
  for(int i=0;i<n;i++){
    printf("%.2fs\t\t", testBubble(test[i]));
  }
  cout << endl;
    cout << "insertSort:\t";
  for(int i=0;i<n;i++){
    printf("%.2fs\t\t", testInsert(test[i]));
  }
  cout << endl;
    cout << "mergeSort:\t";
  for(int i=0;i<n;i++){
    printf("%.2fs\t\t", testMerge(test[i]));
  }
    /*
  int n = 5;
  int *array = new int[n];
  fillArray(array, n);
  showArray(array, n);
  mergeSort(array, n);
  showArray(array, n);
  cout << endl;
  return 0;*/
}
