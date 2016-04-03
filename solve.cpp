//
//
#include"Sudoku.h"
using namespace std;

void Sudoku::solve(){
    for(int j=0;j<2;j++){
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
    }
        
    for (int i=0; i<81; i++) {
        if(read[i]==0){
            opt[i]=options(i);
        }
    }
    if(check()==true)return;
    clean();
  //  guessNum(ctr);
    print();
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
        return 0;
    }
    else return ctr;
}

void Sudoku::block(int i){
    int blockSt=i-(i%9)%3*1-(i/9)%3*9,jump=0;
    for(int a=1;a<10;a++){//\\
        jump=0;
        if(poss[i][a-1]!=0){
            for (int j=blockSt; j<blockSt+20; j+=9) {
                for (int k=0; k<3; k++) {
                    if(j==i)continue;
                    if(read[j+k]==0&&poss[j+k][a-1]==0)continue;
                    else {jump=1;break;}
                }
                if(jump==1)break;
            }
            if(jump==0){read[i]=a;return;}
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
            if(jump==0){read[i]=a;return;}
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
            if(jump==0){read[i]=a;return;}
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
    
    if(ctr==1) return 0;
    else return ctr;
}

bool Sudoku::check(){
    for(int i=0;i<81;i++){
        if(read[i]==0)return false;
    }
    int sum;
    //check row
    for(int i=0;i<9;i++){
        sum=0;
        for(int j=0;j<9;j++){
            sum+=read[i*9+j];
        }
        if(sum!=45)return false;
    }
    //check col
    for(int i=0;i<9;i++){
        sum=0;
        for(int j=0;j<9;j++){
            sum+=read[i+j*9];
        }
        if(sum!=45)return false;
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
        if(sum!=45)return false;
    }
    
    cout<<"1"<<endl;
    print();
    return true;
}

void Sudoku::guessNum(int i){
    
}

