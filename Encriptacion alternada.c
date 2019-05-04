#include <stdio.h>
int main()
{
int i=0, n=1;
char texto [200], texto_encriptado [200];
printf("Introduzca el texto que desea encriptar \n");
scanf("%200[^\n]", texto);
while( texto[i]!='\0')
{
if(i%2!=0) 
	{
	texto_encriptado[i]=texto[i]+n;
	n--;
	i++;
	}
else
	{
	texto_encriptado[i]=texto[i]-n;
	n++;
	i++;	
	}
}
printf("%s \n", texto_encriptado);
return 0;
}
