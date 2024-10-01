#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//funzioni tris
int tris();
int tris_easybot();
int tris_hardbot();

//funzioni battaglia navale
int battnavale();
int battnavale_easybot();
int battnavale_hardbot();

//funzioni forza4
int forza4();
int forza4_easybot();
int forza4_hardbot();
int forza4_controlli(int c, int r);
int forza4_controlli_bot(int c, int r);

char tabella[6][7];
int main()
{
	int tris1=0, tris2=0, trisCPU=0, forz1=0, forz2=0, forzCPU=0, batt1=0, batt2=0, battCPU=0;
	int flag=0, gioco, n, inutile;
	FILE *op;
	char s[20];
	
	int scelta_bot, flag_bot=0;
	
	//apertura FILE.txt in scrittura per risultati
	op=fopen("Risultati_partite.txt", "w");
	
	//MENU E LEADERBOARD
	while(flag==0)
	{
		system("cls");
		printf("GIOCHI PVP\n\n");
		printf("Menu'");
		printf("\n1-Tris\n2-Battaglia Navale\n3-Forza 4\n4-Leaderboard\n5- Exit\n");
		fflush(stdin);
		
		scanf("%d",&gioco);
		
		switch(gioco)
		{
			case 1: 
				
				system("cls");
				printf("Tris\n");
				printf("\n1- Player VS Player\n2- Player vs CPU (Livello Facile)\n3- Player VS CPU (Livello difficile)\n");
				do
				{
					scanf("%d",&scelta_bot);
				
					if(scelta_bot==1 || scelta_bot==2 || scelta_bot==3){
						flag_bot=1;
					}
					else{
						printf("Scelta non valida, reinserire: ");
					}
					
				}while(flag_bot==0);
				
				switch(scelta_bot)
				{
					case 1: 
						
						n=tris(); 
						fflush(stdin);
						if(n==1){
							tris1++;
							fprintf(op,"Tris: Vince player 1.\n");
						}
						else if(n==0){
							tris2++;
							fprintf(op,"Tris: Vince player 2.\n");
						}
						else if(n==2){
							tris1++;
							tris2++;
							trisCPU++;
							fprintf(op, "Tris: Pareggio.\n");
						}
						else if(n==3){
							trisCPU++;
							fprintf(op, "Tris: Vince CPU.\n");
						}
						break;
						
					case 2:
						
						n=tris_easybot();
						fflush(stdin);
						if(n==1){
							tris1++;
							fprintf(op,"Tris (CPU facile): Vince Player.\n");
						}
						else if(n==0){
							tris2++;
							fprintf(op,"Tris (CPU facile): Vince la CPU.\n");
						}
						else if(n==2){
							tris1++;
							tris2++;
							trisCPU++;
							fprintf(op, "Tris (CPU facile): Pareggio.\n");
						}
						else if(n==3){
							trisCPU++;
							fprintf(op, "Tris (CPU facile): Vince CPU.\n");
						}
						break;
						
					case 3:
						
						n=tris_hardbot();
						fflush(stdin);
						if(n==1){
							tris1++;
							fprintf(op,"Tris (CPU difficile): Vince Player.\n");
						}
						else if(n==0){
							tris2++;
							fprintf(op,"Tris (CPU difficile): Vince la CPU.\n");
						}
						else if(n==2){
							tris1++;
							tris2++;
							trisCPU++;
							fprintf(op, "Tris (CPU difficile): Pareggio.\n");
						}
						else if(n==3){
							trisCPU++;
							fprintf(op, "Tris (CPU difficile): Vince CPU.\n");
						}
						break;		
				}
				
				break;
				
			case 2:	
				system("cls");
				printf("Battaglia Navale\n");
				printf("\n1- Player VS Player\n2- Player VS CPU (Livello facile)\n3- CPU (Livello difficile)\n");
				do
				{
					scanf("%d",&scelta_bot);
				
					if(scelta_bot==1 || scelta_bot==2 || scelta_bot==3){
						flag_bot=1;
					}
					else{
						printf("Scelta non valida, reinserire: ");
					}
					
				}while(flag_bot==0);
				
				switch(scelta_bot)
				{
					case 1: 
						
						n=battnavale();	
				
						fflush(stdin);
						if(n==1){
							batt1++;
							fprintf(op, "Battaglia Navale: Vince Player 1.\n");
						}
						else if(n==0){
							batt2++;
							fprintf(op, "FBattaglia Navale: Vince Player 2.\n");
						}
						else if(n==2){
							batt1++;
							batt2++;
							battCPU++;
							fprintf(op, "Battaglia Navale: Pareggio\n");
						}
						else if(n==3){
							battCPU++;
							fprintf(op, "Battaglia Navale: Vince CPU.\n");
						}
						
						break;
								
					case 2:
						
						n=battnavale_easybot();	
				
						fflush(stdin);
						if(n==1){
							batt1++;
							fprintf(op, "Battaglia Navale (CPU facile): Vince Player 1.\n");
						}
						else if(n==0){
							forz2++;
							fprintf(op, "Battaglia Navale (CPU facile): Vince Player 2.\n");
						}
						else if(n==2){
							batt1++;
							batt2++;
							battCPU++;
							fprintf(op, "Battaglia Navale (CPU facile): Pareggio\n");
						}
						else if(n==3){
							battCPU++;
							fprintf(op, "Battaglia Navale (CPU facile): Vince CPU.\n");
						}
						
						break;
						
					case 3:
						
						n=battnavale_hardbot();	
				
						fflush(stdin);
						if(n==1){
							batt1++;
							fprintf(op, "Battaglia Navale (CPU difficile): Vince Player 1.\n");
						}
						else if(n==0){
							batt2++;
							fprintf(op, "Battaglia Navale (CPU difficile): Vince CPU.\n");
						}
						else if(n==2){
							batt1++;
							batt2++;
							forzCPU++;
							fprintf(op, "Battaglia Navale (CPU difficile): Pareggio\n");
						}
						else if(n==3){
							battCPU++;
							fprintf(op, "Battaglia Navale (CPU difficile): Vicne CPU.\n");
						}	
						
						break;	
						
				}
				break;
				
			case 3: 
				system("cls");
				printf("Forza 4\n");
				printf("\n1- Player VS Player\n2- Player VS CPU (Livello facile)\n3- CPU (Livello difficile)\n");
				do
				{
					scanf("%d",&scelta_bot);
				
					if(scelta_bot==1 || scelta_bot==2 || scelta_bot==3){
						flag_bot=1;
					}
					else{
						printf("Scelta non valida, reinserire: ");
					}
					
				}while(flag_bot==0);
				
				switch(scelta_bot)
				{
					case 1: 
						
						n=forza4();	
				
						fflush(stdin);
						if(n==1){
							forz1++;
							fprintf(op, "Forza 4: Vince Player 1.\n");
						}
						else if(n==0){
							forz2++;
							fprintf(op, "Forza 4: Vince Player 2.\n");
						}
						else if(n==2){
							forz1++;
							forz2++;
							forzCPU++;
							fprintf(op, "Forza 4: Pareggio\n");
						}
						else if(n==3){
							forzCPU++;
							fprintf(op, "Forza 4: Vince CPU.\n");
						}
						
						break;
								
					case 2:
						
						n=forza4_easybot();	
				
						fflush(stdin);
						if(n==1){
							forz1++;
							fprintf(op, "Forza 4 (CPU facile): Vince Player 1.\n");
						}
						else if(n==0){
							forz2++;
							fprintf(op, "Forza 4 (CPU facile): Vince CPU.\n");
						}
						else if(n==2){
							forz1++;
							forz2++;
							forzCPU++;
							fprintf(op, "Forza 4 (CPU facile): Pareggio\n");
						}
						else if(n==3){
							forzCPU++;
							fprintf(op, "Forza 4 (CPU facile): Vince CPU.\n");
						}
						
						break;
						
					case 3:
						
						n=forza4_hardbot();	
				
						fflush(stdin);
						if(n==1){
							forz1++;
							fprintf(op, "Forza 4 (CPU difficile): Vince Player 1.\n");
						}
						else if(n==0){
							forz2++;
							fprintf(op, "Forza 4 (CPU difficile): Vince CPU.\n");
						}
						else if(n==2){
							forz1++;
							forz2++;
							forzCPU++;
							fprintf(op, "Forza 4 (CPU difficile): Pareggio\n");
						}
						else if(n==3){
							forzCPU++;
							fprintf(op, "Forza 4 (CPU difficile): Vince CPU.\n");
						}	
						
						break;
				}
				
				break;
			case 4: 
				system("cls");
				fflush(stdin);
				printf("Leaderboard: ");
				printf("\n			P1		P2		CPU");
				printf("\nTris			%d		%d		%d", tris1, tris2, trisCPU);
				printf("\nBattaglia navale	%d		%d		%d", batt1, batt2, battCPU);
				printf("\nForza4			%d		%d		%d\n\n", forz1, forz2, forzCPU); 
				printf("Premere per tornare al menu': ");
				scanf("%d",&inutile);
				
				break;
			case 5:
				fclose(op);
				exit(0);
		}
	}
	
	return 0;
}

