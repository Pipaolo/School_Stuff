using System;
using System.Windows.Forms;
using MaterialSkin;
using MaterialSkin.Controls;

namespace _5th_Act
{
    public partial class  Login : MaterialForm
    {
        string username = "ciit";
        string password = "admin";

        public Login()
        {
            InitializeComponent();
            // Create a material theme manager and add the form to manage (this)
            MaterialSkinManager materialSkinManager = MaterialSkinManager.Instance;
            materialSkinManager.AddFormToManage(this);
            materialSkinManager.Theme = MaterialSkinManager.Themes.LIGHT;

            // Configure color schema
            materialSkinManager.ColorScheme = new ColorScheme(
                Primary.Blue400, Primary.Blue500,
                Primary.Blue500, Accent.LightBlue200,
                TextShade.WHITE
            );
        }

        private void password_isFocused(object sender, EventArgs e)
        {
            if(txtUsername.Text.Length == 0)
            {
                txtUsername.Text = "Username";
            }
            txtPassword.Text = "";
        }

        private void checkKeyPress (object sender, KeyEventArgs e)
        {
            txtPassword.UseSystemPasswordChar = true;
            if(e.KeyCode == Keys.Enter)
            {
                if (txtUsername.Text == username &&
                    txtPassword.Text == password)
                {
                    InfoMenu infoMenu = new InfoMenu();
                    this.Hide();
                    infoMenu.ShowDialog();
                    this.Close();
                }
                else
                {
                    MessageBox.Show("Incorrect Username/Password!");
                }
            }
        }

        private void username_isFocused(object sender, EventArgs e)
        {
            if (txtPassword.Text.Length == 0)
            {
                txtPassword.Text = "Password";
            }
            txtUsername.Text = "";
        }

        private void btnLogin_Pressed(object sender, EventArgs e)
        {
            if (txtUsername.Text == username && 
                txtPassword.Text == password)
            {
                InfoMenu infoMenu = new InfoMenu();
                this.Hide();
                infoMenu.ShowDialog();
                this.Close();
            }
            else
            {
                MessageBox.Show("Incorrect Username/Password!");
            }
        }

        private void Login_Load(object sender, EventArgs e)
        {
            ActiveControl = txtUsername;
        }
    }
}
