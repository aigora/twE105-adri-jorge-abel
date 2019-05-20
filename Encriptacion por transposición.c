#include <stdio.h>
#define MAX 200
void trans(int i);
int main()
{
trans(0);
    return 0;
}
void trans(int i)
{
		
int cifrado[10]={5,2,6,3,8,4,9,0,7,1}, inicial[10]={0,1,2,3,4,5,6,7,8,9},j,k,l,m, espacios=0, caracteres_restantes;
char msg[MAX], cyph[MAX], v1[10], v2[10];
printf("Cifrado por transposicion \n");
printf("Introduzca el mensaje que desa cifrar: \n");
scanf ("%200[^\n]", &msg);

    for (i=0, j=0; msg[i]!='\0'; i++, j++)
    {
        if (msg[i]==' ')//Cada vez que nos encontremos un espacio pasamos al siguiente carácter
        {
            i++;
        }
        cyph[j]=msg[i];//El texto queda igual con los espacios eliminados
    }
    caracteres_restantes =10-(j%10);//Se guarda el número de caracteres restantes para completar los grupos de 10
    for (i=0;i<caracteres_restantes;i++)//mientras queden caracteres restantes
    {
        cyph[j]='*';//Se le asigna a cada uno un caracter nulo
        j++;
    }
    for (i=0, k=0;i<j;i++)//Recorremos el mensaje sin espacios
    {
        v1[k]=cyph[i];//copiamos el carácter en otra cadena
        k++;
        if (k%10==0)//si es multiplo de 10
        {
            v1[k]='\0';//se cierra el grupo
            for (m=0;m<10;m++)//Recorremos el grupo de 10
            {
                v2[m]=v1[inicial[m]];//guardamos en otra cadena los caracteres en el orden inicial
            }
              v2[10]='\0';//
            printf("%s", v2);//imprimimos en pantalla el grupo de 1
            
            k=0;//reiniciamos el recorrido de la primera cadena
     
        }
    }
   printf("\n");
     for (i=0;i<j;i++)//recorremos el  mensaje
    {
        v1[k]=cyph[i];//copiamos el carácter original en otra cadena
        k++;
        if (k%10==0)//si es múltiplo de 10
        {
            v1[k]='\0';//se cierra el grupo
            for (l=0;l<10;l++)//Recorremos el grupo
            {
                v2[l]=v1[cifrado[l]];//Guardamos el grupo con el orden cifrado
            }
              v2[10]='\0';//y lo cerramos
   
            printf("%s ", v2);//imprimimos en pantalla el grupo
            
            k=0;//reiniciamos la lectura de grupo
        }
    }   
}
