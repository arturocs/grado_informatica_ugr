// Bomba de Arturo Cortés Sánchez
// gcc -Og bomba.c -o bomba -no-pie


#include <stdio.h>    // para printf(), fgets(), scanf()
#include <stdlib.h>   // para exit()
#include <string.h>   // para strncmp()
#include <sys/time.h> // para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 15

//  contraseña ="secuRepass"
//  pin = -788

char password[] = "contrasena_segura";
char p[] = "\x73\xa\xd\x1\x20\x4\x3\x4\x1d\x12";
int passcode = 1024;

void boom(void) {
  printf("\n"
         "***************\n"
         "*** BOOM!!! ***\n"
         "***************\n"
         "\n");
  exit(-1);
}

void defused(void) {
  printf("\n"
         "·························\n"
         "··· bomba desactivada ···\n"
         "·························\n"
         "\n");
  exit(0);
}

void cifradosuperseguro(char *input) {
  for (int i = sizeof(password) - 1; i > 0; i--) {
    input[i] ^= password[i];
  }
}

int cifradoultraseguro(int n) {
  for (int i = 0; i < sizeof(password); i++)
    n += password[i];
  return n;
}

int main() {
  char pw[SIZE];
  int pc, n;

  struct timeval tv1, tv2; // gettimeofday() secs-usecs
  gettimeofday(&tv1, NULL);

  do {
    printf("\nIntroduce la contraseña: ");
  } while (fgets(pw, SIZE, stdin) == NULL);

  cifradosuperseguro(pw);

  if (strncmp(pw, p, sizeof(p) - 1))
    boom();

  gettimeofday(&tv2, NULL);

  if (tv2.tv_sec - tv1.tv_sec > TLIM)
    boom();

  do {
    printf("\nIntroduce el pin: ");
    if ((n = scanf("%i", &pc)) == 0)
      scanf("%*s") == 1;
  } while (n != 1);

  if (cifradoultraseguro(pc) != passcode)
    boom();

  gettimeofday(&tv1, NULL);

  if (tv1.tv_sec - tv2.tv_sec > TLIM)
    boom();

  defused();
}
