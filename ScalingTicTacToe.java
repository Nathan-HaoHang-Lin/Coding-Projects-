
import java.util.Scanner;

class Main {
    /**
     * Run a game of tic-tac-toe
     */
    public static void main(String[] args) {
        
        // Ask user for integer to set size of board.
        int BOARD_SIZE;
        Scanner sc = new Scanner(System.in);
        System.out.print("Input tic-tac-toe board size (default is 3):\n> ");
        String input = sc.nextLine();
        try {
           BOARD_SIZE = Integer.parseInt(input); 
           // throws NumberFormatException if not an int.
        } catch(NumberFormatException e) {
           // Input is not an int value.
           BOARD_SIZE = 3;
        } 
        if (BOARD_SIZE < 2) {
            throw new IllegalArgumentException("Size must be no smaller than 2.");
        }
        System.out.println("Specified board size: " + BOARD_SIZE);
        
        
        // Create a new board object.
        Board board = new Board(BOARD_SIZE);
        System.out.println(board.toString());
        
        // Run game
        while (!board.checkWin()) {
            System.out.print(board.getLetter() + ": Place your turn (format: \"x y\")\n> ");
            input = sc.nextLine();
            String[] coords = input.split(" ");
            board.place(Integer.parseInt(coords[0]), Integer.parseInt(coords[1]));
            System.out.println("\n" + board);
        }
    }
    
    /**
     * board class to group and organize all board actions
     * into a single object
     */
    private static class Board {
        private static int[][] board;
        private static int size;
        private static int turn;
        
        // Create new board of given dimensions.
        public Board(int size) {
            board = new int[size][size];
            this.size = size;
            turn = 0;
        }
        
        // Return the number of turns made.
        public int getTurn() {
            return turn;
        }
        
        // Return the letter to be placed.
        public String getLetter() {
            return ((turn + 1) % 2 == 1) ? "X" : "O";
        }
        
        // Convert numeric value to letter.
        private String valToLetter(int val) {
            return( val == 1 ? "X" : 
                    val == 2 ? "O" :
                    " ");
        }
        
        // Place letter.
        public boolean place(int x, int y) {
            
            // Check validity.
            if (!(x > 0 && x <= size && y > 0 && y <= size) ||
               !(board[y-1][x-1] == 0)) {
                // Invalid Position.
                return false;
            }
            
            // Place a letter.
            turn ++;
            board[y-1][x-1] = (turn % 2 == 1) ? 1 : 2;
            return true;
        }
        
        public boolean checkWin() {
            
            // Draw if board is full.
            if (turn == size * size) {
                System.out.println("\n\n\n=== Draw! ===");
            }
            
            // Check horizontal.
            for (int row = 0; row < size; row ++) {
                int temp = board[row][0];
                for (int col = 1; col < size; col ++) {
                    if (board[row][col] == 0 || board[row][col] != temp) {
                        break;
                    }
                    if (col == size-1) {
                        System.out.println("=== " + valToLetter(temp) + " wins horizonally! ===");
                        return true;
                    }
                }
            }
            // Check Vertical.
            for (int col = 0; col < size; col ++) {
                int temp = board[0][col];
                for (int row = 1; row < size; row ++) {
                    if (board[row][col] == 0 || board[row][col] != temp) {
                        break;
                    }
                    if (row == size-1) {
                        System.out.println("=== " + valToLetter(temp) + " wins vertically! ===");
                        return true;
                    }
                }
            }
            // Check Diagonal 135 deg.
            int temp = board[0][0];
            for (int i = 1; i < size; i ++) {
                if (board[i][i] == 0 || board[i][i] != temp) {
                    break;
                }
                if (i == size-1) {
                    System.out.println("=== " + valToLetter(temp) + " wins diagonally! ===");
                    return true;
                }
            }
            // Check diagonal 45 deg.
            temp = board[0][size - 1];
            for (int i = 1; i < size; i ++) {
                if (board[(size - 1) - i][i] == 0 || board[i][i] != temp) {
                    break;
                }
                if (i == size-1) {
                    System.out.println("=== " + valToLetter(temp) + " wins diagonally! ===");
                    return true;
                }
            }
            return false;
        }
        
        @Override
        // Override the Object class toString() to return accurate
        // representation of TTT board.
        public String toString() {
            
            // Define vertical separation line.
            StringBuilder vertLine = new StringBuilder();
            for (int i = 0; i < size-1; i ++) {
                vertLine.append("----");
            }
            vertLine.append("---");
            
            // Build string representation of board.
            StringBuilder sb = new StringBuilder();
            for (int row = -1; row < size; row ++) {
                sb.append(" ");
                for (int col = -1; col < size; col++) {
                    // Append letter and column divider when necessary.
                    if (col == -1) {
                        sb.append((row > -1) ? String.format("%2d", row + 1) : "").append(" ");
                    } else if (row == -1) {
                        sb.append((col > -1) ? String.format("%3d", col + 1) + " " : "   ");
                    } else {
                        sb.append(valToLetter(board[row][col]));
                        sb.append((col != size - 1) ? " | " : "");
                    }
                }
                // Append row divider when necessary.
                sb.append("\n   ");
                sb.append((row != size - 1) ? vertLine.toString() : "");
                sb.append("\n");
            }
            return sb.toString();
        }
    }
    
}
