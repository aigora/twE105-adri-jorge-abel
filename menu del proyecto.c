#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

int main()
{
	int opc;
	int i=0, x;
	char msg[100], cyph[100];
	do{
		system("cls");
		printf("MENU DE OPCIONES\n\n");//menu principal
		//le mostramos al usuario los diferentes menus
		printf("1.-Menu de encriptacion\n");
		printf("2.-Menu de desencriptacion\n");
		printf("3.-Desctipcion de los codigos\n");
		printf("4.-Salir\n");//sales del programa
		printf("Opcion escogida: ");
		scanf("%d",&opc);//elige la opcion
		switch(opc)
		{
			case 1:
				system("cls");//borra lo que hay escrito en la ventana
				int opc1;
				do{
				system("cls");
				printf("MENU DE ENCRIPTACION\n\n");
				//metodos de encriptacion
				printf("1.-Metodo Cesar \n");
				printf("2.-Forma 1\n");
				printf("3.-Forma 1\n");
				printf("4.-Salir\n");//vas al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc1);//eliges el codigo
 					switch(opc1)
 					{
 					case 1:
 						system("cls");
 						printf("defina x:");
 						scanf("%i", &x);
 						printf("\n");
 						printf("escriba el mensaje:\n");
 						scanf("%100[^\n]", msg);
 						x=x%27;
 						while (msg[i] !='\0'){
 						if('a'<=msg[i]<='z'){  // if (ord('a')<=msg[i]<='z')
							cyph[i]=msg[i]+x;
							if(msg[i]>'z')
							cyph[i]='a'+(msg[i]-123);//123=z+1
						}
						else
						if('A'<=msg[i]<='Z'){
							cyph[i]=msg[i]+x;
							if(msg[i]>'Z')
							cyph[i]='A'+(msg[i]-91); //91=Z+1
						}
						else
						cyph[i]=msg[i];
						++i;
					    }
					    printf("%s", cyph);
					    getch();
 						break;
 					case 2:
 						break;
 					case 3:
 						break;
 					case 4:
 						break;
 					default:
 						system("cls");
 						printf("la opcion no esta en el menu");//si el usuario elige un numero que no este en el menu
 						getch();//le das a cualquier tecla y regresas al menu principal
 						break;
		 			}
		 		}while(opc1!=4);//si le das al 4 regresas al menu principal
		 		break;
			case 2:
				system("cls");
				int opc2;
				do{
				system("cls");
				printf("MENU DE DESENCRIPTACION\n\n");
				printf("1.-Metodo Cesar\n");
				printf("2.-Forma 1\n");
				printf("3.-Forma 1\n");
				printf("4.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc2);
		 			switch(opc2)
		 			{
		 				case 1:
		 					break;
		 				case 2:
		 					break;
		 				case 3:
		 					break;
		 				case 4:
		 					break;
		 				default:
		 					system("cls");
		 					printf("la opcion no esta en el menu");
		 					getch();
		 					break;
							}
		 		}while(opc2!=4);
					break;
			case 3:
				system("cls");
				int opc3;
				do{
				system("cls");
				printf("MENU DE INFORMACION\n\n");//en este menu se	ofrece informacio de los codigos
				printf("1.-Metodo Cesar\n");
				printf("2.-Forma 1\n");
				printf("3.-Forma 1\n");
				printf("4.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc3);
			 		switch(opc3)
			 		{	
					 	case 1:
				 			break;
				 		case 2:
				 			break;
				 		case 3:
				 			break;
				 		case 4:
				 			break;
			 		default:
				 		system("cls");
					 	printf("la opcion no esta en el menu");
					 	getch();
					 	break;
						}
		 		}while(opc2!=4);
					break;
			case 4:
				//sales del programa
				break;
			default:
				system("cls");
				printf("la opcion que has escogido no esta en el menu ");
				getch();
				break;
		}
	}while(opc!=4);
	return 0;
}
