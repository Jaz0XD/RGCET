import java.io.*;
import java.net.*;
public class EchoServer
{
public EchoServer(int portnum)
{
try
{
Server=new ServerSocket(portnum);
}
catch(IOException e)
{
System.out.println("Error"+e);
}
}
public void Server()
{
try
{
while(true)
{
Socket client=Server.accept();
BufferedReader r=new BufferedReader(new
InputStreamReader(client.getInputStream()));
PrintWriter w=new PrintWriter(client.getOutputStream(),true);
w.println("welcome to the Java EchoServer...Type 'bye' to close the window");
String line;
do
{
line=r.readLine();
if(line!=null)
w.println("Echoes Message is:"+line);
System.out.println("The client message is:"+line);
}
while(!line.trim().equals("Bye"));
client.close();
}
}
catch(IOException e)
{
System.out.println("Error"+e);
}
}
public static void main(String args[])
{
EchoServer s=new EchoServer(8888);
System.out.println("Connection Established..:");
s.Server();
}
private ServerSocket Server;
}
