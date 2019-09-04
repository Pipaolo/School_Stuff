import java.util.ArrayList;
import java.util.Scanner;

//Paolo Tolentino
//16:30
public class Main {
    public static final ArrayList<String> colors = new ArrayList<>();

    public static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        int userChoice;

        println("Choose a number: ");
        println("[1] Check Magic Square");
        println("[2] Magic Square Generator");
        print("> ");

        do {
            userChoice = input.nextInt();
            if (userChoice == 1) {
                MagicSquareChecker.checkMagicSquare();
                break;
            } else if (userChoice == 2) {
                MagicSquareMaker.magicSquareGenerator();
                break;
            }

        } while (userChoice < 3);
    }


    static void printMagicSquare(int[][] magicSquare) {
        String ANSI_RESET = "\u001B[0m";
        String ANSI_BLACK = "\u001B[30m";
        String ANSI_WHITE = "\u001B[37m";
        String ANSI_BLUE_BACKGROUND = "\u001B[44m";
        String ANSI_WHITE_BACKGROUND = "\u001B[47m";

        for (int i = 0; i < magicSquare.length; i++) {

            for (int j = 0; j < magicSquare.length; j++) {
                if(j == magicSquare.length - 1){
                    print( ANSI_BLACK + ANSI_BLUE_BACKGROUND);
                }

                if(j != magicSquare.length - 1){
                    print( ANSI_BLACK + ANSI_WHITE_BACKGROUND);
                }


                if(i == magicSquare.length - 1){
                    print(ANSI_BLACK + ANSI_BLUE_BACKGROUND);
                }

                print(String.format("%5d",  magicSquare[i][j]));
                print(ANSI_RESET);
            }
            println("");
        }
    }

    static void print(String string) {
        System.out.print(string);
    }

    static void println(String string) {
        System.out.println(string);
    }

}
