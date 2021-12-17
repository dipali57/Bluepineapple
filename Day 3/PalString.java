import java.util.*;

class PalFunc
{
	void PalindromeStr(String str)
	{
		int len=str.length();
		
		char backupStr[]=new char[len];
		char arr[]=str.toCharArray();
		

		for(int i=len-1,j=0 ; i>=0 ; i--,j++){
				
				backupStr[j]=arr[i];

		}
		
		if(Arrays.equals(arr,backupStr)){
			System.out.println(" Palindrome String ");
		}
		else
			System.out.println(" Not Palindrome String");
		
	}
}
class PalString
{
	public static void main(String args[])
	{
		
			Scanner sobj = new Scanner(System.in);

			System.out.println("Enter string");
			String str = sobj.nextLine();

			PalFunc pobj = new PalFunc();

			pobj.PalindromeStr(str);
		
	}
}

