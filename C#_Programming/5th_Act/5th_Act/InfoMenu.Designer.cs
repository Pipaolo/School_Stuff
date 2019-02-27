namespace _5th_Act
{
    partial class InfoMenu
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
            this.txtStudentName = new MaterialSkin.Controls.MaterialSingleLineTextField();
            this.txtStudentSection = new MaterialSkin.Controls.MaterialSingleLineTextField();
            this.materialLabel1 = new MaterialSkin.Controls.MaterialLabel();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.materialFlatButton1 = new MaterialSkin.Controls.MaterialFlatButton();
            this.pbTitle = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbTitle)).BeginInit();
            this.SuspendLayout();
            // 
            // txtStudentName
            // 
            this.txtStudentName.Depth = 0;
            this.txtStudentName.Hint = "";
            this.txtStudentName.Location = new System.Drawing.Point(59, 166);
            this.txtStudentName.MaxLength = 32767;
            this.txtStudentName.MouseState = MaterialSkin.MouseState.HOVER;
            this.txtStudentName.Name = "txtStudentName";
            this.txtStudentName.PasswordChar = '\0';
            this.txtStudentName.SelectedText = "";
            this.txtStudentName.SelectionLength = 0;
            this.txtStudentName.SelectionStart = 0;
            this.txtStudentName.Size = new System.Drawing.Size(211, 23);
            this.txtStudentName.TabIndex = 2;
            this.txtStudentName.TabStop = false;
            this.txtStudentName.Text = "Name of Examinee";
            this.txtStudentName.UseSystemPasswordChar = false;
            this.txtStudentName.Click += new System.EventHandler(this.studentName_isFocused);
            this.txtStudentName.Enter += new System.EventHandler(this.studentName_isFocused);
            // 
            // txtStudentSection
            // 
            this.txtStudentSection.Depth = 0;
            this.txtStudentSection.Hint = "";
            this.txtStudentSection.Location = new System.Drawing.Point(59, 204);
            this.txtStudentSection.MaxLength = 32767;
            this.txtStudentSection.MouseState = MaterialSkin.MouseState.HOVER;
            this.txtStudentSection.Name = "txtStudentSection";
            this.txtStudentSection.PasswordChar = '\0';
            this.txtStudentSection.SelectedText = "";
            this.txtStudentSection.SelectionLength = 0;
            this.txtStudentSection.SelectionStart = 0;
            this.txtStudentSection.Size = new System.Drawing.Size(211, 23);
            this.txtStudentSection.TabIndex = 3;
            this.txtStudentSection.TabStop = false;
            this.txtStudentSection.Text = "Section of Examinee";
            this.txtStudentSection.UseSystemPasswordChar = false;
            this.txtStudentSection.Click += new System.EventHandler(this.studentSection_isFocused);
            this.txtStudentSection.Enter += new System.EventHandler(this.studentSection_isFocused);
            // 
            // materialLabel1
            // 
            this.materialLabel1.AutoSize = true;
            this.materialLabel1.Depth = 0;
            this.materialLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.materialLabel1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(222)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.materialLabel1.Location = new System.Drawing.Point(55, 244);
            this.materialLabel1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialLabel1.Name = "materialLabel1";
            this.materialLabel1.Size = new System.Drawing.Size(149, 18);
            this.materialLabel1.TabIndex = 4;
            this.materialLabel1.Text = "Date of Examination: ";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(59, 266);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(200, 20);
            this.dateTimePicker1.TabIndex = 5;
            // 
            // materialFlatButton1
            // 
            this.materialFlatButton1.AutoSize = true;
            this.materialFlatButton1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.materialFlatButton1.Depth = 0;
            this.materialFlatButton1.Icon = null;
            this.materialFlatButton1.Location = new System.Drawing.Point(174, 295);
            this.materialFlatButton1.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.materialFlatButton1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialFlatButton1.Name = "materialFlatButton1";
            this.materialFlatButton1.Primary = false;
            this.materialFlatButton1.Size = new System.Drawing.Size(105, 36);
            this.materialFlatButton1.TabIndex = 6;
            this.materialFlatButton1.Text = "Start Exam";
            this.materialFlatButton1.UseVisualStyleBackColor = true;
            this.materialFlatButton1.Click += new System.EventHandler(this.materialFlatButton1_Click);
            // 
            // pbTitle
            // 
            this.pbTitle.BackColor = System.Drawing.SystemColors.Window;
            this.pbTitle.Image = global::_5th_Act.Properties.Resources.Capture;
            this.pbTitle.Location = new System.Drawing.Point(59, 79);
            this.pbTitle.Name = "pbTitle";
            this.pbTitle.Size = new System.Drawing.Size(311, 69);
            this.pbTitle.TabIndex = 1;
            this.pbTitle.TabStop = false;
            // 
            // InfoMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(436, 362);
            this.Controls.Add(this.materialFlatButton1);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.materialLabel1);
            this.Controls.Add(this.txtStudentSection);
            this.Controls.Add(this.txtStudentName);
            this.Controls.Add(this.pbTitle);
            this.Name = "InfoMenu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Identification";
            ((System.ComponentModel.ISupportInitialize)(this.pbTitle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbTitle;
        private MaterialSkin.Controls.MaterialSingleLineTextField txtStudentName;
        private MaterialSkin.Controls.MaterialSingleLineTextField txtStudentSection;
        private MaterialSkin.Controls.MaterialLabel materialLabel1;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private MaterialSkin.Controls.MaterialFlatButton materialFlatButton1;
    }
}