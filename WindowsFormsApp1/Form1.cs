using System;
using System.IO.Ports;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class MainWindow : Form

    {
        private SerialPort port;

        private void SendToController(int a, int b = 0, int c = 0, int d = 0, int e = 0)
        {
            try
            {
                port.Write(BitConverter.GetBytes(a), 0, 1);
                port.Write(BitConverter.GetBytes(b), 0, 1);
                port.Write(BitConverter.GetBytes(c), 0, 1);
                port.Write(BitConverter.GetBytes(d), 0, 1);
                port.Write(BitConverter.GetBytes(e), 0, 1);

                Console.WriteLine("Sending to controller:\n" + $"First Byte is [{a}]\n" + $"Second Byte is [{b}]\n" + $"Third Byte is [{c}]\n" + $"Fourth Byte is [{d}]\n" + $"Fivth Byte is [{e}]\n________________________________________________________________________________________________________________________\n");
            }

            catch (System.InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public MainWindow()
        {
            InitializeComponent();
        }

        private void testButton_Click(object sender, EventArgs e)
        {
            ConsoleTextbox.AppendText("Sending test message\n");
            SendToController(0xAA, 0xAA, 0xAA, 0xAA, 0xFF);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            port = new SerialPort();
            port.PortName = "COM7";
            port.BaudRate = 9600;
            port.ReadTimeout = 500;
            port.WriteTimeout = 500;
            try
            {
                port.Open();
                ConsoleTextbox.AppendText("Connection successfull!\n");
            }
            catch (System.UnauthorizedAccessException ex)
            {
                // open window explaining that the device is already being use by another program.
                Console.WriteLine(ex.Message);
            }
            catch (System.IO.IOException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private void disconnectButton_Click(object sender, EventArgs e)
        {
            port.Close();
            ConsoleTextbox.AppendText("Disconnection successfull!\n");
        }
    }
}