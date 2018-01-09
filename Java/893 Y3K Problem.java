import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		int days_to_add = 0, day = 0, month = 0, year = 0;
		
		Scanner sc = new Scanner(System.in);
		
		while(((days_to_add = sc.nextInt()) != 0 ? true : false) &&
			((day = sc.nextInt()) != 0 ? true : false) &&
			((month = sc.nextInt()) != 0 ? true : false) &&
			((year = sc.nextInt()) != 0 ? true : false))
			
		{
			GregorianCalendar cal = new GregorianCalendar(year, month-1, day);
			
			cal.add(Calendar.DAY_OF_YEAR, days_to_add);
			
			System.out.println(cal.get(Calendar.DAY_OF_MONTH) + " "
								+ (cal.get(Calendar.MONTH)+1) + " "
								+ cal.get(Calendar.YEAR));
		}
		
		sc.close();
	}
}

