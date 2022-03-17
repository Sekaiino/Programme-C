#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

int main ()
{

    setlocale (LC_ALL, "");
    int cloques, impacts;
    char on;

    printf (" Observez-vous une griffe de plus de 5cm : (O)ui/(N)on ? ");
    scanf ("%c", &on);
    printf ("\n\n");

    if (on == 'o')
    {
        printf (" Pièce non-conforme à mettre au rebut.\n\n");
    }
    else if (on == 'n')
    {
       printf (" Combien de cloques observez-vous ? ");
       scanf ("%d", &cloques);
       printf ("\n\n");
       
       if (cloques > 3)
       {
           printf (" Pièce non-conforme à retoucher.\n\n");
       } 
       else if (cloques <= 3)
       {
          printf (" Combien d'impacts observez-vous ? ");
          scanf ("%d", &impacts);
          printf ("\n\n");

          if (impacts > 5)
          {
              printf (" Pièce non-conforme pouvant être acceptée après dérogation.\n\n");
          }
          else if (impacts <= 5)
          {
              printf ("Pièce conforme\n\n");
          }
       }
    }

}