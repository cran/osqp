#ifndef SOLVE_LINSYS_DATA_H
#define SOLVE_LINSYS_DATA_H
#include "osqp.h"


/* create data and solutions structure */
typedef struct {
c_int test_solve_KKT_n;
c_int test_solve_KKT_m;
csc * test_solve_KKT_A;
csc * test_solve_KKT_Pu;
c_float test_solve_KKT_rho;
c_float test_solve_KKT_sigma;
csc * test_solve_KKT_KKT;
c_float * test_solve_KKT_rhs;
c_float * test_solve_KKT_x;
} solve_linsys_sols_data;

/* function prototypes */
solve_linsys_sols_data *  generate_problem_solve_linsys_sols_data();
void clean_problem_solve_linsys_sols_data(solve_linsys_sols_data * data);


/* function to define problem data */
solve_linsys_sols_data *  generate_problem_solve_linsys_sols_data(){

solve_linsys_sols_data * data = (solve_linsys_sols_data *)c_malloc(sizeof(solve_linsys_sols_data));

data->test_solve_KKT_n = 3;
data->test_solve_KKT_m = 4;

// Matrix test_solve_KKT_A
//------------------------
data->test_solve_KKT_A = (csc*) c_malloc(sizeof(csc));
data->test_solve_KKT_A->m = 4;
data->test_solve_KKT_A->n = 3;
data->test_solve_KKT_A->nz = -1;
data->test_solve_KKT_A->nzmax = 5;
data->test_solve_KKT_A->x = (c_float*) c_malloc(5 * sizeof(c_float));
data->test_solve_KKT_A->x[0] = 0.40730783228994515976;
data->test_solve_KKT_A->x[1] = 0.54620731990215798390;
data->test_solve_KKT_A->x[2] = 0.29701835710768775822;
data->test_solve_KKT_A->x[3] = 0.96963240582679277590;
data->test_solve_KKT_A->x[4] = 0.17698462366793654699;
data->test_solve_KKT_A->i = (c_int*) c_malloc(5 * sizeof(c_int));
data->test_solve_KKT_A->i[0] = 0;
data->test_solve_KKT_A->i[1] = 1;
data->test_solve_KKT_A->i[2] = 2;
data->test_solve_KKT_A->i[3] = 2;
data->test_solve_KKT_A->i[4] = 0;
data->test_solve_KKT_A->p = (c_int*) c_malloc((3 + 1) * sizeof(c_int));
data->test_solve_KKT_A->p[0] = 0;
data->test_solve_KKT_A->p[1] = 3;
data->test_solve_KKT_A->p[2] = 4;
data->test_solve_KKT_A->p[3] = 5;


// Matrix test_solve_KKT_Pu
//-------------------------
data->test_solve_KKT_Pu = (csc*) c_malloc(sizeof(csc));
data->test_solve_KKT_Pu->m = 3;
data->test_solve_KKT_Pu->n = 3;
data->test_solve_KKT_Pu->nz = -1;
data->test_solve_KKT_Pu->nzmax = 4;
data->test_solve_KKT_Pu->x = (c_float*) c_malloc(4 * sizeof(c_float));
data->test_solve_KKT_Pu->x[0] = 0.38349652976488485256;
data->test_solve_KKT_Pu->x[1] = 0.15100215738121633424;
data->test_solve_KKT_Pu->x[2] = 0.06132391965054660721;
data->test_solve_KKT_Pu->x[3] = 0.08979292345498494921;
data->test_solve_KKT_Pu->i = (c_int*) c_malloc(4 * sizeof(c_int));
data->test_solve_KKT_Pu->i[0] = 0;
data->test_solve_KKT_Pu->i[1] = 1;
data->test_solve_KKT_Pu->i[2] = 1;
data->test_solve_KKT_Pu->i[3] = 2;
data->test_solve_KKT_Pu->p = (c_int*) c_malloc((3 + 1) * sizeof(c_int));
data->test_solve_KKT_Pu->p[0] = 0;
data->test_solve_KKT_Pu->p[1] = 1;
data->test_solve_KKT_Pu->p[2] = 2;
data->test_solve_KKT_Pu->p[3] = 4;

data->test_solve_KKT_rho = 4.00000000000000000000;
data->test_solve_KKT_sigma = 1.00000000000000000000;

// Matrix test_solve_KKT_KKT
//--------------------------
data->test_solve_KKT_KKT = (csc*) c_malloc(sizeof(csc));
data->test_solve_KKT_KKT->m = 7;
data->test_solve_KKT_KKT->n = 7;
data->test_solve_KKT_KKT->nz = -1;
data->test_solve_KKT_KKT->nzmax = 19;
data->test_solve_KKT_KKT->x = (c_float*) c_malloc(19 * sizeof(c_float));
data->test_solve_KKT_KKT->x[0] = 1.38349652976488490808;
data->test_solve_KKT_KKT->x[1] = 0.40730783228994515976;
data->test_solve_KKT_KKT->x[2] = 0.54620731990215798390;
data->test_solve_KKT_KKT->x[3] = 0.29701835710768775822;
data->test_solve_KKT_KKT->x[4] = 1.15100215738121636200;
data->test_solve_KKT_KKT->x[5] = 0.06132391965054660721;
data->test_solve_KKT_KKT->x[6] = 0.96963240582679277590;
data->test_solve_KKT_KKT->x[7] = 0.06132391965054660721;
data->test_solve_KKT_KKT->x[8] = 1.08979292345498501859;
data->test_solve_KKT_KKT->x[9] = 0.17698462366793654699;
data->test_solve_KKT_KKT->x[10] = 0.40730783228994515976;
data->test_solve_KKT_KKT->x[11] = 0.17698462366793654699;
data->test_solve_KKT_KKT->x[12] = -0.25000000000000000000;
data->test_solve_KKT_KKT->x[13] = 0.54620731990215798390;
data->test_solve_KKT_KKT->x[14] = -0.25000000000000000000;
data->test_solve_KKT_KKT->x[15] = 0.29701835710768775822;
data->test_solve_KKT_KKT->x[16] = 0.96963240582679277590;
data->test_solve_KKT_KKT->x[17] = -0.25000000000000000000;
data->test_solve_KKT_KKT->x[18] = -0.25000000000000000000;
data->test_solve_KKT_KKT->i = (c_int*) c_malloc(19 * sizeof(c_int));
data->test_solve_KKT_KKT->i[0] = 0;
data->test_solve_KKT_KKT->i[1] = 3;
data->test_solve_KKT_KKT->i[2] = 4;
data->test_solve_KKT_KKT->i[3] = 5;
data->test_solve_KKT_KKT->i[4] = 1;
data->test_solve_KKT_KKT->i[5] = 2;
data->test_solve_KKT_KKT->i[6] = 5;
data->test_solve_KKT_KKT->i[7] = 1;
data->test_solve_KKT_KKT->i[8] = 2;
data->test_solve_KKT_KKT->i[9] = 3;
data->test_solve_KKT_KKT->i[10] = 0;
data->test_solve_KKT_KKT->i[11] = 2;
data->test_solve_KKT_KKT->i[12] = 3;
data->test_solve_KKT_KKT->i[13] = 0;
data->test_solve_KKT_KKT->i[14] = 4;
data->test_solve_KKT_KKT->i[15] = 0;
data->test_solve_KKT_KKT->i[16] = 1;
data->test_solve_KKT_KKT->i[17] = 5;
data->test_solve_KKT_KKT->i[18] = 6;
data->test_solve_KKT_KKT->p = (c_int*) c_malloc((7 + 1) * sizeof(c_int));
data->test_solve_KKT_KKT->p[0] = 0;
data->test_solve_KKT_KKT->p[1] = 4;
data->test_solve_KKT_KKT->p[2] = 7;
data->test_solve_KKT_KKT->p[3] = 10;
data->test_solve_KKT_KKT->p[4] = 13;
data->test_solve_KKT_KKT->p[5] = 15;
data->test_solve_KKT_KKT->p[6] = 18;
data->test_solve_KKT_KKT->p[7] = 19;

data->test_solve_KKT_rhs = (c_float*) c_malloc(7 * sizeof(c_float));
data->test_solve_KKT_rhs[0] = -0.63399257171184431048;
data->test_solve_KKT_rhs[1] = -0.35040972742971709941;
data->test_solve_KKT_rhs[2] = -0.02410800044866062697;
data->test_solve_KKT_rhs[3] = -1.34371499037447983405;
data->test_solve_KKT_rhs[4] = -1.45546731605839774204;
data->test_solve_KKT_rhs[5] = 0.34410890511674868675;
data->test_solve_KKT_rhs[6] = 0.42486953514052661074;
data->test_solve_KKT_x = (c_float*) c_malloc(7 * sizeof(c_float));
data->test_solve_KKT_x[0] = -1.71780105107436642520;
data->test_solve_KKT_x[1] = 0.60858861958156984517;
data->test_solve_KKT_x[2] = -0.42578886161429124746;
data->test_solve_KKT_x[3] = -0.77503190385329412404;
data->test_solve_KKT_x[4] = -0.93827550823243910383;
data->test_solve_KKT_x[5] = 0.07988880133571663045;
data->test_solve_KKT_x[6] = 0.00000000000000000000;

return data;

}

/* function to clean data struct */
void clean_problem_solve_linsys_sols_data(solve_linsys_sols_data * data){

c_free(data->test_solve_KKT_A->x);
c_free(data->test_solve_KKT_A->i);
c_free(data->test_solve_KKT_A->p);
c_free(data->test_solve_KKT_A);
c_free(data->test_solve_KKT_Pu->x);
c_free(data->test_solve_KKT_Pu->i);
c_free(data->test_solve_KKT_Pu->p);
c_free(data->test_solve_KKT_Pu);
c_free(data->test_solve_KKT_KKT->x);
c_free(data->test_solve_KKT_KKT->i);
c_free(data->test_solve_KKT_KKT->p);
c_free(data->test_solve_KKT_KKT);
c_free(data->test_solve_KKT_rhs);
c_free(data->test_solve_KKT_x);

c_free(data);

}

#endif
