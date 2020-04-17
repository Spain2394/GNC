/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_milqr_mex.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 16-Apr-2020 13:51:41
 */

/* Include Files */
#include "_coder_milqr_api.h"
#include "_coder_milqr_mex.h"

/* Function Declarations */
static void milqr_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[5]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[4]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
static void milqr_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[5])
{
  const mxArray *outputs[4];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4, 5,
                        "milqr");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "milqr");
  }

  /* Call the function. */
  milqr_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(milqr_atexit);

  /* Module initialization. */
  milqr_initialize();

  /* Dispatch the entry-point. */
  milqr_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  milqr_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_milqr_mex.c
 *
 * [EOF]
 */