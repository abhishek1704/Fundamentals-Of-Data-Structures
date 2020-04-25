
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

	FILE *fp1,*fp2;
	char c,d;
	int ch,k=0,p;

	do
	{
		printf("\n----Main Menu----\n\n1.Copy\n2.Type\n3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			fp1 = fopen(argv[1],"r");
			if(fp1!=NULL)
			{
				fp2 = fopen(argv[2],"w");
				while((c=getc(fp1))!=EOF)
				{
					putc(c,fp2);
				}
				printf("Contents copied successfully!!");
			}
			else{printf("File is not opened successfully !!");}
			fclose(fp1);
			fclose(fp2);
			break;

		case 2:
			fp2 = fopen(argv[2],"r");
			if(fp2!=NULL)
			{
				printf("Contents of second file are :\n\n");
				while((d=getc(fp2))!=EOF)
				{
					printf("%c",d);
				}
			}
			else{printf("File is not opened successfully !!");}
			fclose(fp2);
			break;

		case 3:
			k++;
			break;
		}
		printf("\nDo you want to continue?\nPress 1 if yes and 0 if no :");
		scanf("%d",&p);
	}while(k==0 && p!=0);


return EXIT_SUCCESS;
}
