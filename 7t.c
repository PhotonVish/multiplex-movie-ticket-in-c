/* Same as 6. Each hall will have a capacity of 30. Generate a booking list sorted on category (front
circle, rear circle) if 50% tickets are sold. Senior citizens will have preference over normal category.
user may enquire about seat through interactive mode. If hall is full, user will have option to book
for any of the other 3 movies (if available). */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "function.c"

void display(struct customer hf[],struct customer hr[],int hF,int hR);
void book(struct customer h[],int *H);

struct customer h1f[15],h2f[15],h3f[15],h4f[15],h1r[15],h2r[15],h3r[15],h4r[15];
//we have taken 8 counter variable to check weather hall&seat is unfilled or not
int h1F=0,h2F=0,h3F=0,h4F=0,h1R=0,h2R=0,h3R=0,h4R=0;

int main()
{	
	int hChoice , sChoice,a,bChoice,nChoice;
	while(1)
	{	
		system("clear");
		printf("************************************");
		printf("\n Multiplex Movie Ticket reservation ");
		printf("\n************************************");
		printf("\nEnter the no of ticket u want to book : ");
		scanf("%d",&nChoice);
		for(int i=0;i<nChoice;i++)
		{
			system("clear");
			printf("************************************");
			printf("\n Multiplex Movie Ticket reservation ");
			printf("\n************************************");
			printf("\n Select Movie\n 1 : First Movie\n 2 : Second Movie \n 3 : Third Movie\n 4 : Fourth movie\n\n Enter your choice : ");
			scanf("%d",&hChoice);
		
			if(fullH(hChoice))
				continue;
			
			if(fullS(hChoice ,&sChoice))
				continue;
			
			sselect(hChoice , sChoice);		
				
			if(h1F+h1R>=5 || h2F+h2R>=5 || h3F+h3R>=5 || h4F+h4R>=5)
			{
			//sorting list
				sort(h1f,h1F);
				sort(h1r,h1R);
				sort(h2f,h2F);
				sort(h2r,h2R);
				sort(h3f,h3F);
				sort(h3r,h3R);
				sort(h4f,h4F);
				sort(h4r,h4R);
				
				printf("\ndo u want to see the booking list(1 for yes , else for no) ?");
				scanf("%d",&bChoice);
				if(bChoice == 1)
				{	
					if(h1F+h1R>=5)
					{
						printf("\n\n\t\t\t\t\t HALL 1 \n");
						display(h1f,h1r,h1F,h1R);
					}
					
					if(h2F+h2R>=5)
					{
						printf("\n\n\t\t\t\t\t HALL 2 \n");
						display(h2f,h2r,h2F,h2R);
					}
					
					if(h3F+h3R>=5)
					{
						printf("\n\n\t\t\t\t\t HALL 3 \n");
						display(h3f,h3r,h3F,h3R);
					}
					
					if(h4F+h4R>=5)
					{
						printf("\n\n\t\t\t\t\t HALL 4 \n");
						display(h4f,h4r,h4F,h4R);
					}
				}
			}
		}
	printf("\n Press 1 to BOOK MORE TICKETS or any other integer to STOP : ");
	scanf("%d",&a);
	if(a!=1)
		break;
	}
}
