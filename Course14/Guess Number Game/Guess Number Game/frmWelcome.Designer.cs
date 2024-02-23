namespace Guess_Number_Game
{
    partial class frmWelcome
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmWelcome));
            this.lbPlay = new System.Windows.Forms.Label();
            this.pbLogo = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbLogo)).BeginInit();
            this.SuspendLayout();
            // 
            // lbPlay
            // 
            this.lbPlay.AutoSize = true;
            this.lbPlay.BackColor = System.Drawing.Color.Crimson;
            this.lbPlay.Cursor = System.Windows.Forms.Cursors.Hand;
            this.lbPlay.Font = new System.Drawing.Font("Showcard Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbPlay.ForeColor = System.Drawing.SystemColors.Window;
            this.lbPlay.Location = new System.Drawing.Point(242, 338);
            this.lbPlay.Name = "lbPlay";
            this.lbPlay.Size = new System.Drawing.Size(65, 27);
            this.lbPlay.TabIndex = 1;
            this.lbPlay.Text = "Play";
            this.lbPlay.Click += new System.EventHandler(this.lbPlay_Click);
            // 
            // pbLogo
            // 
            this.pbLogo.BackColor = System.Drawing.Color.Crimson;
            this.pbLogo.Image = ((System.Drawing.Image)(resources.GetObject("pbLogo.Image")));
            this.pbLogo.Location = new System.Drawing.Point(-2, -6);
            this.pbLogo.Name = "pbLogo";
            this.pbLogo.Size = new System.Drawing.Size(346, 407);
            this.pbLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pbLogo.TabIndex = 3;
            this.pbLogo.TabStop = false;
            // 
            // frmWelcome
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(339, 394);
            this.Controls.Add(this.lbPlay);
            this.Controls.Add(this.pbLogo);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmWelcome";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Guess Number Game";
            this.Move += new System.EventHandler(this.frmWelcome_Move);
            this.Resize += new System.EventHandler(this.frmWelcome_Resize);
            ((System.ComponentModel.ISupportInitialize)(this.pbLogo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbPlay;
        private System.Windows.Forms.PictureBox pbLogo;
    }
}