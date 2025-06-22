#include <iostream> // include I/O library
using namespace std; // use standard namespace

int currentPlayer; // tracks current player number (1 or 2)
char currentMarker; // current marker symbol ('X' or 'O')
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} }; // tic-tac-toe board cells

void drawBoard() { // function to print the board
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n"; // row 0
    cout << "---|---|---\n"; // separator
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n"; // row 1
    cout << "---|---|---\n"; // separator
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n"; // row 2
    cout << "---|---|---\n"; // bottom separator
}

bool placeMarker(int slot) { // attempt to place marker at slot
    int row = (slot - 1) / 3; // compute row index
    int col = (slot - 1) % 3; // compute column index

    if (board[row][col] != 'X' && board[row][col] != 'O') { // check if free
        board[row][col] = currentMarker; // place marker
        return true; // success
    } else {
        return false; // already occupied
    }
}

int winner() { // check for a winner
    for (int i = 0; i < 3; i++) // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) // all equal
            return currentPlayer; // current player wins
    for (int i = 0; i < 3; i++) // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) // all equal
            return currentPlayer; // current player wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) // diagonal
        return currentPlayer; // current player wins
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) // other diagonal
        return currentPlayer; // current player wins
    return 0; // no winner
}

void swapPlayerAndMarker() { // swap player and marker
    if (currentMarker == 'X') // if X's turn
        currentMarker = 'O'; // switch to O
    else
        currentMarker = 'X'; // else switch to X
    currentPlayer = (currentPlayer == 1) ? 2 : 1; // toggle player number
}

void game() { // main game function
    cout << "Player1 choose your marker: X or O "; // prompt marker choice
    cin >> currentMarker; // read player marker

    currentPlayer = 1; // start with player 1
    drawBoard(); // show initial board

    int playerwon = 0; // winner flag
    for (int i = 0; i < 9; i++) { // up to 9 turns
        cout << "its player " << currentPlayer << " its turn Enter your slot: "; // prompt move
        int slot; // chosen slot variable
        cin >> slot; // read slot choice

        if (slot < 1 || slot > 9) { // validate range
            cout << "its is not a valid slot, you may try again\n"; // error message
            i--; // retry this turn
            continue;
        }
        if (!placeMarker(slot)) { // try to place marker
            cout << "slot occupied try again\n"; // error message
            i--; // retry this turn
            continue;
        }

        drawBoard(); // show updated board
        playerwon = winner(); // check for win

        if (playerwon == 1) { // if player 1 won
            cout << "player 1 wins\n";
            break; // exit loop
        }
        if (playerwon == 2) { // if player 2 won
            cout << "Player 2 wins\n";
            break; // exit loop
        }

        swapPlayerAndMarker(); // switch turns
    }

    if (playerwon == 0) // no winner after all turns
        cout << "its a tie\n"; // tie message
}

int main() { // program entry point
    game(); // start game
    return 0; // exit program
}
