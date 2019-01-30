using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5th_App
{
    class Program
    {
         /*
          *  5. Create a POS(point of sale) for any food industry. it needs IPO

            Input: all items to be purchased

            Process: all transaction that can have computation

            output : display change , total purchased etc.
          * 
          */

        static void Main(string[] args)
        {
            char userInput;
            bool isExit = false;
            decimal userPayment = 0M;
            decimal userChange = 0M;
            decimal itemPrice = 0M;

            while (isExit != true)
            {
                Console.Clear();
                Console.WriteLine("<--PMGT'S FRIES 'N STUFF!!-->");
                Console.WriteLine("\n\nHere is our menu: ");
                Console.WriteLine("[1] Fries");
                Console.WriteLine("[2] Deluxe Fries");
                Console.WriteLine("[3] Omega Fries");
                Console.WriteLine("[4] Curly Fries");
                Console.WriteLine("[5] Darth Vader Fries (I AM YOUR FATHER)");
                Console.WriteLine("[E] Exit");
                Console.Write("Enter a Choice: ");
                userInput = Convert.ToChar(Console.ReadLine());

                switch (userInput)
                {
                    case '1':
                        Console.Clear();
                        itemPrice = 20M;
                        Console.WriteLine("You have chosen Fries!");
                        Console.WriteLine("What flavor do you like?");
                        Console.WriteLine("[1] Barbecue");
                        Console.WriteLine("[2] Cheese");
                        Console.WriteLine("[3] Sour Cream");
                        userInput = Convert.ToChar(Console.ReadLine());
                        switch (userInput)
                        {
                            case '1':
                                Console.WriteLine("Flavor Barbecue");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat1:
                                userPayment = Convert.ToDecimal(Console.ReadLine());
                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat1;
                                }
                            case '2':
                                Console.WriteLine("Flavor Cheese");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat2:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat2;
                                }

                            case '3':
                                Console.WriteLine("Flavor Sour Cream");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat3:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat3;
                                }
                        }
                        break;
                    case '2':
                        Console.Clear();
                        itemPrice = 35M;
                        Console.WriteLine("You have chosen Deluxe Fries!");
                        Console.WriteLine("What flavor do you like?");
                        Console.WriteLine("[1] Barbecue");
                        Console.WriteLine("[2] Cheese");
                        Console.WriteLine("[3] Sour Cream");
                        userInput = Convert.ToChar(Console.ReadLine());
                        switch (userInput)
                        {
                            case '1':
                                Console.WriteLine("Flavor Barbecue");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat1:
                                userPayment = Convert.ToDecimal(Console.ReadLine());
                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat1;
                                }
                            case '2':
                                Console.WriteLine("Flavor Cheese");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat2:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat2;
                                }

                            case '3':
                                Console.WriteLine("Flavor Sour Cream");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat3:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat3;
                                }
                        }
                        break;

                    case '3':
                        Console.Clear();
                        itemPrice = 50M;
                        Console.WriteLine("You have chosen Omega Fries!");
                        Console.WriteLine("What flavor do you like?");
                        Console.WriteLine("[1] Barbecue");
                        Console.WriteLine("[2] Cheese");
                        Console.WriteLine("[3] Sour Cream");
                        userInput = Convert.ToChar(Console.ReadLine());
                        switch (userInput)
                        {
                            case '1':
                                Console.WriteLine("Flavor Barbecue");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat1:
                                userPayment = Convert.ToDecimal(Console.ReadLine());
                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat1;
                                }
                            case '2':
                                Console.WriteLine("Flavor Cheese");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat2:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat2;
                                }

                            case '3':
                                Console.WriteLine("Flavor Sour Cream");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat3:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat3;
                                }
                        }
                        break;
                    case '4':
                        Console.Clear();
                        itemPrice = 45M;
                        Console.WriteLine("You have chosen Curly Fries!");
                        Console.WriteLine("What flavor do you like?");
                        Console.WriteLine("[1] Barbecue");
                        Console.WriteLine("[2] Cheese");
                        Console.WriteLine("[3] Sour Cream");
                        userInput = Convert.ToChar(Console.ReadLine());
                        switch (userInput)
                        {
                            case '1':
                                Console.WriteLine("Flavor Barbecue");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat1:
                                userPayment = Convert.ToDecimal(Console.ReadLine());
                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat1;
                                }
                            case '2':
                                Console.WriteLine("Flavor Cheese");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat2:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat2;
                                }

                            case '3':
                                Console.WriteLine("Flavor Sour Cream");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat3:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat3;
                                }
                        }
                        break;
                    case '5':
                        Console.Clear();
                        itemPrice = 100M;
                        Console.WriteLine("You have chosen Darth Vader Fries!");
                        Console.WriteLine("What flavor do you like?");
                        Console.WriteLine("[1] Barbecue");
                        Console.WriteLine("[2] Cheese");
                        Console.WriteLine("[3] Sour Cream");
                        userInput = Convert.ToChar(Console.ReadLine());
                        switch (userInput)
                        {
                            case '1':
                                Console.WriteLine("Flavor Barbecue");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat1:
                                userPayment = Convert.ToDecimal(Console.ReadLine());
                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat1;
                                }
                            case '2':
                                Console.WriteLine("Flavor Cheese");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat2:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat2;
                                }

                            case '3':
                                Console.WriteLine("Flavor Sour Cream");
                                Console.Write($"That would be {itemPrice}PHP: ");
                                repeat3:
                                userPayment = Convert.ToDecimal(Console.ReadLine());

                                if (userPayment >= itemPrice)
                                {
                                    userChange = userPayment - itemPrice;
                                    Console.WriteLine("Thank You!");
                                    Console.WriteLine("Your change is " + userChange.ToString("0.00") + "PHP");
                                    System.Threading.Thread.Sleep(1000);
                                    break;
                                }
                                else
                                {
                                    Console.WriteLine("Insufficient Funds!");
                                    goto repeat3;
                                }
                        }
                        break;
                    case 'E':
                    case 'e':

                        Console.Clear();
                        Console.WriteLine("Thank You!");
                        System.Threading.Thread.Sleep(100);
                        isExit = true;
                        break;
                }
            }           
        }
    }
}
