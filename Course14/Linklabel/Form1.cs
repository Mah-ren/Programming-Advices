using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Linklabel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

         
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.ProcessStartInfo psi = new System.Diagnostics.ProcessStartInfo();
            psi.UseShellExecute = true;
            psi.FileName = "chrome.exe"; // Change this to your browser's executable
            psi.Arguments = "cognito www.ProgrammingAdvices.com"; 

            System.Diagnostics.Process.Start(psi);
        }
    }
}
