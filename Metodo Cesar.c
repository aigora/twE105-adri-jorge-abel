#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
//prototipo de funciones.
void encriptar(char texto[MAX],int numero);
//Funci�n para encriptar Cifrado Cesar en C
void encriptar(char texto[MAX],int numero)
{
    int i;
    char letra;
    for (i=0; texto[i]!='\0'; i++)
    {
        texto[i]=texto[i]+numero;
        
    }
    printf("\nEl texto encriptado es:\n%s\n",texto);
}
 
//Procedimiento principal.
int main()
{
    //Variables necesarias
    int x;
    char texto[MAX];
    //Presentaci�n
    printf("Encriptacion por Metodo Cesar:\n");
    printf("Introduzca su texto (max 300 caracteres):     ");
    //Un especificador que admite texto:
    scanf("%200[^\n]", texto);
    //Vac�a el buffer del teclado
    while(getchar()!='\n');
    //Pedimos el n�mero
    printf("introduce un numero : ");
    scanf("%d",&x);
    //Vac�a el buffer del teclado
    while(getchar()!='\n');
    //Llamamos a la funci�n encriptar
    encriptar(texto, x);
    return 0;
}
