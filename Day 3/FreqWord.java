import java.util.Scanner;

class FreqFunc
{
	int CountWords(String str,String substr)
	{
		String arr[]=str.split(" ");
		
		int icnt=0;

		for(String s : arr)
		{
			if(s.equals(substr))
			{
				icnt++;
			}
		}

		return icnt;
	}
}
class FreqWord
{
	public static void main(String args[])
	{
		
			Scanner sobj = new Scanner(System.in);

			System.out.println("Enter first string");
			String str = sobj.nextLine();


			System.out.println("Enter sub string");
			String substr = sobj.nextLine();


			FreqFunc mobj = new FreqFunc();

			int iret = mobj.CountWords(str,substr);
		
			System.out.println(" \""+ substr +"\" word occurs "+ iret + " times ");
		
	}
}







