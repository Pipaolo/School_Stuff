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

        private void Form1_Load(object sender, EventArgs e)
        {
            List<string> output = new List<string>();
            int userInput = 0;
            int remainder = 0;
            int temp = 0;
            string finalResult = "";

            string[] englishNumbers = new string[10] {"zero", "one", "two", "three", "four", "five",
                                                     "six", "seven", "eight", "nine"};

            string user_Input = Interaction.InputBox("Enter Number", "12th_App", "---");

            userInput = Convert.ToInt32(user_Input);
            while (userInput > 0)
            {
                remainder = userInput % 10;
                userInput /= 10;

                switch (remainder)
                {
                    case 0:
                        output.Add(englishNumbers[0]);
                        break;
                    case 1:
                        output.Add(englishNumbers[1]);
                        break;
                    case 2:
                        output.Add(englishNumbers[2]);
                        break;
                    case 3:
                        output.Add(englishNumbers[3]);
                        break;
                    case 4:
                        output.Add(englishNumbers[4]);
                        break;
                    case 5:
                        output.Add(englishNumbers[5]);
                        break;
                    case 6:
                        output.Add(englishNumbers[6]);
                        break;
                    case 7:
                        output.Add(englishNumbers[7]);
                        break;
                    case 8:
                        output.Add(englishNumbers[8]);
                        break;
                    case 9:
                        output.Add(englishNumbers[9]);
                        break;
                }
            }

            for (int i = 0; i < output.Count; i++)
            {
                finalResult += output[i] + " ";
            }
            MessageBox.Show(finalResult);
            this.Close();
        }
    }
}
