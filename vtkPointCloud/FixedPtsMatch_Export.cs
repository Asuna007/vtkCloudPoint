using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace vtkPointCloud
{
    public partial class FixedPtsMatch_Export : Form
    {
        public List<Point3D> FixedPtsTrueValueList;
        public string pathOut;
        public FixedPtsMatch_Export()
        {
            InitializeComponent();
        }
        private void pathSelbtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.Filter += "��������(*.txt)|*.txt";
            openFile.Title = "�򿪹̶�����ֵ�ļ�";
            String fullFilePath;
            if (openFile.ShowDialog() == DialogResult.OK && openFile.FileName.Length > 1)
            {
               
                FixedPtsTrueValueList = new List<Point3D>();
                fullFilePath = openFile.FileName;
                this.PathSeltxt.Text = fullFilePath;
                //����ļ�·��
                int index = fullFilePath.LastIndexOf("\\");
                string filePath = fullFilePath.Substring(0, index);
                //����ļ�����
                string fileName = fullFilePath.Substring(index + 1);

                FileMap fileMap = new FileMap();
                try
                {
                    List<string> pointsList = fileMap.ReadFile(fullFilePath);
                Point3D ppp;
                double pX, pY, pZ;
                for (int i = 0; i < pointsList.Count; i++)
                {
                    if ((pointsList[i] == null) || (pointsList[i] == "")) continue;
                    string[] tmpxyz = pointsList[i].Split(',');
                    if (!double.TryParse(tmpxyz[1], out pX))
                    {
                        MessageBox.Show("������ļ���ʽ��������������");
                        return;
                    }
                    if (!double.TryParse(tmpxyz[2], out pY))
                    {
                        MessageBox.Show("������ļ���ʽ��������������");
                        return;
                    }
                    if (!double.TryParse(tmpxyz[3], out pZ))
                    {
                        MessageBox.Show("������ļ���ʽ��������������");
                        return;
                    }
                    ppp = new Point3D();
                    ppp.pointName = tmpxyz[0];
                    ppp.X = pX;
                    ppp.Y = pY;
                    ppp.Z = pZ;
                    ppp.ifShown = true;
                    FixedPtsTrueValueList.Add(ppp);
                }
                }
                catch (Exception)
                {
                    MessageBox.Show("��ȡ��ֵ�ļ�����");
                    throw;
                }
            }
        }
        private void pathSel2Btn_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFile1 = new SaveFileDialog();
            saveFile1.Filter = "�ı��ļ�(.txt)|*.txt";
            saveFile1.FilterIndex = 1;
            if (saveFile1.ShowDialog() == System.Windows.Forms.DialogResult.OK && saveFile1.FileName.Length > 0)
            {
                this.PathSeltxt2.Text = saveFile1.FileName;
            }
        }
        private void SureBtn_Click(object sender, EventArgs e)
        {
            if (this.PathSeltxt.Text.Equals("δѡ��·��"))
            {
                MessageBox.Show("δ������ֵ�ļ�·��");
                return;
            } if (this.PathSeltxt2.Text.Equals("δѡ��·��"))
            {
                MessageBox.Show("δ����ƥ���ļ�����·��");
                return;
            }
            this.pathOut = this.PathSeltxt2.Text;
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
        private void CancelBtn_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        private void FixedPtsMatch_Export_Load(object sender, EventArgs e)
        {

        }
    }
}
