using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDI_Sample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private Form form2 = new Form2();
        private void button1_Click(object sender, EventArgs e)
        {
            form2.MdiParent = this;
            form2.Show();
        }
    }
}
