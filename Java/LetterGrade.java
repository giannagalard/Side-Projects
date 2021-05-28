import java.util.*;
public class LetterGrades
{
   public static void main(String args[])
   {
       Scanner sc = new Scanner(System.in);
      
       while(true)
       {
           System.out.print("Please enter your grade or -1 to exit: ");
           double grade = sc.nextDouble();
          
           if(grade == -1)
           {
               System.out.print("Exited.");
               break;
           }
          
           
           if(grade<0 || grade>100)
           {
               while(true)
               {
                   System.out.print("INVALID");
                  
                   System.out.print("TRY AGAIN: ");
                   grade = sc.nextDouble();
                  
                   if(grade>=0 && grade<=100) 
                   {
                       break;
                   }
               }
           }
          
           if(grade>=90 && grade<=100) //Grade A for 100-90
               System.out.print("Your letter grade is A.\n\n");
          
           else if(grade>=80 && grade<=89.99) //Grade B for 89.99-80.
               System.out.print("Your letter grade is B.\n\n");
          
           else if(grade>=70 && grade<=79.99) //Grade C for 79.99-70.
               System.out.print("Your letter grade is C.\n\n");
          
           else if(grade>=60 && grade<=69.99) //Grade D for 69.99-60.
               System.out.print("Your letter grade is D.\n\n");
          
           else //Grade F for 59.99-0
               System.out.print("Your letter grade is F.\n\n");
       }
   }}
