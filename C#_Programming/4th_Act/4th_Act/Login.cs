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
    public partial class Login : Form
    {
        public string username = "pipaolo";
        public string password = "123";
        string userInput = "";
        string passInput = "";

        public Login()
        {
            InitializeComponent();
        }

        private void txtUsername_Clicked(object sender, EventArgs e)
        {
            txtUsername.Text = "";
        }

        private void txtPassword_Clicked(object sender, EventArgs e)
        {
            txtPass.Text = "";
            txtPass.UseSystemPasswordChar = true;
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            this.Close();
        }

        private void Check_KeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                userInput = txtUsername.Text;
                passInput = txtPass.Text;
                if (username == userInput && password == passInput)
                {
                    MessageBox.Show("Login Success!!");
                    Main_Menu menu = new Main_Menu();
                    this.Hide();
                    menu.ShowDialog();
                    this.Show();
                }
                else
                {
                    MessageBox.Show("Incorrect Username or Password!");
                }
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            userInput = txtUsername.Text;
            passInput = txtPass.Text;
            if (username == userInput && password == passInput)
            {
                MessageBox.Show("Login Success!!");
                Main_Menu menu = new Main_Menu();
                this.Hide();
                menu.ShowDialog();
                this.Show();
            }
            else
            {
                MessageBox.Show("Incorrect Username or Password!");
            }
        }

        private void Login_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtPass.Text = "Password";
        }

    }
}
