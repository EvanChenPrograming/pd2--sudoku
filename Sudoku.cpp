//
//
#include<iostream>
#include<cstdlib>
#include <ctime>
#include"Sudoku.h"
using namespace std;

Sudoku::Sudoku(){
    count=0;
    for (int i=0; i<81; i++) {
        opt[i]=0;
    }
    
    for (int i=0; i<81; i++) {
        for (int j=0; j<10; j++) {
            poss[i][j]=0;
        }
    }
    
}

void Sudoku::giveQuestion(){
    
    int ques[81]={0,2,1,6,0,0,0,0,3
        ,0,0,7,0,0,1,0,0,0
        ,0,0,0,7,0,0,9,5,0
        ,0,0,0,0,1,0,8,0,4
        ,0,3,0,0,8,0,0,2,0
        ,8,0,5,0,9,0,0,0,0
        ,0,5,3,0,0,2,0,0,0
        ,0,0,0,3,0,0,4,0,0
        ,2,0,0,0,0,4,1,3,0};
    
    for (int i=0; i<81; i++){
        cout<<ques[i]<<" ";
        if(i%9==8)cout<<endl;
    }
    
}
void Sudoku::solve(){
    checkReadin();
    int k=0;
    for(int j=0;j<5;j++){
        k=count;
        for (int i=0; i<81; i++) {
            if(read[i]==0){
                opt[i]=options(i);
            }
        }
        clean();
        for (int i=0; i<81; i++) {
            if(read[i]==0)block(i);
        }
        clean();
        for (int i=0; i<81; i++) {
            if(read[i]==0)col(i);
        }
        clean();
        for (int i=0; i<81; i++) {
            if(read[i]==0)row(i);
        }
        if(check()==true)return;
        if(k==count)break;
    }
    cout<<"";
    clean();
    guessNum();
    check2ndAns();
    check();
}

void Sudoku::print(){
    for (int i=0; i<81; i++){
        cout<<read[i]<<" ";
        if(i%9==8)cout<<endl;
    }
}

int Sudoku::options(int i){
    
    int col=i%9,row=i/9,blockSt=i-col%3*1-row%3*9,note[10]={0},ctr=0,c=0;
    
    //check colum
    for (int j=col; j<81; j+=9) {
        note[read[j]]++;
    }
    //check row
    for (int j=row*9; j<row*9+9; j++) {
        note[read[j]]++;
    }
    //check block
    for (int j=blockSt; j<blockSt+20; j+=9) {
        for (int k=0; k<3; k++) {
            note[read[j+k]]++;
        }
    }
    
    for (int j=1; j<10; j++) {
        if (note[j]==0) {
            poss[i][j-1]++;
            c=j;
            ctr++;
        }
    }
    
    if(ctr==1){
        read[i]=c;
        count++;
        return 0;
    }
    else return ctr;
}

void Sudoku::block(int i){
    int blockSt=i-(i%9)%3*1-(i/9)%3*9,jump=0;
    for(int a=1;a<10;a++){
        jump=0;
        if(poss[i][a-1]!=0){
            for (int j=blockSt; j<blockSt+20; j+=9) {
                for (int k=0; k<3; k++) {
                    if(j+k==i)continue;
                    if(read[j+k]==0&&poss[j+k][a-1]==0)continue;
                    else {jump=1;break;}
                }
                if(jump==1)break;
            }
            if(jump==0){read[i]=a;count++;return;}
        }
        
    }
    
}

void Sudoku::row(int i){
    int row=i/9*9,jump;
    for(int a=1;a<10;a++){
        jump=0;
        if(poss[i][a-1]!=0){
            for(int j=row;j<row+9;j++){
                if(j==i)continue;
                if(read[j]!=0)continue;
                if(poss[j][a-1]!=0) {jump=1;break;}
            }
            if(jump==0){read[i]=a;count++;return;}
        }
    }
}

void Sudoku::col(int i){
    int col=i%9,jump;
    for(int a=1;a<10;a++){
        jump=0;
        if(poss[i][a-1]!=0){
            for(int j=col;j<81;j+=9){
                if(j==i)continue;
                if(read[j]!=0)continue;
                if(poss[j][a-1]!=0) {jump=1;break;}
            }
            if(jump==0){read[i]=a;count++;return;}
        }
    }
}

void Sudoku::clean(){
    for (int i=0; i<81; i++) {
        opt[i]=0;
        for (int j=0; j<9; j++) {
            poss[i][j]=0;
        }
    }
    for(int i=0;i<81;i++){
        if(read[i]==0) opt[i]=setposs(i);
    }
}

