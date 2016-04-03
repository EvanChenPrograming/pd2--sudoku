//
//
#include<iostream>

using namespace std;

class Sudoku{
public:
    Sudoku(){
        for (int i=0; i<81; i++) {
            opt[i]=0;
        }
        
        for (int i=0; i<81; i++) {
            for (int j=0; j<9; j++) {
                poss[i][j]=0;
            }
        }
    }
    void giveQuestion();
    
    void readIn();
    void solve();
    void print();
    
    void changeNum(int,int);
    void changeRow(int,int);
    void changeCol(int,int);
    void rotate(int);
    void flip(int);
    
    void transform();
    int opt[81];//
private:
    bool check();
    int options(int);
    void block(int);
    void row(int);
    void col(int);
    void clean();
    int setposs(int);
    void guessNum(int);
    int read[81];
    int ques[81];
    
   // int opt[81];
    int poss[81][9];
    
};
