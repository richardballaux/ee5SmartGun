
package ee5_smartgun;

/**
 *
 * @author Olivier
 */

//import java.io.*;
import java.net.*;

class UDPServer
{
   public static void main(String args[]) throws Exception
      {
            int port = 9877;
            DatagramSocket serverSocket = new DatagramSocket(port);
            byte[] buffer = new byte[4];
            System.out.println("SERVER IS RUNNING...\n");
            while(true)
               {
                  DatagramPacket receivePacket = new DatagramPacket(buffer, buffer.length);
                  serverSocket.receive(receivePacket);
                  byte[] receivedData = receivePacket.getData();
                  System.out.println("RECEIVED: " + receivedData[0] + " + " + receivedData[1] + " + " + receivedData[2] + " + " + receivedData[3] + "\n ******************** \n");
                  
               }
      }
}