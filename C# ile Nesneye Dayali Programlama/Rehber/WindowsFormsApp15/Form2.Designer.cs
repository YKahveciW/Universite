namespace WindowsFormsApp15
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelad = new System.Windows.Forms.Label();
            this.textBoxAd = new System.Windows.Forms.TextBox();
            this.labelsoyad = new System.Windows.Forms.Label();
            this.textBoxSoyad = new System.Windows.Forms.TextBox();
            this.labelNumara = new System.Windows.Forms.Label();
            this.maskedTextBoxNumara = new System.Windows.Forms.MaskedTextBox();
            this.comboBoxAd = new System.Windows.Forms.ComboBox();
            this.comboBoxSoyad = new System.Windows.Forms.ComboBox();
            this.comboBoxNumara = new System.Windows.Forms.ComboBox();
            this.ButtonKaydet = new System.Windows.Forms.Button();
            this.labelKayitPaneli = new System.Windows.Forms.Label();
            this.LabelForm2Uyari = new System.Windows.Forms.Label();
            this.TelTaxtBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // labelad
            // 
            this.labelad.AutoSize = true;
            this.labelad.Location = new System.Drawing.Point(12, 19);
            this.labelad.Name = "labelad";
            this.labelad.Size = new System.Drawing.Size(20, 13);
            this.labelad.TabIndex = 0;
            this.labelad.Text = "Ad";
            // 
            // textBoxAd
            // 
            this.textBoxAd.Location = new System.Drawing.Point(12, 35);
            this.textBoxAd.Name = "textBoxAd";
            this.textBoxAd.Size = new System.Drawing.Size(153, 20);
            this.textBoxAd.TabIndex = 1;
            // 
            // labelsoyad
            // 
            this.labelsoyad.AutoSize = true;
            this.labelsoyad.Location = new System.Drawing.Point(9, 84);
            this.labelsoyad.Name = "labelsoyad";
            this.labelsoyad.Size = new System.Drawing.Size(37, 13);
            this.labelsoyad.TabIndex = 2;
            this.labelsoyad.Text = "Soyad";
            // 
            // textBoxSoyad
            // 
            this.textBoxSoyad.Location = new System.Drawing.Point(12, 100);
            this.textBoxSoyad.Name = "textBoxSoyad";
            this.textBoxSoyad.Size = new System.Drawing.Size(153, 20);
            this.textBoxSoyad.TabIndex = 3;
            // 
            // labelNumara
            // 
            this.labelNumara.AutoSize = true;
            this.labelNumara.Location = new System.Drawing.Point(9, 149);
            this.labelNumara.Name = "labelNumara";
            this.labelNumara.Size = new System.Drawing.Size(44, 13);
            this.labelNumara.TabIndex = 4;
            this.labelNumara.Text = "Numara";
            // 
            // maskedTextBoxNumara
            // 
            this.maskedTextBoxNumara.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.maskedTextBoxNumara.Enabled = false;
            this.maskedTextBoxNumara.ForeColor = System.Drawing.SystemColors.Info;
            this.maskedTextBoxNumara.Location = new System.Drawing.Point(12, 231);
            this.maskedTextBoxNumara.Mask = "(999) 000-0000";
            this.maskedTextBoxNumara.Name = "maskedTextBoxNumara";
            this.maskedTextBoxNumara.Size = new System.Drawing.Size(10, 13);
            this.maskedTextBoxNumara.TabIndex = 5;
            // 
            // comboBoxAd
            // 
            this.comboBoxAd.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxAd.FormattingEnabled = true;
            this.comboBoxAd.Items.AddRange(new object[] {
            "Kirmizi",
            "Yesil",
            "Mavi"});
            this.comboBoxAd.Location = new System.Drawing.Point(171, 34);
            this.comboBoxAd.Name = "comboBoxAd";
            this.comboBoxAd.Size = new System.Drawing.Size(101, 21);
            this.comboBoxAd.TabIndex = 6;
            this.comboBoxAd.SelectedIndexChanged += new System.EventHandler(this.comboBoxAd_SelectedIndexChanged);
            // 
            // comboBoxSoyad
            // 
            this.comboBoxSoyad.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxSoyad.FormattingEnabled = true;
            this.comboBoxSoyad.Items.AddRange(new object[] {
            "Kirmizi",
            "Yesil",
            "Mavi"});
            this.comboBoxSoyad.Location = new System.Drawing.Point(171, 100);
            this.comboBoxSoyad.Name = "comboBoxSoyad";
            this.comboBoxSoyad.Size = new System.Drawing.Size(101, 21);
            this.comboBoxSoyad.TabIndex = 7;
            this.comboBoxSoyad.SelectedIndexChanged += new System.EventHandler(this.comboBoxSoyad_SelectedIndexChanged);
            // 
            // comboBoxNumara
            // 
            this.comboBoxNumara.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxNumara.FormattingEnabled = true;
            this.comboBoxNumara.Items.AddRange(new object[] {
            "Kirmizi",
            "Yesil",
            "Mavi"});
            this.comboBoxNumara.Location = new System.Drawing.Point(171, 165);
            this.comboBoxNumara.Name = "comboBoxNumara";
            this.comboBoxNumara.Size = new System.Drawing.Size(101, 21);
            this.comboBoxNumara.TabIndex = 8;
            this.comboBoxNumara.SelectedIndexChanged += new System.EventHandler(this.comboBoxNumara_SelectedIndexChanged);
            // 
            // ButtonKaydet
            // 
            this.ButtonKaydet.Location = new System.Drawing.Point(71, 226);
            this.ButtonKaydet.Name = "ButtonKaydet";
            this.ButtonKaydet.Size = new System.Drawing.Size(141, 23);
            this.ButtonKaydet.TabIndex = 9;
            this.ButtonKaydet.Text = "KAYDET";
            this.ButtonKaydet.UseVisualStyleBackColor = true;
            this.ButtonKaydet.Click += new System.EventHandler(this.ButtonKaydet_Click);
            // 
            // labelKayitPaneli
            // 
            this.labelKayitPaneli.AutoSize = true;
            this.labelKayitPaneli.Location = new System.Drawing.Point(186, 9);
            this.labelKayitPaneli.Name = "labelKayitPaneli";
            this.labelKayitPaneli.Size = new System.Drawing.Size(79, 13);
            this.labelKayitPaneli.TabIndex = 10;
            this.labelKayitPaneli.Text = "KAYIT PANELI";
            // 
            // LabelForm2Uyari
            // 
            this.LabelForm2Uyari.AutoSize = true;
            this.LabelForm2Uyari.Location = new System.Drawing.Point(130, 201);
            this.LabelForm2Uyari.Name = "LabelForm2Uyari";
            this.LabelForm2Uyari.Size = new System.Drawing.Size(0, 13);
            this.LabelForm2Uyari.TabIndex = 11;
            // 
            // TelTaxtBox
            // 
            this.TelTaxtBox.Location = new System.Drawing.Point(12, 165);
            this.TelTaxtBox.Name = "TelTaxtBox";
            this.TelTaxtBox.Size = new System.Drawing.Size(153, 20);
            this.TelTaxtBox.TabIndex = 12;
            this.TelTaxtBox.TextChanged += new System.EventHandler(this.TelTaxtBox_TextChanged);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.TelTaxtBox);
            this.Controls.Add(this.LabelForm2Uyari);
            this.Controls.Add(this.labelKayitPaneli);
            this.Controls.Add(this.ButtonKaydet);
            this.Controls.Add(this.comboBoxNumara);
            this.Controls.Add(this.comboBoxSoyad);
            this.Controls.Add(this.comboBoxAd);
            this.Controls.Add(this.maskedTextBoxNumara);
            this.Controls.Add(this.labelNumara);
            this.Controls.Add(this.textBoxSoyad);
            this.Controls.Add(this.labelsoyad);
            this.Controls.Add(this.textBoxAd);
            this.Controls.Add(this.labelad);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelad;
        private System.Windows.Forms.TextBox textBoxAd;
        private System.Windows.Forms.Label labelsoyad;
        private System.Windows.Forms.TextBox textBoxSoyad;
        private System.Windows.Forms.Label labelNumara;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxNumara;
        private System.Windows.Forms.ComboBox comboBoxAd;
        private System.Windows.Forms.ComboBox comboBoxSoyad;
        private System.Windows.Forms.ComboBox comboBoxNumara;
        private System.Windows.Forms.Button ButtonKaydet;
        private System.Windows.Forms.Label labelKayitPaneli;
        private System.Windows.Forms.Label LabelForm2Uyari;
        private System.Windows.Forms.TextBox TelTaxtBox;
    }
}