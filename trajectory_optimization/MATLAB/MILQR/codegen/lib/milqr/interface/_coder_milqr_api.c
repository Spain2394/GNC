/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_milqr_api.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 16-Apr-2020 13:51:41
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_milqr_api.h"
#include "_coder_milqr_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "milqr",                             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[7000]);
static const mxArray *b_emlrt_marshallOut(const real32_T u[2997]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xg, const
  char_T *identifier, real32_T y[7]);
static const mxArray *c_emlrt_marshallOut(const real32_T u[17982]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[7]);
static const mxArray *d_emlrt_marshallOut(const boolean_T u);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u0, const
  char_T *identifier, real32_T y[2997]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x0, const
  char_T *identifier, real32_T y[7000]);
static const mxArray *emlrt_marshallOut(const real32_T u[7000]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[2997]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_lims,
  const char_T *identifier, real32_T y[6]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[6]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B_ECI, const
  char_T *identifier, real32_T y[3000]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3000]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[7000]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[7]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[2997]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[6]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3000]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[7000]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[7000])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[2997]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real32_T u[2997])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 3, 999 };

  real32_T *pData;
  int32_T i1;
  int32_T i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m1);
  i1 = 0;
  for (i = 0; i < 999; i++) {
    pData[i1] = u[3 * i];
    i1++;
    pData[i1] = u[1 + 3 * i];
    i1++;
    pData[i1] = u[2 + 3 * i];
    i1++;
  }

  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *xg
 *                const char_T *identifier
 *                real32_T y[7]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xg, const
  char_T *identifier, real32_T y[7])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(xg), &thisId, y);
  emlrtDestroyArray(&xg);
}

/*
 * Arguments    : const real32_T u[17982]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real32_T u[17982])
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv2[3] = { 3, 6, 999 };

  real32_T *pData;
  int32_T i2;
  int32_T i;
  int32_T b_i;
  int32_T i3;
  y = NULL;
  m2 = emlrtCreateNumericArray(3, iv2, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m2);
  i2 = 0;
  for (i = 0; i < 999; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      i3 = 3 * b_i + 18 * i;
      pData[i2] = u[i3];
      i2++;
      pData[i2] = u[i3 + 1];
      i2++;
      pData[i2] = u[i3 + 2];
      i2++;
    }
  }

  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[7]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[7])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const boolean_T u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m3;
  y = NULL;
  m3 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u0
 *                const char_T *identifier
 *                real32_T y[2997]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u0, const
  char_T *identifier, real32_T y[2997])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(u0), &thisId, y);
  emlrtDestroyArray(&u0);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *x0
 *                const char_T *identifier
 *                real32_T y[7000]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x0, const
  char_T *identifier, real32_T y[7000])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x0), &thisId, y);
  emlrtDestroyArray(&x0);
}

/*
 * Arguments    : const real32_T u[7000]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real32_T u[7000])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 7, 1000 };

  real32_T *pData;
  int32_T i0;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxSINGLE_CLASS, mxREAL);
  pData = (real32_T *)emlrtMxGetData(m0);
  i0 = 0;
  for (i = 0; i < 1000; i++) {
    for (b_i = 0; b_i < 7; b_i++) {
      pData[i0] = u[b_i + 7 * i];
      i0++;
    }
  }

  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[2997]
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[2997])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u_lims
 *                const char_T *identifier
 *                real32_T y[6]
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_lims,
  const char_T *identifier, real32_T y[6])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(u_lims), &thisId, y);
  emlrtDestroyArray(&u_lims);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[6]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[6])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *B_ECI
 *                const char_T *identifier
 *                real32_T y[3000]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B_ECI, const
  char_T *identifier, real32_T y[3000])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(B_ECI), &thisId, y);
  emlrtDestroyArray(&B_ECI);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[3000]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3000])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[7000]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[7000])
{
  static const int32_T dims[2] = { 7, 1000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[7]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[7])
{
  static const int32_T dims[1] = { 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 1U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[2997]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[2997])
{
  static const int32_T dims[2] = { 3, 999 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[6]
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[6])
{
  static const int32_T dims[2] = { 3, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[3000]
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3000])
{
  static const int32_T dims[2] = { 3, 1000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void milqr_api(const mxArray * const prhs[5], int32_T nlhs, const mxArray *plhs
               [4])
{
  static real32_T x0[7000];
  real32_T xg[7];
  static real32_T u0[2997];
  real32_T u_lims[6];
  static real32_T B_ECI[3000];
  static real32_T x[7000];
  real32_T u[2997];
  static real32_T K[17982];
  boolean_T result;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x0", x0);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "xg", xg);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "u0", u0);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "u_lims", u_lims);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "B_ECI", B_ECI);

  /* Invoke the target function */
  milqr(x0, xg, u0, u_lims, B_ECI, x, u, K, &result);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(x);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(u);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(K);
  }

  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(result);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void milqr_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  milqr_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void milqr_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void milqr_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_milqr_api.c
 *
 * [EOF]
 */