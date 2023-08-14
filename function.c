#include "hh.h"

extern struct customer h1f[15],h2f[15],h3f[15],h4f[15],h1r[15],h2r[15],h3r[15],h4r[15];
extern int h1F,h2F,h3F,h4F,h1R,h2R,h3R,h4R;

int fullS(int hChoice,int *sChoice)
{
		//int kk;
		if(hChoice==1)
			return k(h1F,h1R,sChoice);

		else if(hChoice==2)
			return k(h2F,h2R,sChoice);
		
		else if(hChoice==3)
			return k(h3F,h3R,sChoice);	

		else if(hChoice==4)
			return k(h4F,h4R,sChoice);
		return 0;
}

int k(int hF, int hR,int *sChoice)
{
			int kk;
			if(hF < 15 && hR <15)
			{
				printf("\n 1 : FRONT circle seat\n 2 : REAR circle seat\n\n your choice : ");
				scanf("%d",sChoice);
			}
			else if(hF < 15)
			{
				printf("\nonly FRONT CIRCLE seat is available , do u want to select it(1 for yes)");
				scanf("%d",&kk);
				if(kk==1)
					*sChoice=1;
				else if(kk != 1)
					return 1;
			}
			else if(hR <15)
			{
				printf("\nonly REAR CIRCLE seat is available , do u want to select it(1 for yes)");
				scanf("%d",&kk);
				if(kk==1)
					*sChoice=2;
				else if(kk != 1)
					return 1;
			}
			return 0;
}

void sselect(int hChoice , int sChoice)
{
	if(hChoice==1)
		{
			if(sChoice==1)
				book(h1f,&h1F);
			else if(sChoice==2)
				book(h1r,&h1R);	
		}

		else if(hChoice==2)
		{	
			if(sChoice==1)
				book(h2f,&h2F);
			else if(sChoice==2)
				book(h2r,&h2R);	
		}
		
		else if(hChoice==3)
		{	
			if(sChoice==1)
				book(h3f,&h3F);
			else if(sChoice==2)
				book(h3r,&h3R);	
		}

		else if(hChoice==4)
		{	
			if(sChoice==1)
				book(h4f,&h4F);
			else if(sChoice==2)
				book(h4r,&h4R);	
		}
		else
			printf(" please enter right choices !");
}
	
void book(struct customer h[],int *H)
{
	int ku=(*H);
	printf("\n enter the name : ");
	scanf("%s",h[ku].name);
	printf(" enter age : ");
	scanf("%d",&h[ku].age);
	*H=(*H)+1;
}

void sort(struct customer h[],int H)
{
	char nTemp[15];
	for(int i= 0;i < H; ++i)
	{      
    		for (int j=0; j < H-i;++j)
    		{
      		if (h[j].age < h[j+1].age)
      		 {
        			int aTemp = h[j].age;
        			strcpy(nTemp,h[j].name);
        			h[j].age = h[j+1].age;
        			strcpy(h[j].name,h[j+1].name);
        			h[j+1].age = aTemp;
        			strcpy(h[j+1].name,nTemp);
			}
		 }
	}
}

void display(struct customer hf[],struct customer hr[],int hF,int hR)
{
	printf("\t FRONT CIRCLE SEAT \t\t\t\t\t\t REAR CIRCLE SEAT \n");
	printf("\t  NAME\t\t AGE \t\t\t\t\t\t  NAME\t\t AGE \n");
	//printf("\033[s");
	for(int i=0;i<hF;i++)
		printf("\t%-16s %d\n",hf[i].name,hf[i].age);
	printf("\033[%dA",hF);
	for(int i=0;i<hR;i++)
		printf("\t\t\t\t\t\t\t\t\t %-16s %d\n",hr[i].name,hr[i].age);
	if(hF>hR)
		printf("\033[%dB",hF-hR);

}

int fullH(int hChoice)
{
	if(hChoice ==1 && h1R+h1F ==30)
	{
		printf(" this hall is full please check other halls :");
		return 1;
	}
	else if(hChoice ==2 && h2R+h2F ==30)
	{
		printf(" this hall is full please check other halls :");
		return 1;
	}
	else if(hChoice ==3 && h3R+h3F ==30)
	{
		printf(" this hall is full please check other halls :");
		return 1;
	}
	else if(hChoice ==4 && h4R+h4F ==30)
	{
		printf(" this hall is full please check other halls :");
		return 1;
	}
	return 0;
}
