#include <stdio.h>
int LengthOfLSubstring(char* s)
{
 int maxlength = 0;// strore the  known max length 
 int length = 1;
 char t; // store temporary char in traversal strings
 int flag[128];//
 int i;
 int j;
 int k; 
 int changenu;
 int chartoint;
 for(i = 0; i < 128; i++){flag[i] = 0;}//init flag array to 0

 for(i = 0;s[i] != '\0';i++)
 {

   printf("no.%drun\n",i+1);
   flag[(int)s[i]] = 1;

   for(j = i+1; s[j] != '\0'; j++)
   {
        chartoint = (int)s[j];
     	if(flag[chartoint] == 1)
    	 {
      		 break;
     	 }
    	 length++;
         flag[chartoint] = 1;

   }
   printf("run %d time\n",j-i-1); 
   if(length > maxlength)
   {
     maxlength = length;
   }
   length = 1;
   for(k = 0; k < 128; k++){flag[k] = 0;}
}
 return maxlength;
}

int main()
{
   char *s = "pwwkew";
   int t =   LengthOfLSubstring(s);
   printf("%d",t);
   return 0;
}
