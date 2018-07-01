using System;
using System.IO;
using System.Threading;
using System.Diagnostics;
using System.Windows.Forms;

namespace winConsole
{
    public partial class winConsole : Form
    {
        string cmd = string.Empty;
        string readData = string.Empty;

/*        Thread thread;*/

        Process pro;
        Process showlog;

        StreamReader output;
        StreamWriter input;

        // 建一个文件流用于保存日志
        static string filename = "command_log.txt";
        FileStream fs;
        StreamWriter sw;
        public winConsole()
        {
            InitializeComponent();
        }

        private void button_cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBox_keypress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == 13)
            {
                // 发送前先判断链接是否还在
                if(pro.HasExited)
                {
                    MessageBox.Show("进程状态判断不正确，弹框错误！");
                }
                button_ok.Focus();
                SendKeys.Send("{Enter}");
            }
        }

        private void button_ok_Click(object sender, EventArgs e)
        {
            cmd = textBox_cmd.Text;
            if((cmd == "cls") || (cmd == "clear"))
            {
                fs = new FileStream(filename, FileMode.Append | FileMode.Create);
                sw = new StreamWriter(fs);
                sw.AutoFlush = true;
                sw.Write(richTextBox_output.Text);
                sw.Close();
                fs.Close();

                richTextBox_output.Text = string.Empty;
                input.Write("\n");
            }
            else
            {
                input.WriteLine(@cmd);
                input.Write("\n");
            }
            textBox_cmd.Focus();
            textBox_cmd.SelectAll();
        }

        private void getout(object sender, DataReceivedEventArgs e)
        {
            readData = e.Data;
            if (!string.IsNullOrEmpty(readData))
            {
/*                richTextBox_output.Text += readData + "\n";*/
                richTextBox_output.AppendText(readData + "\n");
            }
            else
            {
                richTextBox_output.ScrollToCaret();
            }
        }

        private void temp()
        {
            if (pro.Start())
            {
                string outputtext = string.Empty;

                input = pro.StandardInput;
                input.WriteLine(@cmd);
                input.Dispose();

                output = pro.StandardOutput;
                outputtext = output.ReadToEnd();
                output.Dispose();

                input.Close();
                output.Close();
                
                if (!pro.WaitForExit(3000))
                {
                    MessageBox.Show("Command execute failed!");
                    return;
                }

                richTextBox_output.Text += outputtext + "\n";



                fs = new FileStream(filename, FileMode.Append | FileMode.Create);
                sw = new StreamWriter(fs);
                sw.AutoFlush = true;
                sw.Write(outputtext + "\n");
                sw.Close();
                fs.Close();
            }
            else
            {
                MessageBox.Show("运行程序失败！");
            }
        }

        private void winConsole_Load(object sender, EventArgs e)
        {
            // 根据当前时间获取一个文件名
            string date = DateTime.Now.ToShortDateString();
            filename = date.Replace('/', '_') + "-log.txt";

            showlog = new Process();

            showlog.StartInfo.FileName               = "E:\\Program Files (x86)\\Notepad++\\notepad++.exe";
            showlog.StartInfo.Arguments              = filename;
            showlog.StartInfo.WindowStyle            = ProcessWindowStyle.Hidden;
            showlog.StartInfo.CreateNoWindow         = true;
            showlog.StartInfo.UseShellExecute        = false;
            showlog.StartInfo.RedirectStandardInput  = true;
            showlog.StartInfo.RedirectStandardOutput = true;
            
            pro = new Process();

            pro.StartInfo.FileName = "powershell.exe"; //cmd.exe
            pro.StartInfo.UseShellExecute = false;
            pro.StartInfo.RedirectStandardOutput = true;
            pro.StartInfo.RedirectStandardInput = true;
            pro.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            pro.StartInfo.CreateNoWindow = true;

            richTextBox_output.Text = string.Empty;

            pro.Start();

            input = pro.StandardInput;

            pro.OutputDataReceived += new DataReceivedEventHandler(getout);
            pro.BeginOutputReadLine();

            // 测试按键自动处理程序
//             thread = new Thread(new ThreadStart(threadRun));
//             thread.Start();

            Thread.Sleep(500);
            SendKeys.Send("{Enter}");

            this.Activate();
        }

        private void threadRun()
        {
            MessageBox.Show("test auto close", "tips", MessageBoxButtons.YesNo);
        }

        private void button_show_log_Click(object sender, EventArgs e)
        {
            if(!showlog.Start())
            {
                MessageBox.Show("打开日志文件失败！");
            }
        }

        private void form_closing(object sender, FormClosingEventArgs e)
        {
            fs = new FileStream(filename, FileMode.Append | FileMode.Create);
            sw = new StreamWriter(fs);
            sw.AutoFlush = true;
            sw.Write(richTextBox_output.Text);
            sw.Close();
            fs.Close();

            pro.Close();

//             thread.Abort();
//             thread.Join();
        }
    }
}
