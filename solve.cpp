//
//
#include"Sudoku.h"
#include<iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    Sudoku ss;
    ss.readIn();
    ss.solve();
    
    return 0;
}
