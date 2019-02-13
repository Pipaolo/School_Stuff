namespace _4th_Act
{
    partial class Form1
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
            this.txtUsername = new System.Windows.Forms.TextBox();
            this.txtInitialPass = new System.Windows.Forms.TextBox();
            this.txtFinalPass = new System.Windows.Forms.TextBox();
            this.btnRegister = new System.Windows.Forms.Button();
            this.lnkSwitchMenu = new System.Windows.Forms.LinkLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // txtUsername
            // 
            this.txtUsername.BackColor = System.Drawing.Color.Gainsboro;
            this.txtUsername.ForeColor = System.Drawing.SystemColors.WindowText;
            this.txtUsername.Location = new System.Drawing.Point(12, 19);
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.Size = new System.Drawing.Size(142, 20);
            this.txtUsername.TabIndex = 1;
            this.txtUsername.Click += new System.EventHandler(this.txtBoxUsername_Clicked);
            this.txtUsername.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Check_KeyPress);
            // 
            // txtInitialPass
            // 
            this.txtInitialPass.BackColor = System.Drawing.Color.Gainsboro;
            this.txtInitialPass.Location = new System.Drawing.Point(12, 69);
            this.txtInitialPass.Name = "txtInitialPass";
            this.txtInitialPass.Size = new System.Drawing.Size(142, 20);
            this.txtInitialPass.TabIndex = 1;
            this.txtInitialPass.Click += new System.EventHandler(this.txtBoxInitialPass_Clicked);
            this.txtInitialPass.Enter += new System.EventHandler(this.txtBoxInitialPass_Clicked);
            this.txtInitialPass.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Check_KeyPress);
            // 
            // txtFinalPass
            // 
            this.txtFinalPass.BackColor = System.Drawing.Color.Gainsboro;
            this.txtFinalPass.Location = new System.Drawing.Point(12, 100);
            this.txtFinalPass.Name = "txtFinalPass";
            this.txtFinalPass.Size = new System.Drawing.Size(142, 20);
            this.txtFinalPass.TabIndex = 1;
            this.txtFinalPass.Click += new System.EventHandler(this.txtBoxFinalPass_Clicked);
            this.txtFinalPass.Enter += new System.EventHandler(this.txtBoxFinalPass_Clicked);
            this.txtFinalPass.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Check_KeyPress);
            // 
            // btnRegister
            // 
            this.btnRegister.Location = new System.Drawing.Point(120, 297);
            this.btnRegister.Name = "btnRegister";
            this.btnRegister.Size = new System.Drawing.Size(75, 23);
            this.btnRegister.TabIndex = 2;
            this.btnRegister.Text = "Register";
            this.btnRegister.UseVisualStyleBackColor = true;
            this.btnRegister.Click += new System.EventHandler(this.btnRegister_Click);
            // 
            // lnkSwitchMenu
            // 
            this.lnkSwitchMenu.AutoSize = true;
            this.lnkSwitchMenu.Location = new System.Drawing.Point(49, 337);
            this.lnkSwitchMenu.Name = "lnkSwitchMenu";
            this.lnkSwitchMenu.Size = new System.Drawing.Size(222, 13);
            this.lnkSwitchMenu.TabIndex = 3;
            this.lnkSwitchMenu.TabStop = true;
            this.lnkSwitchMenu.Text = "Already have an account? Click here to login!";
            this.lnkSwitchMenu.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.lnkSwitchMenu_LinkClicked);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtUsername);
            this.groupBox1.Controls.Add(this.txtInitialPass);
            this.groupBox1.Controls.Add(this.txtFinalPass);
            this.groupBox1.Location = new System.Drawing.Point(74, 160);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(163, 131);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::_4th_Act.Properties.Resources._1;
            this.pictureBox1.Location = new System.Drawing.Point(86, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(142, 142);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.SeaGreen;
            this.ClientSize = new System.Drawing.Size(316, 359);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.btnRegister);
            this.Controls.Add(this.lnkSwitchMenu);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Register";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox txtUsername;
        private System.Windows.Forms.TextBox txtInitialPass;
        private System.Windows.Forms.TextBox txtFinalPass;
        private System.Windows.Forms.Button btnRegister;
        private System.Windows.Forms.LinkLabel lnkSwitchMenu;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

