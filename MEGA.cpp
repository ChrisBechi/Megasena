#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include"FMega.h"
//função

main(){
	setlocale(LC_ALL,"portuguese");	
	system("title Mega-Sena");
	FILE *f;
	for(int indi=0;indi<6;indi++)
		jogar(indi);
	if((f=fopen("mega.txt","r"))==NULL){
 		printf("Não foi possivel abrir o arquivo");
	}
 	while(!feof(f)){
		fscanf(f,"%04d %d %d %d %d %d %d",&nresult[0],&nresult[1],&nresult[2],&nresult[3],&nresult[4],&nresult[5],&nresult[6]);
		fgets(guarda,2000,f);
		soma(nresult,s);
    	int acertos = comp_vet(nresult,palpite,quant);
		switch(acertos){
	    	case 4:{
	    		strcpy(auxi," ");
				strcpy(auxil," ");
	    		if(nresult[0] < 100){
					strcat(auxi,"00");
				}else if(nresult[0] < 1000){
					strcat(auxi,"0");
				}
	    		for(int indi=0;indi<7;indi++){
	    			if(nresult[indi] < 10){
	    				strcat(auxi,"0");
					}
					if(indi==0){
	    				itoa(nresult[indi],auxil,10);
						strcat(auxi,auxil);
						strcat(auxi," | ");
					}else{
						itoa(nresult[indi],auxil,10);
						strcat(auxi,auxil);
						strcat(auxi," ");
					}
				}
				strcat(auxi,"|");
				strcat(auxi,guarda);
				strcpy(ganhou[ganha],auxi);
	    		quadra++;
	    		ganha++;
				break;
			}
			case 5:{
				strcpy(auxi," ");
				strcpy(auxil," ");
	    		if(nresult[0] < 100){
					strcat(auxi,"00");
				}else if(nresult[0] < 1000){
					strcat(auxi,"0");
				}
				for(int indi=0;indi<7;indi++){
					if(nresult[indi] < 10){
	    				strcat(auxi,"0");
					}
					itoa(nresult[indi],auxil,10);
					strcat(auxi,auxil);
					strcat(auxi," ");
				}
				strcat(auxi,guarda);
				strcpy(ganhou[ganha],auxi);
				strcpy(auxi," ");
	    		ganha++;
				quina++;
				break;
			}
			case 6:{
				strcpy(auxi," ");
				strcpy(auxil," ");
	    		if(nresult[0] < 100){
					strcat(auxi,"00");
				}else if(nresult[0] < 1000){
					strcat(auxi,"0");
				}
				for(int indi=0;indi<7;indi++){
					if(nresult[indi] < 10){
	    				strcat(auxi,"0");
					}
					itoa(nresult[indi],auxil,10);
					strcat(auxi,auxil);
					strcat(auxi," ");
				}
				strcat(auxi,guarda);
				strcpy(ganhou[ganha],auxi);
				strcpy(auxi," ");
	    		ganha++;
				sena++;
				break;
			}
		}
	}
	int sair=1;
	do{
		sair = menu();
	}while(sair); 
}
