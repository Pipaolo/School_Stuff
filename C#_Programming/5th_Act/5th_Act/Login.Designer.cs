namespace _5th_Act
{
    partial class Login
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
            this.txtUsername = new MaterialSkin.Controls.MaterialSingleLineTextField();
            this.txtPassword = new MaterialSkin.Controls.MaterialSingleLineTextField();
            this.btnSubmit = new MaterialSkin.Controls.MaterialFlatButton();
            this.pbTitle = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbTitle)).BeginInit();
            this.SuspendLayout();
            // 
            // txtUsername
            // 
            this.txtUsername.Depth = 0;
            this.txtUsername.Hint = "";
            this.txtUsername.Location = new System.Drawing.Point(97, 211);
            this.txtUsername.MaxLength = 32767;
            this.txtUsername.MouseState = MaterialSkin.MouseState.HOVER;
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.PasswordChar = '\0';
            this.txtUsername.SelectedText = "";
            this.txtUsername.SelectionLength = 0;
            this.txtUsername.SelectionStart = 0;
            this.txtUsername.Size = new System.Drawing.Size(250, 23);
            this.txtUsername.TabIndex = 1;
            this.txtUsername.TabStop = false;
            this.txtUsername.Text = "Username";
            this.txtUsername.UseSystemPasswordChar = false;
            this.txtUsername.Click += new System.EventHandler(this.username_isFocused);
            // 
            // txtPassword
            // 
            this.txtPassword.Depth = 0;
            this.txtPassword.Hint = "";
            this.txtPassword.Location = new System.Drawing.Point(97, 261);
            this.txtPassword.MaxLength = 32767;
            this.txtPassword.MouseState = MaterialSkin.MouseState.HOVER;
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '\0';
            this.txtPassword.SelectedText = "";
            this.txtPassword.SelectionLength = 0;
            this.txtPassword.SelectionStart = 0;
            this.txtPassword.Size = new System.Drawing.Size(250, 23);
            this.txtPassword.TabIndex = 2;
            this.txtPassword.TabStop = false;
            this.txtPassword.Text = "Password";
            this.txtPassword.UseSystemPasswordChar = false;
            this.txtPassword.Click += new System.EventHandler(this.password_isFocused);
            this.txtPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.checkKeyPress);
            // 
            // btnSubmit
            // 
            this.btnSubmit.AutoSize = true;
            this.btnSubmit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnSubmit.Depth = 0;
            this.btnSubmit.Icon = null;
            this.btnSubmit.Location = new System.Drawing.Point(192, 293);
            this.btnSubmit.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnSubmit.MouseState = MaterialSkin.MouseState.HOVER;
            this.btnSubmit.Name = "btnSubmit";
            this.btnSubmit.Primary = false;
            this.btnSubmit.Size = new System.Drawing.Size(61, 36);
            this.btnSubmit.TabIndex = 3;
            this.btnSubmit.Text = "Login";
            this.btnSubmit.UseVisualStyleBackColor = true;
            this.btnSubmit.Click += new System.EventHandler(this.btnLogin_Pressed);
            // 
            // pbTitle
            // 
            this.pbTitle.BackColor = System.Drawing.SystemColors.Window;
            this.pbTitle.Image = global::_5th_Act.Properties.Resources.Capture;
            this.pbTitle.Location = new System.Drawing.Point(61, 78);
            this.pbTitle.Name = "pbTitle";
            this.pbTitle.Size = new System.Drawing.Size(311, 69);
            this.pbTitle.TabIndex = 0;
            this.pbTitle.TabStop = false;
            // 
            // Login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(440, 419);
            this.Controls.Add(this.btnSubmit);
            this.Controls.Add(this.txtPassword);
            this.Controls.Add(this.txtUsername);
            this.Controls.Add(this.pbTitle);
            this.Name = "Login";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Load += new System.EventHandler(this.Login_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pbTitle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbTitle;
        private MaterialSkin.Controls.MaterialSingleLineTextField txtUsername;
        private MaterialSkin.Controls.MaterialSingleLineTextField txtPassword;
        private MaterialSkin.Controls.MaterialFlatButton btnSubmit;
    }
}

