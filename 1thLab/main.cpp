#include <stdio.h>
#include <iostream>

using namespace std;

void drawLine(int size, string ch){
    for(int i=0;i<size;i++){
        cout << ch;
    }
}

void drawTriangle(int size) {
    int i=0;
    for(i=0; i<size;i++){
        drawLine(i+1, "X");
        cout << "\n";
    }
}
void drawRectangle(int size) {
    int i=0;
    drawLine(size, "X");
    cout << "\n";
    for(i=1;i<=size-2;i++){
        drawLine(1, "X");
        drawLine(size-2, " ");
        drawLine(1, "X");
        cout << "\n";
    }
    drawLine(size, "X");
    cout << "\n";
}

void drawPiramid(int size, int t=0){
    int x=1;
    for(int i=0;i<size;i++) {
        drawLine(size-i-1+t, " ");
        drawLine(x, "X");
        x += 2;
        cout << "\n";
    }
}

void drawChristmasTree(int size){
    for(int i=1;i<=size;i++) {
        drawPiramid(i, size-i);
    }
}

int main(){
	const int MAXLINE=100;
	char line[MAXLINE];
	char oneChar;
	int value;
	while(true){
		cin >> oneChar;
		if(oneChar=='#')
		{
			cin.getline(line, MAXLINE);
			continue;
		}
		if(oneChar=='E')
			break;
		// read next argument, one int value
		cin >> value;
		switch(oneChar){
		case 'T': drawTriangle(value); break;
		case 'R': drawRectangle(value); break;
		case 'P': drawPiramid(value); break;
		case 'C': drawChristmasTree(value); break;
		}
	}
}
