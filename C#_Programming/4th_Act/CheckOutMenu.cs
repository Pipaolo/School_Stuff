using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4th_Act
{
    public partial class CheckOutMenu : Form
    {
        string seperator = "---------------------------------------------";
        public int totalBill = 0;

        public CheckOutMenu()
        {
            InitializeComponent();
        }

        private void CheckOutMenu_Load(object sender, EventArgs e)
        {
            listBoxCheckOut.Items.Add("\n");
            listBoxCheckOut.Items.Add(seperator);
            listBoxCheckOut.Items.Add($"Total Bill: {totalBill}");
        }

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                int payment = Convert.ToInt32(txtPayment.Text);
                if(payment < totalBill)
                {
                    MessageBox.Show("Insufficient Funds!");
                }
                else
                {
                    payment -= totalBill;
                    MessageBox.Show($"Thank you! Your change is P{payment}");
                }
                this.Close();
            }
        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            int payment = Convert.ToInt32(txtPayment.Text);
            if(payment < totalBill)
            {
                MessageBox.Show("Insufficient Funds!");
            }
            else
            {
                payment -= totalBill;
                MessageBox.Show($"Thank you! Your change is P{payment}");
            }
            this.Close();
        }
        
    }
}
