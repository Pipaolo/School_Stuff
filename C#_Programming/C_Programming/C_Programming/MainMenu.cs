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
    public partial class MainMenu : Form
    {
        string username = string.Empty;

        public MainMenu(ref string name)
        {
            username = name;
            InitializeComponent();
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            BrowseMenu browseMenu = new BrowseMenu(ref username);
            this.Hide();
            browseMenu.ShowDialog();
            this.Show();

        }

        private void btnRent_Click(object sender, EventArgs e)
        {
            RentMenu rentMenu = new RentMenu(ref username);
            this.Hide();
            rentMenu.ShowDialog();
            this.Show();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Thank You!");
            this.Close();
        }
    }
}
