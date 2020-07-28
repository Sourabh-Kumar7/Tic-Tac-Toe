#include<bits/stdc++.h>
using namespace std;

class TicTacToe
{
    public :
        void Board()
        {
            cout<<"\nhey\n";
            
        }
        void Instruction()
        {
            cout<<"\n\n";
            cout<<"\t\t\t\t Tic-Tac_Toe \n\n";
            cout<<"\t\tChoose a cell no. from 1-9 as below and play\n\n";
            
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| 1 | 2 | 3 |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| 4 | 5 | 6 |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| 7 | 8 | 9 |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\n";
            
            cout<<"--\t--\t--\t--\t--\t--\t--\t--\t--\t--\t--\n";
        }
        
        
};

int main()
{
    TicTacToe t;
    
    t.Instruction();
    
    return 0;
}