int tris(void)
{
	char griglia[3][3];		
	int i, j, P1rig, P1col, P2rig, P2col; 
	int inutile, flag=0, flag1=0, cont;
	int win;
	
	system("cls");
	
	//riempimento griglia
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			griglia[i][j]='#';
		}
	}
	
	//stampo la griglia
	printf("  0 1 2\n");
	
	for(i=0;i<3;i++)
	{
		printf("%d ",i);
		for(j=0;j<3;j++)
		{
			printf("%c ",griglia[i][j]);
		}
		printf("\n");
	}
	
	//ciclo inserimento coordinate
	while(flag==0)
	{
		//turno P1
		printf("Giocatore 1: inserire coordinate:\n");
		scanf("%d",&P1rig);
		scanf("%d",&P1col);
		
		flag1=0;
		
		//controllo validità coordinate
		while(flag1==0)
		{
			if(griglia[P1rig][P1col]!='#' || P1rig<0 || P1rig>2 || P1col<0 || P1col>2)
			{
				printf("Tabella gia' occupata o non valida, reinserire: ");
				scanf("%d",&P1rig);
				scanf("%d",&P1col);
			}
			else
			{
				flag1=1;
			}
		}
		
		griglia[P1rig][P1col]='X';
		
		//ristampo la griglia
		
		system("cls");
		
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controlli vincita
		if(griglia[0][0]=='X' && griglia[1][0]=='X' && griglia[2][0]=='X' || griglia[0][1]=='X' && griglia[1][1]=='X' && griglia[2][1]=='X' || griglia[0][2]=='X' && griglia[1][2]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[0][1]=='X' && griglia[0][2]=='X' || griglia[1][0]=='X' && griglia[1][1]=='X' && griglia[1][2]=='X' || griglia[2][0]=='X' && griglia[2][1]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[1][1]=='X' && griglia[2][2]=='X' || griglia[0][2]=='X' && griglia[1][1]=='X' && griglia[2][0]=='X')
		{
			printf("\nGiocatore 1 Vince!!!");
			win=1;
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win; 
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
		//	fprintf(op,"\nTris: Pareggio!!!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}
		
		//turno P2
		printf("Giocatore 2, inserire le coordinate:\n");
		scanf("%d",&P2rig);
		scanf("%d",&P2col);
		
		flag1=0;
		
		while(flag1==0)
		{
			if(griglia[P2rig][P2col]!='#' || P2rig<0 || P2rig>2 || P2col<0 || P2col>2)
			{
				printf("Tabella gia' occupata o non valida, reinserire: ");
				scanf("%d",&P2rig);
				scanf("%d",&P2col);
			}
			else
			{
				flag1=1;
			}
		}
		
		griglia[P2rig][P2col]='O';
		
		//ristampo la griglia
		
		system("cls");
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controllo vincita
		if(griglia[0][0]=='O' && griglia[1][0]=='O' && griglia[2][0]=='O' || griglia[0][1]=='O' && griglia[1][1]=='O' && griglia[2][1]=='O' || griglia[0][2]=='O' && griglia[1][2]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[0][1]=='O' && griglia[0][2]=='O' || griglia[1][0]=='O' && griglia[1][1]=='O' && griglia[1][2]=='O' || griglia[2][0]=='O' && griglia[2][1]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[1][1]=='O' && griglia[2][2]=='O' || griglia[0][2]=='O' && griglia[1][1]=='O' && griglia[2][0]=='O')
		{
			printf("\nGiocatore 2 Vince!!!");
			win=0;
		//	fprintf(op,"\nTris: Giocatore 2 vince!!!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win;
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
		//	fprintf(op,"\nTris: Pareggio!!!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}

	}
	return win;
}//fine funzione

int tris_easybot()
{
	char griglia[3][3];		
	int i, j, P1rig, P1col, CPUrig, CPUcol; 
	int inutile, flag=0, flag1=0, cont;
	int win;
	
	int random;
	
	srand(time(0));
	system("cls");
	
	//riempimento griglia
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			griglia[i][j]='#';
		}
	}
	
	//stampo la griglia
	printf("  0 1 2\n");
	
	for(i=0;i<3;i++)
	{
		printf("%d ",i);
		for(j=0;j<3;j++)
		{
			printf("%c ",griglia[i][j]);
		}
		printf("\n");
	}
	
	//ciclo inserimento coordinate
	while(flag==0)
	{
		//turno P1
		printf("Giocatore 1: inserire coordinate:\n");
		scanf("%d",&P1rig);
		scanf("%d",&P1col);
		
		flag1=0;
		
		//controllo validità coordinate
		while(flag1==0)
		{
			if(griglia[P1rig][P1col]!='#' || P1rig<0 || P1rig>2 || P1col<0 || P1col>2)
			{
				printf("Tabella gia' occupata o non valida, reinserire: ");
				scanf("%d",&P1rig);
				scanf("%d",&P1col);
			}
			else
			{
				flag1=1;
			}
		}
		
		griglia[P1rig][P1col]='X';
		
		//ristampo la griglia
		
		system("cls");
		
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controlli vincita
		if(griglia[0][0]=='X' && griglia[1][0]=='X' && griglia[2][0]=='X' || griglia[0][1]=='X' && griglia[1][1]=='X' && griglia[2][1]=='X' || griglia[0][2]=='X' && griglia[1][2]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[0][1]=='X' && griglia[0][2]=='X' || griglia[1][0]=='X' && griglia[1][1]=='X' && griglia[1][2]=='X' || griglia[2][0]=='X' && griglia[2][1]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[1][1]=='X' && griglia[2][2]=='X' || griglia[0][2]=='X' && griglia[1][1]=='X' && griglia[2][0]=='X')
		{
			printf("\nGiocatore 1 Vince!!!");
			win=1;
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win; 
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}
		
		//turno CPU
		
		CPUrig=rand()%3;
		CPUcol=rand()%3;
		
		flag1=0;
		
		while(flag1==0)
		{
			if(griglia[CPUrig][CPUcol]!='#' || CPUrig<0 || CPUrig>2 || CPUcol<0 || CPUcol>2)
			{
				CPUrig=rand()%3;
				CPUcol=rand()%3;
			}
			else
			{
				flag1=1;
			}
		}
		
		griglia[CPUrig][CPUcol]='O';
		
		//ristampo la griglia
		
		system("cls");
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controllo vincita
		if(griglia[0][0]=='O' && griglia[1][0]=='O' && griglia[2][0]=='O' || griglia[0][1]=='O' && griglia[1][1]=='O' && griglia[2][1]=='O' || griglia[0][2]=='O' && griglia[1][2]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[0][1]=='O' && griglia[0][2]=='O' || griglia[1][0]=='O' && griglia[1][1]=='O' && griglia[1][2]=='O' || griglia[2][0]=='O' && griglia[2][1]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[1][1]=='O' && griglia[2][2]=='O' || griglia[0][2]=='O' && griglia[1][1]=='O' && griglia[2][0]=='O')
		{
			printf("\nCPU Vince!!!");
			win=3;
		//	fprintf(op,"\nTris: Giocatore 2 vince!!!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win;
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}

	}
	return win;
}

