#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
void limparVagas(int *vaga, int *num);

int main()
{
	int num,user,vaga[51],opcao;
	user=0;
	char placa[user][8], cor[user][16], modelo[user][16];
	int diaE[user],mesE[user],horaE[user],minE[user];
	int diaS[user],mesS[user],horaS[user],minS[user];
	//ctime_ini
    time_t dataIni[user],dataFim[user];
    dataIni[user]=0; 
	dataFim[user]=0;
    tm *dataIniPnt=localtime(&dataIni[user]); //seta
	tm *dataFimPnt=localtime(&dataFim[user]); //seta
	double diffTemp;
	//ctime_fim
	
	limparVagas(vaga, &num);
	printf("\nok");
	
	do
	{
		printf ("\n\n");
		printf ("\t823 - INTRODUCAO A PROGRAMACAO 2016/2\n");
		printf ("\t2016200484 - Lucas Moreira Peres Barga\n");
		printf ("\tSistema Gerenciador de Estacionamento\n");
		
		printf ("\n\nMenu: \n");
		printf ("1- Entrada veiculo\n");
		printf ("2- Saida veiculo\n");
		printf ("3- XXX\n");
		printf ("0- Sair do programa\n");
		
		printf("\nOpcao: ");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
				//ENTRADA
				printf("\n\n Numero da vaga (1~50): ");
				scanf ("%d", &num);
				user=num;
				
				if(num<=50)
				{
					if(vaga[num] == 0)
					{
						printf("\nok");
						
						printf("\n\n Vaga Disponivel!\n\n");
						
						printf("\nInformacoes do veiculo\n");
						printf("Placa:");
						scanf("%s", &placa[user]);
						printf("Cor:");
						scanf("%s", &cor[user]);
						printf("Modelo:");
						scanf("%s", &modelo[user]);
						printf("\nV- %s,%s,%s",placa[user],cor[user],modelo[user]);
						
						printf("\nData e hora de entrada\n");
						printf("Dia:");
						scanf("%d", &diaE[user]);
						printf("Mes:");
						scanf("%d", &mesE[user]);
						printf("Horas:");
						scanf("%d", &horaE[user]);
						printf("Minutos:");
						scanf("%d", &minE[user]);
						printf("\nE- %d,%d,%d,%d",diaE[user],mesE[user],horaE[user],minE[user]);
						
												
						//atribui valores - dataIni
						dataIniPnt->tm_year=2016-1900; //ano=2016 (� necess�rio subtrair 1900, pois os anos iniciam em 1900)
						dataIniPnt->tm_mon=mesE[user]-1; //m�s=maio (� necess�rio subtrair 1, pois os meses iniciam no zero)
						dataIniPnt->tm_mday=diaE[user]; //
						dataIniPnt->tm_hour=horaE[user]; //
						dataIniPnt->tm_min=minE[user]; //
						dataIniPnt->tm_sec=0; //
						dataIni[num]=mktime(dataIniPnt); //salva os valores
						
						//teste
						int ty,tme,td,th,tm,ts;
						ty=dataIniPnt->tm_year=2016-1900; //ano=2016 (� necess�rio subtrair 1900, pois os anos iniciam em 1900)
						tme=dataIniPnt->tm_mon=mesE[user]-1; //m�s=maio (� necess�rio subtrair 1, pois os meses iniciam no zero)
						td=dataIniPnt->tm_mday=diaE[user]; //
						th=dataIniPnt->tm_hour=horaE[user]; //
						tm=dataIniPnt->tm_min=minE[user]; //
						ts=dataIniPnt->tm_sec=0; //
						
						printf("\n1- %d,%d,%d,%d,%d,%d",ty,tme,td,th,tm,ts);
						
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
						vaga[num]=num;
						
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
					}
					else
					{
						printf("\n\nVaga ocupada, escolha outra vaga.\n\n");
					}
				}
				else
				{
					printf("\n\nVaga nao existente!\n\n");
				}
				
			break;
			
			case 2:
				//SAIDA
				printf("\n\n Numero da vaga (1~50): ");
				scanf ("%d", &num);
				user=num;
				
				if(num<=50)
				{
					if(vaga[num] != 0)
					{
						printf("\nok");
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
						printf("\nData e hora de saida\n");
						printf("Dia:");
						scanf("%d", &diaS[user]);
						printf("Mes:");
						scanf("%d", &mesS[user]);
						printf("Horas:");
						scanf("%d", &horaS[user]);
						printf("Minutos:");
						scanf("%d", &minS[user]);
						printf("\nS- %d,%d,%d,%d",diaS[user],mesS[user],horaS[user],minS[user]);
						
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
						//atribui valores - dataFim
						dataFimPnt->tm_year=2016-1900; //ano=2016 (� necess�rio subtrair 1900, pois os anos iniciam em 1900)
						dataFimPnt->tm_mon=mesS[user]-1; //m�s=maio (� necess�rio subtrair 1, pois os meses iniciam no zero)
						dataFimPnt->tm_mday=diaS[user]; //
						dataFimPnt->tm_hour=horaS[user]; //
						dataFimPnt->tm_min=minS[user]; //
						dataFimPnt->tm_sec=0; //
						dataFim[user]=mktime(dataFimPnt); //salva os valores
					
						//teste
						int tyF,tmeF,tdF,thF,tmF,tsF;
						tyF=dataFimPnt->tm_year=2016-1900; //ano=2016 (� necess�rio subtrair 1900, pois os anos iniciam em 1900)
						tmeF=dataFimPnt->tm_mon=mesS[user]-1; //m�s=maio (� necess�rio subtrair 1, pois os meses iniciam no zero)
						tdF=dataFimPnt->tm_mday=diaS[user]; //
						thF=dataFimPnt->tm_hour=horaS[user]; //
						tmF=dataFimPnt->tm_min=minS[user]; //
						tsF=dataFimPnt->tm_sec=0; //
						
						printf("\n2- %d,%d,%d,%d,%d,%d",tyF,tmeF,tdF,thF,tmF,tsF);
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
						//calcula diferenca
						diffTemp = difftime( dataFim[user], dataIni[user] );
						printf("\nD- %f", diffTemp); //60.000 = 1min, 3600.00 = 1 hora
						
						printf("\nvaga-%d \nnum-%d\nvaga[num]-%d",vaga,num,vaga[num]);
						
						
					}
					else
					{
						printf("\n\nVaga vazia!\n\n");
					}
					
				}
				else
				{
					printf("\n\nVaga nao existente!\n\n");
				}
				
				break;	
		}
	}while(opcao!=0);
	
	
return 0;

}

void limparVagas(int *vaga, int *num)
{	
	for (*num = 1; *num <= 50;*num=*num+1)
	{
		vaga[*num] = 0;;
		printf("\n%d", vaga[*num]);
	}
}	