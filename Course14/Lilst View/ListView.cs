using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lilst_View
{
    public partial class ListView : Form
    {
        public ListView()
        {
            InitializeComponent();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        

        private void lbl1_click(object sender, EventArgs e)
        {

        }



        private void remove_button_click(object sender, EventArgs e)
        {
            try
            {

                if (listView1.Items.Count == 1)
                    listView1.Items.Remove(listView1.SelectedItems[0]);
                
                else
                {

                    foreach (ListViewItem item in listView1.SelectedItems)
                    {
                        listView1.Items.Remove(item);
                    }

                    // another way to remove all the selected items 
                    //for (int i = listView1.SelectedItems.Count - 1; i >= 0; i--)
                    //{
                    //    ListViewItem item = listView1.SelectedItems[i];
                    //    listView1.Items.Remove(item);
                    //}
                }

                

            }
            catch (Exception)
            {

                throw;
            }


         
        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void bnCancel_Click(object sender, EventArgs e)
        {
            this.Close();            
        }

        private void cmbxView_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.LargeIcon;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.SmallIcon;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.Details;
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.List;
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.Tile;
        }

        private void bnFillRandom_Click(object sender, EventArgs e)
        {
            try
            {

                for (int i = 1; i <= 10; i++)
                {
                    ListViewItem item = new ListViewItem(i.ToString());

                    if (i % 2 == 0)
                        item.ImageIndex = 1;
                    else
                        item.ImageIndex = 0;


                    item.SubItems.Add("Person" + i);
                    listView1.Items.Add(item);
                }
        }
            catch (Exception)
            {

                MessageBox.Show("This is an error in Fill random function", "Warning",MessageBoxButtons.OK,
                    MessageBoxIcon.Warning);

            }

}

        private void ID_Validating(object sender, CancelEventArgs e)
        {
            if (string.IsNullOrEmpty(txtID.Text))
            {
                e.Cancel = true;
                txtID.Focus();
                errorProvider1.SetError(txtID, "ID is required!");
            }

            else
            {
                e.Cancel = false;
                errorProvider1.SetError(txtID, "");
            }
        }

        private void Name_Validating(object sender, CancelEventArgs e)
        {
            if (string.IsNullOrEmpty(txtName.Text))
            {
                e.Cancel = true;
                txtID.Focus();
                errorProvider1.SetError(txtName, "ID is required!");
            }

            else
            {
                e.Cancel = false;
                errorProvider1.SetError(txtName, "");
            }
        }

        private void rbMale_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void btnAdd_click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtID.Text) || string.IsNullOrEmpty(txtName.Text))
                return;

            ListViewItem item = new ListViewItem(txtID.Text.Trim());

            item.SubItems.Add(txtName.Text.Trim());

            if (rbMale.Checked)
            {
                item.ImageIndex = 0;
                //item.SubItems.Add(rbMale.Text);
            }
            else
            {
                item.ImageIndex = 1;
                //item.SubItems.Add(rbFemale.Text);
            }




            listView1.Items.Add(item);

            txtID.Clear();
            txtName.Clear();

            txtID.Focus();


        }
    }
}
