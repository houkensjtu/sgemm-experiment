#include <stdio.h>
#include <time.h>

#define N 512

int main(){
  float a[N][N];
  float b[N][N];
  float c[N][N];

  time_t st, ed;
  float flop = 2.0 * N * N * N;
  
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      a[i][j] = 1.0;
      b[i][j] = 2.0;
      c[i][j] = 0.0;
    }
  }
  
  st = clock();
  float acc;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      acc = 0.0;
      for (int k = 0; k < N; ++k){
	acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
  ed = clock();
  
  float used_time = 1.0 * (ed - st) / CLOCKS_PER_SEC;
  printf("Time collapsed: %5.3f ms.\n", used_time * 1000);
  printf("Performance: %5.3f GFLOPS.\n", flop / used_time / 1e9) ; 
  
  return 0;
}
