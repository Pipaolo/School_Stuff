import java.util.Scanner;

//Paolo Tolentino
//16:30
public class Main {
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
        for (int[] ints : magicSquare) {
            for (int j = 0; j < magicSquare.length; j++) {
                print(String.format("%5d", ints[j]));
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