int tris_hardbot()
{
	char griglia[3][3];		
	int i, j, P1rig, P1col, CPUrig, CPUcol; 
	int inutile, flag=0, flag1=0, cont;
	int win, start;
	
	int flagturn=0, flagcentro, flagangolo, flagalto, flaglato, flagaw, flagleft, flag01, flag10, flag21, flag12;
	int flagang1, Vflag_angoli[7], flagang2, flagang3, flagang4, flagalto_c1, flagalto_c2, flagalto_c3, flagalto_d1, flagalto_d2, flagalto_d3, flagalto_d4; 
	int random;
	
	srand(time(0));
	//system("cls");
	
	srand(time(0));
	
	//riempimento griglia
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			griglia[i][j]='#';
		}
	}
	
	//stampo la griglia
	printf("  0 1 2\n");
	
	for(i=0;i<3;i++)
	{
		printf("%d ",i);
		for(j=0;j<3;j++)
		{
			printf("%c ",griglia[i][j]);
		}
		printf("\n");
	}
	
	//ciclo inserimento coordinate
	while(flag==0)
	{
		//turno P1
		printf("Giocatore 1: inserire coordinate:\n");
		scanf("%d",&P1rig);
		scanf("%d",&P1col);
		
		flag1=0;
		
		//controllo validità coordinate
		while(flag1==0)
		{
			if(griglia[P1rig][P1col]!='#' || P1rig<0 || P1rig>2 || P1col<0 || P1col>2)
			{
				printf("Tabella gia' occupata o non valida, reinserire: ");
				scanf("%d",&P1rig);
				scanf("%d",&P1col);
			}
			else
			{
				flag1=1;
			}
		}
		
		griglia[P1rig][P1col]='X';
		
		//ristampo la griglia
		
		system("cls");
		
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controlli vincita
		if(griglia[0][0]=='X' && griglia[1][0]=='X' && griglia[2][0]=='X' || griglia[0][1]=='X' && griglia[1][1]=='X' && griglia[2][1]=='X' || griglia[0][2]=='X' && griglia[1][2]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[0][1]=='X' && griglia[0][2]=='X' || griglia[1][0]=='X' && griglia[1][1]=='X' && griglia[1][2]=='X' || griglia[2][0]=='X' && griglia[2][1]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[1][1]=='X' && griglia[2][2]=='X' || griglia[0][2]=='X' && griglia[1][1]=='X' && griglia[2][0]=='X')
		{
			printf("\nGiocatore 1 Vince!!!");
			win=1;
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win; 
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}
		
		//turno CPU
		
		flagturn++;
		
		//inizio bot_hardcore tris
		int nul=0;
		
		if(flagturn==1)								//primo turno
		{
			do{
				i=rand()%2;
				j=rand()%2;
			}while(griglia[i][j]!='#');
		
			griglia[i][j]='O';
		}
		else										//altri turni
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(griglia[i][j]=='#')
					{
						griglia[i][j]='O';
						if(griglia[0][0]=='O' && griglia[1][0]=='O' && griglia[2][0]=='O' || griglia[0][1]=='O' && griglia[1][1]=='O' && griglia[2][1]=='O' || griglia[0][2]=='O' && griglia[1][2]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[0][1]=='O' && griglia[0][2]=='O' || griglia[1][0]=='O' && griglia[1][1]=='O' && griglia[1][2]=='O' || griglia[2][0]=='O' && griglia[2][1]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[1][1]=='O' && griglia[2][2]=='O' || griglia[0][2]=='O' && griglia[1][1]=='O' && griglia[2][0]=='O')
						{
							griglia[i][j]='O';	
							nul=0;	//controllo attacco
							goto outfor;
						}
						griglia[i][j]='X';
						if(griglia[0][0]=='X' && griglia[1][0]=='X' && griglia[2][0]=='X' || griglia[0][1]=='X' && griglia[1][1]=='X' && griglia[2][1]=='X' || griglia[0][2]=='X' && griglia[1][2]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[0][1]=='X' && griglia[0][2]=='X' || griglia[1][0]=='X' && griglia[1][1]=='X' && griglia[1][2]=='X' || griglia[2][0]=='X' && griglia[2][1]=='X' && griglia[2][2]=='X' || griglia[0][0]=='X' && griglia[1][1]=='X' && griglia[2][2]=='X' || griglia[0][2]=='X' && griglia[1][1]=='X' && griglia[2][0]=='X')
						{
							griglia[i][j]='O';
							nul=0;		//controllo difesa
							goto outfor;
						}
						else
						{
							nul=1;
							griglia[i][j]='#';
						}
					}
				}
			} 
		}
		
	if(nul==1)
	{
		nul=0;	
		do{
			i=rand()%2;
			j=rand()%2;
		}while(griglia[i][j]!='#');
		griglia[i][j]='O';
		goto outfor;
		
	}	
	outfor:
		//ristampo la griglia
		
		system("cls");
		printf("  0 1 2");
		printf("\n");
		
		for(i=0;i<3;i++)
		{
			printf("%d ",i);
			
			for(j=0;j<3;j++)
			{
				printf("%c ",griglia[i][j]);
			}
			printf("\n");
		}
		
		//controllo vincita
		if(griglia[0][0]=='O' && griglia[1][0]=='O' && griglia[2][0]=='O' || griglia[0][1]=='O' && griglia[1][1]=='O' && griglia[2][1]=='O' || griglia[0][2]=='O' && griglia[1][2]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[0][1]=='O' && griglia[0][2]=='O' || griglia[1][0]=='O' && griglia[1][1]=='O' && griglia[1][2]=='O' || griglia[2][0]=='O' && griglia[2][1]=='O' && griglia[2][2]=='O' || griglia[0][0]=='O' && griglia[1][1]=='O' && griglia[2][2]=='O' || griglia[0][2]=='O' && griglia[1][1]=='O' && griglia[2][0]=='O')
		{
			printf("\nCPU Vince!!!");
			win=3;
		//	fprintf(op,"\nTris: Giocatore 2 vince!!!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			system("cls");
			return win;
		}
		
		//controllo pareggio
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(griglia[i][j]!='#')
				{
					cont++;
				}
			}
		}
		
		if(cont==9)
		{
			printf("\nPareggio!");
			printf("\n\nPremere per continuare: ");
			scanf("%d",&inutile);
			flag=1;
			win=2;
			system("cls");
			return win;
		}
		else
		{
			cont=0;
		}

	}
	return win;
}

