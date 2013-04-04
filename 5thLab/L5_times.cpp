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
        swapped = false;
      }
    }
  }
}
void mergeSort(int arr[],int len);
/*void mergeArr(int *arr, int *arrAux, int nFrom, int center, int nTo)
{
    nTo--;
    int h,i,j,k;
    h=nFrom;
    i=nFrom;
    j=center+1;
    while( (h <= center) && ( j <= nTo) ) {
        if(arr[h]<=arr[j]) {
            arrAux[i]=arr[h];
            h++;
        } else {
            arrAux[i]=arr[j];
            j++;
        }
        i++;
    }
    cout << "-----------" << endl;
    showArray(arrAux, i);
    cout << "-----------" << endl;
    if(h>center)  {
        for(k=j; k<=nTo; k++)  {
            arrAux[i]=arr[k];
            i++;
        }
    } else {
        for(k=h; k<=center; k++) {
            arrAux[i]=arr[k];
            i++;
        }
    }
    for(k=nFrom; k<=nTo; k++) arr[k]=arrAux[k];
}*/
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
  /*int test[] = {100,10000, 50000};
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
  }*/
  int n = 5;
  int *array = new int[n];
  fillArray(array, n);
  showArray(array, n);
  mergeSort(array, n);
  showArray(array, n);
  cout << endl;
  return 0;
}
