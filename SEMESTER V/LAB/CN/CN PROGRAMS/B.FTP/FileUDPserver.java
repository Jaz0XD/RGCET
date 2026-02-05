import java.net.*;
import java.io.*;
public class FileUDPserver
{
 public static void main(String args[])throws IOException
 {
 byte b[]=new byte[3072];
 DatagramSocket dsoc=new DatagramSocket(1000);
 FileOutputStream f=new FileOutputStream("greetings1.txt");
 while(true)
 {
 DatagramPacket dp=new DatagramPacket(b,b.length);
 dsoc.receive(dp);
String r=new String(dp.getData());
byte[] n=r.getBytes();
int len=dp.getLength();
while(len!=0)
{
f.write(n);
break;
}
 System.out.println(new String(dp.getData(),0,dp.getLength()));
 f.close();
 break;
 }
dsoc.close();
 }
}
