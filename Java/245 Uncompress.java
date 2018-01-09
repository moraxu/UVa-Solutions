import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		Decompresser decompresser = new Decompresser(System.in, System.out);
		decompresser.decompress();
	}
}

class Decompresser
{
	private boolean wordContinues, numberContinues;
	private StringBuilder sBWord, sBNumber;
	private ArrayList<String> words;
	private PrintStream outStr;
	private InputStream inStr;
	
	private void wrapWordIfContinues()
	{
		if(wordContinues)
		{
			String word = sBWord.toString();
			words.add(0, word);

			outStr.print(word);
			
			sBWord.setLength(0);
			wordContinues = false;
		}
	}
	
	private void wrapNumberIfContinues()
	{
		if(numberContinues)
		{
			String word = words.remove(Integer.parseInt(sBNumber.toString())-1);
			words.add(0, word);

			outStr.print(word);
			
			sBNumber.setLength(0);
			numberContinues = false;
		}
	}
	
	public Decompresser(InputStream inStr, PrintStream outStr)
	{
		this.wordContinues = false;
		this.numberContinues = false;
		this.sBWord = new StringBuilder();
		this.sBNumber = new StringBuilder();
		this.words = new ArrayList<>();
		this.outStr = outStr;
		this.inStr = inStr;
	}
	
	public void decompress()
	{
		Scanner sc = new Scanner(inStr);
		
		for(int i = 0 ; sc.hasNextLine() ; ++i)
		{
			String line = sc.nextLine();
			
			if(line.length() < 1)
			{
				outStr.println();
				continue;
			}
				
			if(line.charAt(0) == '0')
				break;
			
			for(char c : line.toCharArray())
			{
				if(Character.isLetter(c))
				{
					if(!wordContinues)
						wordContinues = true;
					
					sBWord.append(c);
				}
				else if(Character.isDigit(c))
				{
					if(!numberContinues)
						numberContinues = true;
					
					sBNumber.append(c);
				}
				else
				{
					wrapNumberIfContinues();
					wrapWordIfContinues();
					
					outStr.print(c);
				}
			}
			
			wrapNumberIfContinues();
			wrapWordIfContinues();

			outStr.println();
		}
		
		words.clear();
		sc.close();
	}

	public PrintStream getOutStr()
	{
		return outStr;
	}

	public void setOutStr(PrintStream outStr)
	{
		this.outStr = outStr;
	}

	public InputStream getInStr()
	{
		return inStr;
	}

	public void setInStr(InputStream inStr)
	{
		this.inStr = inStr;
	}
}