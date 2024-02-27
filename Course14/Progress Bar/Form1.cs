using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Progress_Bar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void startDownloading(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            progressBar1.Minimum = 0;
            progressBar1.Maximum = 100;

            for (short i = 0; i < 10; ++i)
            {

                if (progressBar1.Value < progressBar1.Maximum)
                {
                
                    Thread.Sleep(500);
                    progressBar1.Value += 10;
                    label1.Text = (((float)progressBar1.Value / progressBar1.Maximum) * 100)+ "%";

                    progressBar1.Refresh();
                    label1.Refresh();
             
                }

                else
                    button1.Enabled = false;

            }
        }    
    
        private void restartDownloading(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            label1.Text = "0%";    
        }

        private void showProgressBar(object sender, EventArgs e)
        {
            if (progressBar1.Visible) 
                progressBar1.Visible = false;
            else
                progressBar1.Visible = true;
        }


    }
}
