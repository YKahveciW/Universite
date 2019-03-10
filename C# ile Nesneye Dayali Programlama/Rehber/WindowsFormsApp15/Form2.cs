using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security;

namespace WindowsFormsApp15
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        private void comboBoxAd_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void comboBoxSoyad_SelectedIndexChanged(object sender, EventArgs e)
        { 
        }

        private void comboBoxNumara_SelectedIndexChanged(object sender, EventArgs e)
        {
        }
        
        private void ButtonKaydet_Click(object sender, EventArgs e)
        {
            if ((comboBoxAd.SelectedIndex==0|| comboBoxAd.SelectedIndex == 1 || comboBoxAd.SelectedIndex == 2 )&& (comboBoxNumara.SelectedIndex==0|| comboBoxNumara.SelectedIndex == 1 || comboBoxNumara.SelectedIndex == 2 )&&(comboBoxNumara.SelectedIndex==0|| comboBoxNumara.SelectedIndex == 1 || comboBoxNumara.SelectedIndex == 2))
            {
                try
                {

                    StreamWriter yazmaislemi = new StreamWriter("Rehber.txt",true);
                    yazmaislemi.Write(comboBoxAd.SelectedIndex + " " + comboBoxSoyad.SelectedIndex + " " + comboBoxNumara.SelectedIndex + " " + textBoxAd.Text + " " + textBoxSoyad.Text + " " + TelTaxtBox.Text + Environment.NewLine);
                    yazmaislemi.Close();
                    LabelForm2Uyari.Text = "Kayit Yapilmistir.";
                }
                catch (Exception)
                {
                    LabelForm2Uyari.Text = "Kayit Yapilamamistir.";
                }
            }
            else
            {
                MessageBox.Show("Renk Kutulari Bos Birakilamaz!");
            }
        }

        private void TelTaxtBox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
