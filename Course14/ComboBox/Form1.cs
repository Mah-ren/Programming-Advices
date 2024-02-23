using ComboBox.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ComboBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex)
            {
                case (0):
                    lblTitle.Text = "أحمد أبو فتحي";
                    pictureBox1.Image = Resources.أحمد_أبو_فتحي;
                    break;
                case (1):
                    lblTitle.Text = "الشيخ محسن";
                    pictureBox1.Image = Resources.الشيخ_محسن;
                    break;
                case (2):
                    lblTitle.Text = "بحبح";
                    pictureBox1.Image = Resources.بحبح;
                    break;
                case (3):
                    lblTitle.Text = "جدي لطفي";
                    pictureBox1.Image = Resources.جدي_لطفي;
                    break;
                case (4):
                    lblTitle.Text = "حصان";
                    pictureBox1.Image = Resources.حصان;
                    break;
                case (5):
                    lblTitle.Text = "دين";
                    pictureBox1.Image = Resources.دين;
                    break;
                case (6):
                    lblTitle.Text = "قطة";
                    pictureBox1.Image = Resources.قطة;
                    break;
                case (7):
                    lblTitle.Text = "محمد";
                    pictureBox1.Image = Resources.محمد;
                    break;
                default:
                    lblTitle.Text = "بحبح";
                    pictureBox1.Image = Resources.بحبح;
                    break;
            }

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = null;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 2;
            pictureBox1.Image = Resources.بحبح;
        }

        
    }
}
