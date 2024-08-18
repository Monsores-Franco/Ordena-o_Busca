#include <stdio.h>
#define tam 10

void troca(int* i,int* j);
int particao(int* vetor,int left,int right);
void QuickSort(int* vetor,int left,int right);
int buscaseq(int* vetor,int chave);
int buscabin(int* vetor,int chave,int inicio,int final);
void inicializa_vetor(int* vetor);
void imprime_vetor(int* vetor);
void Bubble_Sort(int* vetor);

int main(){
    int vetor[tam];
    printf("digite o vetor fora de ordem\n");
    inicializa_vetor(vetor);

    int left = 0;
    int right = sizeof(vetor)/sizeof(vetor[0]) - 1;
    int opcao_2;
    int opcao;
    do{
        
        printf("escolha como você quer ordenar:\n1 - QuickSort\n2 - Bubblesor\n0 - sair");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                QuickSort(vetor,left,right);
                printf("ordenação por QuickSort:\n");
                imprime_vetor(vetor);
                break;
            case 2:
                Bubble_Sort(vetor);
                printf("\nordenação por Bubble Sort\n");
                imprime_vetor(vetor);
                break;
            case 0:
                break;
        
        }
        printf("\ndeseja escolher outra opção?\n1 - sim 0-nao ");
        scanf("%d",&opcao_2);
        getchar();
        if(opcao_2 == 1){
            printf("Digite novamente os valores de array fora de ordem:\n");
            inicializa_vetor(vetor);
        }
        else{
            break;
        }
    }while(opcao!=0);

    int opcao_busca;
    int buscando;
    int resultado_busca = 0;

    do{
        printf("digite o tipo de busca:\n1-sequencial\n2-binaria\n0-sair");
        scanf("%d",&opcao_busca);
        switch(opcao_busca){
            case 1:
                printf("\nescolha o numero a ser buscado: ");
                scanf("%d",&buscando);
                getchar();
                resultado_busca = buscaseq(vetor,buscando);
                if(resultado_busca == 1){
                    printf("\nvalor encontrado");
                }else{
                    printf("\nvalor não encontrado :( ");
                }
                break;
            case 2:
                printf("\nescolha o numero a ser buscado: ");
                scanf("%d",&buscando);
                getchar();
                resultado_busca = buscabin(vetor,buscando,0,tam -1);
                if(resultado_busca != -1){
                    printf("valor encontrado !");
                }
                else{
                    printf("valor não encontrado :(");
                }
                break;
            case 0:
                break;
        }
    }while(opcao_busca!=0);

    return 0;
}

void Bubble_Sort(int* vetor){
    for(int i =0;i<tam -1;i++){
        for(int j = 0;j<tam - i -1;j++){
            if(vetor[j] > vetor[j + 1]){
                troca(&vetor[j],&vetor[j + 1]);
            }
        }
    }
}

void imprime_vetor(int* vetor){
    for(int i =0;i<tam;i++){
        printf("%d | ",vetor[i]);
    }
}

void inicializa_vetor(int* vetor){
    for(int i = 0;i < tam;i++){
        printf("digite o %dº elemento: ",i + 1);
        scanf("%d",&vetor[i]);
    }

}

int buscabin(int* vetor,int key,int inicio,int final){
    while(inicio <= final){
        int media = (inicio + final)/2;
        if(vetor[media] == key){
            return media;
        }
        if(vetor[media] < key){
            inicio = media + 1;
        }
        else{
            final = media -1;
        }
    }
    return -1;
}

int buscaseq(int* vetor,int key){
    for(int i = 0; i < tam - 1;i++){
        if(vetor[i]==key){
            return 1;
        }
    }
    return -1;
}

void QuickSort(int* vetor,int left,int right){
    if(left <= right){
        int index_pivot = particao(vetor,left,right);
        QuickSort(vetor,left,index_pivot - 1);
        QuickSort(vetor,index_pivot + 1,right);
    }
}

int particao(int* vetor,int left,int right){
    int pivot = vetor[left];
    int i = left;
    for(int j = left + 1; j <= right;j++){
        if(vetor[j] < pivot){
            i++;
            troca(&vetor[i],&vetor[j]);
        }
    }
    troca(&vetor[i],&vetor[left]);

    return i;
}

void troca(int* i, int* j){
    int aux = 0;

    aux = *i;
    *i = *j;
    *j = aux;
}