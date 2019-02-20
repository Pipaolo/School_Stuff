using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1st_MidTerm_Quiz
{
    public partial class frmLogin : Form
    {
        string username = "ciit";
        string password = "admin";

        public frmLogin()
        {
            InitializeComponent();
            txtUsername.Text = "Username";
            txtPassword.Text = "Password";

        }

        private void usernameSelected(object sender, EventArgs e)
        {
            txtUsername.Text = "";
        }

        private void passwordSelected(object sender, EventArgs e)
        {
            txtPassword.Text = "";
            txtPassword.UseSystemPasswordChar = true;
        }

        private void checkKeypress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (txtUsername.Text == username && txtPassword.Text == password)
                {
                    MessageBox.Show("Login Successful!");
                    Student_Identification gradingMenu = new Student_Identification();
                    this.Hide();
                    gradingMenu.ShowDialog();
                    this.Show();
                }
                else
                {
                    MessageBox.Show("Incorrect username/password!");
                }
            }
        }


        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (txtUsername.Text == username && txtPassword.Text == password)
            {
                MessageBox.Show("Login Successful!");
                Student_Identification gradingMenu = new Student_Identification();
                this.Hide();
                gradingMenu.ShowDialog();
                this.Show();
            }
            else
            {
                MessageBox.Show("Incorrect username/password!");
            }
        }
    }
}
