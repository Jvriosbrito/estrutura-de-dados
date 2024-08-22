#include <stdio.h>
#include <cstring>

// Escreva um algoritmo que solicite ao usuario a idade de n alunos e ao final apresente:
// Versao01: A maior e a Menor das idades
// Versao02: A media de idades
// Versao03: Alem das idades, solicitar tambem as notas das tres provas realizadas pelo aluno
// Versao 04: Se eh verdade que alunos mais jovens teem notas melhores que os veteranos
// Versao 05: Gerar um relatorio de alunos aprovados e reprovados

struct Aluno {
    char Nome[30];
    int idade;
    char Sexo;
    float Notas[3];
    bool aprovado = false;
    bool jovem = false;
    float somaNotasArr;
};

int main() {
    // Vamos declarar uma estrutura do tipo aluno
    struct Aluno Turma[100];
    // Estamos declarando a variavel para controlar a quantidade de dados coletados
    int Qtd, Resposta;
    // Estamos declarando as variaveis para armazenar o maior e o menor dos valores coletados
    float Maior, Menor, MediaIdade = 0;
    float somaNotas=0, mediaFaculdade, mediaNotasVeterano=0, mediaNotasJovem=0;
    Qtd = 0;
    
    printf(" Informe a media da faculdade: ");
    scanf("%f", &mediaFaculdade);

    do
    {
        Qtd++;
        do{
           printf(" Informe o sexo do %i aluno: ", Qtd);
           scanf("%s", &Turma[Qtd].Sexo);}
           while (Turma[Qtd].Sexo != 'm' && Turma[Qtd].Sexo != 'M' & 
		          Turma[Qtd].Sexo != 'f' && Turma[Qtd].Sexo != 'F');
       
	    if(Turma[Qtd].Sexo == 'm' or Turma[Qtd].Sexo == 'M')
             printf(" Informe o nome do aluno: ");
	    
		else(Turma[Qtd].Sexo == 'f' or Turma[Qtd].Sexo == 'F');
		printf(" Informe o nome da aluna: ");
        scanf("%s", &Turma[Qtd].Nome);
		
		do{
		  printf(" Informe a idade de %s: ", Turma[Qtd].Nome); 
		  scanf("%d", &Turma[Qtd].idade);}
		  while (Turma[Qtd].idade < 15 or Turma[Qtd].idade > 130);
        
        Turma[Qtd].somaNotasArr=0;
		for (int j=0; j<3; j++) 
		  do{
        	printf("   Informe a %i. nota: ", j+1);
            scanf("%f", &Turma[Qtd].Notas[j]);
            Turma[Qtd].somaNotasArr=Turma[Qtd].somaNotasArr + Turma[Qtd].Notas[j];
        } while (Turma[Qtd].Notas[j] < 0 or Turma[Qtd].Notas[j] > 10);
        
        Turma[Qtd].aprovado = (Turma[Qtd].somaNotasArr >= mediaFaculdade);

        // Verifica primeira iteracao e inicializa as variaveis
        if (Qtd == 1)
        {
            Maior = Turma[1].idade;
            Menor = Turma[1].idade;
        }
        // Itera pelo vetor e verifica qual valor eh maior/menor
        else
        {
            if (Turma[Qtd].idade > Maior)
                Maior = Turma[Qtd].idade;
            else if (Turma[Qtd].idade < Menor)
                Menor = Turma[Qtd].idade;
        }

        // Soma as idades ate o loop acabar
        MediaIdade = MediaIdade + Turma[Qtd].idade;
        // Reseta a variavel somaNotas
        //somaNotas = 0;
        // Itera pelo vetor de notas e verifica se o aluno foi aprovado mediante à do mesmo
        //for (int i = 0; i < 3; i++)
            //somaNotas = somaNotas + Turma[Qtd].Notas[i];

        somaNotas = somaNotas / 3;

        Turma[Qtd].aprovado = somaNotas >= mediaFaculdade;

        printf("Deseja informar o proximo aluno? 1/Sim - 2/Nao\n");
        scanf("%i", &Resposta);
    } while (Resposta == 1);

    // Nao precisa reduzir qtd -1 pois so e aumentado no inicio do loop do while{}
    MediaIdade = MediaIdade / Qtd;
    printf("\n A maior idade: %0.2f", Maior);
    printf("\n A menor idade: %0.2f", Menor);
    printf("\n Media das %i(s) idades: %0.2f\n\n", Qtd, MediaIdade);

    printf("Deseja receber relatório dos alunos? 1/Sim - 2/Nao\n");

    scanf("%d", &Resposta);
    if (Resposta == 1)
        for (int i = 1; i <= Qtd; i++)
        {
            if (Turma[i].idade > MediaIdade)
            {
                // Seta aluno como veterano
                Turma[i].jovem = false;
                mediaNotasVeterano += Turma[i].somaNotasArr;
            }
            else
            {
                // Seta aluno como jovem
                Turma[i].jovem = true;
                mediaNotasJovem += Turma[i].somaNotasArr;
            }
            printf("\n Idade: %d", Turma[i].idade);
            printf("\n Nome: %s", Turma[i].Nome);

            if (Turma[i].idade > MediaIdade)
            {
                printf("Aluno Veterano\n");
            }
            else
            {
                printf("Aluno Jovem\n");
            }
            for (int j = 0; j < 3; j++)
            {
                printf("Nota %d: %f\n", j + 1, Turma[i].Notas[j]);
            }
            if (Turma[i].aprovado == true)
                printf("Aluno Aprovado\n\n");
            else
                printf("Aluno Reprovado\n\n");
        }

    // Fora do loop acima pois ja foi somado
    // Verifica se media dos veteranos > que dos jovens
    if (mediaNotasVeterano > mediaNotasJovem)
        printf("Alunos mais jovens NAO TEM notas melhores que veteranos!!\n");
    else
        printf("Alunos mais jovens TEM notas melhores que veteranos!!\n");

    return 0;
}
