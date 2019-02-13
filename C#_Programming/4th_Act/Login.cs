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
        public string username = "Pipaolo";
        public string password = "123";

        string userInput = "";
        string passInput = "";

        public Login()
        {
            InitializeComponent();
        }

        private bool loginChecker(ref string userInput, ref string passInput)
        {
            if (userInput == username && passInput == password)
            {
                MessageBox.Show("Login Successfully!");
                return true;
            }
            else
            {
                MessageBox.Show("Incorrect Username/Password!");
                return false;
            }

            
        }

        private void txtUsername_Clicked(object sender, EventArgs e)
        {
            txtUsername.Text = "";
        }

        private void txtPassword_Clicked(object sender, EventArgs e)
        {
            txtPassword.Text = "";
            txtPassword.UseSystemPasswordChar = true;
        }

        private void checkKeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                try
                {
                    userInput = txtUsername.Text;
                    passInput = txtPassword.Text;
                    if(loginChecker(ref userInput, ref passInput) == true)
                    {
                        MainMenu mainMenu = new MainMenu();
                        this.Hide();
                        mainMenu.ShowDialog();
                        this.Close();
                    }
                }
                catch (System.FormatException)
                {

                }
            }
        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                userInput = txtUsername.Text;
                passInput = txtPassword.Text;
                if (loginChecker(ref userInput, ref passInput) == true)
                {
                    MainMenu mainMenu = new MainMenu();
                    this.Hide();
                    mainMenu.ShowDialog();
                    this.Close();
                }
            }
            catch (System.FormatException)
            {

            }
        }

        private void Login_Load(object sender, EventArgs e)
        {
            txtUsername.Text = "Username";
            txtPassword.Text = "Password";
        }

    }
}
