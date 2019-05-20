#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 200
int main()
{
	int opc, i, x, n, j;// opc es la opcion que se elige en el menu principal
	char msg[MAX], cyph[MAX];
	do{

		system("cls");//Borramos todo lo escrito anteriormente
		printf("MENU DE OPCIONES\n\n");//menú principal
		//le mostramos al usuario las diferentes opciones
		printf("1.-Menu de encriptacion\n");//este menú contiene los distintos métodos de encriptacion
		printf("2.-Menu de desencriptacion\n");//este otro contiene las formas en las que se pueden descodificar los mensajes ya encriptados por estos métodos
		printf("3.-Descripcion de los codigos\n");//este apartado explica al usuario las opciones en las que puede encriptar su mensaje
		printf("9.-Salir\n");//sales del programa, fin
		printf("Opcion escogida: ");
		scanf("%d",&opc);//elige la opcion
		switch(opc)
		{
			case 1://en caso de que se elija el menú de encriptación
				system("cls");//borra lo que hay escrito en la ventana
				int opc1;//variable opcion que se elige en el menú de encriptación
				do{// se ejecutan al menos una vez y mientras l usuario no salga del menu (presione 9)
				system("cls");
				printf("MENU DE ENCRIPTACION\n\n");
				//metodos de encriptacion
				printf("1.-Metodo Cesar \n");
				printf("2.-Metodo Ascii\n");
				printf("3.-Encriptacion Alternada\n");
				printf("4.-Salir\n");//vas al menu principal
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
									cyph[i]='a'+(cyph[i]-123);//123=z+1. de esta forma provocamos que vuelva al principio del alfabeto
							}

						else
							if(msg[i] >= 'A' && msg[i] <= 'Z')//si el carácter es una letra mayúscula
							{
							cyph[i]=msg[i]+x;//el caracter es cifrado con normalidad
								if(cyph[i]>'Z')//si se pasa  de la Z
								cyph[i]='A'+(cyph[i]- 91); //91=Z+1. provocamos que vuelva al principio del alfabeto 
							}
						else//en caso de que sea cualquier otro caracter
						cyph[i]=msg[i];//se mantiene igual
					    }
					    cyph[i] ='\0';
					    printf("%s", cyph);//se imprime en pantalla el mensaje cifrado
					    getch();//cuando se pulse cualquier tecla se finaliza la secuencia
 						break;
 					case 2:
 						system("cls");
 						printf("escriba el mensaje:\n");
 						scanf(" %[^\n]", msg);
 						printf("|%s|\n", msg);
 						i=0;
 						while (msg[i] !='\0'){
 						cyph[i]=msg[i];
 						printf("|%i|", cyph[i]);
 						++i;
					    }
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
				printf("3.-Forma 1\n");
				printf("4.-Salir\n");//vuelves al menu principal
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
							msg[i]='z'-(96-msg[i]);//123=z+1
						}
						else
						if(cyph[i] >= 'A' && cyph[i] <= 'Z')
						{
							msg[i]=cyph[i]-x;
							if(msg[i]<'A')
							msg[i]='Z'-(64-msg[i]); //91=Z+1
						}
						else
						msg[i]=cyph[i];
						++i;
					    }
					    msg[i] ='\0';
					    printf("%s", msg);


					    getch();
		 					break;
		 				case 2:
		 					system("cls");
		 					printf("indique el numero de caracteres (incluyendo espacios):");
		 					scanf("%i", &x);
		 					
		 					for(i=0;i<x;++i){
							scanf(" %i\t", j);
							msg[i]=j;
							printf("%c",msg[i] );
 							}
 							
		 					break;
		 				case 3:
		 				system("cls");
		 					printf("indique el numero de caracteres (incluyendo espacios):");
		 					scanf("%i", &x);
		 					i=0;
		 					while (i<0){
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
				printf("3.-Forma 1\n");
				printf("4.-Salir\n");//vuelves al menu principal
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
								j=97+(n-123);
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
								j=65+(n-91);
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

							for(i=97;i<123;i++){
								x=x%27;
								n=i-60;
								j=n;
								printf("%c", i);
								printf("\t");
								printf("%c", j);
								printf("\n");
							}
							for(i=65;i<91;i++){
								x=x%27;
								n=i+90;
								j=n;
								printf("%c", i);
								printf("\t");
								printf("%c", j);
								printf("\n");
							}
							getch();
				 			break;
				 		case 4:
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



