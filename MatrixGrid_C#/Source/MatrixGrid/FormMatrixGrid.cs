using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace MatrixGrid
{
    public partial class FormMatrixGrid : Form
    {
        //Add the member variables
        public int m_iWidth; //Width of the grid cell

        public int m_iHeight; // The height of the Cell

        public int m_iNoOfRows; // The Number Of Rows

        public int m_iNoOfCols; // The Number Of Columns

        public int m_iXOffset; //Offset from which drawing start
        public int m_iYOffset;
        public int m_iCount=2;
        public int m_iMaxSize=3;

        public const int DEFAULT_IX_OFFSET = 100;
        public const int DEFAULT_IY_OFFSET = 50;
        public const int DEFAULT_INO_ROWS = 2;
        public const int DEFAULT_INO_COLS = 2;
        public const int DEFAULT_IWIDTH = 60;
        public const int DEFAULT_IHEIGHT = 60;


        public FormMatrixGrid()
        {
            Initialize();
            InitializeComponent();
            bThreadStatus = false;
        }

        private void OnPaint(object sender, EventArgs e)
        {
            DrawGrid();
        }

        public void Initialize()
        {
            //Put all the default values
            m_iNoOfRows = DEFAULT_INO_ROWS;
            m_iNoOfCols = DEFAULT_INO_COLS;
            m_iWidth = DEFAULT_IWIDTH;
            m_iHeight = DEFAULT_IHEIGHT;
            m_iXOffset = DEFAULT_IX_OFFSET;
            m_iYOffset = DEFAULT_IY_OFFSET;

        }

        private void DrawGrid()
        {
            Graphics boardLayout = this.CreateGraphics();
            Pen layoutPen = new Pen(Color.Green);
            layoutPen.Width = 5;
           
                //boardLayout.DrawLine(layoutPen, 0, 0, 100, 0);
                int X = DEFAULT_IX_OFFSET;
                int Y = DEFAULT_IY_OFFSET;
                //Draw The rows
                for (int i = 0; i <= m_iCount; i++)
                {
                    boardLayout.DrawLine(layoutPen, X, Y, X + this.m_iWidth * this.m_iCount, Y);
                    Y = Y + this.m_iHeight;
                }

                //Draw The Cols
                X = DEFAULT_IX_OFFSET;
                Y = DEFAULT_IY_OFFSET;
                for (int j = 0; j <= m_iCount; j++)
                {
                    boardLayout.DrawLine(layoutPen, X, Y, X, Y + this.m_iHeight * this.m_iCount);
                    X = X + this.m_iWidth;
                
                      }
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            m_iMaxSize =5;
            this.Refresh();
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            m_iMaxSize = 4;
            this.Refresh();
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            m_iMaxSize = 6;
            this.Refresh();
        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
            m_iMaxSize = 7;
            this.Refresh();
        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread = new Thread(new ThreadStart(ThreadCounter));
            CounterThread.Start();//starts the thread
            bThreadStatus = true;
        }

        private void pauseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread.Suspend();//Pauses the thread
        }

        private void resumeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread.Resume(); //Resumes the thread

        }
        public void ThreadCounter()
        {
            try
            {
                while (true)
                {
                    m_iCount++;
                    if(m_iCount>m_iMaxSize)
                    {
                        m_iCount = 1;
                    }
                    Invalidate();
                    Thread.Sleep(500);
               
               
                }

            }
            catch (Exception ex)
            {

            }
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }
    }
}