int Sudoku::setposs(int i){
    int col=i%9,row=i/9,blockSt=i-col%3*1-row%3*9,note[10]={0},ctr=0;
    
    //check colum
    for (int j=col; j<81; j+=9) {
        note[read[j]]++;
    }
    //check row
    for (int j=row*9; j<row*9+9; j++) {
        note[read[j]]++;
    }
    //check block
    for (int j=blockSt; j<blockSt+20; j+=9) {
        for (int k=0; k<3; k++) {
            note[read[j+k]]++;
        }
    }
    
    for (int j=1; j<10; j++) {
        if (note[j]==0) {
            poss[i][j-1]++;
            ctr++;
        }
    }
    return ctr;
}

bool Sudoku::check(){
    int noAns=0;
    for(int i=0;i<81;i++){
        if(opt[i]!=0)noAns++;
    }
    for(int i=0;i<81;i++){
        if(read[i]==0&&noAns==0){cout<<"0"<<endl; exit(0);}
        if(read[i]==0)return false;
    }
    int sum;
    //check row
    for(int i=0;i<9;i++){
        sum=0;
        for(int j=0;j<9;j++){
            sum+=read[i*9+j];
        }
        if(sum!=45){cout<<"0"<<endl; exit(0);}
    }
    //check col
    for(int i=0;i<9;i++){
        sum=0;
        for(int j=0;j<9;j++){
            sum+=read[i+j*9];
        }
        if(sum!=45){cout<<"0"<<endl; exit(0);}
    }
    //check block
    for(int i=0;i<63;i+=3){
        if(i%27==9)i+=18;
        sum=0;
        for (int j=i; j<i+20; j+=9) {
            for (int k=0; k<3; k++) {
                sum+=read[j+k];
            }
        }
        if(sum!=45){cout<<"0"<<endl; exit(0);}
    }
    
    cout<<"1"<<endl;
    print();
    return true;
}

void Sudoku::guessNum(){
    int loc[81]={0},l=0;
    for(int i=0;i<81;i++){
        if(opt[i]!=0){
            loc[l]=i;
            for(int j=read[i];j<11;j++){
                if(j==10){
                    read[i]=0;
                    i=loc[l-1]-1;
                    read[loc[l-1]]++;
                    l-=2;
                    if(l<-1){cout<<0<<endl;exit(0);}
                    break;
                }
                if(poss[i][j-1]!=0){
                    read[i]=j;
                    if(checkRule(read,i)==true)break;}
            }
            
            l++;
        }
    }
    
}

bool Sudoku::checkRule(int arr[81],int i){
    int col=i%9,row=i/9,blockSt=i-col%3*1-row%3*9;
    if(arr[i]==0)return false;
    //check colum
    for (int j=col; j<81; j+=9) {
        if(i==j)continue;
        if(arr[i]==arr[j])return false;
    }
    //check row
    for (int j=row*9; j<row*9+9; j++) {
        if(i==j)continue;
        if(arr[i]==arr[j])return false;
    }
    //check block
    for (int j=blockSt; j<blockSt+20; j+=9) {
        for (int k=0; k<3; k++) {
            if(i==j+k)continue;
            if(arr[i]==arr[j+k])return false;
        }
    }
    
    return true;
}

void Sudoku::check2ndAns(){
    int loc[81]={0},l=0,Ans2[81]={0};
    for(int i=0;i<81;i++){
        Ans2[i]=read[i];
        if(opt[i]!=0)Ans2[i]=10;
    }
    for(int i=0;i<81;i++){
        if(opt[i]!=0){
            loc[l]=i;
            for(int j=Ans2[i];j>=0;j--){
                if(j==0){
                    Ans2[i]=10;
                    i=loc[l-1]-1;
                    Ans2[loc[l-1]]--;
                    l-=2;
                    break;
                }
                if(poss[i][j-1]!=0){
                    Ans2[i]=j;
                    if(checkRule(Ans2,i)==true)break;}
            }
            
            l++;
        }
    }
    for (int i=0; i<81; i++){
        if(Ans2[i]!=read[i]){
            cout<<"2"<<endl;
            exit(0);
        }
    }
}

void Sudoku::checkReadin(){
    int j=0;
    for(int i=0;i<81;i++){
        if(read[i]!=0){
            j++;
            if(checkRule(read, i)==false){
                cout<<0<<endl;
                exit(0);
            }
        }
    }
    if(j<17){
        cout<<2<<endl;
        exit(0);
    }
}

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

void Sudoku::transform(){
    srand(time(NULL));
    changeNum(rand()%9+1, rand()%9+1);
    changeRow(rand()%3, rand()%3);
    changeCol(rand()%3, rand()%3);
    rotate(rand()%101);
    flip(rand()%2);
    cout<<endl;
	print();
}
