#ifndef UNCONSTRAINED_DATA_H
#define UNCONSTRAINED_DATA_H
#include "osqp.h"


/* create additional data and solutions structure */
typedef struct {
c_float * x_test;
c_float obj_value_test;
c_int status_test;
} unconstrained_sols_data;

/* function prototypes */
OSQPData * generate_problem_unconstrained();
void clean_problem_unconstrained(OSQPData * data);
unconstrained_sols_data *  generate_problem_unconstrained_sols_data();
void clean_problem_unconstrained_sols_data(unconstrained_sols_data * data);


/* function to generate QP problem data */
OSQPData * generate_problem_unconstrained(){

OSQPData * data = (OSQPData *)c_malloc(sizeof(OSQPData));

// Problem dimensions
data->n = 5;
data->m = 0;

// Problem vectors
data->l = (c_float*) c_malloc(0 * sizeof(c_float));
data->u = (c_float*) c_malloc(0 * sizeof(c_float));
data->q = (c_float*) c_malloc(5 * sizeof(c_float));
data->q[0] = -1.10593508000000007030;
data->q[1] = -1.65451545000000010965;
data->q[2] = -2.36346860000000003055;
data->q[3] = 1.13534534999999991989;
data->q[4] = -1.01701413999999989990;


// Matrix A
//---------
data->A = (csc*) c_malloc(sizeof(csc));
data->A->m = 0;
data->A->n = 5;
data->A->nz = -1;
data->A->nzmax = 0;
data->A->x = OSQP_NULL;
data->A->i = OSQP_NULL;
data->A->p = (c_int*) c_malloc((5 + 1) * sizeof(c_int));
data->A->p[0] = 0;
data->A->p[1] = 0;
data->A->p[2] = 0;
data->A->p[3] = 0;
data->A->p[4] = 0;
data->A->p[5] = 0;


// Matrix P
//---------
data->P = (csc*) c_malloc(sizeof(csc));
data->P->m = 5;
data->P->n = 5;
data->P->nz = -1;
data->P->nzmax = 5;
data->P->x = (c_float*) c_malloc(5 * sizeof(c_float));
data->P->x[0] = 0.61702199999999995939;
data->P->x[1] = 0.92032449000000005057;
data->P->x[2] = 0.20011437000000001363;
data->P->x[3] = 0.50233256999999997827;
data->P->x[4] = 0.34675589000000001105;
data->P->i = (c_int*) c_malloc(5 * sizeof(c_int));
data->P->i[0] = 0;
data->P->i[1] = 1;
data->P->i[2] = 2;
data->P->i[3] = 3;
data->P->i[4] = 4;
data->P->p = (c_int*) c_malloc((5 + 1) * sizeof(c_int));
data->P->p[0] = 0;
data->P->p[1] = 1;
data->P->p[2] = 2;
data->P->p[3] = 3;
data->P->p[4] = 4;
data->P->p[5] = 5;

return data;

}

/* function to clean problem data structure */
void clean_problem_unconstrained(OSQPData * data){

// Clean vectors
c_free(data->l);
c_free(data->u);
c_free(data->q);

//Clean Matrices
c_free(data->A->x);
c_free(data->A->i);
c_free(data->A->p);
c_free(data->A);
c_free(data->P->x);
c_free(data->P->i);
c_free(data->P->p);
c_free(data->P);

c_free(data);

}

/* function to define solutions and additional data struct */
unconstrained_sols_data *  generate_problem_unconstrained_sols_data(){

unconstrained_sols_data * data = (unconstrained_sols_data *)c_malloc(sizeof(unconstrained_sols_data));

data->x_test = (c_float*) c_malloc(5 * sizeof(c_float));
data->x_test[0] = 1.79237541999999994147;
data->x_test[1] = 1.79775228000000009132;
data->x_test[2] = 11.81058885000000024945;
data->x_test[3] = -2.26014677999999991087;
data->x_test[4] = 2.93293975000000006759;
data->obj_value_test = -19.20975202681327687060;
data->status_test = OSQP_SOLVED;

return data;

}

/* function to clean solutions and additional data struct */
void clean_problem_unconstrained_sols_data(unconstrained_sols_data * data){

c_free(data->x_test);

c_free(data);

}

#endif
