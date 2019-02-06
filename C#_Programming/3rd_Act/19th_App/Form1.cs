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

namespace _19th_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string finalOutput = "";
            int convert = 0;
            char convertedChar;
            
            string user_Input = Interaction.InputBox("Enter a Sentence/Word", "19th_App", "---");
            user_Input = user_Input.ToUpper();
            foreach (char index in user_Input)
            {
                if(index == 'A'|| index == 'B' || index == 'C' || 
                  index == 'D' || index == 'E' || index == 'F' || 
                  index == 'G' || index == 'H' || index == 'I')
                {
                    convert = Convert.ToInt16(index);
                    convert -= 32;                   
                }
                else if (index == 'J')
                {
                    convert = Convert.ToInt16(index);
                    convert -= 30;
                }
                else if (index == 'K')
                {
                    convert = Convert.ToInt16(index);
                    convert -= 29;
                }
                else if (index == 'L')
                {
                    convert = Convert.ToInt16(index);
                    convert += 20;
                }
                else if (index == 'M')
                {
                    convert = Convert.ToInt16(index);
                    convert += 48;
                }
                else if (index == 'N')
                {
                    convert = Convert.ToInt16(index);
                    convert += 46;
                }
                else if (index == 'O')
                {
                    convert = Convert.ToInt16(index);
                    convert += 12;
                }
                else if (index == 'P' || index == 'Q' || index == 'R' || 
                         index == 'S')
                {
                    convert = Convert.ToInt16(index);
                    convert += 12;
                }
                else if(index == 'T' || index == 'U' || index == 'V' ||
                        index == 'W' || index == 'X' || index == 'Y' ||
                        index == 'Z')
                {
                    convert = Convert.ToInt16(index);
                    convert -= 26;
                }

                convertedChar = Convert.ToChar(convert);
                finalOutput += convertedChar.ToString();
            }
            MessageBox.Show($"Your Converted Output is {finalOutput}");
            this.Close();
        }
    }
}
