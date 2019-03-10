using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Proje
{
    class Sekiller
    {
        private int x, y, x2, y2;
        public  Sekiller()
        {
            x = 0;
            y = 0;
            x2 = 0;
            y2 = 0;
        }
        public int X
        {
            get
            {
                return x;
            }
            set
            {
                if ((value >= 25 &&value <= 557)||value==570)
                {
                    x = value;
                }
            }
        }
        public int Y
        {
            get
            {
                return y;
            }
            set
            {
                if ((value >= 23 && value <= 403) || value == 420)
                {
                    y = value;
                }
            }
        }
        public int X2
        {
            get
            {
                return x2;
            }
            set
            {
                if ((x!=0&&value >= 25 && value <= 557 )|| value == 570)
                {
                    x2 = value;
                }
            }
        }
        public int Y2
        {
            get
            {
                return y2;
            }
            set
            {
                if ((x!=0&&value >= 23 && value <= 403 )|| value == 420)
                {
                    y2 = value;
                }
            }
        }
        public void Kareciz(Graphics cizimAraci,Color Deger)
        {
            if (y >= y2 && x > x2)
            {
                Brush Kalem = new SolidBrush(Deger);
                cizimAraci.FillRectangle(Kalem, x2, y2, (x - x2), (y - y2));
            }
            else if (x < x2 && y > y2)
            {
                Brush Kalem = new SolidBrush(Deger);
                cizimAraci.FillRectangle(Kalem, x, y2, (x2 - x), (y - y2));
            }
            else if (x > x2 && y2 > y)
            {
                Brush Kalem = new SolidBrush(Deger);
                cizimAraci.FillRectangle(Kalem, x2, y, (x - x2), (y2 - y));
            }
            else
            {
                Brush Kalem = new SolidBrush(Deger);
                cizimAraci.FillRectangle(Kalem, x, y, (x2 - x),( y2 - y));
            }          
        }
        public void Daireciz(Graphics cizimAraci, Color Deger)
        {
            Brush Kalem = new SolidBrush(Deger);
            if (y >= y2 && x > x2)
            {
                cizimAraci.FillEllipse(Kalem, x2, y2, (x - x2), (y - y2));
            }
            else if (x < x2 && y > y2)
            {
                cizimAraci.FillEllipse(Kalem, x, y2, (x2 - x), (y - y2));
            }
            else if (x > x2 && y2 > y)
            {
                cizimAraci.FillEllipse(Kalem, x2, y, (x - x2), (y2 - y));
            }
            else
            {
                cizimAraci.FillEllipse(Kalem, x, y, (x2 - x), (y2 - y));
            }
        }
        public void Ucgenciz(Graphics cizimAraci, Color Deger)
        {
            Brush Kalem = new SolidBrush(Deger);
            Point p1 = new Point(x, y);
            Point p2 = new Point((2 * x - x2), (y2));
            Point p3 = new Point(x2, y2);
            Point[] noktalar = { p1, p2, p3 };
            cizimAraci.FillPolygon(Kalem, noktalar);
        }
        public void Altigen(Graphics cizimAraci, Color Deger)
        {
            Brush Kalem = new SolidBrush(Deger);
            Point p1 = new Point(x, y);
            Point p2 = new Point(x2, y);
            Point p3 = new Point(x2 + (x2 - x) / 2, (y2 + y) / 2);
            Point p4 = new Point(x2, y2);
            Point p5 = new Point(x, y2);
            Point p6 = new Point(x - (x2 - x) / 2, (y + y2) / 2);
            Point[] altigen = { p1, p2, p3, p4, p5, p6 };
            cizimAraci.FillPolygon(Kalem, altigen);
        }
    }
}
