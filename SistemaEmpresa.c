#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

typedef struct dados{
    char nome[51], sexo[2];
    int pecas;
    float sal;
} dados;

struct dados *p;
int n=0;

void menu(){
    int choice, j;

    printf("===Programa Da Empresa===\n");
    printf("\n Declarar Funcionario: 1");
    printf("\n Saber Salario:        2");
    printf("\n Folha De Pag Da Emp:  3");
    printf("\n Media Sal. Masc:      4");
    printf("\n Med Pec Fab Mul/Clas: 5");
    printf("\n Dados Maior Salario:  6");
    printf("\n Para Fechar O Prog:   0\n\n");
    printf(" Resposta: ");

    scanf("%d", &choice);
    //printf("n=%d\n", n);

    if(choice==1){
        system("cls");
        n=n+declara_funcionario(n);
    }
    else if(choice==2){
        system("cls");
        if(n==0){
            n=n+declara_funcionario(n);
        }
            salario_funcionario(n,j=1);
    }
    else if(choice==3){
        system("cls");
        if(n==0){
            n=n+declara_funcionario(n);
        }
            salario_funcionario(n,j=0);
            salario_total();
    }
    else if(choice==4){
        system("cls");
        if(n==0){
            n=n+declara_funcionario(n);
        }
        salario_funcionario(n,j=0);
        salario_medio_homens(n);

    }
    else if(choice==5){
        system("cls");
        if(n==0){
            n=n+declara_funcionario(n);
        }
        media_pecas_mulheres(n);
    }
    else if(choice==6){
        system("cls");
        if(n==0){
            n=n+declara_funcionario(n);
        }
        salario_funcionario(n,j=0);
        maior_salario(n);
    }
    else if(choice==0){
        return;
    }

    printf("\n\n Tecle '1' para voltar ao menu");
    printf("\n Tecle '0' para encerrar o programa\n\n ");
    scanf("%d", &choice);

    if(choice==1){
        system("cls");
        menu();
    }
    else{
        return;
    }
}


int declara_funcionario(int n){
    int i, x;

    printf(" Declare o numero de funcionarios: ");
    scanf("%d", &x);

    p=(struct dados *)calloc(x,sizeof(struct dados));

    for(i=0;i<x;i++){
        fflush(stdin);
        printf("\n #%d Nome: ", i+1+n);
        gets(p[i].nome);
        printf(" #%d Pecas fab/mes: ", i+1+n);
        scanf("%d", &p[i].pecas);
        fflush(stdin);
        printf(" #%d Sexo: ", i+1+n);
        gets(p[i].sexo);
    }
return(x);
}

void salario_funcionario(int n, int j){
    int i, k=30;

    for(i=0;i<n;i++, k=30){
        if(p[i].pecas<=30){
            p[i].sal=1000;
        }
        else if(p[i].pecas>30 && p[i].pecas<=35){
            k=p[i].pecas-k;
            p[i].sal=1000+(0.03*k*1000);
        }
        else if(p[i].pecas>35){
            k=p[i].pecas-k;
            p[i].sal=1000+(0.05*k*1000);
        }
        if(j==1)
        printf("\n Salario de %s: %.2f", p[i].nome, p[i].sal);
    }

}

void salario_total(){
    float sal_total=0;
    int i;

    for(i=0;i<n;i++){
        sal_total=sal_total+p[i].sal;
    }

    printf("\n Salario total dos empregados: %.2f", sal_total);
}

void salario_medio_homens(int n){
    int i, cont=0;
    float media_m;

    for(i=0;i<n;i++){
        if(p[i].sexo[0] == 'M'){
            media_m=media_m+p[i].sal;
            cont++;
        }
    }

    media_m=(float)media_m/cont;
    printf("\n Media Salarial Masculina: %.2f", media_m);
}

void media_pecas_mulheres(int n){
    int i, cont=0, conta=0, contb=0, contc=0;
    float a=0, b=0, c=0, media_f=0;

    for(i=0;i<n;i++){
        if(p[i].sexo[0]=='F'){
            if(p[i].pecas<=30){
                a=a+p[i].pecas;
                conta++;
            }
            else if(p[i].pecas>30 && p[i].pecas<=35){
                b=b+p[i].pecas;
                contb++;
            }
            else if(p[i].pecas>35){
                c=c+p[i].pecas;
                contc++;
            }
            media_f=media_f+p[i].pecas;
            cont++;
        }
        media_f=(float)(media_f/cont);
        if(a!=0)
        a=(float)(a/conta);
        if(b!=0)
        b=(float)(b/contb);
        if(c!=0)
        c=(float)(c/contc);
    }
    printf(" \n Media Das Que Produzem Ate 30 Pecas: %.2f", a);
    printf(" \n Media Das Que Produzem Entre 31 & 35 Pecas: %.2f", b);
    printf(" \n Media Das Que Produzem Mais De 35 Pecas: %.2f", c);
    printf(" \n Media Total: %.2f", media_f);
}

void maior_salario(int n){
    int i, j;
    float k=999;

    for(i=0;i<n;i++){
        if(p[i].sal>k){
            k=p[i].sal;
            j=i;
        }
    }
    printf("\n %s tem o maior salario, que e de: %.2f", p[j].nome, k);

}

int main(){

    int n=0;

    menu();

    free(p);

    printf("\n\n\n");
return 0;
}
