#include <iostream>

using namespace std;

//Function to print game board

void printBoard(string gameBoard[3][3]) {

    for (int i = 0; i < 3; i++) {
        cout << gameBoard[i][0] << " | " << gameBoard[i][1] << " | " << gameBoard[i][2] << endl;
        if (i != 2) cout << "----------" << endl;
    }

}

// Function to check for a win

bool checkForWin(string gameBoard[3][3], int numOfPlays) {

    bool noWinner = true;

    // Horizontal win condition

    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            noWinner = false;
            cout << "Player '" << gameBoard[i][0] << "' won!\n" << endl;
        }
    }

    // Vertical win condition
    for (int i = 0; i < 3; i++) {
        if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            noWinner = false;
            cout << "Player '" << gameBoard[0][i] << "' won!\n" << endl;
        }
    }

    // Diagonal win condition
    if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        noWinner = false;
        cout << "Player '" << gameBoard[0][0] << "' won!\n" << endl;
    }
    if (gameBoard[0][2] != " " && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        noWinner = false;
        cout << "Player '" << gameBoard[0][2] << "' won!\n" << endl;
    }

    return noWinner;
}

int main() {

    // Create a 2D array to represent the 3x3 tic-tac-toe board

    string gameBoard[3][3] = {
        { " ", " ", " " },
        { " ", " ", " " },
        { " ", " ", " " }
    };

    // Variables for user input and game state

    int row, column;
    int numOfPlays = 0;
    bool squareEmpty = true;
    bool noWinner = true;

    // Main game loop

    while (numOfPlays < 9 && noWinner) {
        squareEmpty = true;

        //print the board

        printBoard(gameBoard);

        // Get user input for move

        while (squareEmpty) {

            cout << "\nPlease enter row-column you would like to place [Ex: 1-3]: ";
            cin >> row;
            cin.ignore();  // Ignore the '-' character
            cin >> column;
            cout << endl;
            // Check if the chosen square is empty

            if (gameBoard[row - 1][column - 1] != " ") {
                cout << "Square " << row << "-" << column << " has already been played.\n" << endl;
            } else {
                // Assign the move to the board
                if (numOfPlays % 2 == 0) {
                    gameBoard[row - 1][column - 1] = "O";
                } else {
                    gameBoard[row - 1][column - 1] = "X";
                }

                numOfPlays++;
                squareEmpty = false;
            }
        }

        // Check for a win after each move

        noWinner = checkForWin(gameBoard, numOfPlays);

        // Reset squareEmpty for the next round

        squareEmpty = true;
    }

    //print the final board

    printBoard(gameBoard);

    if (noWinner) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
