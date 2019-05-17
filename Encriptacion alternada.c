#include <#include <stdio.h>
int main()
{
int i, n, t;
char texto [200];
char texto_encriptado []="Hola";
printf("Introduzca el texto que desea encriptar \n");
scanf("%200[^\n]", texto);
printf("%s\n", texto);
n=0;
while(texto[n]!='\0')
{
	t=n;
	n++;
}
n=n-1;
i=0;
while(texto[i]!='\0')
{
	if(i<t/2) 
	{
	texto_encriptado[i]=texto[n];
	n=n-1;
	}
else
	{
		if(i%2==0)
		texto_encriptado[i]=texto[i];
		else
		{
		texto_encriptado[i]=texto[n];
		n=n-1;
		}
	}
	i++;
}
printf("%s\n", texto_encriptado);

return 0;
}

