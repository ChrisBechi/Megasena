#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

char guarda[35],ganhou[10][40],auxi[35] = {' '},auxil[50] = {' '};
int posi[60] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int jogo_num[60] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
int palpite[6] = {0}; 
int nresult[7] = {0}; 
int quant[6] = {0};
int s[60] = {0};
int ganha=0;
int quadra=0,quina=0,sena=0;

gotoxy(int linha,int coluna){
	COORD xy;
	xy.X = linha;
	xy.Y = coluna;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy); 
}

void concast(char *msg, char vetP[][50]){
	int i=0,con=0,ind=0,c=0;
	char dest[100];
	while(msg[i] != '\0'){
		if(msg[i] == '@'){
			for(c=0;vetP[con][c]!='\0';c++){
				dest[ind] = vetP[con][c];
				ind++;
			}
			con++;
		}else{
			dest[ind] = msg[i];
			ind++;
		}
		i++;
	}
	dest[ind] = '\0';
	strcpy(vetP[0],dest);
}

void ord_vet(int resul[], int posi[]){
    for(int c=0;c<60;c++){
		for(int i=0;i<60;i++){
	    	if(resul[c] > resul[i]){
	    		int aux = resul[c];
	    		resul[c] = resul[i];
	    		resul[i] = aux;
	    		aux = posi[c];
	    		posi[c] = posi[i];
	    		posi[i] = aux;
			}
		} 
	}
}

void desord_vet(int resul[], int posi[]){
    for(int c=0;c<60;c++){
		for(int i=0;i<60;i++){
	    	if(posi[c] < posi[i]){
	    		int aux = resul[c];
	    		resul[c] = resul[i];
	    		resul[i] = aux;
	    		aux = posi[c];
	    		posi[c] = posi[i];
	    		posi[i] = aux;
			}
		} 
	}
}

jogar(int controle){
	int jogo;
	system("mode 53,19");
	system("cls");
	printf("+===================================================+\n");
	printf("|                      MEGA SENA                    |\n");
	printf("+===================================================+\n");
	printf("|                                                   |\n");
	for(int l=0;l<6;l++){
		printf("| ");
		for(int c=0,po;c<10;c++,po++){
			if(jogo_num[po] != 0){
				printf("[%02d] ",jogo_num[po]);
			}else{
				printf("[XX] ");
			}
		}
		printf("|\n|                                                   |\n");
	}
	printf("+===================================================+\n");
	printf("| =>                                                |\n");
	printf("+===================================================+");
	gotoxy(5,17);
	int err = scanf("%d",&jogo);
	fflush(stdin);
	while((err == 0 || jogo > 60 || jogo < 1) || jogo_num[jogo-1] == 0){
		gotoxy(5,17);
		printf("                                               |\n");
		gotoxy(5,17);
		err = scanf("%d",&jogo);
		fflush(stdin);
	}
	palpite[controle] = jogo;
	jogo_num[jogo-1] = 0;	
}

int menu(){
	int escol;
	system("cls");
	system("mode 39,9");
	printf("=======================================\n");
	printf("|              MEGA-SENA              |\n");
	printf("=======================================\n");
	printf("| [1] - Mostrar Resultados            |\n");
	printf("| [2] - Num. Jogados que se repetiram |\n");
	printf("| [3] - qtd de vezes que ja cairam    |\n");
	printf("| [4] - Sair                          |\n");
	printf("=======================================\n");
	printf("=> ");
	scanf("%d",&escol);
	switch(escol){
		case 1:{
			system("cls");
			system("mode 41,21");
			printf("+=======================================+\n");
			printf("|              JOGOS GANHOS             |\n");
			printf("+=======================================+\n");
			printf("|    QUADRA   |    QUINA   |    SENA    |\n");
			printf("+=======================================+\n");
			printf("|");
			gotoxy(5,5);
			printf("%d",quadra);
			gotoxy(14,5);
			printf("|");
			gotoxy(19,5);
			printf("%d",quina);
			gotoxy(27,5);
			printf("|");
			gotoxy(32,5);
			printf("%d",sena);
			gotoxy(40,5);
			printf("|");
			printf("\n+=======================================+\n");
			printf("\n+=======================================+\n");
			printf(  "|  Resultado dos Numeros dos festivais  |\n");
			printf(  "+=======================================+\n");
			printf(  "|Festi.|   Nº que sairam   |    Datas   |\n");
			printf(  "+=======================================+\n");
			if(quadra == 0 && quina == 0 && sena == 0)
				printf("|   Voce não ganhou nada, Tente novamente    |");
			for(int rep=0;rep<=ganha-1;rep++){
				printf("|%s",ganhou[rep]);
				gotoxy(40,rep+13);
				printf("|\n");
			}
			printf("+=======================================+\n");
			printf("\n     Digite <ENTER> para continuar");
			getch();
			break;
		}
		case 2:{
			system("cls");
			system("mode 43,10");
			printf("+=========================================+\n");
			printf("| NUMEROS JOGADOS E QUANTAS VEZES JÁ SAIU |\n");
			printf("+=========================================+\n");
			printf("|  %02d  |  %02d  |  %02d  |  %02d  |  %02d  |  %02d  |\n",palpite[0],palpite[1],palpite[2],palpite[3],palpite[4],palpite[5]);
			printf("|=========================================|\n");
			printf("| %d",quant[0]);
			gotoxy(7,5);
			printf("| %d",quant[1]);
			gotoxy(14,5);
			printf("| %d",quant[2]);
			gotoxy(21,5);
			printf("| %d",quant[3]);
			gotoxy(28,5);
			printf("| %d",quant[4]);
			gotoxy(35,5);
			printf("| %d",quant[5]);
			gotoxy(42,5);
			printf("|");
			printf("\n+=========================================+\n");
			printf("\n      Digite <ENTER> para continuar");
			getch();
			break;
		}
		case 3:{
			char tmp;
			system("cls");
			system("mode 44,10");
			printf("Mostrar em ordem que mais se repetiram [S/N]");
			printf("\n=> ");
			fflush(stdin);
			scanf("%c",&tmp);
			while(tmp != 's' && tmp != 'S' && tmp != 'n' && tmp != 'N'){
				printf("Mostrar em ordem que mais se repetiram [S/N]");
				printf("\n=> ");
				fflush(stdin);
				scanf("%c",&tmp);
			}
			system("mode 91,17");
			if(tmp == 'S' || tmp == 's'){
				ord_vet(s,posi);
			}else{
				desord_vet(s,posi);
			}
			printf("+-----------------------------------------------------------------------------------------+\n");
			printf("|                    NUMEROS QUE MAIS CAIRAM NA HISTORIA DA MEGA SENA                     |\n");
			printf("+--------------+--------------+--------------+--------------+--------------+--------------+\n");
			int l=0;
			for(int col=0;col<10;col++){
				for(int tt=0;tt<6;tt++){
					printf("| [ %02d | %3d ] ",posi[l],s[l]);
					l++;
				}
				printf("|");
				printf("\n");
			}
			printf("+--------------+--------------+--------------+--------------+--------------+--------------+\n");
			printf("\n                             Digite <ENTER> para continuar");
			getch(); 
			l=0;
			break;
		}
		case 4:{
			return 0;
			break;
		}
	}
}

