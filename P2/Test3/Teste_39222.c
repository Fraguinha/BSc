#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float soma(float *v, int n, float x, float r);

int main()
{
  int n;
  printf("tamanho: ");
  scanf("%d", &n);

  float v[n];

  for(int i=0; i<n; i++) {

    scanf("%f", &v[i]);

  }

  float f;
  printf("real positivo: ");
  do {
    
    scanf("%f", &f);

  } while (f <= 0);

  float result = soma(v, n-1, f, 0);

  printf("Resultado: %f\n", result);
  
  return 1;
}

float soma(float *v, int n, float x, float r) {

  if (v[n] > x) {

    r += v[n];

  }

  if (n == 0) {

    return r;

  } else {

    return soma(v, n-1, x, r);

  }

}
