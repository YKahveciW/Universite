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
using System.IO.MemoryMappedFiles;

namespace WindowsFormsApp15
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void buttonListele_Click(object sender, EventArgs e)
        {
            int AralikElemanSayisi, RenkElemanSayisi;
            AralikElemanSayisi = 0;
            RenkElemanSayisi = 0;
            int[] aralik = new int[60];
            int[] renk = new int[42];
            using (var mappedFile1 = MemoryMappedFile.CreateFromFile("Rehber.txt"))
            {
                using (Stream mmStream = mappedFile1.CreateViewStream())
                {
                    using (StreamReader okunandosya = new StreamReader(mmStream, ASCIIEncoding.ASCII))
                    {
                        
                        int KacinciKelimeyiOkuyor = 1;
                        int kelimeuzunluk=0;
                        while (!okunandosya.EndOfStream)
                        {
                            var line = okunandosya.ReadLine();

                            foreach (var okunankelime in line.Split(' '))
                            {
                                if (KacinciKelimeyiOkuyor == 1|| KacinciKelimeyiOkuyor == 2|| KacinciKelimeyiOkuyor == 3)
                                {
                                    if (okunankelime == "0" || okunankelime == "1" || okunankelime == "2")
                                    {
                                        renk[RenkElemanSayisi] = Convert.ToInt32(okunankelime);
                                        RenkElemanSayisi++;
                                    }
                                }
                                if (KacinciKelimeyiOkuyor == 4 || KacinciKelimeyiOkuyor == 5)
                                {
                                    AralikElemanSayisi++;
                                    kelimeuzunluk = kelimeuzunluk + okunankelime.Length;
                                    richTextBox1.AppendText(okunankelime + " ");
                                    aralik[AralikElemanSayisi] = kelimeuzunluk;
                                }
                                if (KacinciKelimeyiOkuyor == 6 )
                                {
                                    AralikElemanSayisi++;
                                    kelimeuzunluk = kelimeuzunluk + okunankelime.Length;
                                    richTextBox1.AppendText(okunankelime + "\n");
                                    aralik[AralikElemanSayisi] = kelimeuzunluk;
                                }
                                if (KacinciKelimeyiOkuyor == 6)
                                {
                                    KacinciKelimeyiOkuyor = 0;
                                }
                                KacinciKelimeyiOkuyor += 1;

                            }
                        }
                    }
                }
            }
            int r = 0;
            for(int i=0;i<=RenkElemanSayisi;i++)
            {
                if (i==0)
                {
                    
                    if (renk[r] == 0)
                    {
                        richTextBox1.Select(0, aralik[1]+i);
                        richTextBox1.SelectionColor = Color.Red;
                    }
                    if (renk[r] == 1)
                    {
                        richTextBox1.Select(0, aralik[1]+i);
                        richTextBox1.SelectionColor = Color.Green;
                    }
                    if (renk[r] == 2)
                    {
                        richTextBox1.Select(0, aralik[1]+i);
                        richTextBox1.SelectionColor = Color.Blue;
                    }
                }
                else
                {

                    if (renk[r] == 0)
                    {
                        richTextBox1.Select(aralik[i]+i, aralik[i+1]+i);
                        richTextBox1.SelectionColor = Color.Red;
                    }
                    if (renk[r] == 1)
                    {
                        richTextBox1.Select(aralik[i] + i, aralik[i+1]+i);
                        richTextBox1.SelectionColor = Color.Green;
                    }
                    if (renk[r] == 2)
                    {
                        richTextBox1.Select(aralik[i] + i, aralik[i+1]+i);
                        richTextBox1.SelectionColor = Color.Blue;
                    }
                }
               
                r++;
            }





        }
        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}