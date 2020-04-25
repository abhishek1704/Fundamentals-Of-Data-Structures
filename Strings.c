#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i=0,ch,lens,p,len_subs,l,m;
	char s[30],s1[20],s2[30],comp,str1[50],str2[30];

	do
	{

	    printf("\n----Main Menu----\n1.Substring\n2.Palindrome\n");
	    printf("3.Compare\n4.Copy\n5.Reverse\n6.Cocatenation\n7.Exit\n");
	    printf("\nEnter your choice: ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    case 1:
		printf("Enter a string: ");
		scanf("\n");
	    gets(s);
	    printf("Enter a substring: ");
	    scanf("%s",s1);
	    lens = length(s);
	    len_subs = length(s1);
	    m =  substring(s,s1,lens,len_subs);
	    if(m==1)
	    	printf("String is present !!");
	    else
	    	printf("String is not present !!");
	    break;

	    case 2:
	    printf("Enter a string: ");
		scanf("%s",s);
	    lens = length(s);
	    palindrome(s,lens);
	    break;

	    case 3:
	    printf("Enter first string: ");
	    scanf("%s",s1);
	    printf("Enter second string: ");
	    scanf("%s",s2);
	    comp = compare(s1,s2);
	    if(comp==0)
	    	printf("Both strings are same !!");
	    else
	    	printf("strings are different !!");
	    break;

	    case 4:
	    printf("Enter a string: ");
	    scanf("%s",str1);
	    copy(str1,str2);
	    printf("String 1: ");
	    puts(str1);
	    printf("String 2: ");
	    puts(str2);
	    break;

	    case 5:
	    printf("Enter a string: ");
	    scanf("%s",str1);
	    l = length(str1);
	    reverse(str1,l);
	    printf("String after reversing : ");
	    printf("%s",str1);
	    break;

	    case 6:
	    printf("Enter first string: ");
	    scanf("%s",str1);
	    printf("Enter the second string: ");
	    scanf("%s",str2);
	    stringcat(str1,str2);
	    printf("String after concatenation: %s\n",str1);
	    break;

	    case 7:
	    break;
        }
	    if(ch==7)
	      	break;
	    printf("\n\nDo you want to continue?\n");
	    printf("Press 1 if yes and 0 if no: ");
	    scanf("%d",&p);
   }while(p!=0);

   return EXIT_SUCCESS;
}

int length(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}

void palindrome(char s[],int lens)
{
	int i;
    for(i=0;i<lens;i++)
	{
	   	if(s[i]==s[lens-1-i])
	   	{
			printf("\nString is a palindrome !!");\
			break;
		}
		else
		{
			printf("\nString is not a palindrome !!");
			break;
		}
	}
}

int compare(char s1[],char s2[])
{
	int i,j,count=0,flag;
	for(i=0;((s1[i]!='\0')&&(s2[i]!='\0'));i++)
	{
		if(s1[i]==s2[i])
		{
			count++;
		}
	}
	if(count==i)
		flag= 0;
	else
		flag=1;

	return flag;
}

void copy(char str1[],char str2[])
{
	int i=0,j=0;
	for(i=0;str1[i]!='\0';i++)
	{
		str2[i]=str1[j];
		j++;
	}
}

void reverse(char str1[],int l)
{

	int i;
	char temp;
	for(i=0;i<l/2;i++)
	{
		temp = str1[i];
		str1[i] = str1[l-1-i];
		str1[l-1-i] = temp;
	}

}

int substring(char s[],char s1[],int lens,int len_subs)
{
	int i,j,flag;
	for(i=0;i<lens-len_subs;i++)
	{
		for(j=i;j<i+len_subs;j++)
		{
			flag=1;
			if(s[j]!=s1[j-i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
				break;
	}

	return flag;
}

void stringcat(char str1[],char str2[])
{
	int i,l1,l2;
	l1 = length(str1);
	str1[l1] = ' ';
	for(i=0;str2[i]!='\0';i++)
	{
		str1[l1+i+1] = str2[i];
	}
	str1[l1+i+1] = '\0';

}
