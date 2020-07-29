#include<bits/stdc++.h>
#include<conio.h>
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
        int moveIndex = 0,x,y;
        int place;
        int count=0;
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
            system("clear");
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
        
        void initialise(char board[][side])
        {
            
            for(int i = 0; i < side ; i++)
            {
                for(int j = 0; j < side; j++)
                {
                    board[i][j] = ' ';
                }
            }
            
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
            system("clear");
            if(turn == PLAYER1)
            {
                cout<<"Congratualtions Player 1 !!!\n You have won the match\n\n";
            }
            else
            {
                cout<<"Congratualtions Player 2 !!!\n You have won the match\n\n";
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
            
            initialise(board);
            
            while(gameOver(board)==false && moveIndex != side*side)
            {
                if(turn == PLAYER1)
                {
                    showBoard();
                    place = getData(turn);
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    
                    if(board[x][y]!=' ')
                    {
                        count++;
                        if(count<3)
                        {
                            cout<<"This place is already marked\n";
                            cout<<"Try Again\n";
                            
                        }
                        else
                        {
                            cout<<"You have tried 3 times in a wrong place\n\n";
                            cout<<"You have to again start the game\n";
                            cout<<"Press ENTER for menu\n";
                            return;
                        }
                    }
                    else
                    {
                        count=0;
                        board[x][y] = PLAYER1MOVE;
                        cout<<"Player 1 has put "<<PLAYER1MOVE<<" in a cell "<<place<<"\n";
                        moveIndex++;
                        turn = PLAYER2;
                    }
                    
                }
                else if(turn == PLAYER2)
                {
                    showBoard();
                    place = getData(turn);
                    system("clear");
                    x=(place-1)/side;
                    y=(place-1)%side;
                    
                    if(board[x][y]!=' ')
                    {
                        count++;
                        if(count<3)
                        {
                            cout<<"This place is already marked\n";
                            cout<<"Try Again\n";
                            
                        }
                        else
                        {
                            cout<<"You have tried 3 times in a wrong place\n\n";
                            cout<<"You have to again start the game\n";
                            cout<<"Press ENTER for menu\n";
                            return;
                        }
                    }
                    else
                    {
                        count=0;
                        board[x][y] = PLAYER2MOVE;
                        cout<<"Player 2 has put "<<PLAYER2MOVE<<" in a cell "<<place<<"\n";

                        moveIndex++;
                        turn = PLAYER1;
                    }
                }
            }
            
            if(gameOver(board)==false && moveIndex == side*side)
            {
                system("clear");
                showBoard();
                cout<<"It's a draw match \n\n";
            }
            else
            {
                cout<<moveIndex<<endl;
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

    int choice;
  
    do 
    {    
        system("clear");
        cout<<"\n\n";
        cout<<"\t\t      //--------------\\\\ "<<"\n";
        cout<<"\t\t     //----------------\\\\ "<<"\n";
        cout<<"\t\t    //------------------\\\\ "<<"\n";
        cout<<"\t\t   //--------------------\\\\ "<<"\n";
        cout<<"\t\t  //----------------------\\\\ "<<"\n";
        cout<<"\t\t //------------------------\\\\ "<<"\n";
        cout<<"\t\t//--||-- TIC-TAC-TOE -- ||--\\\\ "<<"\n\n\n";
        cout<<"\t\t  - - - - -  MENU - - - - -\n\n\n";
        cout<<"\t\t  1.  INSTRUCTION\n\n";
        cout<<"\t\t  2.  PLAY\n\n";
        cout<<"\t\t  3.  EXIT\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    system("clear");
                    t.Instruction();
                    getch();
                    getch();
                }
                break;
            case 2:
                system("clear");
                t.play(PLAYER1);
                getch();
                getch();
                break;
            case 3:
                system("clear");
                cout<<"\t\tThank you for your lovely time.\n";
                cout<<"--\t--\t--\t     BYE\t    --\t--\t--\t\n";
                return 0;
                break;
            default:
                system("clear");
                cout<<" \t---\tInvalid Choice\t---\t\n";
                cout<<"\t---  Press ENTER for menu  ---\n";
                getch();
                getch();
                break;
        }
    }while(choice!=3);
    
    return 0;
}
