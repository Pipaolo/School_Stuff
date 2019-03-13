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
    public partial class BrowseMenu : Form
    {
        Books jGenres;
        string selected = string.Empty;
        int selectedGenre = 0;

        public BrowseMenu(ref string name)
        {
            InitializeComponent();
            getJson();
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

        #endregion

    }
}
