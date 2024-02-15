namespace WindowsFormsApp1
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
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.DisableText1 = new System.Windows.Forms.Button();
            this.EnableText1 = new System.Windows.Forms.Button();
            this.HideText1 = new System.Windows.Forms.Button();
            this.ShowText1 = new System.Windows.Forms.Button();
            this.TurnFormGreen = new System.Windows.Forms.Button();
            this.changeFormTitle = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(89, 89);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(257, 20);
            this.textBox1.TabIndex = 0;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(497, 89);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(234, 20);
            this.textBox2.TabIndex = 1;
            // 
            // DisableText1
            // 
            this.DisableText1.BackColor = System.Drawing.Color.DarkOrange;
            this.DisableText1.Location = new System.Drawing.Point(316, 130);
            this.DisableText1.Name = "DisableText1";
            this.DisableText1.Size = new System.Drawing.Size(193, 45);
            this.DisableText1.TabIndex = 2;
            this.DisableText1.Text = "c textBox1.Visible = false;";
            this.DisableText1.UseVisualStyleBackColor = false;
            this.DisableText1.Click += new System.EventHandler(this.DisableText1ToEffectOnText2_Click);
            // 
            // EnableText1
            // 
            this.EnableText1.BackColor = System.Drawing.Color.PeachPuff;
            this.EnableText1.Location = new System.Drawing.Point(316, 193);
            this.EnableText1.Name = "EnableText1";
            this.EnableText1.Size = new System.Drawing.Size(193, 45);
            this.EnableText1.TabIndex = 3;
            this.EnableText1.Text = "Enable";
            this.EnableText1.UseVisualStyleBackColor = false;
            this.EnableText1.Click += new System.EventHandler(this.EnableText1_Click);
            // 
            // HideText1
            // 
            this.HideText1.BackColor = System.Drawing.Color.BurlyWood;
            this.HideText1.Location = new System.Drawing.Point(524, 130);
            this.HideText1.Name = "HideText1";
            this.HideText1.Size = new System.Drawing.Size(193, 45);
            this.HideText1.TabIndex = 4;
            this.HideText1.Text = "HideText1";
            this.HideText1.UseVisualStyleBackColor = false;
            this.HideText1.Click += new System.EventHandler(this.button1_Click);
            // 
            // ShowText1
            // 
            this.ShowText1.BackColor = System.Drawing.Color.BurlyWood;
            this.ShowText1.Location = new System.Drawing.Point(524, 193);
            this.ShowText1.Name = "ShowText1";
            this.ShowText1.Size = new System.Drawing.Size(193, 45);
            this.ShowText1.TabIndex = 5;
            this.ShowText1.Text = "ShowText1";
            this.ShowText1.UseVisualStyleBackColor = false;
            this.ShowText1.Click += new System.EventHandler(this.ShowText1_Click);
            // 
            // TurnFormGreen
            // 
            this.TurnFormGreen.BackColor = System.Drawing.Color.PeachPuff;
            this.TurnFormGreen.Location = new System.Drawing.Point(100, 193);
            this.TurnFormGreen.Name = "TurnFormGreen";
            this.TurnFormGreen.Size = new System.Drawing.Size(193, 45);
            this.TurnFormGreen.TabIndex = 6;
            this.TurnFormGreen.Text = "TurnFormGreen";
            this.TurnFormGreen.UseVisualStyleBackColor = false;
            this.TurnFormGreen.Click += new System.EventHandler(this.TurnFormGreen_Click);
            // 
            // changeFormTitle
            // 
            this.changeFormTitle.BackColor = System.Drawing.Color.PeachPuff;
            this.changeFormTitle.Location = new System.Drawing.Point(100, 130);
            this.changeFormTitle.Name = "changeFormTitle";
            this.changeFormTitle.Size = new System.Drawing.Size(193, 45);
            this.changeFormTitle.TabIndex = 7;
            this.changeFormTitle.Text = "changeFormTitle";
            this.changeFormTitle.UseVisualStyleBackColor = false;
            this.changeFormTitle.Click += new System.EventHandler(this.changeFormTitle_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.changeFormTitle);
            this.Controls.Add(this.TurnFormGreen);
            this.Controls.Add(this.ShowText1);
            this.Controls.Add(this.HideText1);
            this.Controls.Add(this.EnableText1);
            this.Controls.Add(this.DisableText1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Name = "Form1";
            this.Text = "This the first Form";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button DisableText1;
        private System.Windows.Forms.Button EnableText1;
        private System.Windows.Forms.Button HideText1;
        private System.Windows.Forms.Button ShowText1;
        private System.Windows.Forms.Button TurnFormGreen;
        private System.Windows.Forms.Button changeFormTitle;
    }
}

