import java.util.Scanner;

public class Exer5_1 extends Main {
    //Tolentino, Paolo
    //10:30
    public static void Exer5_1Main(){
        Scanner input = new Scanner(System.in);
        char resp;

        do{
            int n = 0;
            int num = 0;
            int sum = 0;
            String[] values;

            //Input n
            print("How many values?: ");
            n = input.nextInt();
            //Input Values
            values = new String[n];
            print("Enter Values: ");
            input.nextLine();
            try{
                values = input.nextLine().split(" ");
                if(values.length > n){
                    println("ERROR: The Values you have entered exceeded the limit");
                    print("Start Again(y/n)?: ");
                    resp = input.nextLine().charAt(0);
                    continue;
                }
            } catch (Exception ex){
                values[0] = input.nextLine();
            }

            for (int i = 0; i < n; i++) {
                sum += Integer.parseInt(values[i]);
                if(i != n - 1){
                    print(String.format("%s + ", values[i]));
                } else {
                    print(String.format("%s", values[i]));
                }
            }

            double average = ((double) sum) / n;

            //Display sum, average
            println(String.format(" = %d", sum));

            print("ave(");
            for(int i = 0; i < n; i++){
                if(i != n - 1){
                    print(String.format("%s, ", values[i]));
                } else {
                    println(String.format("%s) = %.2f", values[i], average));
                }
            }

            print("Start Again(y/n): ");
            input.nextLine();
            resp = input.nextLine().charAt(0);

        } while (resp == 'y');
    }
}