/* TRABALHO FINAL FUNDAMENTOS DE PROGAMAÇÃO
   PROJETO SUDOKU
   UNIVERCIDADE FEDERAL DO CEARA-CAMPUS RUSSAS
   PROF. PABLO SOARES
   PRODUZIDO POR MARLO HENRIQUE DE LIMA OLIVEIRA
   EMAIL:marloh2222@gmail.com
*/
/*
SUMARIO:
escolha:opção para navegar pelo menu principal
escolha3:opção para navegar no menu extras
escolha4:navegar na versão beta
escolhab:quantidade de casas vazias na opção beta
escolhal: escolha para definir o layout do jogo utilizado
facil: contador para a quantidade de vezes jogadas no facil
medio:contador para a quantidade de vezes jogadas no medio
dificil:contador para a quantidade de vezes jogadas no dificil
fixo[][]:matriz utilizada para saber se tal cordenada tem uma peça fixa
sudoku[][]:matriz principal do jogo
sudokuteste[][]matriz ja pronta para testes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>
#define N 9
int difi,linha,coluna,numero;
float tinicial,tfinal,ttotal;
int escolha,escolha3,escolha4,escolhab,escolhal,facil,dificil,medio,sair;
FILE *melhortempo; 
int fixo [N][N]={0};
int sudoku[N][N]= {0};
int sudokuteste[N][N]={
   { 1, 9, 3, 7, 4, 5, 8, 2, 6},
   { 2, 8, 5, 6, 9, 1, 4, 7, 3},
   { 6, 7, 4, 8, 2, 3, 5, 9, 1},
   { 3, 1, 9, 5, 6, 2, 7, 8, 4},
   { 5, 2, 8, 3, 7, 4, 6, 1, 9},
   { 4, 6, 7, 9, 1, 8, 3, 5, 2},
   { 7, 3, 2, 1, 8, 6, 9, 4, 5},
   { 9, 4, 6, 2, 5, 7, 1, 3, 8},
   { 8, 5, 1, 4, 3, 9, 2, 6, 7}};

   // estrutura do tipo salvar com o nome jogador dentro
   struct{
	   char jogador[20];
   }salvar;

//função que prenche a matriz sudoku gerando linha,colunas e numeros aleatorios e verificando na função preencher
void matriz(){
	int a,b,i,j,l,c,x;
	
if(difi == 1){
	b=60 ;
}
if (difi== 2){
	b= 30;
}
if(difi==3){
	b=25;
}
a=0;
	for(l=0; l<9;l++){
	for(c=0; c<9; c++){
	sudoku[l][c]=0;
	fixo[l][c]=0;}}
while(a<b){

	 i= (rand() %9);
	
	 j= (rand() %9);
	 
		if(sudoku[i][j]== 0){
			
			 x= 1+(rand() % 9);
			 
			if(preencher(i,j,x)==1){
			fixo[i][j]=1;
			a++;}	

		}
}
}

int preencher(int i,int j,int k){
  int c,l;
 
	for (l = 0; l < N; l++)//coluna fica comparando com as linhas
	if (sudoku[l][j] == k)
	  return 0;
  
	for (c = 0; c < N; c++)//linha fixa comparando com as colunas
	if (sudoku[i][c] == k)
     return 0;
	
     for(l=0; l<N; l+=3)//verifica posiçoes para a peça, comparando posiçoes de cada quadrante.
     for(c=0; c<N; c+=3)
		 if(l+i<9 || j+c<9)
         if(sudoku[i+l][j+c]== k  )
     return 0;
	 
	for (l = i - i % 3; l < i - i % 3 +3; l++)//verifica os quadrantes.
	for (c = j - j % 3; c < j - j % 3 + 3; c++)
	  if (sudoku[l][c] == k)
     return 0;
		sudoku[i][j] = k;
    return 1;
}

//função da opção 4 beta,lança zeros aleatorios em uma matriz pre definida
void matrizdeteste(){
int b,a,i,j,l,c;

a=0;
 
  for(l=0; l<9;l++){
  for(c=0; c<9; c++){
   sudoku[l][c]=sudokuteste[l][c];
   fixo[i][j]=0;}}
    while(a<escolhab){
	  i= (rand() %9);
	  j= (rand() %9);
		if(sudoku[i][j]!= 0){
			sudoku[i][j];
			sudoku[i][j] = 0;
			fixo[i][j]=1;
			a++;}
		}
}



//função para desenhar o layout da matriz
void desenho1(){

int i,j,k;
      	printf("  1    2    3     4    5    6     7    8    9  ");
	 printf("\n+___  ___  ___   ___  ___  ___   ___  ___  ___+ \n");
      
        for(i=0; i<9; ++i){
        {printf("|   ||   ||   | |   ||   ||   | |   ||   ||   | %d \n",i+1);
			for(j=0; j<N; j++){
				if (j%3==2){
				
				if(sudoku[i][j]==0){
					printf("|   | ");
					
				
				}
				if(sudoku[i][j]!=0){
				
				printf("| %d | ",sudoku[i][j]);
				
				}
				}
					else{
					if(sudoku[i][j]==0){
					printf("|   |");
					
				
				}
				if(sudoku[i][j]!=0){
				
				printf("| %d |",sudoku[i][j]);
				
				}	
					}
					
				}
			}if(i%3==2){ 
			if(i!=8){
			
			printf("\n|___||___||___| |___||___||___| |___||___||___| \n");
			printf("+___  ___  ___   ___  ___  ___   ___  ___  ___+ \n");}
			if(i==8)
				printf("\n|___||___||___| |___||___||___| |___||___||___| \n");
			
			}
			else
			 printf("\n|___||___||___| |___||___||___| |___||___||___| \n");
          
        }

}
	
//função que desenha o layout normal da matriz
void desenho2(){
	int i,j,k;

	printf("   1  2  3   4  5  6   7  8  9  \n");
		printf(" x-----------------------------x\n");
		for (i = 0; i < N; i++) {
		printf("%d|",i+1);
			for (j = 0; j < N; j++) {	
			if (sudoku[i][j] != 0)	
			printf(" %d ", sudoku[i][j]);
			if (sudoku[i][j] == 0)
			printf("   ");
			if (j % 3 == 2)
			printf("|");
			}
		if (i % 3 == 2)
		printf(" \n x-----------------------------x");
		printf("\n");
		}
	
}

//minha função que faz que o jogo so termine quando tudo for preenchido.
int terminar()
{
	
    int i,j;
    int cont=0;
	for ( i=0;i<9;i++){
		for (j=0;j<9;j++){
		   if (sudoku[i][j]==0){
            cont=cont+1;
		   }

		}
	}
	if (cont>0){
        return 1;
	}
	if(cont==0){
        return 0;
	}
}
//verificar se o numero escolhido é valido.
int numerovalido(int numero)
{
	  if(numero>=0 && numero <=9)
	  return 1;
      else
	  return 0;

}
//verificar se a posição é valida. vale resaltar que a parametro lançado  receber o valor -1, pois as posiçoes da matriz começa em 0.
int posicaovalida(int linha, int coluna)
{
	  if(linha>=0 && linha <9 && coluna>=0 && coluna <9)
	  return 1;
      else
	  return 0;
}
// verificar na matriz secundaria se a posição escolhida retorna 1, se retornar 1 indica que a posição nao pode ser alterada
// na versão beta do jogo se for igual a 1 retorna 1, se for diferente retorna 0
int pecafixar (int linha, int coluna, int fixo[N][N],int escolha){
	if(escolha==1){
	  if(fixo[linha][coluna]== 1)
	  return 0;
	  else
	return 1;}
	if(escolha==4){
		if(fixo[linha][coluna]== 1)
	  return 1;
	  else
	return 0;}
		
	}

//função tentar, verificar se na mesma linha vertical, ou horizontal temos algum termo repitido, ou se no quadrante temos algum termo repetido. se 
//nao tiver a matriz sudoku recebe o numero, e chama a função desenho que imprime a matriz com o novo numero.
int tentar(int i, int j, int k,int difi) {
  int c,l;
  if(difi==1){

	for (l = 0; l < N; l++)
	if (sudoku[l][j] == k)
	  return 0;
	for (c = 0; c < N; c++)
	if (sudoku[i][c] == k)
      return 0;}
 if(pecafixar(linha-1,coluna-1,fixo,escolha)== 0)
	 return 0;
 if(difi!=3){
    for (l = i - i % 3; l < i - i % 3 +3; l++)//verificação de quadrante
	for (c = j - j % 3; c < j - j % 3 + 3; c++)
	  if (sudoku[l][c] == k )
        return 0;}
		sudoku[i][j] = k;
        return 1;
	
}
//função responsavel por conferir ao final do jogo se temos algum termo repitido na linhas, pegando uma coluna fixa e comparando. 
int clinha(int sudoku[N][N]){
int i, j, k, x = 0;
	for(i = 0; i < 9; i++)
    for(j = 0; j < 9; j++)
    for(k = 0; k < 9; k++)
        if((j != k) && (sudoku[i][j] == sudoku[i][k])){
        x = 1;}
		if(x==0)
	return 1;
if(x==1)
	return 0;
}
//função responsavel, por conferir ao final do jogo se temos algum termo repitido nas colunas, pegando uma linha fixa e conparando
int ccoluna(int sudoku[N][N]){
int i, j, k, x = 0;

    for(j = 0; j < 9; j++)
    for(i = 0; i < 9; i++)
    for(k = 0; k < 9; k++)
       if((i != k) && (sudoku[i][j] == sudoku[k][j])){
	   x = 1;}
if(x==0)
    return 1;
if(x==1)
	return 0;

}

//função responsavel por verificar as condiçoes do jogo, cordenadas, numero, e tentar, que é a função para lança a peça
void game(){

	
	if (posicaovalida(linha-1, coluna-1)==1 )
	{
	
	if (numerovalido(numero)==1)
	{
	 
	if (tentar( linha-1, coluna-1,numero,difi )==1)
	{
	
	}
	else{
		printf("ESSA POSICAO JA ESTA OCUPADA\n");
	 system("pause");
	system("cls");
	}
	}
	else{
	printf("NUMERO INVALIDO\n");
	system("pause");
	system("cls");	
	}
	}
	else{
	printf("CORDENADA INVALIDA\n");
	system("pause");
	system("cls");	
	}
}

//função responsavel por chamar todas as outras funçoes que fazem o jogo funcionar
void montarjogo(){
sair=0;
tinicial= clock();// tempo inicial, armazena de acordo com o relogio a hora que o jogo começou
	
	do{ //laço que chamaa função que faz com que o jogo so termine quando todas as peças forem preenchidas, ou aperta TAB
	if(difi==1){
		printf("#JOGANDO NO FACIL -_- \n");
	}
	if(difi==2){
		printf("#JOGANDO NO MEDIO   •_•\n");
	}
	if(difi==3){
		printf("#JOGANDO NO DIFICIL  (*_*) \n");
	}
 
 if(escolhal==1){
 desenho2();}
 if(escolhal!=1){
 desenho1();}
 printf("\nDESISTIR [TAB] | CONTINUAR [ENTER]\n");
 sair=getch();


if(sair==13){
   printf("digite um linha:\n");
   scanf("%d",&linha);
   printf("digite uma coluna:\n");
   scanf("%d",&coluna);
   printf("digite o numero:\n");
	scanf("%d",&numero);

game();
}
system("cls");
 terminar();


   }while(terminar()!=0 && sair!=9);

	//condição você terminpu o jogo, preencheu todas as posiçoes
	if(sair==13){
	

	tfinal=clock();
	ttotal=( (tfinal - tinicial) / CLOCKS_PER_SEC)/60;
	printf("VOCE CONCLUIU SEU SUDOKU EM  %.2f MINUTOS, PARABENS!!! \n\n",ttotal);
	printf("HORA DE VERIFICAR SEU JOGO:\n");
	system("pause");
	system("cls");}
	
	//condição você desistiu.
	if(sair!=13){
printf(" _______  _______  __   __  _______    _______  __   __  _______  ______   \n");
printf("|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  \n");
printf("|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  \n");
printf("|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n");
printf("|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n");
printf("|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n");
printf("|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n\n");

		system("pause");
		system("cls");
	}

}

int main(){
	
	char m;
	FILE *dificuldade;//arquivo da dificuldade
	FILE *campeao;//arquivo do nome do jogador que conseguir
	
	
	do{
		system("musica.mp3");
	printf("               _       _                \n");
    printf("              | |     | |               \n");
    printf(" ___ _   _  __| | ___ | | ___   _       \n");
    printf("/ __| | | |/ _` |/ _ \\| |/ / | | |     \n");
    printf("\\__ \\ |_| | (_| | (_) |   <| |_| |    \n");
    printf("|___/\\__,_|\\__,_|\\___/|_|\\_\\\\__,_|\n");
	printf("\n");
	printf("[1]- INICIAR JOGO \n");
	printf("[2]- AJUDA\n");
	printf("[3]- EXTRAS\n");
	printf("[4]- BETA \n");
	printf("[5]- SAIR");
	printf("\n-> ");
    setbuf(stdin,0);
    fflush(stdin);

	scanf("%i",&escolha);
	system("cls");
	switch(escolha)
	{
		case 1://caso iniciar o jogo
	
					
					printf("*-------------------------------*\n");
					printf("*INFORME O NOME DO JOGADOR:     *\n");
					printf("*-------------------------------*\n");
					scanf(" %20[^\n]s",salvar.jogador);
					system("cls");
					
					printf("*-------------------------------*\n");
					printf("*ESCOLHA A DIFICULDADE DO GAME:  *\n");
					printf("*-------------------------------*\n");
					printf("\a[1]- FACIL\n");
					printf("\a[2]- MEDIO\n");
					printf("\a[3]- DIFICIL\n");
					scanf("%i",&difi);
					
					
						dificuldade =fopen("dificuldades.txt", "a");//abertura do arquivo dificuldade
						if (dificuldade==NULL){
							printf("arquivo não pode ser aberto");
							getchar();
							exit(1);
						}
						if(difi==1){
						
						m='a';
						fprintf(dificuldade, "%c",m);}
						if(difi==2){
							m='b';
							fprintf(dificuldade, "%c",m);
						}
						if(difi==3){
							m='c';
							fprintf(dificuldade, "%c",m);
						}
						fclose(dificuldade);
					
					system("cls");
					//system("pause
					
					
					if(difi>3 || difi<1){
					
						printf("#DIFICUDADE INVALIDA!!!\n");
						system("pause");
						system("cls");}
						else{
						
						matriz();
					
						montarjogo(sudoku);//função que chama funçoes responsaveis pora o jogo ocorrer
					 if(sair==13){
					 	if(clinha(sudoku)==1 && ccoluna(sudoku)==1){//verifica a matriz ao final do jogo
						
						printf(" _______  __   __  ______   _______  ___   _  __   __                                        \n");
						printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                       \n");
						printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                       \n");
						printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                       \n");
						printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                       \n");
						printf(" _____| ||       ||       ||       ||    _  ||       |                                       \n");
						printf("|_______||_______||______| |_______||___| |_||_______|                                       \n");
						printf(" _______  _______  ______    _______  _______  ___   _______  _______    ___          ____   \n");
						printf("|       ||       ||    _ |  |       ||       ||   | |       ||       |  |   |        |    |  \n");
						printf("|    _  ||    ___||   | ||  |    ___||    ___||   | |_     _||   _   |  |___|  ____  |_    | \n");
						printf("|   |_| ||   |___ |   |_||_ |   |___ |   |___ |   |   |   |  |  | |  |   ___  |____|   |   | \n");
						printf("|    ___||    ___||    __  ||    ___||    ___||   |   |   |  |  |_|  |  |   |          |   | \n");
						printf("|   |    |   |___ |   |  | ||   |    |   |___ |   |   |   |  |       |  |___|         _|   | \n");
						printf("|___|    |_______||___|  |_||___|    |_______||___|   |___|  |_______|               |____|  \n");
						system("pause");
						system("cls");
						
						campeao =fopen("nomes.txt", "a");//abertura do arquivo caso a pessoa tenha consiguido montar
						if (campeao==NULL){
							printf("arquivo não pode ser aberto");
							getchar();
							exit(1);
						}
						int i=0;
						for(i=0;salvar.jogador[i]!= '\0' ; i++ ){
								fprintf(campeao,"%c ",salvar.jogador[i]);
							}
						fprintf(campeao,"%.2f \n\a\a\a",ttotal);
						fclose(campeao);
						ttotal=0;}
					else{
					printf(" _______  __   __  ______   _______  ___   _  __   __                                                  \n");  
					printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                                 \n");
					printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                                 \n");
					printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                                 \n");
					printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                                 \n");
					printf(" _____| ||       ||       ||       ||    _  ||       |                                                 \n");
					printf("|_______||_______||______| |_______||___| |_||_______|                                                 \n");
					printf(" ___   __    _  _______  _______  ______    ______    _______  _______  _______    ___           ____   \n");
					printf("|   | |  |  | ||       ||       ||    _ |  |    _ |  |       ||       ||       |  |   |         |    | \n");
					printf("|   | |   |_| ||       ||   _   ||   | ||  |   | ||  |    ___||_     _||   _   |  |___|  ____  |    _| \n");
					printf("|   | |       ||       ||  | |  ||   |_||_ |   |_||_ |   |___   |   |  |  | |  |   ___  |____| |   |   \n");
					printf("|   | |  _    ||      _||  |_|  ||    __  ||    __  ||    ___|  |   |  |  |_|  |  |   |        |   |   \n");
					printf("|   | | | |   ||     |_ |       ||   |  | ||   |  | ||   |___   |   |  |       |  |___|        |   |_  \n");
					printf("|___| |_|  |__||_______||_______||___|  |_||___|  |_||_______|  |___|  |_______|                |____| \n");
					system("pause");
					system("cls");
					}}
				}
					break;
					
					case 2://opção do menu ajuda
					system ("cls");
					printf("*---------------------> AJUDA: <---------------------------*\n");
					printf("*                                                          *\n");
					printf("*--------------- O QUE E O JOGO? --------------------------*\n");
					printf("*Sudoku e um jogo numa matriz de 9x9 quadrados,            *\n");
					printf("*divididos em matrizes de 3x3 chamadas quadrantes.         *\n");
					printf("*--------------- REGRAS DO JOGO: --------------------------*\n");
					printf("*1- Preencher os quadrados vazios com números entre 1 e 9. *\n");
					printf("*2- Numero pode aparecer apenas uma vez em cada linha.     *\n");
					printf("*3- Numero pode aparecer apenas uma vez em cada quadrante. *\n");
					printf("*4- Pecas geradas pelo jogo nao podem ser substituidas.    *\n");
					printf("*5- Apagar uma peca, escolha a cordenada e numero 0.       *\n");
					printf("*--------------- MODOS DE JOGO-----------------------------*\n");
					printf("*1- Facil: Jogo ajuda verificando pecas repetidas em linhas*\n");
					printf("*colunas ou no quandrante!                                 *\n");
					printf("*2- Medio: Jogo  verifica pecas repetidas no quadrante!    *\n");
					printf("*3- Dificil: jogo nao oferece ajuda nessa dificuldade!     *\n");
					printf("*--------------- BOA SORTE!!! -----------------------------*\n");
					system("pause");
					system("cls");
				    break;
					
					case 3://opçoes extras do menu
					
						printf("*-------------------------------*\n");
						printf("*EXTRAS DO JOGO                 *\n");
						printf("*-------------------------------*\n");

						printf("1-JOGADORES QUE CONSIGUIRAM\n\n");//jogadores que consiguiram respectivos tempos
						printf("2-TOTAL DE PARTIDAS POR NIVEL\n");//total de partidas por dificuldade
						scanf("%i",&escolha3);
						switch(escolha3){
							 case 1://caso dos jogadores que conseguiram
							 	system("cls");
								printf("*-------------------------------*\n");
								printf("*JOGADORES QUE CONSEGUIRAM      *\n");
								printf("*-------------------------------*\n");
							 	printf("NOME DO JOGADOR || SEU TEMPO EM MIN:\n");
								campeao=fopen("nomes.txt","r");//leitura do arquivo nomes dos jogadores que conseguiram
								if (campeao==NULL){
								printf("arquivo não pode ser aberto");
								getchar();
								exit(1);          }
								char y;
								while((y=fgetc(campeao))!= EOF){
								putchar(y);
								}
								fclose(campeao);
								system("pause");
								system("cls");
							 	
							 
							 break;
							 
							 case 2://caso do tanto das dificuldades.
							 	system("cls");
							 	dificuldade=fopen("dificuldades.txt","r");//leitura do arquivo dificuldades
								 if (dificuldade==NULL){
							 	printf("arquivo não pode ser aberto");
							 	getchar();
							 	exit(1);}
								int x;
									while((x=fgetc(dificuldade))!= EOF){
									if (x=='a'){//caso a agrega valor ao facil
									facil+=1;}
									if(x=='b'){//caso b agrega valor ao medio
									medio+=1;}
									if(x=='c'){//caso c agrega valor ao dificil
									dificil+=1;}
								}
								fclose(dificuldade);
							printf("*-------------------------------*\n");
							printf("*PARTIDAS POR DIFICULDADE       *\n");
							printf("*-------------------------------*\n");
							 printf("VEZES JOGADAS NO DIFICIL:  %d\n",dificil);
							 printf("VEZES JOGADAS NO MEDIO:    %d\n",medio );
							 printf("VEZES JOGADAS NO FACIL:    %d\n", facil);
							 facil= 0;
							 dificil= 0;
							 medio= 0;
							 system("pause");
							 system("cls");
		
							 break;
						
							 default:
							 printf("#COMANDO INVALIDDO!!!\n");
							 system("pause");
							 system("cls");
						   	 break;
							system("cls");
							
							
						} 

					break;
					
					case 4://versão beta do jogo com matriz pronta
					printf("#DESEJA SALVAR OS DADOS? \n");
					printf("[1]-SIM   [2]-NAO  \n");//se sim os dados vão para os arquivos
					scanf("%i",&escolha4);
					system("cls");	
					
					if(escolha4==1){//vão para os arquivos
					printf("#ESCOLHA O LAYOUT DO JOGO \n");
					printf("[1]-NORMAL   [2]-ANORMAL   \n");//se sim os dados vão para os arquivos
					scanf("%i",&escolhal);
					system("cls");
					printf("#ESCOLHA A QUANTIDADES DE CASAS VAZIAS: \n");
					scanf("%i",&escolhab);
					system("cls");
					printf("*-------------------------------*\n");
					printf("*INFORME O NOME DO JOGADOR:     *\n");
					printf("*-------------------------------*\n");
					scanf(" %15[^\n]s",salvar.jogador);
					system("cls");
					
					printf("*-------------------------------*\n");
					printf("*ESCOLHA A DIFICULDADE DO GAME: *\n");
					printf("*-------------------------------*\n");
					printf("\a[1]- FACIL\n");
					printf("\a[2]- MEDIO\n");
					printf("\a[3]- DIFICIL\n");
					scanf("%i",&difi);
					
					
						dificuldade =fopen("dificuldades.txt", "a");
						if (dificuldade==NULL){
							printf("ARQUIVO NAO PODE SER ABERTO :(");
							getchar();
							exit(1);
						}
						if(difi==1){
						
						m='a';
						fprintf(dificuldade, "%c",m);}
						if(difi==2){
							m='b';
							fprintf(dificuldade, "%c",m);
						}
						if(difi==3){
							m='c';
							fprintf(dificuldade, "%c",m);
						}
						fclose(dificuldade);
					
					system("cls");
					//system("pause
					
					
					if(difi>3 || difi<1){
					
						printf("#DIFICUDADE INVALIDA!!!\n");
						system("pause");
						system("cls");}
						else{
						
						matrizdeteste();
					
						montarjogo(sudoku);//função que chama funçoes responsaveis pora o jogo ocorrer
					  if(sair==13){
					 	if(clinha(sudoku)==1 && ccoluna(sudoku)==1){
						printf(" _______  __   __  ______   _______  ___   _  __   __                                        \n");
						printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                       \n");
						printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                       \n");
						printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                       \n");
						printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                       \n");
						printf(" _____| ||       ||       ||       ||    _  ||       |                                       \n");
						printf("|_______||_______||______| |_______||___| |_||_______|                                       \n");
						printf(" _______  _______  ______    _______  _______  ___   _______  _______    ___          ____   \n");
						printf("|       ||       ||    _ |  |       ||       ||   | |       ||       |  |   |        |    |  \n");
						printf("|    _  ||    ___||   | ||  |    ___||    ___||   | |_     _||   _   |  |___|  ____  |_    | \n");
						printf("|   |_| ||   |___ |   |_||_ |   |___ |   |___ |   |   |   |  |  | |  |   ___  |____|   |   | \n");
						printf("|    ___||    ___||    __  ||    ___||    ___||   |   |   |  |  |_|  |  |   |          |   | \n");
						printf("|   |    |   |___ |   |  | ||   |    |   |___ |   |   |   |  |       |  |___|         _|   | \n");
						printf("|___|    |_______||___|  |_||___|    |_______||___|   |___|  |_______|               |____|  \n");
						system("pause");
						system("cls");
												
						campeao =fopen("nomes.txt", "a");
						if (campeao==NULL){
							printf("ARQUIVO NÃO PODE SER ABERTO :(");
							getchar();
							exit(1);
						}
						int i=0;
						for(i=0;salvar.jogador[i]!= '\0' ; i++ ){
						fprintf(campeao,"%c ",salvar.jogador[i]);}
						fprintf(campeao,"%.2f \n\a\a\a",ttotal);
						fclose(campeao);
						ttotal=0;}
					else{
					printf(" _______  __   __  ______   _______  ___   _  __   __                                                  \n");  
					printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                                 \n");
					printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                                 \n");
					printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                                 \n");
					printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                                 \n");
					printf(" _____| ||       ||       ||       ||    _  ||       |                                                 \n");
					printf("|_______||_______||______| |_______||___| |_||_______|                                                 \n");
					printf(" ___   __    _  _______  _______  ______    ______    _______  _______  _______    ___           ____   \n");
					printf("|   | |  |  | ||       ||       ||    _ |  |    _ |  |       ||       ||       |  |   |         |    | \n");
					printf("|   | |   |_| ||       ||   _   ||   | ||  |   | ||  |    ___||_     _||   _   |  |___|  ____  |    _| \n");
					printf("|   | |       ||       ||  | |  ||   |_||_ |   |_||_ |   |___   |   |  |  | |  |   ___  |____| |   |   \n");
					printf("|   | |  _    ||      _||  |_|  ||    __  ||    __  ||    ___|  |   |  |  |_|  |  |   |        |   |   \n");
					printf("|   | | | |   ||     |_ |       ||   |  | ||   |  | ||   |___   |   |  |       |  |___|        |   |_  \n");
					printf("|___| |_|  |__||_______||_______||___|  |_||___|  |_||_______|  |___|  |_______|                |____| \n");
					system("pause");
					system("cls");}
					}
						
						
						
					}
					escolhal=0;}
					if(escolha4==2){//nao vão para os arquivos
					
					printf("#ESCOLHA O LAYOUT DO JOGO \n");
					printf("[1]-NORMAL   [2]-ANORMAL   \n");//se sim os dados vão para os arquivos
					scanf("%i",&escolhal);
					system("cls");
					printf("#ESCOLHA A QUANTIDADES DE CASAS VAZIAS: \n");
					scanf("%i",&escolhab);
					system("cls");					
					printf("*-------------------------------*\n");
					printf("*ESCOLHA A DIFICULDADE DO GAME: *\n");
					printf("*-------------------------------*\n");
					printf("\a[1]- FACIL\n");
					printf("\a[2]- MEDIO\n");
					printf("\a[3]- DIFICIL\n");
					scanf("%i",&difi);
					
					system("cls");
					//system("pause
					
					
					if(difi>3 || difi<1){
					
						printf("#DIFICUDADE INVALIDA!!!\n");
						system("pause");
						system("cls");}
						else{
						
						matrizdeteste();
					
						montarjogo(sudoku);
						
					if(sair==13){
					 	if(clinha(sudoku)==1 && ccoluna(sudoku)==1){
						printf(" _______  __   __  ______   _______  ___   _  __   __                                        \n");
						printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                       \n");
						printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                       \n");
						printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                       \n");
						printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                       \n");
						printf(" _____| ||       ||       ||       ||    _  ||       |                                       \n");
						printf("|_______||_______||______| |_______||___| |_||_______|                                       \n");
						printf(" _______  _______  ______    _______  _______  ___   _______  _______    ___          ____   \n");
						printf("|       ||       ||    _ |  |       ||       ||   | |       ||       |  |   |        |    |  \n");
						printf("|    _  ||    ___||   | ||  |    ___||    ___||   | |_     _||   _   |  |___|  ____  |_    | \n");
						printf("|   |_| ||   |___ |   |_||_ |   |___ |   |___ |   |   |   |  |  | |  |   ___  |____|   |   | \n");
						printf("|    ___||    ___||    __  ||    ___||    ___||   |   |   |  |  |_|  |  |   |          |   | \n");
						printf("|   |    |   |___ |   |  | ||   |    |   |___ |   |   |   |  |       |  |___|         _|   | \n");
						printf("|___|    |_______||___|  |_||___|    |_______||___|   |___|  |_______|               |____|  \n");
						system("pause");
						system("cls");
						}
					else{
					
					printf(" _______  __   __  ______   _______  ___   _  __   __                                                  \n");  
					printf("|       ||  | |  ||      | |       ||   | | ||  | |  |                                                 \n");
					printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |                                                 \n");
					printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |                                                 \n");
					printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |                                                 \n");
					printf(" _____| ||       ||       ||       ||    _  ||       |                                                 \n");
					printf("|_______||_______||______| |_______||___| |_||_______|                                                 \n");
					printf(" ___   __    _  _______  _______  ______    ______    _______  _______  _______    ___           ____   \n");
					printf("|   | |  |  | ||       ||       ||    _ |  |    _ |  |       ||       ||       |  |   |         |    | \n");
					printf("|   | |   |_| ||       ||   _   ||   | ||  |   | ||  |    ___||_     _||   _   |  |___|  ____  |    _| \n");
					printf("|   | |       ||       ||  | |  ||   |_||_ |   |_||_ |   |___   |   |  |  | |  |   ___  |____| |   |   \n");
					printf("|   | |  _    ||      _||  |_|  ||    __  ||    __  ||    ___|  |   |  |  |_|  |  |   |        |   |   \n");
					printf("|   | | | |   ||     |_ |       ||   |  | ||   |  | ||   |___   |   |  |       |  |___|        |   |_  \n");
					printf("|___| |_|  |__||_______||_______||___|  |_||___|  |_||_______|  |___|  |_______|                |____| \n");
					system("pause");
					system("cls");
					}}}
				
				escolhal=0;}
				
					break;
					case 5:
					break;
					default:
					printf("#COMANDO INVALIDO!!! \n");
					system("pause");
					system("cls");
					break ;
	}
	
	} while(escolha!=5);
				










return 0;


}


