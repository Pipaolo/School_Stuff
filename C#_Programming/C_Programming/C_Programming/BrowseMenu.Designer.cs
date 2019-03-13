namespace C_Programming
{
    partial class BrowseMenu
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.tsmGenre = new System.Windows.Forms.ToolStripMenuItem();
            this.tsAdventure = new System.Windows.Forms.ToolStripMenuItem();
            this.tsFantasy = new System.Windows.Forms.ToolStripMenuItem();
            this.tsSciFi = new System.Windows.Forms.ToolStripMenuItem();
            this.tsRomance = new System.Windows.Forms.ToolStripMenuItem();
            this.tsHorror = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1 = new System.Windows.Forms.Panel();
            this.genreBox = new System.Windows.Forms.ListBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tslblName = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslblGenre = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmGenre});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(423, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // tsmGenre
            // 
            this.tsmGenre.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsAdventure,
            this.tsFantasy,
            this.tsSciFi,
            this.tsRomance,
            this.tsHorror});
            this.tsmGenre.Name = "tsmGenre";
            this.tsmGenre.Size = new System.Drawing.Size(55, 20);
            this.tsmGenre.Text = "Genres";
            // 
            // tsAdventure
            // 
            this.tsAdventure.Name = "tsAdventure";
            this.tsAdventure.Size = new System.Drawing.Size(180, 22);
            this.tsAdventure.Text = "Adventure";
            this.tsAdventure.Click += new System.EventHandler(this.SelectedGenre);
            // 
            // tsFantasy
            // 
            this.tsFantasy.Name = "tsFantasy";
            this.tsFantasy.Size = new System.Drawing.Size(180, 22);
            this.tsFantasy.Text = "Fantasy";
            this.tsFantasy.Click += new System.EventHandler(this.SelectedGenre);
            // 
            // tsSciFi
            // 
            this.tsSciFi.Name = "tsSciFi";
            this.tsSciFi.Size = new System.Drawing.Size(180, 22);
            this.tsSciFi.Text = "Sci-Fi";
            this.tsSciFi.Click += new System.EventHandler(this.SelectedGenre);
            // 
            // tsRomance
            // 
            this.tsRomance.Name = "tsRomance";
            this.tsRomance.Size = new System.Drawing.Size(180, 22);
            this.tsRomance.Text = "Romance";
            this.tsRomance.Click += new System.EventHandler(this.SelectedGenre);
            // 
            // tsHorror
            // 
            this.tsHorror.Name = "tsHorror";
            this.tsHorror.Size = new System.Drawing.Size(180, 22);
            this.tsHorror.Text = "Horror";
            this.tsHorror.Click += new System.EventHandler(this.SelectedGenre);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.genreBox);
            this.panel1.Location = new System.Drawing.Point(12, 27);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(399, 392);
            this.panel1.TabIndex = 1;
            // 
            // genreBox
            // 
            this.genreBox.FormattingEnabled = true;
            this.genreBox.Location = new System.Drawing.Point(3, 3);
            this.genreBox.Name = "genreBox";
            this.genreBox.Size = new System.Drawing.Size(393, 381);
            this.genreBox.TabIndex = 0;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslblName,
            this.tslblGenre});
            this.statusStrip1.Location = new System.Drawing.Point(0, 430);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(423, 22);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tslblName
            // 
            this.tslblName.Name = "tslblName";
            this.tslblName.Size = new System.Drawing.Size(0, 17);
            // 
            // tslblGenre
            // 
            this.tslblGenre.Name = "tslblGenre";
            this.tslblGenre.Size = new System.Drawing.Size(0, 17);
            // 
            // BrowseMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(423, 452);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "BrowseMenu";
            this.Text = "BrowseMenu";
            this.Load += new System.EventHandler(this.BrowseMenu_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem tsmGenre;
        private System.Windows.Forms.ToolStripMenuItem tsAdventure;
        private System.Windows.Forms.ToolStripMenuItem tsFantasy;
        private System.Windows.Forms.ToolStripMenuItem tsSciFi;
        private System.Windows.Forms.ToolStripMenuItem tsRomance;
        private System.Windows.Forms.ToolStripMenuItem tsHorror;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tslblName;
        private System.Windows.Forms.ListBox genreBox;
        private System.Windows.Forms.ToolStripStatusLabel tslblGenre;
    }
}