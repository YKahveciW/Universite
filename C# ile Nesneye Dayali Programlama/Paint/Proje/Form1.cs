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

namespace Proje
{
    public partial class Form1 : Form
    {
        Sekiller seklim = new Sekiller();
        Sekiller[] sekillers = new Sekiller[100];
        public Color[] RenkDizim = new Color[100];
        int[] NeSekli = new int[100];
        int sekilsayisi = 0;
        bool Aktiflik = false;
        bool Kareaktif = false;
        bool Daireaktif = false;
        bool ucgenaktif = false;
        bool altigenaktif = false;
        Color paintcolor = Color.Red;
        bool NoktaAktif = false;
        int Kacincinesneyedokundu;
        bool yeninesneyedokun = false;
        bool SilAktif = false;
        bool renkdegistir = false;
        bool Silmekontrol = false;
        public Form1()
        {
            InitializeComponent();
        }
        private void Kare_Click(object sender, EventArgs e)
        {
            Kareaktif = true;
            Daireaktif = false;
            ucgenaktif = false;
            altigenaktif = false;
        }

        private void Daire_Click(object sender, EventArgs e)
        {
            Kareaktif = false;
            Daireaktif = true;
            ucgenaktif = false;
            altigenaktif = false;
        }

        private void ucgen_Click(object sender, EventArgs e)
        {
            Kareaktif = false;
            Daireaktif = false;
            ucgenaktif = true;
            altigenaktif = false;
        }

