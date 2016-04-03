//
//
#include<iostream>
#include"Sudoku.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Sudoku ss;
    ss.readIn();
    ss.solve();
    
    return 0;
}
