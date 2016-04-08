//
//
#include<iostream>

using namespace std;

class Sudoku{
public:
    Sudoku();
    void giveQuestion();
    
    void readIn();
    void solve();
    void print();
    
    void changeNum(int,int);
    void changeRow(int,int);
    void changeCol(int,int);
    void rotate(int);
    void flip(int);
    
    //void pairs(int);
    
    void transform();
   // int opt[81];
private:
    bool check();
    void checkReadin();
    bool checkRule(int arr[81],int);
    int options(int);
    void block(int);
    void row(int);
    void col(int);
    void clean();
    void check2ndAns();
    int setposs(int);
    void guessNum();
    int count;
    int read[81];
    int ques[81];
    
    int opt[81];
    int poss[81][10];
    
};