        private void Altigen_Click(object sender, EventArgs e)
        {
            Kareaktif = false;
            Daireaktif = false;
            ucgenaktif = false;
            altigenaktif = true;
        }



        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            Aktiflik = false;
            if (seklim.X2 != 0 && seklim.Y2 != 0)
            {
                sekillers[sekilsayisi] = seklim;
                sekilsayisi++;
            }


        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (Aktiflik == true && NoktaAktif == false)
            {
                if (e.X > 25 && e.Y > 23 && e.X < 557 && e.Y < 403)
                {
                    seklim.X2 = e.X;
                    seklim.Y2 = e.Y;
                }
                Invalidate();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            seklim = new Sekiller();
            if (e.X > 25 && e.Y > 23 && e.X < 557 && e.Y < 403)
            {
                seklim.X = e.X;
                seklim.Y = e.Y;
            }
            Invalidate();
            Aktiflik = true;

        }
        private void kirmizi_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Red;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }
        }

        private void Mavi_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Blue;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }

        private void yesil_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Green;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }

        private void turuncu_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Orange;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }
        }

        private void siyah_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Black;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }

        private void mor_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Purple;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }

        private void sari_Click(object sender, EventArgs e)
        {
            paintcolor = Color.Yellow;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }

        private void beyaz_Click(object sender, EventArgs e)
        {
            paintcolor = Color.White;
            if (NoktaAktif == true)
            {
                renkdegistir = true;
            }

        }
        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if (SilAktif == true)
            {
                Silmekontrol = true;
            }
            if (NoktaAktif == true)
            {
                for (int i = 0; i < sekilsayisi; i++)
                {
                    if (sekillers[i].X < e.X && sekillers[i].Y < e.Y && sekillers[i].X2 > e.X && sekillers[i].Y2 > e.Y ||
                        sekillers[i].X > e.X && sekillers[i].Y > e.Y && sekillers[i].X2 < e.X && sekillers[i].Y2 < e.Y ||
                        sekillers[i].X > e.X && sekillers[i].Y < e.Y && sekillers[i].X2 < e.X && sekillers[i].Y2 > e.Y ||
                        sekillers[i].X < e.X && sekillers[i].Y > e.Y && sekillers[i].X2 > e.X && sekillers[i].Y2 < e.Y)
                    {
                        Kacincinesneyedokundu = i;
                        yeninesneyedokun = true;
                        if (SilAktif == true && Silmekontrol == true)
                        {
                            NeSekli[Kacincinesneyedokundu] = 5;
                            sekillers[Kacincinesneyedokundu].X = 570;
                            sekillers[Kacincinesneyedokundu].Y = 420;
                            sekillers[Kacincinesneyedokundu].X2 = 570;
                            sekillers[Kacincinesneyedokundu].Y2 = 420;
                            SilAktif = false;
                            Sil.BackColor = Color.Red;
                            Silmekontrol = false;
                        }
                        break;
                    }

                    if (!(sekillers[i].X < e.X && sekillers[i].Y < e.Y && sekillers[i].X2 > e.X && sekillers[i].Y2 > e.Y))
                    {
                        yeninesneyedokun = false;
                    }

                }
                if (NoktaAktif == true && yeninesneyedokun == true && SilAktif == false && renkdegistir == true)
                {
                    RenkDizim[Kacincinesneyedokundu] = paintcolor;
                    yeninesneyedokun = false;
                    renkdegistir = false;
                }
            }
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics cizimAraci = e.Graphics;
            if (Aktiflik == true)
            {
                if (NoktaAktif == false)
                {
                    if (Kareaktif == true)
                    {
                        seklim.Kareciz(cizimAraci, paintcolor);
                        NeSekli[sekilsayisi] = 1;
                    }
                    if (Daireaktif == true)
                    {
                        seklim.Daireciz(cizimAraci, paintcolor);
                        NeSekli[sekilsayisi] = 2;
                    }
                    if (ucgenaktif == true)
                    {
                        seklim.Ucgenciz(cizimAraci, paintcolor);
                        NeSekli[sekilsayisi] = 3;
                    }
                    if (altigenaktif == true)
                    {
                        seklim.Altigen(cizimAraci, paintcolor);
                        NeSekli[sekilsayisi] = 4;
                    }
                    RenkDizim[sekilsayisi] = paintcolor;
                }
            }
            for (int i = 0; i < sekilsayisi; i++)
            {
                if (sekillers[i] != null)
                {
                    if (NeSekli[i] == 1)
                    {
                        sekillers[i].Kareciz(cizimAraci, RenkDizim[i]);
                    }
                    if (NeSekli[i] == 2)
                    {
                        sekillers[i].Daireciz(cizimAraci, RenkDizim[i]);
                    }
                    if (NeSekli[i] == 3)
                    {
                        sekillers[i].Ucgenciz(cizimAraci, RenkDizim[i]);
                    }
                    if (NeSekli[i] == 4)
                    {
                        sekillers[i].Altigen(cizimAraci, RenkDizim[i]);
                    }
                    if (NeSekli[i] == 5)
                    {
                        continue;
                    }

                }
            }
        }

        private void nokta_Click(object sender, EventArgs e)
        {
            if (NoktaAktif == false)
            {
                NoktaAktif = true;
                nokta.BackColor = Color.Green;
            }
            else
            {
                NoktaAktif = false;
                nokta.BackColor = Color.Red;
            }
        }

        private void Sil_Click(object sender, EventArgs e)
        {

            if (SilAktif == false)
            {
                SilAktif = true;
                Sil.BackColor = Color.Green;
            }
            else
            {
                SilAktif = false;
                Sil.BackColor = Color.Red;
            }
        }

        private void kayit_Click(object sender, EventArgs e)
        {
            SaveFileDialog DosyaKayit = new SaveFileDialog();
            if (DosyaKayit.ShowDialog() == DialogResult.OK)
            {
                using (Stream s = File.Open(DosyaKayit.FileName, FileMode.CreateNew))
                using (StreamWriter sw = new StreamWriter(s))
                {

                    for (int i = 0; i < sekilsayisi; i++)
                    {
                        if (NeSekli[i] == 5)
                        {
                            continue;
                        }
                        if (sekillers[i] != null)
                        {
                            sw.Write(NeSekli[i] + " " + sekillers[i].X + " " + sekillers[i].Y + " " + sekillers[i].X2 + " " + sekillers[i].Y2 + " " + RenkDizim[i].ToKnownColor() + Environment.NewLine);
                        }
                    }
                }
            }
        }

        private void AC_Click(object sender, EventArgs e)
        {
            int KacinciKelime = 1;
            int KacinciSatir = 0;
            int deger;
            OpenFileDialog Okunacak = new OpenFileDialog();
            if (Okunacak.ShowDialog() == DialogResult.OK)
            {
                using (StreamReader dosyam = new StreamReader(Okunacak.FileName, ASCIIEncoding.ASCII))
                    while (!dosyam.EndOfStream)
                    {
                        var line = dosyam.ReadLine();

                        foreach (var item in line.Split(' '))
                        {
                            if (KacinciKelime == 1)
                            {
                                deger = Convert.ToInt32(item);
                                NeSekli[KacinciSatir] = deger;
                            }
                            if (KacinciKelime == 2)
                            {
                                seklim = new Sekiller();
                                deger = Convert.ToInt32(item);
                                seklim.X = deger;
                            }
                            if (KacinciKelime == 3)
                            {
                                deger = Convert.ToInt32(item);
                                seklim.Y = deger;
                            }
                            if (KacinciKelime == 4)
                            {
                                deger = Convert.ToInt32(item);
                                seklim.X2 = deger;
                            }
                            if (KacinciKelime == 5)
                            {
                                deger = Convert.ToInt32(item);
                                seklim.Y2 = deger;
                            }
                            if (KacinciKelime == 6)
                            {
                                if (item=="Red")
                                {
                                    RenkDizim[KacinciSatir] = Color.Red;
                                }
                                if (item == "Blue")
                                {
                                    RenkDizim[KacinciSatir] = Color.Blue;
                                }
                                if (item == "Green")
                                {
                                    RenkDizim[KacinciSatir] = Color.Green;
                                }
                                if (item == "Orange")
                                {
                                    RenkDizim[KacinciSatir] = Color.Orange;
                                }
                                if (item == "Black")
                                {
                                    RenkDizim[KacinciSatir] = Color.Black;
                                }
                                if (item == "Purple")
                                {
                                    RenkDizim[KacinciSatir] = Color.Purple;
                                }
                                if (item == "Yellow")
                                {
                                    RenkDizim[KacinciSatir] = Color.Yellow;
                                }
                                if (item == "White")
                                {
                                    RenkDizim[KacinciSatir] = Color.White;
                                }
                            }
                            KacinciKelime++;
                            if (KacinciKelime == 7)
                            {
                                sekillers[KacinciSatir] = seklim;
                                KacinciKelime = 1;
                                KacinciSatir++;
                            }
                            sekilsayisi = KacinciSatir;
                        }
                    }
            }
        }
    }
}
