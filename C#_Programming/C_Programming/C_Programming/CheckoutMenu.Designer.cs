namespace C_Programming
{
    partial class CheckoutMenu
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
            this.rtxtCheckout = new System.Windows.Forms.RichTextBox();
            this.btnRent = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // rtxtCheckout
            // 
            this.rtxtCheckout.Location = new System.Drawing.Point(12, 12);
            this.rtxtCheckout.Name = "rtxtCheckout";
            this.rtxtCheckout.Size = new System.Drawing.Size(399, 185);
            this.rtxtCheckout.TabIndex = 0;
            this.rtxtCheckout.TabStop = false;
            this.rtxtCheckout.Text = "";
            // 
            // btnRent
            // 
            this.btnRent.Location = new System.Drawing.Point(145, 203);
            this.btnRent.Name = "btnRent";
            this.btnRent.Size = new System.Drawing.Size(139, 46);
            this.btnRent.TabIndex = 1;
            this.btnRent.Text = "Rent Out";
            this.btnRent.UseVisualStyleBackColor = true;
            this.btnRent.Click += new System.EventHandler(this.btnRent_Click);
            // 
            // CheckoutMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(423, 257);
            this.Controls.Add(this.btnRent);
            this.Controls.Add(this.rtxtCheckout);
            this.Name = "CheckoutMenu";
            this.Text = "CheckoutMenu";
            this.Load += new System.EventHandler(this.CheckoutMenu_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtxtCheckout;
        private System.Windows.Forms.Button btnRent;
    }
}