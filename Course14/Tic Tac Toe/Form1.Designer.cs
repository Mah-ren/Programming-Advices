namespace Tic_Tac_Toe
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lblTitle = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.bn1 = new System.Windows.Forms.Button();
            this.bn2 = new System.Windows.Forms.Button();
            this.bn3 = new System.Windows.Forms.Button();
            this.bn4 = new System.Windows.Forms.Button();
            this.bn5 = new System.Windows.Forms.Button();
            this.bn6 = new System.Windows.Forms.Button();
            this.bn7 = new System.Windows.Forms.Button();
            this.bn8 = new System.Windows.Forms.Button();
            this.bn9 = new System.Windows.Forms.Button();
            this.lblTurn = new System.Windows.Forms.Label();
            this.lblWinner = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.BackColor = System.Drawing.Color.Black;
            this.lblTitle.Font = new System.Drawing.Font("Tahoma", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.ForeColor = System.Drawing.Color.White;
            this.lblTitle.Location = new System.Drawing.Point(582, -2);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(613, 77);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Tic-Tac-Toe Game";
            this.lblTitle.Click += new System.EventHandler(this.label1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Black;
            this.label1.Font = new System.Drawing.Font("Algerian", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(60, 83);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(143, 54);
            this.label1.TabIndex = 1;
            this.label1.Text = "Turn";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Black;
            this.label2.Font = new System.Drawing.Font("Algerian", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(60, 319);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(200, 54);
            this.label2.TabIndex = 2;
            this.label2.Text = "Winner";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Aqua;
            this.button1.Font = new System.Drawing.Font("Algerian", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(60, 576);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(244, 71);
            this.button1.TabIndex = 3;
            this.button1.Text = "Restart Game";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // bn1
            // 
            this.bn1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn1.ForeColor = System.Drawing.Color.Black;
            this.bn1.Image = global::Tic_Tac_Toe.Properties.Resources.questionMark;
            this.bn1.Location = new System.Drawing.Point(915, 152);
            this.bn1.Name = "bn1";
            this.bn1.Size = new System.Drawing.Size(177, 127);
            this.bn1.TabIndex = 18;
            this.bn1.Tag = "?";
            this.bn1.UseVisualStyleBackColor = true;
            this.bn1.Click += new System.EventHandler(this.button_Click);
            // 
            // bn2
            // 
            this.bn2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn2.ForeColor = System.Drawing.Color.Black;
            this.bn2.Image = ((System.Drawing.Image)(resources.GetObject("bn2.Image")));
            this.bn2.Location = new System.Drawing.Point(1132, 152);
            this.bn2.Name = "bn2";
            this.bn2.Size = new System.Drawing.Size(177, 127);
            this.bn2.TabIndex = 19;
            this.bn2.Tag = "?";
            this.bn2.UseVisualStyleBackColor = true;
            this.bn2.Click += new System.EventHandler(this.button_Click);
            // 
            // bn3
            // 
            this.bn3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn3.ForeColor = System.Drawing.Color.Black;
            this.bn3.Image = ((System.Drawing.Image)(resources.GetObject("bn3.Image")));
            this.bn3.Location = new System.Drawing.Point(1357, 161);
            this.bn3.Name = "bn3";
            this.bn3.Size = new System.Drawing.Size(177, 127);
            this.bn3.TabIndex = 20;
            this.bn3.Tag = "?";
            this.bn3.UseVisualStyleBackColor = true;
            this.bn3.Click += new System.EventHandler(this.button_Click);
            // 
            // bn4
            // 
            this.bn4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn4.ForeColor = System.Drawing.Color.Black;
            this.bn4.Image = ((System.Drawing.Image)(resources.GetObject("bn4.Image")));
            this.bn4.Location = new System.Drawing.Point(915, 326);
            this.bn4.Name = "bn4";
            this.bn4.Size = new System.Drawing.Size(177, 127);
            this.bn4.TabIndex = 21;
            this.bn4.Tag = "?";
            this.bn4.UseVisualStyleBackColor = true;
            this.bn4.Click += new System.EventHandler(this.button_Click);
            // 
            // bn5
            // 
            this.bn5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn5.ForeColor = System.Drawing.Color.Black;
            this.bn5.Image = ((System.Drawing.Image)(resources.GetObject("bn5.Image")));
            this.bn5.Location = new System.Drawing.Point(1146, 326);
            this.bn5.Name = "bn5";
            this.bn5.Size = new System.Drawing.Size(177, 127);
            this.bn5.TabIndex = 22;
            this.bn5.Tag = "?";
            this.bn5.UseVisualStyleBackColor = true;
            this.bn5.Click += new System.EventHandler(this.button_Click);
            // 
            // bn6
            // 
            this.bn6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn6.ForeColor = System.Drawing.Color.Black;
            this.bn6.Image = ((System.Drawing.Image)(resources.GetObject("bn6.Image")));
            this.bn6.Location = new System.Drawing.Point(1362, 326);
            this.bn6.Name = "bn6";
            this.bn6.Size = new System.Drawing.Size(177, 127);
            this.bn6.TabIndex = 23;
            this.bn6.Tag = "?";
            this.bn6.UseVisualStyleBackColor = true;
            this.bn6.Click += new System.EventHandler(this.button_Click);
            // 
            // bn7
            // 
            this.bn7.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn7.ForeColor = System.Drawing.Color.Black;
            this.bn7.Image = ((System.Drawing.Image)(resources.GetObject("bn7.Image")));
            this.bn7.Location = new System.Drawing.Point(906, 482);
            this.bn7.Name = "bn7";
            this.bn7.Size = new System.Drawing.Size(177, 127);
            this.bn7.TabIndex = 24;
            this.bn7.Tag = "?";
            this.bn7.UseVisualStyleBackColor = true;
            this.bn7.Click += new System.EventHandler(this.button_Click);
            // 
            // bn8
            // 
            this.bn8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn8.ForeColor = System.Drawing.Color.Black;
            this.bn8.Image = ((System.Drawing.Image)(resources.GetObject("bn8.Image")));
            this.bn8.Location = new System.Drawing.Point(1133, 492);
            this.bn8.Name = "bn8";
            this.bn8.Size = new System.Drawing.Size(177, 127);
            this.bn8.TabIndex = 25;
            this.bn8.Tag = "?";
            this.bn8.UseVisualStyleBackColor = true;
            this.bn8.Click += new System.EventHandler(this.button_Click);
            // 
            // bn9
            // 
            this.bn9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.bn9.ForeColor = System.Drawing.Color.Black;
            this.bn9.Image = ((System.Drawing.Image)(resources.GetObject("bn9.Image")));
            this.bn9.Location = new System.Drawing.Point(1372, 492);
            this.bn9.Name = "bn9";
            this.bn9.Size = new System.Drawing.Size(177, 127);
            this.bn9.TabIndex = 26;
            this.bn9.Tag = "?";
            this.bn9.UseVisualStyleBackColor = true;
            this.bn9.Click += new System.EventHandler(this.button_Click);
            // 
            // lblTurn
            // 
            this.lblTurn.AutoSize = true;
            this.lblTurn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.lblTurn.Font = new System.Drawing.Font("Algerian", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTurn.ForeColor = System.Drawing.Color.Black;
            this.lblTurn.Location = new System.Drawing.Point(60, 161);
            this.lblTurn.Name = "lblTurn";
            this.lblTurn.Size = new System.Drawing.Size(240, 54);
            this.lblTurn.TabIndex = 27;
            this.lblTurn.Text = "Player1";
            this.lblTurn.Click += new System.EventHandler(this.lblTurn_Click);
            // 
            // lblWinner
            // 
            this.lblWinner.AutoSize = true;
            this.lblWinner.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.lblWinner.Font = new System.Drawing.Font("Algerian", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWinner.ForeColor = System.Drawing.Color.Black;
            this.lblWinner.Location = new System.Drawing.Point(60, 411);
            this.lblWinner.Name = "lblWinner";
            this.lblWinner.Size = new System.Drawing.Size(325, 54);
            this.lblWinner.TabIndex = 28;
            this.lblWinner.Text = "In Progress";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.ClientSize = new System.Drawing.Size(1547, 830);
            this.Controls.Add(this.lblWinner);
            this.Controls.Add(this.lblTurn);
            this.Controls.Add(this.bn9);
            this.Controls.Add(this.bn8);
            this.Controls.Add(this.bn7);
            this.Controls.Add(this.bn6);
            this.Controls.Add(this.bn5);
            this.Controls.Add(this.bn4);
            this.Controls.Add(this.bn3);
            this.Controls.Add(this.bn2);
            this.Controls.Add(this.bn1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lblTitle);
            this.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Name = "Form1";
            this.Text = "    ";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button bn1;
        private System.Windows.Forms.Button bn2;
        private System.Windows.Forms.Button bn3;
        private System.Windows.Forms.Button bn4;
        private System.Windows.Forms.Button bn5;
        private System.Windows.Forms.Button bn6;
        private System.Windows.Forms.Button bn7;
        private System.Windows.Forms.Button bn8;
        private System.Windows.Forms.Button bn9;
        private System.Windows.Forms.Label lblTurn;
        private System.Windows.Forms.Label lblWinner;
    }
}

