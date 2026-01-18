/* File FITTING.C: Curve Fitting by Method of Least Squares */

#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPOINTS 100
#define MAXDEGREE 10
#define MAXSIZE (MAXDEGREE + 1)

#define SINGULAR (-1)
#define SUCCESS 0

void readdata(char *datafile, unsigned int *num);
unsigned int printdata(unsigned int num);
void calcmatrix(unsigned int degree, unsigned int num);
double sum(double a[], double b[], unsigned int num);
int gauss(unsigned int ncol);
void swapdouble(double *x, double *y);
void printresult(unsigned int degree, double x2sum, double y2sum, double xysum);

double A[MAXSIZE][MAXSIZE];
double b[MAXSIZE];
double coef[MAXSIZE + 1];
double x[MAXPOINTS];
double y[MAXPOINTS];
FILE *stream;

#define printerrmsg(s)              \
    do {                            \
        fputs("\n" s "\n", stderr); \
        exit(EXIT_FAILURE);         \
    } while (0);

int main(int argc, char *argv[])
{
    unsigned int degree, num;
    double x2sum, y2sum, xysum;

    if (argc < 2) {
        puts("Usage:  fitting datafile");
        exit(EXIT_FAILURE);
    }

    readdata(argv[1], &num);

    degree = printdata(num);

    calcmatrix(degree, num);

    x2sum = sum(x, y, num);
    y2sum = sum(y, y, num);
    xysum = sum(x, y, num);

    if (gauss(degree + 1) == SINGULAR) {
        printerrmsg("Singular error.");
    }

    printresult(degree, x2sum, y2sum, xysum);

    fputc('\x1a', stdout);

    return 0;
}

void readdata(char *datafile, unsigned int *num)
{
    unsigned int i;

    stream = fopen(datafile, "rt");

    if (stream == NULL) {
        printerrmsg("Data file not found !");
    }

    if (fscanf(stream, "%u\n", num) != 1) {
        printerrmsg("Illegal number of points in data file.");
    } else if (*num > MAXPOINTS) {
        printerrmsg("Too many points in data file.");
    } else if (*num < 2) {
        printerrmsg("Too few points in data file.");
    }

    for (i = 0; i < *num; i++) {
        if (fscanf(stream, "%lf %lf\n", &x[i], &y[i]) != 2) {
            printerrmsg("Too few coordinates in data file.");
        }
    }
}

unsigned int printdata(unsigned int num)
{
    unsigned int degree, i;
    unsigned int maxdegree = min(num - 1, MAXDEGREE);

    fprintf(stdout, "\n   Input data:\n\n%15s  %15s\n\n", "x", "y");

    for (i = 0; i < num; i++) {
        fprintf(stdout, "%15.5lf, %15.5lf\n", x[i], y[i]);
    }

    fprintf(stdout, "\n\nEnter degree of x (1 - %u): ", maxdegree);

    if ((scanf("%u", &degree) != 1) || (degree < 1)) {
        printerrmsg("Illegal degree of x");
    } else if (degree > maxdegree) {
        printerrmsg("Too high degree of x");
    }

    return degree;
}

/* Calculate Coefficient Matrix A[][] and b[] */
void calcmatrix(unsigned int degree, unsigned int num)
{
    unsigned int i, j, k;

    for (i = 0; i < num; i++) {
        for (j = 1; j <= degree + 1; j++) {
            for (k = 1; k <= degree + 1; k++) {
                A[j][k] += pow(x[i], (double)(j + k - 2));
            }

            b[j] += pow(x[i], (double)(j - 1)) * y[i];
        }
    }
}

double sum(double a[], double b[], unsigned int num)
{
    unsigned int i;
    double sum = 0.;

    for (i = 0; i < num; i++) {
        sum += a[i] * b[i];
    }

    return sum;
}

/* A1gorithm: Gauss elimination */
int gauss(unsigned int n)
{
    unsigned int j, k, p;
    double q, sum;
    static double _A[MAXSIZE][MAXSIZE];
    static double _b[MAXSIZE];

    memcpy(_A, A, sizeof(A));
    memcpy(_b, b, sizeof(b));

    /* Gauss elimination */
    for (k = 1; k <= n - 1; k++) {
        for (j = k; j <= n; j++) {
            if (fabs(_A[j][k]) > 1.e-6) {
                break;
            }
        }

        if (j > n) {
            /* if no such j exists, stop. */

            return SINGULAR;
        } else if (j == k) {
            /* else if j == k, no exchange. */
        } else {
            /* else exchange rows j and k. */
            for (p = 1; p <= n; p++) {
                swapdouble(&_A[j][p], &_A[k][p]);
            }

            swapdouble(&_b[j], &_b[k]);
        }

        for (j = k + 1; j <= n; j++) {
            q = _A[j][k] / _A[k][k];

            for (p = k + 1; p <= n; p++) {
                _A[j][p] -= q * _A[k][p];
            }

            _b[j] -= q * _b[k];
        }
    }

    if (fabs(_A[n][n]) < 1.e-6) {
        return SINGULAR;
    }

    /* Back-substitution */
    coef[n] = _b[n] / _A[n][n];

    for (j = n - 1; j >= 1; j--) {
        sum = 0.;

        for (k = j + 1; k <= n; k++) {
            sum += _A[j][k] * coef[k];
        }

        coef[j] = (_b[j] - sum) / _A[j][j];
    }

    return SUCCESS;
}

void swapdouble(double *px, double *py)
{
    double temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

void printresult(unsigned int degree, double x2sum, double y2sum, double xysum)
{
    unsigned int i;

    fprintf(stdout, "\n\n The results...\n\n");
    fprintf(stdout, " f(x) = A0 + A1x");

    for (i = 2; i <= degree; i++) {
        fprintf(stdout, " + A%ux*%u", i, i);
    }

    fprintf(stdout, "\n\n");

    for (i = 0; i <= degree; i++) {
        fprintf(stdout, "A%u = %.15lg\n", i, coef[i + 1]);
    }

    if (degree == 1) {
        fprintf(stdout, "\nCoefficient of correlation : %.10lg\n",
                xysum / sqrt(x2sum * y2sum));
    }
}
