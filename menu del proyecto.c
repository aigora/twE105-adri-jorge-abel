#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int opc;
	int i, x, n, j;
	char msg[200], cyph[200];
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
				printf("2.-Metodo Ascii\n");
				printf("3.-Metodo Windings\n");
				printf("4.-Forma 1\n");
				printf("10.-Salir\n");//vas al menu principal
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
 						scanf(" %[^\n]", msg);
 						printf("%s\n", msg);
						 x=x%27;
						 i=0;
 						while (msg[i] !='\0'){
 						if(msg[i] >= 'a' && msg[i] <= 'z'){  // if (ord('a')<=msg[i]<='z')
							cyph[i]=msg[i]+x;
							if(cyph[i]>'z')
								cyph[i]='a'+(cyph[i]-123);//123=z+1
						}
						else
						if(msg[i] >= 'A' && msg[i] <= 'Z'){
							cyph[i]=msg[i]+x;
							if(cyph[i]>'Z')
							cyph[i]='A'+(cyph[i]- 91); //91=Z+1
						}
						else
						cyph[i]=msg[i];
						++i;
					    }
					    cyph[i] ='\0';
					    printf("%s", cyph);
					    
						
					    getch();
 						break;
 					case 2:
 						system("cls");
 						printf("escriba el mensaje:\n");
 						scanf(" %[^\n]", msg);
 						while (msg[i] !='\0'){
 						printf("|%i|", msg[i]);
 						++i;
					    }
					    msg[i]='\0';
					    
					    getch();
 						break;
 					case 3:
 						system("cls");
 						printf("escriba el mensaje:\n");
 						scanf(" %[^\n]", msg);
 						printf("%s\n", msg);
						 x=x%27;
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
 					default:
 						system("cls");
 						printf("la opcion no esta en el menu");//si el usuario elige un numero que no este en el menu
 						getch();//le das a cualquier tecla y regresas al menu principal
 						break;
		 			}
		 		}while(opc1!=10);//si le das al 4 regresas al menu principal
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
				printf("4.-Forma 1\n");
				printf("10.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc2);
		 			switch(opc2)
		 			{
		 				case 1:
		 					break;
		 				case 2:
		 					system("cls");
	 						printf("defina x:");
	 						scanf("%i", &x);
	 						printf("escriba los numeros de uno en uno:\n");
	 						for(i=0;i<x;++i){
	 						scanf("%i\t", cyph[i]);
							}
							cyph[i]='\0';
							printf("%s", cyph);
							
							 getch();
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
		 		}while(opc2!=10);
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
				printf("4.-Forma 1\n");
				printf("10.-Salir\n");//vuelves al menu principal
				printf("opcion escogida: ");
				scanf("%d",&opc3);
			 		switch(opc3)
			 		{	
					 	case 1:
					 		printf("\n");
					 		printf("Codigo Cesar:\n");
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
				 			printf("\n");
				 			printf("Codigo Ascii:\n");
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
				 			printf("\n");
					 		printf("Codigo Windings:\n");
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
				 			break;
				 		case 4:
				 			break;
			 		default:
				 		system("cls");
					 	printf("la opcion no esta en el menu");
					 	getch();
					 	break;
						}
		 		}while(opc2!=10);
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
	}while(opc!=10);
	return 0;
}
