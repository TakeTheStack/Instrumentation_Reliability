# Instrumentation_Reliability
Permet de mesurer la fiabilité totale d'un système, configurer soit en série ou soit en parallèle.

# Schéma Entrée/Sortie
série:\
information->|composant 1|->fiabilité 1->|composant 2|->fiabilité 2->|composant 3|->fiabilité 3\

parallèle:\
Information->|composant 1|->fiabilité\
Information->|composant 2|->fiabilité\
Information->|composant 3|->fiabilité

# Formules Mathèmatiques
Série = r1 * r2 *r3\
Série avec la même fiabilité = (r)³->c'est le nombre de composant\

Parallèle = 1 - ((1 - r1) * (1 - r2) * (1 - r3))\
Parallèle avec la même fiabilité = 3r - 3r² + r³

# Pseudo-Program implémenter en langage c
include <stdio.h>, <stdlib.h>, <math.h>\

int main() {\
  double r, tr, r1, r2, r3;\
  int same_component, series_mode, parallel_mode;\

  printf("Is this the same component from the same company ?");\
  scanf(%d", &same_component);\

  (same_component == 1) ? r=tr=r1=r2=r3 : r = 0, tr = 0, r1 = 0, r2 = 0, r3 = 0;\

  printf("\nSeries or Parallel ?");\
  scanf("%d %d", &series_mode, &parallel_mode);\

  if(series_mode == 1 && parallel_mode == 0) {Series(r);}\
  else if(series_mode == 0 && parallel_mode == 1) {Parallel(r);}\
} Series(r); Parallel(r);
//this is the two functions necessary for both systems configurations and computations of reliability

Pour plus d'information, voici le program complet fonctionnel: https://github.com/TakeTheStack/Instrumentation_Reliability/edit/main/instrumentation_reliability.c\
