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
  for (int i=1;i<size;i++) {
    int j = i;
    while (j > 0 && (array[j-1] > array[j])) {
      swap(array[j], array[j-1]);
      j--;
    }
    //showArray(array, size);
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
void mergeSort(int arr[],int len);
void mergeArr(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
    while((h<=pivot)&&(j<=high)) {
        if(a[h]<=a[j]) {
            b[i]=a[h];
            h++;
        } else {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)  {
        for(k=j; k<=high; k++)  {
            b[i]=a[k];
            i++;
        }
    } else {
        for(k=h; k<=pivot; k++) {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

void auxMergeSort(int arr[],int arrAux[], int nFrom, int nTo)
{
  if(nFrom<nTo-1) {
  int nCenter=(nFrom+nTo)/2;
  auxMergeSort(arr,arrAux,nFrom,nCenter);
  auxMergeSort(arr,arrAux,nCenter,nTo);
  mergeArr(arr,arrAux,nFrom,nCenter,nTo); // to implement !!!
  }
}
void mergeSort(int arr[],int len)
{
  int *arr2=new int[len];
  auxMergeSort(arr,arr2,0,len);
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
  insertSort(array, n);
  return (float)((clock()-tStart)*1000/CLOCKS_PER_SEC);
  delete []array;
}
int main(){
  //clock_t tStart = clock();
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  int test[] = {100,10000, 50000};
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
  cout << endl;
  return 0;
}
