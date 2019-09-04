public class MagicSquareChecker extends Main {
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

        println(String.format("Enter %d rows, with %d numbers per line.", magicSize, magicSize));

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
            if(magicSquare[magicSize][magicSize] != magicSquare[magicSize][i]
                    || magicSquare[magicSize][magicSize] != magicSquare[i][magicSize]){
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
}
