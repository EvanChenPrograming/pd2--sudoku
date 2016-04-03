//
//
#include<iostream>
#include"Sudoku.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a,b,ans;
    
    Sudoku ss;
    ss.readIn();
    cout<<"\n\n\n";
    ss.print();
    
    while(true){
        cout<<"1 changeNum(a,b)\n2 changeRow(a,b)\n3 changeCol(a,b)\n4 rotate(a)\n5 flip(a)\n6 transform()"<<endl;
        cin>>ans;
    
        switch (ans) {
            case 1:
                cin>>a>>b;
                ss.changeNum(a,b);
                ss.print();
                break;
                
            case 2:
                cin>>a>>b;
                ss.changeRow(a,b);
                ss.print();
                break;
            
            case 3:
                cin>>a>>b;
                ss.changeCol(a,b);
                ss.print();
                break;
            
            case 4:
                cin>>a;
                ss.rotate(a);
                ss.print();
                break;
            
            case 5:
                cin>>a;
                ss.flip(a);
                ss.print();
                break;
    
            case 6:
                ss.transform();
                break;
    
            case 7:
                ss.solve();
                cout<<endl;
                ss.print();
                
            default:
                break;
        }
    }
    return 0;
}
