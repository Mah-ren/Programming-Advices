using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void DisableText1ToEffectOnText2_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
        }

        private void EnableText1_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Visible = false;
        }

        private void ShowText1_Click(object sender, EventArgs e)
        {
            textBox1.Visible = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void TurnFormGreen_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Cyan;
        }

        private void changeFormTitle_Click(object sender, EventArgs e)
        {
            this.Text = "Hello World";
        }
    }
}

