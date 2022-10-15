#include <iostream>
using namespace std;


void board(string board[3][3]){ //display board
    cout << "\n     |     |\n";
    cout << "  "<<board[0][0] <<"  |  "  <<board[0][1]<<  "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |\n";
    cout << "  "<<board[1][0] <<"  |  " <<board[1][1]<< "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |\n";
    cout << "  "<<board[2][0] <<"  |  " <<board[2][1]<< "  |  " << board[2][2] << "\n";
    cout << "     |     |\n";

}

void action(string board[3][3], string current_player) {
    string position, symbol;
    if (current_player == "1")
        symbol = "X";
    else if (current_player == "2")
        symbol = "O";

    bool valid = 0;
    while (!valid){
        cout << "Player " + current_player + " - choose a square to play (1-9): ";
        cin >> position;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j]==position){
                    board[i][j]= symbol;
                    valid = 1;
                    break;}}
        }
        if (valid==0)
            if ((position!="1") && (position!="2") && (position!="3") && (position!="4") && (position!="5") && (position!="6") && (position!="7") && (position!="8") && (position!="9"))
                cout << "Invalid input, try again!" << endl;
            else
                cout << "This square has already been chosen. Choose another!" << endl;
    }

}

bool on_going(string grid[3][3],int turn, bool tie){
    for (int p=0; p<3; p++){
        if(((grid[p][0]==grid[p][1]) && (grid[p][0]==grid[p][2])) ||
        ((grid[0][p]==grid[1][p]) && (grid[0][p]==grid[2][p])) ||
        ((grid[0][0]==grid[1][1]) && (grid[0][0]==grid[2][2])) ||
        ((grid[0][2]==grid[1][1]) && (grid[0][2]==grid[2][0]))){
            return true;}
    }



}
int main() {

    string grid[3][3] = {"1", "2", "3", "4",
                         "5", "6", "7", "8", "9"};

    string player1, player2, current_player ="1", winner;
    bool tie = false;
    int turn=0;
    cout << "Enter Player1's name: "; cin >> player1;
    cout << "Enter PLayer2's name: "; cin >> player2;

    while (on_going(grid,turn, tie) == false){
        turn ++;
        board(grid);
        action(grid, current_player);

        if (current_player == "1")
            current_player = "2";
        else if (current_player == "2")
            current_player = "1";
        cout << on_going(grid,turn,tie);

    }
    board(grid);


        if (current_player != "1")
            cout << player1 << " is the winner!!" << endl;
        else
            cout << player2 << " is the winner!!" << endl;

    return 0;
}
