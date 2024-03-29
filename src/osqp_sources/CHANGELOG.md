Version 0.6.3 (25 May 2023)
------------------------------
* Fix MKL function prototypes (required for CRAN compilation) (PR [#487](https://github.com/osqp/osqp/pull/487))
* Use a constant interval for adaptive rho when in embedded=2 mode (PR [#347](https://github.com/osqp/osqp/pull/347))
* Include version.h in the OSQP installed headers (Fixes [#323](https://github.com/osqp/osqp/issues/323))
* Switch unit testing to use Catch2
* Switch to GitHub actions CI system
* Switched binary distribution from bintray to GitHub releases
* Various documentation fixes and improvements


Version 0.6.2 (6 January 2021)
------------------------------
* Fix segfault python multithreading
* Compatibility python 3.9
* Updated QDLDL to version 0.1.5
* Drop Python 2.7 support



Version 0.6.0 (30 August 2019)
------------------------------
* Added meaningful return values to internal functions. Changed syntax of `osqp_setup` function. It now returns an exitflag.
* `osqp_setup` function requires `P` to be upper triangular. It returns a nonzero exitflag otherwise.
* Custom memory allocators via cmake and the configure file.
* Changed interfaces to linsys solver functions. The solve function now computes `(x_tilde,z_tilde)` instead of `(x_tilde,nu)`. This allows to implement custom linear system solvers (also indirect).
* Added `solve` function in Python interface that performs `setup` `solve` and `cleanup` for you directly and disables GIL.
* Improved code generation folder structure.


Version 0.5.0 (10 December 2018)
----------------
* Added `update_time` to the info structure.
* Fixed [#101](https://github.com/osqp/osqp/issues/101).


Version 0.4.1 (25 September 2018)
---------------------------------
* Updated QDLDL to version 0.1.3.
* Added check for nonconvex cost function (non-positive semidefinite `P`) after factorization is performed.
* Added complete sources distribution on bintray.com (including QDLDL).


Version 0.4.0 (23 July 2018)
----------------------------
* Added check for nonconvex cost function (non-positive semidefinite `P`).
* Removed SuiteSparse LDL in favor of [QDLDL](https://github.com/osqp/qdldl).
* Static library `libosqpstatic` now renamed as `libosqp`.


Version 0.3.1 (10 June 2018)
----------------------------
* Fixed [#62](https://github.com/osqp/osqp/issues/62).
* Moved interfaces to separate repositories
* Fixed [#54](https://github.com/osqp/osqp/issues/54).
* Changes to support Matlab 2018a
* Added support for new interface in R

Version 0.3.0 (5 March 2018)
----------------------------
* Added `time_limit` option
* Added CUTEst interface
* Fixed bug in upper triangular `P` extraction. Now the solver can accept both complete `P` matrix or just the upper triangular part.
* Fixed [#33](https://github.com/osqp/osqp/issues/33)
* Fixed [#34](https://github.com/osqp/osqp/issues/34)
* Allow `eps_rel=0` [#40](https://github.com/osqp/osqp/issues/40)
* Fixed bug when calling `osqp_solve` or `osqp_cleanup` after failed linear system initialization
* Add "install" CMake target and installation of CMake configuration files
* Fixed potential name conflict with SCS [47](https://github.com/osqp/osqp/issues/47)
* Changed `set_default_settings` to `osqp_set_default_settings` and brought function to main API header `osqp.h`
* Fixed [#49](https://github.com/osqp/osqp/issues/49)


Version 0.2.1 (25 November 2017)
---------------------------------
* Fixed problem with code generation and pypi `data_files` (everything now in [MANIFEST.in](https://github.com/pypa/sampleproject/issues/30))


Version 0.2.0 (23 November 2017)
---------------------------------
*   Added adaptive rho -> Much more reliable convergence!
*   Simplified several settings
    *  "early_terminate" and "early_terminate_interval" -> "check_termination"
    *  "scaling_iter" removed and put inside "scaling" parameter
*   Julia interface [OSQP.jl](https://github.com/osqp/OSQP.jl)
*   Shared libraries available on bintray.com
*   Added inaccurate return statuses
*   Added new object-oriented structure for linear system solvers
*   Added MKL Pardiso interface using shared dynamic library loader
*   Added diagonal rho vector with different values for equality/inequality constraints (interface still have scalar rho)
*   Return certificates of infeasibility in results structure
*   Now code generation produces a static library


Version 0.1.3 (21 September 2017)
---------------------------------
* Fixed sources distribution on Python


Version 0.1.2 (20 July 2017)
------------------------------
*   Added option to terminate with scaled or unscaled residual
*   Now Matlab interface does support logical entries for the settings
*   Fixed bug in index ordering of sparse matrices of Python interface
*   Changed 2-norms to inf-norms
*   Fixed code generation bug when scaling is disabled [#7](https://github.com/osqp/osqp/issues/7)
*   Removed warnings in code-generation for standard <= C99
*   Fixed MATLAB 2015b compatibility [#6](https://github.com/osqp/osqp/issues/6)


Version 0.1.1 (11 April 2017)
-----------------------------
*   Fixed crashes during polishing when factorization fails
*   Added package to Pypi
*   Fixed relative paths Matlab


Version 0.1.0 (10 April 2017)
-----------------------------
*   Linux, Mac and Windows
*   Interface to Python 2.7, 3.5+
*   Interface to Matlab 2015b+
*   Embedded code generation
