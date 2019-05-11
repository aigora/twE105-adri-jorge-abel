#include <stdio.h>
int main()
{
int i, n, t;
char texto [200], texto_encriptado [200];
printf("Introduzca el texto que desea encriptar \n");
scanf("%200[^\n]", texto);
for (n=0; texto[n]!='\0'; n++)
{
	t=n;
}
for(i=0; texto[i]!='\0'; i++)
{
	if(i<=t/2) 
	{
	texto_encriptado[i]=texto[n];
	n=n-1;
	}
else
	{
	texto_encriptado[i]=texto[i];	
	}
}
for(i=0; texto_encriptado[i]!='\0'; i++)
printf("%s\n", texto_encriptado);
return 0;
}
