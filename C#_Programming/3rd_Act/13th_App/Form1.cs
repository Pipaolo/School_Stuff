using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace _13th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /*
         * Write a program to convert a number to an English equivalent string formed from the digits.  
         * For example, 123 represented by “one two three” and 4017 is represented by “four zero one seven”.
         */

        private void Form1_Load(object sender, EventArgs e)
        {
            int userInput = 0;
            int remainder = 0;
            int temp = 0;
            int countDigits = 0;
            int iterator = 0;
            string[] arrResult;
            string finalResult = "";

            string[] englishNumbers = new string[10] {"zero", "one", "two", "three", "four", "five",
                                                     "six", "seven", "eight", "nine"};

            string user_Input = Interaction.InputBox("Enter Number", "12th_App", "---");

            userInput = Convert.ToInt32(user_Input);

            // This part is to get the number of digits of a number
            temp = userInput;

            while (temp > 0)
            {
                temp /= 10;
                countDigits++;
            }

            arrResult = new string[countDigits];
            //End of getting the digit

            while (userInput > 0)
            {
                remainder = userInput % 10;
                userInput /= 10;

                switch (remainder)
                {
                    case 0:
                        arrResult[iterator] += englishNumbers[0];
                        break;
                    case 1:
                        arrResult[iterator] += englishNumbers[1];
                        break;
                    case 2:
                        arrResult[iterator] += englishNumbers[2];
                        break;
                    case 3:
                        arrResult[iterator] += englishNumbers[3];
                        break;
                    case 4:
                        arrResult[iterator] += englishNumbers[4];
                        break;
                    case 5:
                        arrResult[iterator] += englishNumbers[5];
                        break;
                    case 6:
                        arrResult[iterator] += englishNumbers[6];
                        break;
                    case 7:
                        arrResult[iterator] += englishNumbers[7];
                        break;
                    case 8:
                        arrResult[iterator] += englishNumbers[8];
                        break;
                    case 9:
                        arrResult[iterator] += englishNumbers[9];
                        break;
                }
                iterator++;
            }

            for (int i = 0; i < countDigits; i++)
            {
                finalResult += arrResult[i] + " ";
            }

            MessageBox.Show(finalResult);
            this.Close();
        }
    }
}
