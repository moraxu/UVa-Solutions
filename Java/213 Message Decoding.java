import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		Decoder.decode(System.in, System.out);
	}
}

class Decoder
{
	public static void decode(InputStream in, PrintStream out)
	{
		Scanner sc = new Scanner(in);
		
		while(sc.hasNextLine())
		{
			String header = sc.nextLine();
			
			StringBuilder encMessage = new StringBuilder(),
						  decMessage = new StringBuilder();
			
			encMessage.append(sc.nextLine());
			
			boolean lengthMode = true, endOfMessage = false;
			
			for(int i = 0, currSegmentLength = 0 ; !endOfMessage ; )
			{
				if(lengthMode)
				{
					if(i+3 <= encMessage.length())
					{
						currSegmentLength = Integer.parseInt(encMessage.substring(i, i+3), 2);
						
						if(currSegmentLength == 0)
						{
							endOfMessage = true;
							out.println(decMessage.toString());
						}
						else
						{
							i += 3;
							lengthMode = false;
						}
					}
					else
					{
						encMessage.append(sc.nextLine());
					}
				}
				else
				{
					if(i+currSegmentLength <= encMessage.length())
					{
						int currKey = Integer.parseInt(encMessage.substring(i, i+currSegmentLength), 2);
						
						if(currKey == (int)Math.pow(2, currSegmentLength)-1)
						{
							lengthMode = true;
						}
						else
						{
							decMessage.append(header.charAt((int)(Math.pow(2, currSegmentLength))-currSegmentLength-1+currKey));
						}
						
						i += currSegmentLength;
					}
					else
					{
						encMessage.append(sc.nextLine());
					}
				}
			}
		}
		
		sc.close();
	}
}
