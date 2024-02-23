using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Timer.Properties;

namespace Timer
{
    public partial class Form1 : Form
    {
        int counter = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
            


            int count = 12;            
            for (short i = 0; i < count; i++)
            {
                label1.Text = i.ToString();

                if (count <= 4)
                    pictureBox1.Image = Resources.صلي_على_محمد1;

                else if (count >= 8)
                    pictureBox1.Image = Resources.صلي_على_محمد2;
            
                else
                    pictureBox1.Image = Resources.صلى_على_محمد3;


            }
        }


        private void Start_Timer(object sender, EventArgs e)
        {

            timer1.Enabled = true;
        }

        private void End_Timer(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("You Stoped the timer, Are you sure you wanna stop the timer? ", "Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (result == DialogResult.OK)
            {
                timer1.Enabled = false;
            }
            else
                timer1.Enabled = true;

        }
    }
}
