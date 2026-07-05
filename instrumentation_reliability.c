#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes functions
void series(double r[3]);
void parallel(double r[3]);

// Program calculation of instrumentation reliability
int main() {
	double r[3];
	int series_mode, parallel_mode;

	/* We need seed constant with UTC-Time null, for the computation of the pseudo_random numbers, in our case */
	srand(time(NULL)); // Init the seed at UTC-Time null;

	/* reliability informations given by the user */
	printf("Give Reliability");
	printf("\n\nReliability 1: ");
	scanf("%lf", &r[0]);
	printf("\n\nReliability 2: ");
	scanf("%lf", &r[1]);
	printf("\n\nReliability 3: ");
	scanf("%lf", &r[2]);

	/* We need probabilities not integer number */
	/* /!\ use goto label with care (only in case of simple errors like this)*/
	if ((r[0] >= 1 && r[1] >= 1 && r[2] >= 1) || (r[0] <= 0 && r[1] <= 0 && r[2] <= 0)) {
		goto fail;
	}

	/* series or parallel ? */
	printf("\n\nWarning! Characteres answer are not accepted for now, the comparaison functionalities of characters are coming soon :)");
	printf("\n\nSeries or Parallel (answer accepted: yes = 1/ no = 0)");
	printf("\nSeries:");
	scanf("%d", &series_mode);
	printf("\nParallel:");
	scanf("%d", &parallel_mode);

	/* check if the user choose both configurations ; which is an error for our program */
	if (series_mode == parallel_mode) {printf("\n\nyou can't had both components configurations: series and parallel"); exit(0);}

	if(series_mode == 1 && parallel_mode == 0) {series(r);}
	else if(series_mode == 0 && parallel_mode == 1) {parallel(r);}
	else {exit(1);}

	return 0;

	/* /!\ use goto label with care (only in case of simple errors like this) */
	fail:
		exit(1);
}

static int trials_nb = 0;

void series(double r[3]) {
	double series_result;

	/* number of trials */
	printf("\n\niteration: ");
	scanf("%d", &trials_nb);

	for (auto i = 0; i < trials_nb; i++) {
 		series_result = (r[0] * r[1] * r[2]) * 100;
		printf("\n\nSeries Result = %lf%%\n", series_result);

		r[0] *= (double)rand() / RAND_MAX;
		r[1] *= (double)rand() / RAND_MAX;
		r[2] *= (double)rand() / RAND_MAX;

		/* We need probabilities not integer number */
		/* /!\ use goto label with care (only in case of simple errors like this)*/
		if ((r[0] >= 1 || r[1] >= 1 || r[2] >= 1) && (r[0] <= 0 || r[1] <= 0 || r[2] <= 0)) {
			goto outside_proba;
		}
		outside_proba:
			break;
	}
}

void parallel(double r[3]) {
	double parallel_result;

	/* number of trials */
	printf("\n\niteration: ");
	scanf("%d", &trials_nb);

	for (auto i = 0; i < trials_nb; i++) {
		parallel_result = (1 - ( (1 - r[0]) * (1 - r[1]) * (1 - r[2]) ) ) * 100;
		printf("\n\nParallel Result = %lf%%\n", parallel_result);

		r[0] *= (double)rand() / RAND_MAX;
		r[1] *= (double)rand() / RAND_MAX;
		r[2] *= (double)rand() / RAND_MAX;

		/* We need probabilities not integer number */
		/* /!\ use goto label with care (only in case of simple errors like this)*/
		if ((r[0] >= 1 || r[1] >= 1 || r[2] >= 1) && (r[0] <= 0 || r[1] <= 0 || r[2] <= 0)) {
			goto outside_proba;
		}
		outside_proba:
			break;
	}
}
