package com.company;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.*;

public class Main {
    static Scanner input = new Scanner(System.in);
    static int boardWidth = 7;
    static int boardHeight = 6;
    static boolean isPlayer1Win = false;
    static boolean isPlayer2Win = false;
    static boolean isGameRunning = true;

    public static void main(String[] args) {
        mainMenu();
    }

    public static void mainMenu() {
        int userInput;

        println("<--Connect Four-->");
        println("[1] Start Game");
        println("[2] Exit");
        print("Enter Input: ");

        userInput = input.nextInt();

        if (userInput == 1) {
            gameMenu();
        } else if (userInput == 2) {
            println("");
        } else {
            println("Invalid Input!");
        }
    }

    public static void gameMenu() {
        int userInput;
        cls();
        println("<--Select Difficulty-->");
        println("[1] Single Player (W.I.P)");
        println("[2] Multi Player");
        println("[3] Back");
        print("Enter Input: ");
        userInput = input.nextInt();

        if (userInput == 1) {
            println("This feature is not yet working");
            gameMenu();
        } else if (userInput == 2) {
            startMultiplayer();
        } else if (userInput == 3) {

        } else {
            println("Invalid Input");
            gameMenu();
        }
    }

    public static void startMultiplayer() {
        boolean isPlayer1Move = true;
        int playerTurn = 0;
        int playerMove;
        ArrayList<String>[][] gameBoard = populateBoard();
        ArrayList<String> players = new ArrayList<>();
        players.add("Player 1");
        players.add("Player 2");


        printBoard(gameBoard);
        println("");
        println("");
        int count = 0;
        while (isGameRunning) {
            if (isPlayer1Move) {
                println(String.format("<--%s's Turn-->", players.get(playerTurn)));
                print("Enter Col(1..7): ");
                playerMove = input.nextInt();
                if(playerMove > boardWidth){
                    println("Invalid Input!");
                    continue;
                }
                addToBoard(playerMove, "1", gameBoard);
                println("");
            } else {
                println(String.format("<--%s's Turn-->", players.get(playerTurn + 1)));
                print("Enter Col(1..7): ");
                playerMove = input.nextInt();
                if(playerMove > boardWidth){
                    println("Invalid Input!");
                    continue;
                }
                addToBoard(playerMove, "2", gameBoard);
                println("");
            }
            printBoard(gameBoard);
            println("");
            println("");

            isPlayer1Move = !isPlayer1Move;
        }

        printWinner();

    }

    public static void printWinner() {
        if (isPlayer1Win) {
            println("<--Player 1 Win!-->");
        } else if (isPlayer2Win) {
            println("<--Player 2 Win-->");
        } else {
            println("<--Draw!-->");
        }
    }

    public static int addToBoard(int playerMove, String playerId, ArrayList<String>[][] gameBoard) {
        int count = 0;


        for (int i = 0; i < boardHeight; i++) {
            if (!gameBoard[i][playerMove - 1].contains("#")) {
                count++;
            }
        }


        try {
            gameBoard[(boardHeight - 1) - count][playerMove - 1].set(0, playerId);
            checkWinner(playerMove, playerId, gameBoard);
        } catch (Exception ex) {
            print("The Column is Full!");
            return 1;
        }
        return 0;
    }

