using System;
using System.Collections.Generic;
using System.Linq;
using System.IO.Ports;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    static class Program
    {
        /// <summary>
        /// Der Haupteinstiegspunkt für die Anwendung.
        /// </summary>
        [STAThread]
        static void Main()
        {

            /*var port = new SerialPort();
            port.PortName = "COM7";
            port.BaudRate = 9600;
            port.ReadTimeout = 500;
            port.WriteTimeout = 500;
            try
            {
                port.Open();
            }
            catch (System.UnauthorizedAccessException e)
            {
                // open window explaining that the device is already being use by another program.
                Console.WriteLine(e.Message);
            }
            catch (System.IO.IOException e)
            {
                Console.WriteLine(e.Message);
            }*/

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainWindow(/*port*/));
        }
    }
}
