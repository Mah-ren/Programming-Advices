namespace Lilst_View
{
    partial class MainForm
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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.btnNumericUpDown = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnTabControl = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Coral;
            this.button1.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button1.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.button1.Location = new System.Drawing.Point(2, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(339, 50);
            this.button1.TabIndex = 0;
            this.button1.Text = "Show List View Form";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.CornflowerBlue;
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.button2.Location = new System.Drawing.Point(2, 99);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(418, 50);
            this.button2.TabIndex = 1;
            this.button2.Text = "Show TrackBar_Zoom";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // btnNumericUpDown
            // 
            this.btnNumericUpDown.BackColor = System.Drawing.Color.Crimson;
            this.btnNumericUpDown.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnNumericUpDown.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.btnNumericUpDown.Location = new System.Drawing.Point(2, 186);
            this.btnNumericUpDown.Name = "btnNumericUpDown";
            this.btnNumericUpDown.Size = new System.Drawing.Size(418, 50);
            this.btnNumericUpDown.TabIndex = 2;
            this.btnNumericUpDown.Text = "Numeric Up Down";
            this.btnNumericUpDown.UseVisualStyleBackColor = false;
            this.btnNumericUpDown.Click += new System.EventHandler(this.button3_Click);
            // 
            // btnClose
            // 
            this.btnClose.BackColor = System.Drawing.Color.Crimson;
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.btnClose.Location = new System.Drawing.Point(1204, 699);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(132, 50);
            this.btnClose.TabIndex = 3;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = false;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnTabControl
            // 
            this.btnTabControl.BackColor = System.Drawing.Color.Aqua;
            this.btnTabControl.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnTabControl.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.btnTabControl.Location = new System.Drawing.Point(-7, 273);
            this.btnTabControl.Name = "btnTabControl";
            this.btnTabControl.Size = new System.Drawing.Size(339, 50);
            this.btnTabControl.TabIndex = 4;
            this.btnTabControl.Text = "Tab Control";
            this.btnTabControl.UseVisualStyleBackColor = false;
            this.btnTabControl.Click += new System.EventHandler(this.btnTabControl_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.Aqua;
            this.button3.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button3.Font = new System.Drawing.Font("Tahoma", 25F, System.Drawing.FontStyle.Bold);
            this.button3.Location = new System.Drawing.Point(2, 362);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(339, 50);
            this.button3.TabIndex = 5;
            this.button3.Text = "Color Dialoge";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click_1);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkCyan;
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(1348, 761);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.btnTabControl);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnNumericUpDown);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "MainForm";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button btnNumericUpDown;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnTabControl;
        private System.Windows.Forms.Button button3;
    }
}