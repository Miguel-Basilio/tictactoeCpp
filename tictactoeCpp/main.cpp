//
//  main.cpp
//  tictactoeCpp
//
//  Created by AB on 5/22/21.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//tracking used markers;
char currentMarker;
int currentPlayer;


void drawBoard()
{
    cout <<" "<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
    cout <<" ------ \n";
    cout <<" "<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
    cout <<" ------ \n";
    cout <<" "<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<endl;
}

bool placeMarker(int slot)
{
    int row = slot / 3;
    int column;
    
    
    if (slot % 3 == 0)
    {
        row = row - 1;
        column = 2;
    }
    else column = (slot % 3) - 1;
    
    if (board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = currentMarker;
        return  true;
    }
    else return false;
  
}
char winner()
{
    for (int i =0; i<3; i++)
    {
        //rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        // columns:
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;
    
    return 0;
}

void swap_players()
{
    if (currentMarker == 'X') currentMarker ='O';
    else currentMarker = 'X';
        
        if (currentPlayer == 1) currentPlayer = 2;
        else currentPlayer = 1;
}


void game()
{
    cout <<"Player 1 choose marker ( X or O ):";
    char marker_P1;
    cin >> marker_P1;
    
    currentPlayer = 1;
    currentMarker = marker_P1;
    
    drawBoard();
    int player_won;
    
    for (int i = 0; i<9; i++)
    {
        cout << "It's Player" << currentPlayer << "'s turn. Enter your position: ";
        int slot;
        cin >>slot;
        
        if (slot <1 || slot > 9){
            cout <<"That slot is invalid. Try Again\n";
            i--; continue;
        }
        
        //holds player position on grid
        if (!placeMarker(slot)){
            cout <<"That slot is already taken. Try Again\n";
            i--; continue;
        }
        drawBoard();
        player_won = winner();
        if (player_won == 1){
            cout <<"Player one won! Congratulations!"; break;
            
        }
        if (player_won == 2 ){
            cout <<"Player two won! Congratulations!"; break;
        }
        swap_players();
   
    }

    if (player_won == 0){
        cout << "It's a tie!"<<endl;
    }
}


int main(int argc, const char * argv[]) {
 
    
    drawBoard();
    cout <<"_____________"<<endl;
    game();
    return 0;
}
