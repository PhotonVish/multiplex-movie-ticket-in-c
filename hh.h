struct customer
{
	char	name[15];
	int age;
};

int fullS(int hChoice,int *sChoice);

int k(int hF, int hR,int *sChoice);

void sselect(int hChoice , int sChoice);

void book(struct customer h[],int *H);

void display(struct customer hf[],struct customer hr[],int hF,int hR);

int fullH(int hChoice);

void sort(struct customer h[],int H);

//void txt(struct customer hf[],struct customer hr[],int hF,int hR);