int forza4(void)
{
	int tabella[6][7];
	int i, j, r, r1, c, flag=0, flag1=0, flag2=0, win, inutile, contpar=0;
	char barra=186;
	
	system("cls");
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			tabella[i][j]='#';
		}
	}
			
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%c ",barra);
		for(j=0;j<7;j++)
		{
			printf("%c ",tabella[i][j]);
		}
		printf("%c\n",barra);
	}
	
	printf(" ---------------");
	printf("\n  0 1 2 3 4 5 6 ");
	
	while(flag!=1)
	{
		
	//player1 turn
		printf("\nColonna P1:");
		scanf("%d",&r);
		
		while(r<0 || r>6)
		{
			printf("Non valida, inserisci di nuovo: ");
			scanf("%d",&r);
		}
		
		if(tabella[0][r]=='X' || tabella[0][r]=='O')
		{
			r1=r;
			printf("Non puoi inserire in questa colonna, reinserisci: ");	
			scanf("%d",&r);
			while(r1==r)
			{
				printf("Non puoi inserire in questa colonna, reinserisci: ");
				scanf("%d",&r);
			}
		}
		
		for(i=6;i>=0;i--)
		{
			if(tabella[i][r]=='#')
			{
				tabella[i][r]='X';
				c=i;
				i=-1;
			}
			else
			{
				
			}
		}
				
	//stampare la griglia	
	 system("cls");
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
		
		printf(" ---------------");
		printf("\n  0 1 2 3 4 5 6 ");
		
	//controlli vincita
	
		//controlli orizzontali	
		if(tabella[c][r]=='X' && tabella[c][r+1]=='X' &&tabella[c][r+2]=='X' &&  tabella[c][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && tabella[c][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r+1]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r+1]=='X' && tabella[c][r+2]=='X' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X' && tabella[c-3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X' && tabella[c+3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && tabella[c-3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && tabella[c+3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{ 
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && tabella[c+3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && tabella[c-3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
			
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}
		
	//player2 turn
		printf("\nColonna P2:");
		scanf("%d",&r);
		
		while(r<0 || r>6)
		{
			printf("Non valida, inserisci di nuovo: ");
			scanf("%d",&r);
		}
		
		if(tabella[0][r]=='X' || tabella[0][r]=='O')
		{
			r1=r;
			printf("Non puoi inserire in questa colonna, reinserisci: ");	
			scanf("%d",&r);
			while(r1==r)
			{
				printf("Non puoi inserire in questa colonna, reinserisci: ");
				scanf("%d",&r);
			}
			
		}

		for(i=6;i>=0;i--)
		{
			if(tabella[i][r]=='#')
			{
				tabella[i][r]='O';
				c=i;
				i=-1;
			}
			else
			{
				
			}
		}
		
	//stampare la griglia
	 system("cls");	
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
	
		printf(" ---------------");
		printf("\n 0 1 2 3 4 5 6 ");
		
	//controlli vincita
		//controlli orizzontali	
		if(tabella[c][r]=='O' && tabella[c][r+1]=='O' &&tabella[c][r+2]=='O' &&  tabella[c][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria giocatore 2!");
			flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && tabella[c][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 2!");
			flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r+1]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria giocatore 2!");
			flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r+1]=='O' && tabella[c][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 2!");
			flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O' && tabella[c-3][r]=='O')
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O' && tabella[c+3][r]=='O')
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O')
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O')
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && tabella[c-3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && tabella[c+3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && tabella[c+3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && tabella[c-3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria giocatore 2!"); flag=1; win=0; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}		
	}
	
	return win;
}//fine funzione

int forza4_easybot()
{
	int tabella[6][7];
	int i, j, r, r1, c, flag=0, flag1=0, flag2=0, win, inutile, contpar=0;
	char barra=186;
	
	srand(time(0));
		
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			tabella[i][j]='#';
		}
	}

	system("cls");
				
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%c ",barra);
		for(j=0;j<7;j++)
		{
			printf("%c ",tabella[i][j]);
		}
		printf("%c\n",barra);
	}
	
	printf(" ----------------");
	printf("\n   0 1 2 3 4 5 6 ");
	
	while(flag!=1)
	{
		
	//player1 turn
		printf("\nColonna P1:");
		scanf("%d",&r);
		
		while(r<0 || r>6)
		{
			printf("Non valida, inserisci di nuovo: ");
			scanf("%d",&r);
		}
		
		if(tabella[0][r]=='X' || tabella[0][r]=='O')
		{
			r1=r;
			printf("Non puoi inserire in questa colonna, reinserisci: ");	
			scanf("%d",&r);
			while(r1==r)
			{
				printf("Non puoi inserire in questa colonna, reinserisci: ");
				scanf("%d",&r);
			}
		}
		
		for(i=6;i>=0;i--)
		{
			if(tabella[i][r]=='#')
			{
				tabella[i][r]='X';
				c=i;
				i=-1;
			}
			else
			{
				
			}
		}
				
	//stampare la griglia	
	 system("cls");
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
		
		printf(" ---------------");
		printf("\n  0 1 2 3 4 5 6 ");
		
	//controlli vincita
		//controlli orizzontali	
		if(tabella[c][r]=='X' && tabella[c][r+1]=='X' &&tabella[c][r+2]=='X' &&  tabella[c][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && tabella[c][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r+1]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r+1]=='X' && tabella[c][r+2]=='X' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 1!");
			flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X' && tabella[c-3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X' && tabella[c+3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && tabella[c-3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && tabella[c+3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{ 
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && tabella[c+3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && tabella[c-3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria giocatore 1!"); flag=1; win=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
		
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}
		
	//player2 turn
	
		r=rand()%6;
		
		while(r<0 || r>6)
		{
			r=rand()%6;
		}
		
		if(tabella[0][r]=='X' || tabella[0][r]=='O')
		{
			r1=r;
			r=rand()%6;
			while(r1==r)
			{
				r=rand()%6;
			}
		}
		
		for(i=6;i>=0;i--)
		{
			if(tabella[i][r]=='#')
			{
				tabella[i][r]='O';
				c=i;
				i=-1;
			}
			else
			{
				
			}
		}
		
	//stampare la griglia
	 system("cls");	
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
	
		printf(" ---------------");
		printf("\n  0 1 2 3 4 5 6 ");
		
	//controlli vincita
		//controlli orizzontali	
		if(tabella[c][r]=='O' && tabella[c][r+1]=='O' &&tabella[c][r+2]=='O' &&  tabella[c][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!");
			flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && tabella[c][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!");
			flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r+1]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria CPU!");
			flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r+1]=='O' && tabella[c][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!");
			flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O' && tabella[c-3][r]=='O')
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O' && tabella[c+3][r]=='O')
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O')
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O')
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && tabella[c-3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && tabella[c+3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && tabella[c+3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && tabella[c-3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria CPU!"); flag=1; win=3; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}		
	}
	
	return win;
}

int forza4_hardbot()
{
	int i, j, r, r1, c, flag=0, flag1=0, flag2=0, win, inutile, contpar=0, ret;
	char barra=186;
	
	srand(time(0));
	
	system("cls");
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			tabella[i][j]='#';
		}
	}
			
	printf("\n");
	for(i=0;i<6;i++)
	{
		printf("%c ",barra);
		for(j=0;j<7;j++)
		{
			printf("%c ",tabella[i][j]);
		}
		printf("%c\n",barra);
	}
	
	printf(" ---------------");
	printf("\n  0 1 2 3 4 5 6 ");
	
	while(flag!=1)
	{
		
	//player1 turn
		printf("\nColonna P1:");
		scanf("%d",&r);
		
		while(r<0 || r>6)
		{
			printf("Non valida, inserisci di nuovo: ");
			scanf("%d",&r);
		}
		
		if(tabella[0][r]=='X' || tabella[0][r]=='O')
		{
			r1=r;
			printf("Non puoi inserire in questa colonna, reinserisci: ");	
			scanf("%d",&r);
			while(r1==r)
			{
				printf("Non puoi inserire in questa colonna, reinserisci: ");
				scanf("%d",&r);
			}
		}
		
		for(i=6;i>=0;i--)
		{
			if(tabella[i][r]=='#')
			{
				tabella[i][r]='X';
				c=i;
				i=-1;
			}
		}
				
	//stampare la griglia	
	 system("cls");
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
		
		printf(" ---------------");
		printf("\n  0 1 2 3 4 5 6 ");
		
	//controlli vincita
		
		win=forza4_controlli(c, r);
		if(win==1)
		{
			flag=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}
		
	//CPU turn
	
		ret=forza4_controlli_bot(c,r);
		if(ret==0)
		{
			r=rand()%6;	
			if(tabella[0][r]=='X' || tabella[0][r]=='O')
			{
				r1=r;
				r=rand()%6;
				while(r1==r)
				{
					r=rand()%6;
				}		
			}
			
			for(i=6;i>=0;i--)
			{
				if(tabella[i][r]=='#')
				{
					tabella[i][r]='O';
					c=i;
					i=-1;
				}
			}
		}
			
	//stampare la griglia
	 system("cls");	
		printf("\n");
		for(i=0;i<6;i++)
		{
			printf("%c ",barra);
			for(j=0;j<7;j++)
			{
				printf("%c ",tabella[i][j]);
			}
			printf("%c\n",barra);
		}
	
		printf(" ---------------");
		printf("\n  0 1 2 3 4 5 6 ");
		
	//controlli vincita
	
		win=forza4_controlli(c, r);
		if(win==3)
		{
			flag=1; printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		
	//controlli pareggio
		
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(tabella[i][j]=='X' || tabella[i][j]=='O')
					contpar++;
			}
		}
		
		if(contpar==42)
		{
			win=2;
			printf("\nPareggio");
			printf("\nPremere per tornare al menu': "); scanf("%d",&inutile); system("cls"); return win;
		}
		else
		{
			contpar=0;
		}		
	}
	
	return win;
}

int forza4_controlli(int c, int r)
{
	int win;
	//controlli orizzontali	
		if(tabella[c][r]=='X' && tabella[c][r+1]=='X' &&tabella[c][r+2]=='X' &&  tabella[c][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!");
			win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && tabella[c][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!");
			win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r+1]=='X' && tabella[c][r-1]=='X' && tabella[c][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria giocatore 1!");
			win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c][r-1]=='X' && tabella[c][r+1]=='X' && tabella[c][r+2]=='X' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria giocatore 1!");
			win=1; return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X' && tabella[c-3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X' && tabella[c+3][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r]=='X' && tabella[c-1][r]=='X' && tabella[c-2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r]=='X' && tabella[c+1][r]=='X' && tabella[c+2][r]=='X')
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && tabella[c-3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && tabella[c+3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r-1]=='X' && tabella[c-1][r+1]=='X' && tabella[c-2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r+1]=='X' && tabella[c+1][r-1]=='X' && tabella[c+2][r-2]=='X' && (r+1)<7 && (r-2)>=0)
		{ 
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && tabella[c+3][r+3]=='X' && (r+3)<7)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && tabella[c-3][r-3]=='X' && (r-3)>=0)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c-1][r-1]=='X' && tabella[c+1][r+1]=='X' && tabella[c+2][r+2]=='X' && (r-1)>=0 && (r+2)<7)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		else if(tabella[c][r]=='X' && tabella[c+1][r+1]=='X' && tabella[c-1][r-1]=='X' && tabella[c-2][r-2]=='X' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria giocatore 1!"); win=1; return win;
		}
		
//controlli CPU
	
	//controlli orizzontali
		else if(tabella[c][r]=='O' && tabella[c][r+1]=='O' &&tabella[c][r+2]=='O' &&  tabella[c][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && tabella[c][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r+1]=='O' && tabella[c][r-1]=='O' && tabella[c][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c][r-1]=='O' && tabella[c][r+1]=='O' && tabella[c][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		
	//controlli verticali
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O' && tabella[c-3][r]=='O')
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O' && tabella[c+3][r]=='O')
		{
			printf("\nVittoria CPU!");
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r]=='O' && tabella[c-1][r]=='O' && tabella[c-2][r]=='O')
		{
			printf("\nVittoria CPU!"); 
			win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r]=='O' && tabella[c+1][r]=='O' && tabella[c+2][r]=='O')
		{
			printf("\nVittoria CPU!"); 
			win=3; return win;
		}
		
	//controlli obliqui sinistra
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && tabella[c-3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && tabella[c+3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r-1]=='O' && tabella[c-1][r+1]=='O' && tabella[c-2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r+1]=='O' && tabella[c+1][r-1]=='O' && tabella[c+2][r-2]=='O' && (r+1)<7 && (r-2)>=0)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		
	//controlli obliqui destra
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && tabella[c+3][r+3]=='O' && (r+3)<7)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && tabella[c-3][r-3]=='O' && (r-3)>=0)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c-1][r-1]=='O' && tabella[c+1][r+1]=='O' && tabella[c+2][r+2]=='O' && (r+2)<7 && (r-1)>=0)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
		else if(tabella[c][r]=='O' && tabella[c+1][r+1]=='O' && tabella[c-1][r-1]=='O' && tabella[c-2][r-2]=='O' && (r-2)>=0 && (r+1)<7)
		{
			printf("\nVittoria CPU!"); win=3; return win;
		}
	
	return 0;
}

int forza4_controlli_bot(int c, int r)
{
	int i=5;
	
	if(tabella[i][r]=='X')
	{
		if(tabella[i-1][r]=='X' && tabella[i-2][r]=='#')
		{
			tabella[i-2][r]='O';
			return 1;
		}
	}
	
	// Controlli
	if (tabella[c][r] == 'X' && tabella[c][r+1] == 'X' && tabella[c][r+2] == '#' && r+2 < 7 && tabella[c-1][r] != 'X')
	{
		tabella[c][r+2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c][r-1] == 'X' && tabella[c][r-2] == '#' && r-2 >= 0 && tabella[c-1][r] != 'X')
	{
		tabella[c][r-2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c+1][r] == 'X' && tabella[c+2][r] == '#')
	{
		tabella[c+2][r] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c+1][r+1] == 'X' && tabella[c-1][r-1] == '#' && tabella[c][r-1]!='#' && r+2 < 7)
	{
		tabella[c+2][r+2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c-1][r-1] == 'X' && tabella[c-2][r-2] == '#' && tabella[c-1][r-2]!='#' && c-2 >= 0)
	{
		tabella[c-2][r-2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c+1][r-1] == 'X' && tabella[c+2][r-2] == '#' && c+2>=0 && r-2>=0)
	{
		tabella[c+2][r-2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c-1][r+1] == 'X' && tabella[c-2][r+2] == '#' && r+2 < 7 && c-2 >= 0)
	{
		tabella[c-2][r+2] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c-1][r] == 'X' && tabella[c+1][r] == '#' && c-1 >= 0)
	{
		tabella[c+1][r] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c][r+1] == '#' && c-1 >= 0 && tabella[c+1][r+1]!='#' && c+1<6)
	{
		tabella[c][r+1] = 'O';
		return 1;
	}
	else if (tabella[c][r] == 'X' && tabella[c][r-1] == '#' && tabella[c+1][r-1] != '#' && r-1>=0 && c+1<6)
	{
		tabella[c][r-1] = 'O';
		return 1;
	}
	return 0;
}

int battnavale(void)
{
	char mare[10][10];
	int navi;
	int c,r,i,j;
	int inutile;
	
	int flagP=1,flagC=2,flagS=3,flagI=4,flagf=0,flagv=0;
	int orient, finale=0, win1=0, win2=0;
	int flag1p2=0,flag2p2=0,flag3p2=0,flag4p2=0,flagfp2=0,flagvp2=0;
	int orient2;
	
	char marep2[10][10];
	char mareatt1[10][10], mareatt2[10][10];
	char fakemare[10][10];
	
	//output del mare all'inizio del gioco
	
	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			fakemare[r][c]=126;
			printf("| %c",fakemare[r][c]);	
		}
		printf(" |");
			printf("\n");	
	}


	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			mare[r][c]=126;	
			mareatt1[r][c]=126;
			mareatt2[r][c]=126;
		}	
	}
	
	flagf=0;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;	
	printf("\nNavi presenti:\n1- Portaerei (lunghezza 5): %d (P)\n2- Corazzata (lunghezza 4): %d (C)\n3- Sottomarino (lunghezza 3): %d (S)\n4- Incrociatore (lunghezza 2): %d (I)\n",flagP,flagC,flagS,flagI);
	scanf("%d",&navi);
		
	r=0;
	c=0;
	switch(navi)
	{
		case 1:
		if (flagP!=0)
		{
	posizioneP:
		do{
			
		do
		{
			printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
			scanf("%d",&r);
			scanf("%d",&c);
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<5;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='P';
						}
						
					flagP--;
					}
					else{
						goto posizioneP;
					}
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							mare[r+i][c]='P';
						}
					
					flagP--;
					}
					else{
						goto posizioneP;
					}	
					break;
			}
			
		}while(flagv==1);
			
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC:
		do{
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<4;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							mare[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS:
		do{	
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<3;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							mare[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							mare[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
	posizioneI:
		do{
				do
				{
					printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
					scanf("%d",&r);
					scanf("%d",&c);
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<2;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							mare[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							mare[r+i][c]='I';
						}
					
					flagI--;
					}
					else{
						goto posizioneI;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
	
		navi=0;
	
	system("cls");
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	//controllo
	if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
	{
		flagf=1;
	}
	
	}
	//fine input navi
	
	navi=0;
	
	//TURNO GIOCATORE DUE

	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");	
	}
	
	Sleep(3000);
	system("cls");
	printf("Turno giocatore 2\n");
	
		navi=0;                      
	
	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			marep2[r][c]=126;	
		}	
	}
	
	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			marep2[r][c]=126;
			printf("| %c",marep2[r][c]);	
		}
		printf(" |");
		printf("\n");		
	}
	flagf=0;
	flagP=1;
	flagC=2;
	flagS=3;
	flagI=4;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;	
	printf("\nNavi presenti:\n1- Portaerei (lunghezza 5): %d (P)\n2- Corazzata (lunghezza 4): %d (C)\n3- Sottomarino (lunghezza 3): %d (S)\n4- Incrociatore (lunghezza 2): %d (I)\n",flagP,flagC,flagS,flagI);
	scanf("%d",&navi);
		
	r=0;
	c=0;
	switch(navi)
	{
		case 1:
		if (flagP!=0)
		{
	posizioneP2:
		do{
			
		do
		{
			printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
			scanf("%d",&r);
			scanf("%d",&c);
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<5;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<4;i++)
						{
							marep2[r][c+i]='P';
						}
					}
						flagP--;
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							marep2[r+i][c]='P';
						}
					
					flagP--;
					}
					else{
						goto posizioneP2;
					}	
					break;
			}
			
		}while(flagv==1);
			
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC2:
		do{
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<4;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							marep2[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							marep2[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC2;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS2:
		do{	
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<3;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							marep2[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							marep2[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS2;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
	posizioneI2:
		do{
				do
				{
					printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
					scanf("%d",&r);
					scanf("%d",&c);
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<2;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							marep2[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							marep2[r+i][c]='I';
						}
					
					flagI--;
					}
					else{
						goto posizioneI2;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
	}
		//fine input navi
	
	navi=0;
	
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	//controllo
	if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
	{
		flagf=1;
	}
	
	
	Sleep(3000);
	system("cls");
	
	printf("Iniziano gli attacchi:\n\n");
	
	//ATTACCHI
	
	int flagatt=0, contp1=0, contp2=0, win;
	
	while(flagatt==0)
	{
		//turno giocatore 1
		system("cls");
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		printf("\nPlayer 1: inserire le coordinate per attaccare (prima riga, poi colonna): ");
		scanf("%d",&r);
		scanf("%d",&c);
		
		system("cls");
		
		if(marep2[r][c]=='P'|| marep2[r][c]=='C' || marep2[r][c]=='S' || marep2[r][c]=='I'){
			marep2[r][c]=126;
			printf("Nave colpita!\n");
			mareatt1[r][c]='X';
		}
		else if(marep2[r][c]==126){
			printf("Nave mancata...\n");
		}
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(marep2[i][j]==126){
					contp1++;
				}
			}
		}
		
		if(contp1==100){
			printf("\nVince Giocatore 1!!!\n"); win=1; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp1=0;
		}
		
		system("cls");
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt2[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//turno giocatore 2
		printf("\nPlayer 2: inserire le coordinate per attaccare (prima riga, poi colonna): ");
		scanf("%d",&r);
		scanf("%d",&c);
		
		if(mare[r][c]=='P' || mare[r][c]=='C' || mare[r][c]=='S' || mare[r][c]=='I'){
			mare[r][c]=126;
			printf("Nave colpita!\n");
			mareatt2[r][c]='X';
		}
		else if(mare[r][c]==126){
			printf("Nave mancata...\n");
		}
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt2[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(mare[i][j]==126){
					contp2++;
				}
			}
		}
		
		if(contp2==100){
			printf("\nVince Giocatore 2!!!\n"); win=0; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp2=0;
		}
		
		
	}
	
	return win;
}//fine funzione

int battnavale_easybot()
{
	char mare[10][10];
	int navi;
	int c,r,i,j;
	int inutile;
	
	int flagP=1,flagC=2,flagS=3,flagI=4,flagf=0,flagv=0;
	int orient, finale=0, win1=0, win2=0;
	int flag1p2=0,flag2p2=0,flag3p2=0,flag4p2=0,flagfp2=0,flagvp2=0;
	int orient2;
	
	char marep2[10][10];
	char mareatt1[10][10], mareatt2[10][10];
	char fakemare[10][10];
	
	srand(time(0));
	//output del mare all'inizio del gioco
	
	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			fakemare[r][c]=126;
			printf("| %c",fakemare[r][c]);	
		}
		printf(" |");
			printf("\n");	
	}


	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			mare[r][c]=126;	
			mareatt1[r][c]=126;
			mareatt2[r][c]=126;
		}	
	}
	
	flagf=0;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;	
	printf("\nNavi presenti:\n1- Portaerei (lunghezza 5): %d (P)\n2- Corazzata (lunghezza 4): %d (C)\n3- Sottomarino (lunghezza 3): %d (S)\n4- Incrociatore (lunghezza 2): %d (I)\n",flagP,flagC,flagS,flagI);
	scanf("%d",&navi);
		
	r=0;
	c=0;
	switch(navi)
	{
		case 1:
		if (flagP!=0)
		{
	posizioneP:
		do{
			
		do
		{
			printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
			scanf("%d",&r);
			scanf("%d",&c);
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<5;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='P';
						}
					}
						flagP--;
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							mare[r+i][c]='P';
						}
					
					flagP--;
					}
					else{
						goto posizioneP;
					}	
					break;
			}
			
		}while(flagv==1);
			
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC:
		do{
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<4;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							mare[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS:
		do{	
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<3;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							mare[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							mare[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
	posizioneI:
		do{
				do
				{
					printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
					scanf("%d",&r);
					scanf("%d",&c);
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<2;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							mare[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							mare[r+i][c]='I';
						}
					
					flagI--;
					}
					else{
						goto posizioneI;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
	
		navi=0;
	
	system("cls");
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	//controllo
	if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
	{
		flagf=1;
	}
	
	}
	//fine input navi
	
	navi=0;
	
	//TURNO GIOCATORE DUE

	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");	
	}
	
	Sleep(3000);
	system("cls");
	printf("Turno giocatore 2\n");
	
		navi=0;                      
	
	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			marep2[r][c]=126;	
		}	
	}
	
	system("cls");
	for (r=0;r<10;r++)
	{
		for (c=0;c<10;c++)
		{
			marep2[r][c]=126;	
		}	
	}
	flagf=0;
	flagP=1;
	flagC=2;
	flagS=3;
	flagI=4;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;
	navi=rand()%3+1;
		
	r=0;
	c=0;
	switch(navi)
	{
		case 1:
		if (flagP!=0)
		{
	posizioneP2:
		do{
			
		do
		{
			r=rand()%10;
			c=rand()%10;
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%1+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<5;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<4;i++)
						{
							marep2[r][c+i]='P';
						}
					}
						flagP--;
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							marep2[r+i][c]='P';
						}
					
					flagP--;
					}
					else{
						goto posizioneP2;
					}	
					break;
			}
			
		}while(flagv==1);
			
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC2:
		do{
			do
			{
				r=rand()%10;
				c=rand()%10;
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%1+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<4;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							marep2[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							marep2[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC2;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS2:
		do{	
			do
			{
				r=rand()%10;
				c=rand()%10;
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%1+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<3;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							marep2[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							marep2[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS2;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
	posizioneI2:
		do{
				do
				{
					r=rand()%10;
					c=rand()%10;
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				orient=rand()%1+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<2;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							marep2[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							marep2[r+i][c]='I';
						}
					
					flagI--;
					}
					else{
						goto posizioneI2;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
	}
		//fine input navi
	
	navi=0;
	
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	//controllo
	if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
	{
		flagf=1;
	}
	
	
	Sleep(3000);
	system("cls");
	
	printf("Iniziano gli attacchi:\n\n");
	
	//ATTACCHI
	
	int flagatt=0, contp1=0, contp2=0, win;
	
	while(flagatt==0)
	{
		//turno giocatore 1
		system("cls");
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		printf("\nPlayer 1: inserire le coordinate per attaccare (prima riga, poi colonna): ");
		scanf("%d",&r);
		scanf("%d",&c);
		
		system("cls");
		
		if(marep2[r][c]=='P'|| marep2[r][c]=='C' || marep2[r][c]=='S' || marep2[r][c]=='I'){
			marep2[r][c]=126;
			printf("Nave colpita!\n");
			mareatt1[r][c]='X';
		}
		else if(marep2[r][c]==126){
			printf("Nave mancata...\n");
		}
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(marep2[i][j]==126){
					contp1++;
				}
			}
		}
		
		if(contp1==100){
			printf("\nVince Giocatore 1!!!\n"); win=1; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp1=0;
		}
		
		system("cls");
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt2[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//turno giocatore 2
		printf("\nAttacco CPU: ");
		r=rand()%10;
		c=rand()%10;
		
		if(mare[r][c]=='P' || mare[r][c]=='C' || mare[r][c]=='S' || mare[r][c]=='I'){
			mare[r][c]=126;
			printf("Nave colpita!\n");
			mareatt2[r][c]='X';
		}
		else if(mare[r][c]==126){
			printf("Nave mancata...\n");
		}
		
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt2[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(mare[i][j]==126){
					contp2++;
				}
			}
		}
		
		if(contp2==100){
			printf("\nVince Giocatore 2!!!\n"); win=0; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp2=0;
		}
		
		
	}
	
	return win;
}

int battnavale_hardbot()
{
	char mare[10][10];
	int navi;
	int c,r,i,j;
	int inutile;
	
	int flagP=1,flagC=2,flagS=3,flagI=4,flagf=0,flagv=0;
	int orient, finale=0, win1=0, win2=0;
	int flag1p2=0,flag2p2=0,flag3p2=0,flag4p2=0,flagfp2=0,flagvp2=0;
	int orient2;
	
	char marep2[10][10];
	char mareatt1[10][10], mareatt2[10][10];
	char fakemare[10][10];
	
	srand(time(0));
	//output del mare all'inizio del gioco
	
	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			fakemare[r][c]=126;
			printf("| %c",fakemare[r][c]);	
		}
		printf(" |");
			printf("\n");	
	}


	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			mare[r][c]=126;	
			mareatt1[r][c]=126;
			mareatt2[r][c]=126;
		}	
	}
	
	flagf=0;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;	
	printf("\nNavi presenti:\n1- Portaerei (lunghezza 5): %d (P)\n2- Corazzata (lunghezza 4): %d (C)\n3- Sottomarino (lunghezza 3): %d (S)\n4- Incrociatore (lunghezza 2): %d (I)\n",flagP,flagC,flagS,flagI);
	scanf("%d",&navi);
		
	r=0;
	c=0;
	switch(navi)
	{
		case 1:
		if (flagP!=0)
		{
	posizioneP:
		do{
			
		do
		{
			printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
			scanf("%d",&r);
			scanf("%d",&c);
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<5;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='P';
						}
					}
						flagP--;
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							mare[r+i][c]='P';
						}
					
					flagP--;
					}
					else{
						goto posizioneP;
					}	
					break;
			}
			
		}while(flagv==1);
			
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC:
		do{
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<4;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							mare[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							mare[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS:
		do{	
			do
			{
				printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
				scanf("%d",&r);
				scanf("%d",&c);
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<3;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							mare[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							mare[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
	posizioneI:
		do{
				do
				{
					printf("Inserire posizione nave(piu a sinistra o piu in alto)\n");
					scanf("%d",&r);
					scanf("%d",&c);
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				printf("Come vuoi posizionare la nave? Orizzontale (1) o Verticale(2): ");
				scanf("%d",&orient);
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
				
					for(i=0;i<2;i++)
					{
						if(mare[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							mare[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(mare[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							mare[r+i][c]='I';
						}
					
					flagI--;
					}
					else{
						goto posizioneI;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
	
		navi=0;
	
	system("cls");
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	//controllo
	if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
	{
		flagf=1;
	}
	
	}
	//fine input navi
	
	navi=0;
	
	//TURNO GIOCATORE DUE

	system("cls");		
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");	
	}
	
	//Sleep(3000);
	printf("Turno giocatore 2\n");
	
		navi=0;                      
	
	//campo di gioco 
	for (c=0;c<10;c++)
	{
		for (r=0;r<10;r++)
		{
			marep2[r][c]=126;	
		}	
	}
	
	for (r=0;r<10;r++)
	{
		for (c=0;c<10;c++)
		{
			marep2[r][c]=126;	
		}	
	}
	
	flagf=0;
	flagP=1;
	flagC=2;
	flagS=3;
	flagI=4;
	
	//dichiarazioni navi 
	while(flagf==0)
	{
		
	flagv=0;
	navi=rand()%4+1;
	r=0;
	c=0;
	
	switch(navi)
	{
		case 1:
		if(flagP!=0)
		{
	posizioneP2:
		
		do
		{
			r=rand()%10;
			c=rand()%10;
		}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%2+1;
			}while(orient!=1 && orient!=2);
			
			switch(orient)
			{
				case 1:
					
					for(i=0;i<5;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>=5){
							flagv=1;
						}
					}
					if(flagv==0){
						
						for (i=0;i<5;i++)
						{
							marep2[r][c+i]='P';
						}
					}
					flagP--;
					break;
					
				case 2:
					
					for(i=0;i<5;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>=5){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<5;i++)
						{
							marep2[r+i][c]='P';
						}
					
					flagP--;
					}
					else if(flagv==1){
						goto posizioneP2;
					}	
					break;
			}		
		}
		break;	
			
		case 2:
			
			if (flagC!=0)
			{
	posizioneC2:
		do{
			do
			{
				r=rand()%10;
				c=rand()%10;
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%2+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
					
					for(i=0;i<4;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<4;i++)
						{
							marep2[r][c+i]='C';
						}
						flagC--;
					}
					break;
					
				case 2:
					
					for(i=0;i<4;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>6){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<4;i++)
						{
							marep2[r+i][c]='C';
						}
					
					flagC--;
					}	
					else{
						goto posizioneC2;
					}
					break;
			}
			
		}while(flagv==1);
			
		}
		break;
				
		case 3:
			
			if (flagS!=0)
			{
	posizioneS2:
		do{	
			do
			{
				r=rand()%10;
				c=rand()%10;
			}while(r>=10||c>=10||r<0||c<0);
			
			//orientamento nave
			do{
				orient=rand()%2+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
					
					for(i=0;i<3;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<3;i++)
						{
							marep2[r][c+i]='S';
						}
						flagS--;
					}
					break;
					
				case 2:
					
					for(i=0;i<3;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>7){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<3;i++)
						{
							marep2[r+i][c]='S';
						}
					
					flagS--;
					}
					else{
						goto posizioneS2;
					}
					break;
			}
			
		}while(flagv==1);
		}
		break;
			
		case 4:
	
			if (flagI!=0)
			{
posizioneI2:
			do{
				do
				{
					r=rand()%10;
					c=rand()%10;
				}while(r>=10||c>=10||r<0||c<0);
				
				flagv=0;
				
				//orientamento nave
			do{
				orient=rand()%2+1;
			}while(orient!=1 && orient!=2);
			
			flagv=0;
			
			switch (orient)
			{
				case 1:
					
					for(i=0;i<2;i++)
					{
						if(marep2[r][c+i]!=126){
							flagv=1;
						}
						if(c>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{ 
						for (i=0;i<2;i++)
						{
							marep2[r][c+i]='I';
						}
						flagI--;
					}
					break;
					
				case 2:
					
					for(i=0;i<2;i++)
					{
						if(marep2[r+i][c]!=126){
							flagv=1;
						}
						if(r>8){
							flagv=1;
						}
					}
					if(flagv==0)
					{
						for (i=0;i<2;i++)
						{
							marep2[r+i][c]='I';
						}
					flagI--;
					}
					else{
						goto posizioneI2;
					}
					break;
				}
				}while(flagv==1);
			}
			break;
		}
		
		if (flagP==0 && flagC==0 && flagS==0 && flagI==0)
		{
			flagf=1;
		}
	}
	//fine input navi
	
	navi=0;
	
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (r=0;r<10;r++)
	{
		printf("%d",r);
		for (c=0;c<10;c++)
		{
			printf("| %c",mare[r][c]);	
		}
		printf(" |");
		printf("\n");			
	}
	
	Sleep(3000);
	system("cls");
	
	printf("Iniziano gli attacchi:\n\n");
	
	//ATTACCHI
	
	int flagatt=0, contp1=0, contp2=0, win;
	int flag_hit=0, defr, defc, hitcont=0, lato;
	int flagdx=0, flagsx=0, flagup=0, flagdown=0;
	int var;
	
	while(flagatt==0)
	{
		//turno giocatore 1
		system("cls");
		
		printf("Griglia d'attacco:\n");
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		printf("\nLe tue navi:\n");
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mare[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		printf("\nPlayer 1: inserire le coordinate per attaccare (prima riga, poi colonna): ");
		scanf("%d",&r);
		scanf("%d",&c);
		
		system("cls");
		
		if(marep2[r][c]=='P'|| marep2[r][c]=='C' || marep2[r][c]=='S' || marep2[r][c]=='I'){
			marep2[r][c]=126;
			printf("Nave colpita!\n");
			mareatt1[r][c]='X';
		}
		else if(marep2[r][c]==126){
			printf("Nave mancata...\n");
		}
		
		printf("Griglia d'attacco: \n");
		printf("   0  1  2  3  4  5  6  7  8  9\n");
		for (r=0;r<10;r++)
		{
			printf("%d",r);
			for (c=0;c<10;c++)
			{
				printf("| %c",mareatt1[r][c]);	
			}
			printf(" |");
			printf("\n");		
		}
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(marep2[i][j]==126){
					contp1++;
				}
			}
		}
		
		if(contp1==100){
			printf("\nVince Giocatore 1!!!\n"); win=1; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp1=0;
		}
		
		Sleep(2000);
		system("cls");
		
		//TURNO GIOCATORE 2 ---------------------------------------------------------------------
		
		if(flag_hit==0)
		{
			printf("\nAttacco CPU: ");
			r=rand()%10;
			c=rand()%10;
			//printf("%d %d\n",r,c);
			if(mare[r][c]=='P' || mare[r][c]=='C' || mare[r][c]=='S' || mare[r][c]=='I')
			{
				mare[r][c]=126;
				printf("\nNave colpita dalla CPU!\n");
				mareatt2[r][c]='X';
				flag_hit=1;
				defr=r;
				defc=c;
			}
			else if(mare[r][c]==126){
				printf("Nave mancata...\n");
			}
		}
		else
		{
			if((mare[defr][defc+1]!=126 && defc+1<10) || flagdx==1)
			{
				flagdx=1;
				if(mare[defr][defc+1]!=126)
				{
					mare[defr][defc+1]=126;
					mareatt2[defr][defc+1]='X';
					printf("\nNave colpita dalla CPU!");
					var=defc;
					defc=defc+1;
				}
				else if(mare[defr][defc-1]!=126)
				{
					mare[defr][var-1]=126;
					mareatt2[defr][var-1]='X';
					printf("\nNave colpita dalla CPU!");
					var=var-1;
				}
				else{
					flag_hit=0;
				}
			}
			else if((mare[defr][defc-1]!=126 && defc-1>0) || flagsx==1)
			{
				if(mare[defr][defc-1]!=126)
				{
					mare[defr][defc-1]=126;
					mareatt2[defr][defc-1]='X';
					printf("\nNave colpita dalla CPU!");
					var=defc;
					defc=defc-1;
				}
				else if(mare[defr][defc+1]!=126)
				{
					mare[defr][var+1]=126;
					mareatt2[defr][var+1]='X';
					printf("\nNave colpita dalla CPU!");
					var=var+1;
				}
				else{
					flag_hit=0;
				}
			}
			else if((mare[defr+1][defc]!=126 && defr+1<10) || flagdown==1)
			{
				flagdown=1;
				if(mare[defr+1][defc]!=126)
				{
					mare[defr+1][defc]=126;
					mareatt2[defr+1][defc]='X';
					printf("\nNave colpita dalla CPU!");
					var=defr;
					defr=defr+1;
				}
				else if(mare[defr-1][defc]!=126)
				{
					mare[var-1][defc]=126;
					mareatt2[var-1][defc]='X';
					printf("\nNave colpita dalla CPU!");
					var=var-1;
				}
				else{
					flag_hit=0;
				}
			}
			else if((mare[defr-1][defc]!=126 && defr-1>0) || flagup==1)
			{
				flagup=1;
				if(mare[defr-1][defc]!=126)
				{
					mare[defr-1][defc]=126;
					mareatt2[defr-1][defc]='X';
					printf("\nNave colpita dalla CPU!");
					var=defr;
					defr=defr-1;
				}
				else if(mare[var+1][defc]!=126)
				{
					mare[var+1][defc]=126;
					mareatt2[var+1][defc]='X';
					printf("\nNave colpita dalla CPU!");
					var=var+1;
				}
				else{
					flag_hit=0;
				}
				
			}
		}
		
		Sleep(3000);
		
		//controlli vincita
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				if(mare[i][j]==126){
					contp2++;
				}
			}
		}
		
		if(contp2==100){
			printf("\nVince Giocatore 2!!!\n"); win=0; printf("Premere per tornare al menu': "); scanf("%d",&inutile); flagatt=1; return win;
		}
		else{
			contp2=0;
		}
	}
	
	return win;
}
