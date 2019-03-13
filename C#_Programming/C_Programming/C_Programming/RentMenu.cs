using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using Newtonsoft.Json;

namespace C_Programming
{
    public partial class RentMenu : Form
    {
        Books jGenres;
        string selected = string.Empty;
        string bookRent = string.Empty;
        string fullName = string.Empty;
        int daysRent = 0;
        int selectedGenre = 0;

        public RentMenu(ref string name)
        {
            InitializeComponent();
            getJson();
            fullName = name;
            tslblName.Text = name;
            tslblGenre.Text = "Adventure";
        }

        #region Json Shizz

        private void getJson()
        {
            string fileName = "genre.json";
            string json = string.Empty;
            using (StreamReader r = new StreamReader(fileName))
            {
                json = r.ReadToEnd();
            }
            loadJson(json);
        }

        private void loadJson(string json)
        {
            try
            {
                jGenres = JsonConvert.DeserializeObject<Books>(json);
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.Write(ex.Message.ToString());
            }
        }
        #endregion

        #region MenuList Changes

        private void SelectedGenre(object sender, EventArgs e)
        {
            string itemText = (sender as ToolStripMenuItem).Text;
            int itemIndex = (sender as ToolStripMenuItem).Owner.Items.IndexOf(sender as ToolStripMenuItem);
            tslblGenre.Text = itemText;
            changeGenreBox(itemIndex);
        }

        #endregion

        #region UI Changes

        private void BrowseMenu_Load(object sender, EventArgs e)
        {
            changeGenreBox(selectedGenre);
        }

        private void changeGenreBox(int selectedIndex)
        {
            genreBox.Items.Clear();
            for (int i = 0; i < jGenres.Genres[selectedIndex].genre.Count; i++)
            {
                genreBox.Items.Add(jGenres.Genres[selectedIndex].genre[i]);
            }
        }

        private void genreBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            string bookSelected = genreBox.SelectedItem.ToString();
            bookRent = bookSelected;
            txtCurrentBook.Text = bookSelected;

        }

        private void btnRent_Click(object sender, EventArgs e)
        {
            try
            {
                daysRent = Convert.ToInt32(txtRentDays.Text);
                CheckoutMenu checkoutMenu = new CheckoutMenu(ref fullName, ref bookRent, ref daysRent);
                this.Hide();
                checkoutMenu.ShowDialog();
                this.Close();
            }
            catch(Exception ex)
            {
                if(txtRentDays.Text == string.Empty)
                {
                    MessageBox.Show("Enter Amount of Days to be Rented!");
                }
            }

        }

        #endregion

    }
}
