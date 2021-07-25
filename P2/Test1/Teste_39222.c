#include <stdio.h>
#include <string.h>

int LerVetorInteirosFicheiro (int X[], int *tam, char *fich)
{
  FILE *f;
  f = fopen(fich, "r");
  if (f == NULL) {
    return -1;
  }
  *tam = 0;
  while (!feof(f))
  {
    if (fscanf(f, "%d", &X[*tam]) == 1)
      *tam = *tam + 1;
  }
  fclose(f);
  return 1;
}

int LerVetorReaisFicheiro (float X[], int *tam, char *fich)
{
  FILE *f;
  f = fopen(fich, "r");
  if (f == NULL) {
    return -1;
  }
  *tam = 0;
  while (!feof(f))
  {
    if (fscanf(f, "%f", &X[*tam]) == 1)
      *tam = *tam + 1;
  }
  fclose(f);
  return 1;
}

int multiplos5(int X[], int tam, int *soma) {

  *soma = 0;
  int count = 0;

  for (int i=0; i<tam; i++) {
    if (X[i] % 5 == 0) {
      *soma += X[i];
      count++;
    }
  }
  return count;
}

int main()
{
  int parar;
  int X[100];
  int tam;

  int count;
  int soma;

  LerVetorInteirosFicheiro(X, &tam, "InteirosPositivos.txt");

  count = multiplos5(X, tam, &soma);

  printf("Numero de multiplos de 5: %d Soma: %d\n", count, soma);

  FILE *fp;
  fp = fopen("Saida39222.txt", "w");

  fprintf(fp, "Numero de multiplos de 5: %d Soma: %d\n", count, soma);

  fclose(fp);

  printf("Insira um numero inteiro para terminar: ");
  scanf("%d", &parar);
  return 0;
}
