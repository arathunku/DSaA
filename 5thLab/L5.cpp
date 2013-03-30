#include<iostream>

using namespace std;

void showArray(int array[], int size){
	//TODO
}
	
void insertSort(int array[], int size){
	//TODO
}

void bubbleSort(int array[], int size){
	//TODO
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