void soma(int sort[], int s[]){
	for(register int c=1;c<7;c++){
		switch(sort[c]){
			case 1:{ 
				s[0] += 1; 
				break;
			}
			case 2:{
				s[1] += 1;
				break;
			}
			case 3:{
				s[2] += 1;
				break;
			}
			case 4:{
				s[3] += 1;
				break;
			}
			case 5:{
				s[4] += 1;
				break;
			}
			case 6:{
				s[5] += 1;
				break;
			}
			case 7:{
				s[6] += 1;
				break;
			}
			case 8:{
				s[7] += 1;
				break;
			}
			case 9:{
				s[8] += 1;
				break;
			}
			case 10:{
				s[9] += 1;
				break;
			}
			case 11:{
				s[10] += 1;
				break;
			}
			case 12:{
				s[11] += 1;
				break;
			}
			case 13:{
				s[12] += 1;
				break;
			}
			case 14:{
				s[13] += 1;
				break;
			}
			case 15:{
				s[14] += 1;
				break;
			}
			case 16:{
				s[15] += 1;
				break;
			}
			case 17:{
				s[16] += 1;
				break;
			}
			case 18:{
				s[17] += 1;
				break;
			}
			case 19:{
				s[18] += 1;
				break;
			}
			case 20:{
				s[19] += 1;
				break;
			}
			case 21:{
				s[20] += 1;
				break;
			}
			case 22:{
				s[21] += 1;
				break;
			}
			case 23:{
				s[22] += 1;
				break;
			}
			case 24:{
				s[23] += 1;
				break;
			}
			case 25:{
				s[24] += 1;
				break;
			}
			case 26:{
				s[25] += 1;
				break;
			}
			case 27:{
				s[26] += 1;
				break;
			}
			case 28:{
				s[27] += 1;
				break;
			}
			case 29:{
				s[28] += 1;
				break;
			}
			case 30:{
				s[29] += 1;
				break;
			}
			case 31:{
				s[30] += 1;
				break;
			}
			case 32:{
				s[31] += 1;
				break;
			}
			case 33:{
				s[32] += 1;
				break;
			}
			case 34:{
				s[33] += 1;
				break;
			}
			case 35:{
				s[34] += 1;
				break;
			}
			case 36:{
				s[35] += 1;
				break;
			}
			case 37:{
				s[36] += 1;
				break;
			}
			case 38:{
				s[37] += 1;
				break;
			}
			case 39:{
				s[38] += 1;
				break;
			}
			case 40:{
				s[39] += 1;
				break;
			}
			case 41:{
				s[40] += 1;
				break;
			}
			case 42:{
				s[41] += 1;
				break;
			}
			case 43:{
				s[42] += 1;
				break;
			}
			case 44:{
				s[43] += 1;
				break;
			}
			case 45:{
				s[44] += 1;
				break;
			}
			case 46:{
				s[45] += 1;
				break;
			}
			case 47:{
				s[46] += 1;
				break;
			}
			case 48:{
				s[47] += 1;
				break;
			}
			case 49:{
				s[48] += 1;
				break;
			}
			case 50:{
				s[49] += 1;
				break;
			}
			case 51:{
				s[50] += 1;
				break;
			}
			case 52:{
				s[51] += 1;
				break;
			}
			case 53:{
				s[52] += 1;
				break;
			}
			case 54:{
				s[53] += 1;
				break;
			}
			case 55:{
				s[54] += 1;
				break;
			}
			case 56:{
				s[55] += 1;
				break;
			}
			case 57:{
				s[56] += 1;
				break;
			}
			case 58:{
				s[57] += 1;
				break;
			}
			case 59:{
				s[58] += 1;
				break;
			}
			case 60:{
				s[59] += 1;
				break;
			}
		}
	}
}

int comp_vet(int resul[],int comp[],int qtd[]){
    int cont=0;
    for(int c=0;c<6;c++){
		for(int i=1;i<7;i++){
	    	if(resul[i] == comp[c]){
	    		qtd[c] +=1;
	    		cont++;
			}
		} 
	}
	return cont;
}