    public static void checkWinner(int playerMove, String playerId, ArrayList<String>[][] gameBoard) {
        int count = 0;
        //Horizontal check
        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                if (gameBoard[i][j].contains(playerId)) {
                    count++;
                    if (count >= 4) {
                        if (playerId.equals("1")) {
                            isPlayer1Win = true;
                        } else {
                            isPlayer2Win = true;
                        }
                        isGameRunning = false;
                    }
                } else {
                    count = 0;
                }
            }
        }

        count = 0;
        //Vertical Check
        for (int i = 0; i < boardHeight; i++) {
            if (gameBoard[i][playerMove - 1].contains(playerId)) {
                count++;
                if (count >= 4) {
                    if (playerId.equals("1")) {
                        isPlayer1Win = true;
                    } else {
                        isPlayer2Win = true;
                    }
                    isGameRunning = false;
                }
            } else {
                count = 0;
            }
        }

        //Top left to Bottom Right
        for (int startingRow = 0; startingRow < boardHeight - 3; startingRow++) {
            count = 0;
            int row;
            int col;
            for (row = startingRow, col = 0; row < boardHeight && col < boardWidth; row++, col++) {
                if (gameBoard[row][col].contains(playerId)) {
                    count++;
                    if (count >= 4) {
                        if (playerId.equals("1")) {
                            isPlayer1Win = true;
                        } else {
                            isPlayer2Win = true;
                        }
                        isGameRunning = false;
                    }
                } else {
                    count = 0;
                }
            }
        }

        //Top left to Bottom Right
        for (int startingCol = 1; startingCol < boardWidth - 3; startingCol++) {
            count = 0;
            int row;
            int col;
            for (row = 0, col = startingCol; row < boardHeight && col < boardWidth; row++, col++) {
                if (gameBoard[row][col].contains(playerId)) {
                    count++;
                    if (count >= 4) {
                        if (playerId.equals("1")) {
                            isPlayer1Win = true;
                        } else {
                            isPlayer2Win = true;
                        }
                        isGameRunning = false;
                    }
                } else {
                    count = 0;
                }
            }
        }

        //Bottom Left to Top Right
        for (int startingRow = boardHeight - 1; startingRow > boardHeight - 3; startingRow--) {
            count = 0;
            int row;
            int col;
            for (row = startingRow, col = 0; row >= 0 && col < boardWidth; row--, col++) {
                if (gameBoard[row][col].contains(playerId)) {
                    count++;
                    if (count >= 4) {
                        if (playerId.equals("1")) {
                            isPlayer1Win = true;
                        } else {
                            isPlayer2Win = true;
                        }
                        isGameRunning = false;
                    }
                } else {
                    count = 0;
                }
            }
        }

        //Bottom left to Top Right
        for (int startingCol = 1; startingCol < boardWidth - 3; startingCol++) {
            count = 0;
            int row = boardHeight - 1;
            int col = startingCol;
            for (; row >= 0 && col < boardWidth; row--, col++) {
                if (gameBoard[row][col].contains(playerId)) {
                    count++;
                    if (count >= 4) {
                        if (playerId.equals("1")) {
                            isPlayer1Win = true;
                        } else {
                            isPlayer2Win = true;
                        }
                        isGameRunning = false;
                    }
                } else {
                    count = 0;
                }
            }
        }
    }

    public static ArrayList<String>[][] populateBoard() {
        ArrayList<String>[][] gameBoard = new ArrayList[boardHeight][boardWidth];
        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 7; col++) {
                gameBoard[row][col] = new ArrayList<>();
                gameBoard[row][col].add("#");
            }
        }
        return gameBoard;
    }

    public static void printBoard(ArrayList<String>[][] board) {
        char verticalLine = '║';
        char horizontalLine = '═';
        char rightBracket = '╔';
        char leftBracket = '╗';
        char invertRB = '╚';
        char invertLB = '╝';

        println("");
        println("\t\t\tCOLUMN");

        for (int i = 1; i <= 7; i++) {
            print(String.format(" %2d ", i));
        }

        println("");

        //Top Border
        for (int i = 0; i < 27; i++) {
            if (i == 0) {
                print(String.format(" %c", rightBracket));
            } else if (i == 26) {
                print(String.format("%c", leftBracket));
            } else {
                print(String.format("%c", horizontalLine));
            }
        }

        for (int row = 0; row < boardHeight; row++) {
            println("");
            for (int col = 0; col < boardWidth; col++) {
                if (col == boardWidth - 1) {
                    print(String.format("  %2s%c", board[row][col].get(0), verticalLine));
                } else if (col == 0) {
                    print(String.format(" %c%s", verticalLine, board[row][col].get(0)));
                } else {
                    print(String.format("%4s", board[row][col].get(0)));
                }

            }
        }

        println("");

        //Bottom Border
        for (int i = 0; i < 27; i++) {
            if (i == 0) {
                print(String.format(" %c", invertRB));
            } else if (i == 26) {
                print(String.format("%c", invertLB));
            } else {
                print(String.format("%c", horizontalLine));
            }
        }
    }


    public static void cls() {
        for (int i = 0; i < 50; ++i) println("");
    }

    public static void print(String input) {
        System.out.print(input);
    }

    public static void println(String input) {
        System.out.println(input);
    }
}