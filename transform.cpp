//
//
#include"Sudoku.h"
#include<cstdlib>
#include <ctime>
using namespace std;

void Sudoku::transform(){
    srand(time(NULL));
    changeNum(rand()%9+1, rand()%9+1);
    changeRow(rand()%3, rand()%3);
    changeCol(rand()%3, rand()%3);
    rotate(rand()%101);
    flip(rand()%2);
    print();
}