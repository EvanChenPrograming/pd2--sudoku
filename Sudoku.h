//
//
#include<iostream>

using namespace std;

class Sudoku{
public:
  //  Sudoku();
    void giveQuestion();
    
    void readIn();
    void solve();
    void print();
    
    void changeNum(int,int); //Exchange number a and b in the board. (1 <= a, b <= 9)
    void changeRow(int,int); //Exchange row set a and b in the board, each row set include three continuous rows. (0 <= a, b <= 2)
    void changeCol(int,int); //exchange columns. (0 <= a, b <= 2)
    void rotate(int); //Rotate the board 90 degrees n times in clockwise direction. (0 <= n <= 100)
    void flip(int); //If n equals to 0, flip the board vertically. Otherwise, flip it horizontally. (0 <= n <= 1)
    
    void transform();
    
private:
    int read[81];
    int ques[81];
    
    
};
