public class MagicSquareMaker extends Main {

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
        } while (magicSize % 2 == 0);

        println(String.format("Here is your Magic Square with a size of %d:", magicSize));

        MagicSquareMaker.createMagicSquare(magicSize);
    }

    public static void createMagicSquare(int size) {
        int[][] magicSquare = new int[size + 1][size + 1];
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

        //Get Row Sums

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                magicSquare[i][size] += magicSquare[i][j];
            }
        }

        //Get Column Sums
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                magicSquare[size][j] += magicSquare[j][i];
            }
        }

        //Get Diag Sums
        for (int i = 0; i < size; i++) {
            magicSquare[size][size] += magicSquare[i][i];
        }

        println(" ");
        printMagicSquare(magicSquare);

    }
}
