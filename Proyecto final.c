#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 200
int main()
{
	int cifrado[10]={5,2,6,3,8,4,9,0,7,1}, inicial[10]={0,1,2,3,4,5,6,7,8,9},i,j,k,l,m,x,n,opc, espacios=0, caracteres_restantes;
	char msg[MAX], cyph[MAX], v1[10], v2[10];// opc es la opcion que se elige en el menu principal
	
	do{

		system("cls");//Borramos todo lo escrito anteriormente
		printf("MENU DE OPCIONES\n\n");//menú principal
		//le mostramos al usuario las diferentes opciones
		printf("1.-Menu de encriptacion\n");//este menú contiene los distintos métodos de encriptacion
		printf("2.-Menu de desencriptacion\n");//este otro contiene las formas en las que se pueden descodificar los mensajes ya encriptados por estos métodos
		printf("3.-Descripcion de los codigos\n");//este apartado explica al usuario las opciones en las que puede encriptar su mensaje
		printf("4.-Salir\n");//sales del programa, fin
		printf("Opcion escogida: ");
		scanf("%d",&opc);//elige la opcion
		switch(opc)
		{
			case 1://en caso de que se elija el menú de encriptación
				system("cls");//borra lo que hay escrito en la ventana
				int opc1;//variable opcion que se elige en el menú de encriptación
				do{// se ejecutan al menos una vez y mientras l usuario no salga del menu (presione 4)
				system("cls");
				printf("MENU DE ENCRIPTACION\n\n");
				//metodos de encriptacion
				printf("1.-Metodo Cesar\n");
				printf("2.-Metodo Ascii\n");
				printf("3.-Metodo Windings\n");
				printf("4.-Metodo por transposicion\n");
				printf("5.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc1);//eliges el codigo
 					switch(opc1)
 					{
 					case 1://Se inicia el método de encriptación César
 						system("cls");
 						printf("defina x:");//x es el número de posiciones en el alfabeto que se moverá cada letra
 						scanf("%i", &x);//lo determina el usuario
 						printf("\n");// se deja un espacio para favorecer la limpieza de la pantalla
 						printf("escriba el mensaje:\n");
						scanf(" %[^\n]", msg);//el mensaje introducido por el usuario se almacena en la variable msg
 						printf("%s\n", msg);//se muestra el mensaje antes de encriptaro
						x=x%26;//con esta operación evitamos que se sume un numero mayor del total de letras en el abecedario
 						for (i=0; msg[i] !='\0'; i++)//comenzamos la lectura por el primer caracter introducido por el usuario y la finalizamos con la secuencia de cierre
						{
 						if(msg[i] >= 'a' && msg[i] <= 'z')//si el caracter del mensaje introducido es una letra minúscula
							{  
								cyph[i]=msg[i]+x;//el caracter cifrado será ese desplazado x espacios
								if(cyph[i]>'z')//si el desplazamiento provoca que el caracter ya no sea una letra
							 	cyph[i]= rueda(cyph[i]);//123=z+1. de esta forma provocamos que vuelva a la a
							}

						else
							if(msg[i] >= 'A' && msg[i] <= 'Z')//si el carácter es una letra mayúscula
							{
							cyph[i]=msg[i]+x;//el caracter es cifrado con normalidad
								if(cyph[i]>'Z')//si se pasa  de la Z
								cyph[i]= rueda(cyph[i]); //91=Z+1. de esta forma provocamos que vuelva a la A
							}
						else//en caso de que sea cualquier otro caracter
						cyph[i]=msg[i];//se mantiene igual
					    }
					    cyph[i] ='\0';
					    printf("%s", cyph);//se imprime en pantalla el mensaje cifrado
						FILE *ec;
 						ec = fopen("encriptado_cesar.txt", "w");
					    fprintf(ec,"%s",cyph);
					    fclose(ec);
					    printf("%s", cyph);//se imprime en pantalla el mensaje cifrado
					    getch();//cuando se pulse cualquier tecla se finaliza la secuencia
 						break;
 					case 2:
 						system("cls");
 						printf("escriba el mensaje:\n");
 						scanf(" %[^\n]", msg);
 						printf("|%s|\n", msg);
 						i=0;
 						FILE *ea;
 						ea = fopen("encriptado_ascii.txt", "w");
 						while (msg[i] !='\0'){
 						cyph[i]=msg[i];
 						printf("|%i|", cyph[i]);
 						fprintf(ea,"|%i|", cyph[i]);
 						++i;
					    }
					    fclose(ea);
					    getch();
 						break;
 					case 3:
 						system("cls");
 						printf("escriba el mensaje:\n");
 						scanf(" %[^\n]", msg);
 						printf("%s\n", msg);
						 x=x%26;
						 i=0;
 						while (msg[i] !='\0'){
 						if(msg[i] >= 'a' && msg[i] <= 'z'){  // if (ord('a')<=msg[i]<='z')
							cyph[i]=msg[i]-60;
						}
						else
						if(msg[i] >= 'A' && msg[i] <= 'Z'){
							cyph[i]=msg[i]+90;
						}
						else
						cyph[i]=msg[i];
						++i;
					    }
					    cyph[i] ='\0';
					    printf("%s", cyph);
						FILE *ew;
 						ew = fopen("encriptado_windings.txt", "w");
					    fprintf(ew,"%s",cyph);
					    fclose(ew);
					    getch();
 						break;
 					case 4:
 						system("cls");
 						printf("Introduzca el mensaje que desa cifrar: \n");
						scanf(" %[^\n]", msg);
						FILE *eal;
 						eal = fopen("encriptado_alternada.txt", "w");
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
						            fprintf(eal,"%s",v2);
						            k=0;//reiniciamos la lectura de grupo
						        }
						    }  
							fclose(eal); 
						getch();
 						break;
 					case 5:
 						break;
 					default:
 						system("cls");
 						printf("la opcion no esta en el menu");//si el usuario elige un numero que no este en el menu
 						getch();//le das a cualquier tecla y regresas al menu principal
 						break;
		 			}
		 		}while(opc1!=5);//si le das al 5 regresas al menu principal
		 		break;
			case 2:
				system("cls");
				int opc2;
				do{
				system("cls");
				printf("MENU DE DESENCRIPTACION\n\n");
				printf("1.-Metodo Cesar\n");
				printf("2.-Metodo Ascii\n");
				printf("3.-Metodo Windings\n");
				printf("4.-Metodo por transposicion\n");
				printf("5.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc2);
		 			switch(opc2)
		 			{
		 				case 1:
		 					system("cls");
 						    printf("defina x:");
 						    scanf("%i", &x);
 						    printf("\n");
 						    printf("escriba el mensaje encriptado:\n");
 						    scanf(" %[^\n]",cyph);
 						    x=x%27;
 						    i=0;
 						    while (cyph[i] !='\0')
							 {
 						    if(cyph[i] >= 'a' && cyph[i] <= 'z')
							 {  // if (ord('a')<=msg[i]<='z')
							msg[i]=cyph[i]-x;
							if(msg[i]<'a')
							msg[i]='z'-(96-msg[i]);//96=a-1
						}
						else
						if(cyph[i] >= 'A' && cyph[i] <= 'Z')
						{
							msg[i]=cyph[i]-x;
							if(msg[i]<'A')
							msg[i]='Z'-(64-msg[i]); //64=A-1
						}
						else
						msg[i]=cyph[i];
						++i;
					    }
					    msg[i] ='\0';
					    printf("%s", msg);
						FILE *dc;
 						dc = fopen("desencriptado_cesar.txt", "w");
					    fprintf(dc,"%s",msg);
					    fclose(dc);
					    getch();
		 					break;
		 				case 2:
		 					system("cls");
		 					printf("indique el numero de caracteres (incluyendo espacios):");
		 					scanf("%i", &x);
		 					
		 					do{
							scanf("%i\t", j);
							printf("%c",j );
							++i;
 							}
 							while(x>i);
 							
		 					break;
		 				case 3:
		 				system("cls");
		 					printf("indique el numero de caracteres (incluyendo espacios):");
		 					scanf("%i", &x);
		 					i=0;
		 					while (i<x){
							scanf("%i", &j);
							printf("%c",j);
							i++;
 							}
 							getch();
		 					break;
		 				case 4:
 							break;
		 				case 5:
 							break;
 						default:
 						system("cls");
 						printf("la opcion no esta en el menu");//si el usuario elige un numero que no este en el menu
 						getch();//le das a cualquier tecla y regresas al menu principal
 						break;
							}
		 		}while(opc2!=5);
					break;
			case 3:
				system("cls");
				int opc3;
				do{
				system("cls");
				printf("MENU DE INFORMACION\n\n");//en este menu se	ofrece informacio de los codigos
				printf("1.-Metodo Cesar\n");
				printf("2.-Metodo Ascii\n");
				printf("3.-Metodo Windings\n");
				printf("4.-Metodo por transposicion\n");
				printf("5.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc3);
			 		switch(opc3)
			 		{	
					 	case 1:
					 		system("cls");
					 		printf("\n");
					 		printf("CODIGO CESAR:\n");
							printf("Este codigo consiste en la conversion de cada letra del  mensaje en otra separada x espacios en el abecedario,\nsiendo x definida por el usuario\n");
							printf("\n");
							printf("Por ejemplo, si x=3:\n");
							x=2;
							
							for(i=97;i<123;i++){
								x=x%27;
								n=i+x;
								if(n>122)
								j=rueda(n);
								else
								j=n;
								printf("%c", i);
								printf("\t");
								printf("%c", j);
								printf("\n");
							}
							for(i=65;i<91;i++){
								x=x%27;
								n=i+x;
								if(n>90)
								j=rueda(n);
								else
								j=n;
								printf("%c", i);
								printf("\t");
								printf("%c", j);
								printf("\n");
							}
							getch();
				 			break;
				 		case 2:
				 			system("cls");
				 			printf("\n");
				 			printf("CODIGO ASCII:\n");
							printf("Este codigo consiste en la convesion de cada letra del mensaje en la que le corresponde en el codigo ASCII \n");
							printf("\n");
							printf("Por ejemplo:\n");
							for(i=97;i<123;i++){
								printf("%c", i);
								printf("\t");
								printf("%i", i);
								printf("\n");
							}
							for(i=65;i<91;i++){
								printf("%c", i);
								printf("\t");
								printf("%i", i);
								printf("\n");
							}
							getch();
				 			break;
				 		case 3:
				 			system("cls");
				 			printf("\n");
					 		printf("CODIGO WINDINGS:\n");
							printf("Este codigo consiste en la conversion de cada letra del  mensaje un caracter.\n");
							
							
							printf("\n");
							printf("letra:");
							printf("\t");
							printf("  caracter:");
							printf("\t");
							printf("numero ASCII:");
							printf("\n");
							

							for(i=97;i<123;i++){
								x=x%27;
								n=i-60;
								j=n;
								printf("%c", i);
								printf("      \t");
								printf("  %c", j);
								printf("       \t");
								printf("%i", j);
								printf("\n");
							}
							for(i=65;i<91;i++){
								x=x%27;
								n=i+90;
								j=n;
							printf("%c", i);
								printf("      \t");
								printf("  %c", j);
								printf("       \t");
								printf("%i", j);
								printf("\n");
							}
							getch();
				 			break;
				 		case 4:
				 			system("cls");
				 			printf("CODIGO POR TRANSPOSICION:\n");
				 			printf("Este codigo consiste en la reordenacion de las letras del mensaje agrupando \nel mensaje en bloques de 10 caracteres, si en el caso de que faltasen letras\n para completar el ultimo grupo de 10 el programa llenara los huecos \ncon el caracter '*'.");
							printf("\n El programa en primer lugar elimina los espacios del mensaje,\n despues, agrupa los caracteres restantes de 10 en 10\n para finalmente cambiar el orden en el que se encuentran los caracteres de cada grupo.\n");
							printf("\nEjemplo:");
							printf("el mensaje: Este codigo estara encriptado:\n");
							printf("pasa a: Estecodigoestaraencriptado\n");
							printf("se agrupa: Estecodigo estaraencr iptado****\n");
							printf("otdegcoEis ateacrrens ot*a*d*i*p\n");
							getch();
				 			break;
				 		case 5:
 							break;
			 		default:
				 		system("cls");
					 	printf("la opcion no esta en el menu");
					 	getch();
					 	break;
						}
		 		}while(opc3!=5);
					break;
			case 4:
				//sales del programa
				break;
			default:
				system("cls");
				printf("la opcion que has escogido no esta en el menu ");
				getch();
				break;
		
	}while(opc!=4);
	return 0;

}while(opc!=4);
}
int rueda(int letra){

int salida;
salida=  letra-26;//26='z'-'a' ó 'Z'-'A'
return salida;
}


