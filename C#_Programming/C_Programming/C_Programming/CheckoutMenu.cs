using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace C_Programming
{
    public partial class CheckoutMenu : Form
    {
        string book = string.Empty;
        string fullName = string.Empty;
        int rentedDays = 0;

        public CheckoutMenu(ref string name, ref string bookName, ref int days)
        {
            InitializeComponent();
            fullName = name;
            book = bookName;
            rentedDays = days;
        }

        private void CheckoutMenu_Load(object sender, EventArgs e)
        {
            rtxtCheckout.Text = "Name: " + fullName + "\r";
            rtxtCheckout.AppendText("--------------------\r");
            rtxtCheckout.AppendText($"Book: {book} \rDays to be Rented: {rentedDays} \r");
            rtxtCheckout.AppendText("--------------------\r");
        }

        private void btnRent_Click(object sender, EventArgs e)
        {
            DialogResult rentOut = MessageBox.Show("Are you sure?", "Confirmation", MessageBoxButtons.YesNo);
            if(rentOut == DialogResult.Yes)
            {
                MessageBox.Show($"Thank You! Don't forget to return the Book after {rentedDays} day/s!");
                this.Close();
            }
            else
            {
                this.Close();
            }


        }
    }
}
