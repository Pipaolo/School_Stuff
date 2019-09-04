import java.util.Scanner;

//Paolo Tolentino
//16:30
public class Main {
    private static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
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

        boolean isMagicSquare = true;

        String[] magicInput;
        int[] magicSum;
        int[][] magicSquare;

        println("Magic Square Checker!");
        print("Enter Magic Square Size: ");

        magicSize = input.nextInt();
        input.nextLine();
        magicNumber = magicSize * (((magicSize * magicSize) + 1) / 2);
        magicInput = new String[magicSize];
        magicSquare = new int[magicSize + 1][magicSize + 1];
        magicSum = new int[4];

        println("Enter 3 rows, with 3 numbers per line.");

        try{
            for (int i = 0; i < magicSize; i++) {
                magicInput = input.nextLine().split(" ");
                for (int j = 0; j < magicSize; j++) {
                    magicSquare[i][j] = Integer.parseInt(magicInput[j]);
                }
            }
        } catch (Exception ex){
            println("Invalid Input!");
            println("Please Try Again!");
            checkMagicSquare();
        }

        //Commence Checker

        //Get Row Sums

        for (int row = 0; row < magicSize; row++) {
            for (int col = 0; col < magicSize; col++) {
                magicSquare[row][magicSize] += magicSquare[row][col];
            }
        }

        //Get Column Sums
        for (int row = 0; row < magicSize; row++) {
            for (int col = 0; col < magicSize; col++) {
                magicSquare[magicSize][col] += magicSquare[col][row];
            }
        }

        //Get Diag Sums
        for (int row = 0; row < magicSize; row++) {
            magicSquare[magicSize][magicSize] += magicSquare[row][row];
        }

        println("Matrix Sum:");
        println("");
        printMagicSquare(magicSquare);

        for (int i = 0; i < magicSize + 1; i++) {
            if(magicSquare[magicSize][i] != magicNumber || magicSquare[i][magicSize] != magicNumber){
                println("");
                println("It not a Magic Square! UwU :<");
                isMagicSquare = false;
                break;
            }
        }

        if(isMagicSquare){
            println("");
            println("It is a Magic Square! :>");
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
        for (int[] ints : magicSquare) {
            for (int j = 0; j < magicSquare.length; j++) {
                print(String.format("%5d", ints[j]));
            }
            println("");
        }
    }

    public static void print(String string) {
        System.out.print(string);
    }

    public static void println(String string) {
        System.out.println(string);
    }

}
