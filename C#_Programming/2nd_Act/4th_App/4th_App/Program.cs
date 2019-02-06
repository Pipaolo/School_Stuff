using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4th_App
{
    /*
     * Write a program that accepts an ordinary numbered and outputs its equivalent Roman Numerals.  
     * The ordinary number and their equivalent Roman numerals are given below: 
     * 
     * Sample input/output dialogue:
        Input :
        Enter a number : 2968
        Output :
        MMCMLXVIII
        Take note that the maximum input number is 3999.
     */
    class Program
    {

        static void Main(string[] args)
        {
            string one = "I";
            string four = "IV";
            string five = "V";
            string nine = "IX";
            string ten = "X";
            string forty = "XL";
            string fifty = "L";
            string ninety = "XC";
            string oneHundred = "C";
            string fourHundred = "CD";
            string fiveHundred = "D";
            string nineHundred = "CM";
            string oneThousand = "M";

            int userInput;
            Console.WriteLine("Numbers to Roman Numberals Converter!");
            Console.WriteLine("Enter a number (note: Number cannot exceed 3999): ");

            userInput = Convert.ToInt32(Console.ReadLine());
            getOnes:
            while(userInput != 0)
            {
                if (userInput < 10)
                {
                    if (userInput < 4)
                    {
                        for (int i = 0; i < userInput; i++)
                        {
                            Console.Write(one);
                        }
                    }
                    else
                    {
                        if (userInput == 4)
                            Console.Write(four);
                        else if (userInput == 5)
                            Console.Write(five);
                        else if (userInput > 5 && userInput < 9)
                        {
                            for (int i = 0; i < userInput - 4; i++)
                            {
                                if (i == 0)
                                    Console.Write(five);
                                else
                                    Console.Write(one);
                            }
                        }
                        else
                            Console.Write(nine);
                        userInput -= userInput;
                    }
                }
                else if (userInput >= 10 && userInput < 100)
                {
                    if (userInput < 40)
                    {
                        for (int i = 0; i < userInput / 10; i++)
                        {
                            Console.Write(ten);
                        }
                    }
                    else
                    {
                        if (userInput == 40)
                            Console.Write(forty);
                        else if (userInput == 50)
                            Console.Write(fifty);
                        else if (userInput > 50 && userInput < 90)
                        {
                            for (int i = 0; i < (userInput - 40) / 10; i++)
                            {
                                if (i == 0)
                                    Console.Write(fifty);
                                else
                                    Console.Write(ten);
                            }
                        }
                        else
                            Console.Write(ninety);
                    }
                    userInput %= 10;
                    goto getOnes;
                }
                else if (userInput >= 100 && userInput < 1000)
                {
                    if (userInput < 400)
                    {
                        for (int i = 0; i < userInput / 100; i++)
                        {
                            Console.Write(oneHundred);
                        }
                    }
                    else
                    {
                        if (userInput == 400)
                            Console.Write(fourHundred);
                        else if (userInput == 500)
                            Console.Write(fiveHundred);
                        else if (userInput > 500 && userInput < 900)
                        {
                            for (int i = 0; i < userInput - 400; i++)
                            {
                                if (i == 0)
                                    Console.Write(fiveHundred);
                                else
                                    Console.Write(oneHundred);
                            }
                        }
                        else
                            Console.Write(nineHundred);
                    }
                    userInput %= 100;
                    goto getOnes;
                }
                else if (userInput >= 1000 && userInput < 4000)
                {

                    for (int i = 0; i < userInput / 1000; i++)
                    {
                        Console.Write(oneThousand);
                    }
                    userInput %= 1000;
                    goto getOnes;
                }
                else
                {
                    Console.WriteLine("You cannot enter a value above 3999!");
                    Console.Read();
                }
            }       
            Console.Read();
        }
    }
}
