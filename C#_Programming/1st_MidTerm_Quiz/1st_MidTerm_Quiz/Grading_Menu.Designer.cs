namespace _1st_MidTerm_Quiz
{
    partial class Student_Identification
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
            this.txtFirstN = new System.Windows.Forms.TextBox();
            this.txtLastN = new System.Windows.Forms.TextBox();
            this.txtMiddleN = new System.Windows.Forms.TextBox();
            this.lblFirstN = new System.Windows.Forms.Label();
            this.lblLastN = new System.Windows.Forms.Label();
            this.lblMiddleN = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnSubmit = new System.Windows.Forms.Button();
            this.lblSection = new System.Windows.Forms.Label();
            this.txtSection = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtFirstN
            // 
            this.txtFirstN.Location = new System.Drawing.Point(124, 47);
            this.txtFirstN.Name = "txtFirstN";
            this.txtFirstN.Size = new System.Drawing.Size(168, 20);
            this.txtFirstN.TabIndex = 0;
            // 
            // txtLastN
            // 
            this.txtLastN.Location = new System.Drawing.Point(125, 79);
            this.txtLastN.Name = "txtLastN";
            this.txtLastN.Size = new System.Drawing.Size(168, 20);
            this.txtLastN.TabIndex = 1;
            // 
            // txtMiddleN
            // 
            this.txtMiddleN.Location = new System.Drawing.Point(125, 109);
            this.txtMiddleN.Name = "txtMiddleN";
            this.txtMiddleN.Size = new System.Drawing.Size(168, 20);
            this.txtMiddleN.TabIndex = 2;
            // 
            // lblFirstN
            // 
            this.lblFirstN.AutoSize = true;
            this.lblFirstN.Location = new System.Drawing.Point(61, 53);
            this.lblFirstN.Name = "lblFirstN";
            this.lblFirstN.Size = new System.Drawing.Size(60, 13);
            this.lblFirstN.TabIndex = 3;
            this.lblFirstN.Text = "First Name:";
            // 
            // lblLastN
            // 
            this.lblLastN.AutoSize = true;
            this.lblLastN.Location = new System.Drawing.Point(62, 86);
            this.lblLastN.Name = "lblLastN";
            this.lblLastN.Size = new System.Drawing.Size(61, 13);
            this.lblLastN.TabIndex = 4;
            this.lblLastN.Text = "Last Name:";
            // 
            // lblMiddleN
            // 
            this.lblMiddleN.AutoSize = true;
            this.lblMiddleN.Location = new System.Drawing.Point(51, 112);
            this.lblMiddleN.Name = "lblMiddleN";
            this.lblMiddleN.Size = new System.Drawing.Size(72, 13);
            this.lblMiddleN.TabIndex = 5;
            this.lblMiddleN.Text = "Middle Name:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnSubmit);
            this.groupBox1.Controls.Add(this.lblSection);
            this.groupBox1.Controls.Add(this.txtSection);
            this.groupBox1.Controls.Add(this.txtMiddleN);
            this.groupBox1.Controls.Add(this.lblMiddleN);
            this.groupBox1.Controls.Add(this.txtFirstN);
            this.groupBox1.Controls.Add(this.lblLastN);
            this.groupBox1.Controls.Add(this.lblFirstN);
            this.groupBox1.Controls.Add(this.txtLastN);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(403, 196);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Student Identification";
            // 
            // btnSubmit
            // 
            this.btnSubmit.Location = new System.Drawing.Point(170, 173);
            this.btnSubmit.Name = "btnSubmit";
            this.btnSubmit.Size = new System.Drawing.Size(75, 23);
            this.btnSubmit.TabIndex = 7;
            this.btnSubmit.Text = "Submit";
            this.btnSubmit.UseVisualStyleBackColor = true;
            this.btnSubmit.Click += new System.EventHandler(this.btnSubmit_Click);
            // 
            // lblSection
            // 
            this.lblSection.AutoSize = true;
            this.lblSection.Location = new System.Drawing.Point(77, 141);
            this.lblSection.Name = "lblSection";
            this.lblSection.Size = new System.Drawing.Size(46, 13);
            this.lblSection.TabIndex = 7;
            this.lblSection.Text = "Section:";
            // 
            // txtSection
            // 
            this.txtSection.Location = new System.Drawing.Point(125, 135);
            this.txtSection.Name = "txtSection";
            this.txtSection.Size = new System.Drawing.Size(168, 20);
            this.txtSection.TabIndex = 6;
            this.txtSection.KeyDown += new System.Windows.Forms.KeyEventHandler(this.checkKeypress);
            // 
            // Student_Identification
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(431, 247);
            this.Controls.Add(this.groupBox1);
            this.Name = "Student_Identification";
            this.Text = "Student_Identification";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox txtFirstN;
        private System.Windows.Forms.TextBox txtLastN;
        private System.Windows.Forms.TextBox txtMiddleN;
        private System.Windows.Forms.Label lblFirstN;
        private System.Windows.Forms.Label lblLastN;
        private System.Windows.Forms.Label lblMiddleN;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lblSection;
        private System.Windows.Forms.TextBox txtSection;
        private System.Windows.Forms.Button btnSubmit;
    }
}