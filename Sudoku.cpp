//
//
#include<iostream>
#include"Sudoku.h"
using namespace std;


void Sudoku::readIn(){
    for (int i=0; i<81; i++) {
        cin>>read[i];
    }
}


void Sudoku::changeNum(int a,int b){
     if(a<0||a>9||b<0||b>9) return;   //validation
    for (int i=0; i<81; i++) {
        if(read[i]==a){
            read[i]=b;
            continue;
        }
        else if (read[i]==b){
            read[i]=a;
            continue;
        }
    }
}

void Sudoku::changeRow(int a,int b){
    if(b>a){int c=b;b=a;a=c;}
    if(a<0||b>2)return;   //validation
    int store[9],ctrA,ctrB;
    for (int i=0; i<3; i++) {
        ctrA=a*27+i*9;
        ctrB=b*27+i*9;
        for (int j=0; j<9; j++) {
            store[j]=read[j+ctrA];
            read[j+ctrA]=read[j+ctrB];
            read[j+ctrB]=store[j];
        }
    }
}


 void Sudoku::changeCol(int a,int b){
    if(b>a){int c=b;b=a;a=c;}
    if(a<0||b>2)return;   //validation
    int store[3];
    for (int i=0; i<81; i+=9) {
        for (int j=0; j<3; j++) {
            store[j]=read[a*3+i+j];
            read[a*3+i+j]=read[b*3+i+j];
            read[b*3+i+j]=store[j];
        }
        
    }
    
    
}

void Sudoku::rotate(int n){
    int store[81];
    n%=4;
    int k,l;
    for (int j=0; j<n; j++) {
        k=l=8;
        for (int i=0; i<81; i++) {
            store[i]=read[i];
        }
        for (int i=0; i<81; i++,l+=9) {
            if(l>80) l=--k;
            read[l]=store[i];
        }
    }
}

void Sudoku::flip(int n){
    int store[81], k,l;
    for (int i=0; i<81; i++) {
        store[i]=read[i];
    }
    if(n==0){
        k=l=81;
        for (int i=0; i<81; i++,l++) {
            if(l%9==0){ k-=9;l=k;}
            read[i]=store[l];
        }
    }
    else if(n==1){
        k=l=0;
        for (int i=0; i<81; i++,l--) {
            if(l%9==0){ k+=9;l=k;}
            read[i]=store[l-1];
        }
    }
    else return;
}

