import java.util.Scanner;

public class Main {
    private static Scanner input = new Scanner(System.in);

    public static void main(String args[]) {
        int userChoice;

        println("Choose a number: ");
        println("[1] Check Magic Square");
        println("[2] Magic Square Generator");
        print("> ");

        do {
            userChoice = input.nextInt();
            if (userChoice == 1) {
                checkMagicSquare();
                break;
            } else if (userChoice == 2) {
                magicSquareGenerator();
                break;
            }

        } while (userChoice < 3);
    }

    public static void checkMagicSquare() {
        int magicSize;
        int magicNumber;
        int row = 0;
        int col = 0;

        int rowSum = 0;
        int colSum = 0;
        int diagSum = 0;
        int reverseDiagSum = 0;

        boolean isFoundDuplicate = false;

        String[] magicInput;
        int[] magicSum;
        int[][] magicSquare;

        println("Magic Square Checker!");
        print("Enter Magic Square Size: ");

        magicSize = input.nextInt();
        input.nextLine();
        magicNumber = magicSize * (((magicSize * magicSize) + 1) / 2);
        magicInput = new String[magicSize];
        magicSquare = new int[magicSize][magicSize];
        magicSum = new int[4];

        println("Enter Matrices: ");

        for (int i = 0; i < magicSize; i++) {
            magicInput = input.nextLine().split(" ");
            for (int j = 0; j < magicSize; j++) {
                magicSquare[i][j] = Integer.parseInt(magicInput[j]);
            }
        }

        //Commence Checker

        //Check for Duplicates
        for (int i = 0; i < magicSize; i++) {
            if(i + 1 == magicSize){
                break;
            }
            int[] temp = magicSquare[i + 1];
            for (int j = 0; j < magicSize; j++) {
                if(temp[j] == magicSquare[i][j]){
                    isFoundDuplicate = !isFoundDuplicate;
                    break;
                }
            }

        }

        if (isFoundDuplicate){
            //Check Rows
            for (int i = 0; i < magicSize * magicSize; i++) {
                if (row == magicSize) {
                    row = 0;
                    col++;
                }
                rowSum += magicSquare[row][col];
                if (rowSum == magicNumber) {
                    magicSum[0] = rowSum;
                    rowSum = 0;

                }
                row++;
            }

            row = 0;
            col = 0;
            //Check Columns
            for (int i = 0; i < magicSize * magicSize; i++) {
                if (col == magicSize) {
                    col = 0;
                    row++;
                }

                colSum += magicSquare[row][col];
                if (colSum == magicNumber) {
                    magicSum[1] = colSum;
                    colSum = 0;
                }
                col++;
            }

            row = 0;
            col = 0;
            //Check Diag
            for (int i = 0; i < magicSize; i++) {

                diagSum += magicSquare[row][col];
                if (diagSum == magicNumber) {
                    magicSum[2] = diagSum;
                }
                row++;
                col++;
            }

            row = 0;
            col = magicSize - 1;

            //Check Reverse Diag
            for (int i = magicSize - 1; i >= 0; i--) {

                reverseDiagSum += magicSquare[row][col];
                if (reverseDiagSum == magicNumber) {
                    magicSum[3] = reverseDiagSum;
                }
                row++;
                col--;
            }
        }

        if (magicSum[0] == magicNumber && magicSum[1] == magicNumber && magicSum[2] == magicNumber && magicSum[3] == magicNumber) {
            println("You have entered a Magic Square!");
        } else {
            println("You have entered an Invalid Magic Square!");
        }

    }

    public static void magicSquareGenerator() {
        int magicSize;
        println("Magic Square Generator");
        println("Use Odd Numbers Only!");
        do {
            print("Enter Number(3..9): ");
            magicSize = input.nextInt();
            if (magicSize % 2 == 0) {
                println("Use Odd Numbers Only!");
            } else if (magicSize > 9) {
                println("Number cannot be greater than 9!");
            }
        } while (magicSize % 2 == 0 || magicSize > 9);

        println(String.format("Here is your Magic Square with a size of %d:", magicSize));

        createMagicSquare(magicSize);
    }


    public static void createMagicSquare(int size) {
        int[][] magicSquare = new int[size][size];
        int row = 0;
        int col = (int) Math.ceil(size / 2);

        //println(col + "Column");

        for (int i = 1; i <= size * size; ) {
            //If Imaginary Location Column and Row Top
            if (row == -1 && col == size) {
                row += 2;
                col = size - 1;

            } else {
                //If Column Imaginary
                if (col == size) {
                    col = 0;
                }

                //If Row Imaginary Bottom
                if (row == size) {
                    row = 0;
                }

                //If Row Imaginary Top
                if (row < 0) {
                    row = size - 1;
                }
            }

            //If Box contains a number
            if (magicSquare[row][col] != 0) {
                col--;
                row += 2;
                continue;
            } else {

                magicSquare[row][col] = i++;
            }

            // Up Right Movement
            row--;
            col++;
        }

        printMagicSquare(magicSquare);

    }

    public static void printMagicSquare(int[][] magicSquare) {
        for (int i = 0; i < magicSquare.length; i++) {
            println("");
            for (int j = 0; j < magicSquare.length; j++) {
                print(String.format("%4d", magicSquare[i][j]));
            }
        }
    }

    public static void print(String string) {
        System.out.print(string);
    }

    public static void println(String string) {
        System.out.println(string);
    }

}
