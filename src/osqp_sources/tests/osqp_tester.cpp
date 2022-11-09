/* OSQP TESTER MODULE */

/* THE CODE FOR MINIMAL UNIT TESTING HAS BEEN TAKEN FROM
   http://www.jera.com/techinfo/jtns/jtn002.html */

#include <stdio.h>

#include "minunit.h"
#include "osqp.h"
#include "osqp_tester.h"

#include <RInside.h>

/* Make a copy of idxint vector to an int vector */
int * idxint2int(idxint *data, int len) {
  int *result = (int *) malloc(len * sizeof(int)); 
  for (int i = 0; i < len; i++) {
    result[i] = data[i];
  }
  return(result);
}

/* Make a copy of idxint vector to an int vector */
double * pfloat2double(pfloat *data, int len) {
  double *result = (double *) malloc(len * sizeof(double)); 
  for (int i = 0; i < len; i++) {
    result[i] = data[i];
  }
  return(result);
}

std::vector< double > dVec(pfloat *data, int len) {
  double * ddata = pfloat2double(data, len);
  std::vector< double > result;
  for (int i = 0; i < len; i++) result.push_back(ddata[i]);
  free(ddata);
  return(result);
}

std::vector< int > iVec(idxint *data, int len) {
  int * ddata = idxint2int(data, len);  
  std::vector< int > result;
  for (int i = 0; i < len; i++) result.push_back(ddata[i]);
  free(ddata);
  return(result);
}

#define DLEN(x) x? (int) (sizeof(x) / sizeof(pfloat)) : 0
#define ILEN(x) x? (int) (sizeof(x) / sizeof(idxint)) : 0


// Include tests
#include "lin_alg/test_lin_alg.h"
#include "solve_linsys/test_solve_linsys.h"
#include "demo/test_demo.h"
#include "basic_qp/test_basic_qp.h"
#include "basic_qp2/test_basic_qp2.h"
#include "non_cvx/test_non_cvx.h"
#include "primal_dual_infeasibility/test_primal_dual_infeasibility.h"
#include "primal_infeasibility/test_primal_infeasibility.h"
#include "unconstrained/test_unconstrained.h"
#include "update_matrices/test_update_matrices.h"


int tests_run = 0;


static const char* all_tests() {
  mu_run_test(test_lin_alg);
  mu_run_test(test_solve_linsys);
  mu_run_test(test_demo);
  mu_run_test(test_basic_qp);
  mu_run_test(test_basic_qp2);
  mu_run_test(test_non_cvx);
  mu_run_test(test_primal_infeasibility);
  mu_run_test(test_primal_dual_infeasibility);
  mu_run_test(test_unconstrained);
  mu_run_test(test_update_matrices);
  return 0;
}
i
int main(int argc, char* argv[]) {
  RInside R(argc, argv);

  const char *result = all_tests();

  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  printf("Size of pfloat %d\n", sizeof(pfloat));
  printf("Size of idxint %d\n", sizeof(idxint));
  printf("Size of long %d\n", sizeof(long));
  
  return result != 0;
}
