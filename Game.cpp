#include<bits/stdc++.h>
using namespace std;

#define side 3
#define PLAYER1 1
#define PLAYER2 2
#define PLAYER1MOVE '0'
#define PLAYER2MOVE 'X'



class TicTacToe
{
    private :
        char board[side][side];
        int moves[side*side];
        int moveIndex = 0,x,y;
        int place;
    public :
        void showBoard()
        {
            
            cout<<"\n\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\n";
            
            cout<<"--\t--\t--\t--\t--\t--\t--\t--\t--\t--\t--\n";
            
            return;
            
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
        
        void initialise(char board[][side],int moves[])
        {
            srand(time(NULL));
            
            for(int i = 0; i < side ; i++)
            {
                for(int j = 0; j < side; j++)
                {
                    board[i][j] = ' ';
                }
            }
            
            for(int i = 0; i < side*side; i++)
            {
                moves[i]=i;
            }
            
            random_shuffle(moves,moves+side*side);
            
            return;
        }
        
        bool rowCrossed(char board[][side])
        {
            for(int i = 0; i < side; i++)
            {
                if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] !=' ')
                return true;
            }
            return false;
        }
        
        bool columnCrossed(char board[][side])
        {
            for(int i = 0; i < side; i++)
            {
                if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i] !=' ')
                return true;
            }
            return false;
        }
        
        bool diagonalCrossed(char board[][side])
        {
            if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0] !=' ')
                return true;
            if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2] !=' ')
                return true;
                
            return false;
        }
        
        bool gameOver(char board[][side])
        {
            return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
        }
        
        void winner(int turn)
        {
            if(turn == PLAYER1)
            {
                //clrscr();
                //showBoard(board);
                cout<<"Player 1 has won\n\n";
            }
            else
            {
                cout<<"Player 2 has won\n\n";
            }
            return;
        }
        
        int getData(int turn)
        {
            int val;
            if(turn==PLAYER1)cout<<"\t\tPlayer 1 Turn\n";
            else
                cout<<"\t\tPlayer 2 Turn\n";
            cout<<"Enter the place where you want to mark : ";
            cin>>val;
            return val;
        }      
        
        void play(int turn)
        {
            
            initialise(board,moves);
            
            while(gameOver(board)==false && moveIndex != side*side)
            {
                if(turn == PLAYER1)
                {
                    /*
                    x = moves[moveIndex]/side;
                    y = moves[moveIndex]%side;
                    */
                    //system("clear");
                    place = getData(turn);
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    board[x][y] = PLAYER1MOVE;
                    cout<<"Player 2 has put "<<PLAYER1MOVE<<" in a cell "<<place<<"\n";
                    showBoard();
                    moveIndex++;
                    turn = PLAYER2;
                    
                }
                else if(turn == PLAYER2)
                {
                    place = getData(turn);
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    
                    board[x][y] = PLAYER2MOVE;
                    cout<<"Player 2 has put "<<PLAYER2MOVE<<" in a cell "<<place<<"\n";
                    showBoard();
                    moveIndex++;
                    turn = PLAYER1;
                }
            }
            
            if(gameOver(board)==false && moveIndex == side*side)
            {
                //clrscr();
                system("clear");
                showBoard();
                cout<<"It's a draw match \n\n";
            }
            else
            {
                if(turn==PLAYER1)turn=PLAYER2;
                else if(turn == PLAYER2)turn = PLAYER1;
                
                winner(turn);
            }
            
            return ;
        }
        
        
};

int main()
{
    TicTacToe t;
    
    t.Instruction();
    t.play(PLAYER1);
    
    return 0;
}
