#include "types.h"
int fd=1;
//static void                   /*Esta es la función putc(int fd,char c) que utilizan en xv6*/
//putc(int fd, char c)
//{
//  write(fd, &c, 1);
//}
extern int putc(unsigned int fd, char c);

static void
printint(int fd, int xx, int base, int sgn)
{
    static char digits[] = "0123456789ABCDEF";
    char buf[16];
    int i, neg;
    uint x;

    neg = 0;
    if(sgn && xx < 0){
      neg = 1;
      x = -xx;
    } else {
      x = xx;
    }

    i = 0;
    do{
      buf[i++] = digits[x % base];
    }while((x /= base) != 0);
    if(neg)
      buf[i++] = '-';

    while(--i >= 0)
      putc(fd, buf[i]);
}

// print to the given fd. Only understands %d.
void printf(char *fmt, ...)
{
    char *s;
    int c, i, state;
    uint *ap;

    state = 0;
    ap = (uint*)(void*)&fmt + 1;
    for(i = 0; fmt[i]; i++){
        c = fmt[i] & 0xff;
        if(state == 0){
            if(c == '%'){
              state = '%';
            } else {
              putc(fd, c);
            }
        } else if(state == '%'){
        if(c == 'd'){
            printint(fd, *ap, 10, 1);
           ap++;
        }
        else {
        // Unknown % sequence.  Print it to draw attention.
            putc(fd, '%');
            putc(fd, c);
        }
        state = 0;
    }
  }//end for()
}//end printf()

Por último escribiremos un driver de prueba para hacer uso de nuestra primera versión de la función printf().

/*
  TestPrintf.c - driver para usar la funcion
  void printf(char*, ...)
 */

/*#include <stdio.h>*/

extern void printf(int fd,char *fmt,...);
extern void salir(int status);

int main(){
  printf(1,"Viernes %d de febrero de %d.\n",16,2018);

  salir(0xff);
}/*end main()*/
