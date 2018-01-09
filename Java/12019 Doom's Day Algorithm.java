import java.util.Calendar;
import java.util.GregorianCalendar;
import java.text.DateFormatSymbols;
import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int noOfDays = sc.nextInt();
		
		String[] weekdays = new DateFormatSymbols().getWeekdays();
		
		while(noOfDays-- != 0)
		{
			int month = sc.nextInt(),
				day = sc.nextInt();
			
			GregorianCalendar cal = new GregorianCalendar(2011, month-1, day);
			
			System.out.println(weekdays[cal.get(Calendar.DAY_OF_WEEK)]);
		}
		
		sc.close();
	}
}

