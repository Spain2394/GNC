#include <iostream>
#include <cmath>
#include "../../eigen-git-mirror/Eigen/Dense"
#include "MEKF_functions.cpp"
#include <../../pybind11/include/pybind11/pybind11.h>
#include <../../pybind11/include/pybind11/eigen.h>
namespace py = pybind11;
using Eigen::MatrixXd;

MatrixXd get_xk(MatrixXd &xk, MatrixXd &Pk, MatrixXd w, MatrixXd rB, MatrixXd rN, MatrixXd W, MatrixXd V, double dt) {
/*
 * xk - state 7x1 (q,Beta)
 * Pk - covariance 6x6
 * w - measured body rate 3x1
 * rB - measured unit vectors, vertically stacked 6x1
 * rN - expected/modeled measurement unit vectors, vertically stacked 6x1
 * W - Process noise 6x6
 * V - Measurement noise 6x6
 * dt - time step (double)
 * xn - predicted state (mu_k+1|k)
 * Pn - predicted covariance (sigma_k+1|k)
 * A - linearized state transition matrix
 * W - process noise covariance
 * V - measurement noise covariance
 * rN - vector measurement in newtonian frame
 * rB - vector measurement in body frame
 * L - Kalman Gain
 */

        // predict step
        MatrixXd xn(7,1), A(6,6), Pn(6,6);
        predict(xk,Pk,w,dt,A,xn,Pn,W);

        // run measurement step
        MatrixXd y(6,1), R(3,3), C(6,6);
        measurement(xn(seq(0,3),0),rN,y,R,C);

        // run innovation step to find z
        MatrixXd z(6,1), S(6,6);
        Innovation(R, rN, rB, Pn, V, C, z, S);

        // find Kalman Gain
        MatrixXd L(6,6);
        L = Pn * C.transpose() * S.inverse();

        // update step
        update(L,z,xn,Pn,V,C,xk,Pk);
    return xk;
}

MatrixXd get_Pk(MatrixXd &xk, MatrixXd &Pk, MatrixXd w, MatrixXd rB, MatrixXd rN, MatrixXd W, MatrixXd V, double dt) {
 /* same as above, returning Pk instead of xk */
    // predict step
    MatrixXd xn(7,1), A(6,6), Pn(6,6);
    predict(xk,Pk,w,dt,A,xn,Pn,W);

    // run measurement step
    MatrixXd y(6,1), R(3,3), C(6,6);
    measurement(xn(seq(0,3),0),rN,y,R,C);

    // run innovation step to find z
    MatrixXd z(6,1), S(6,6);
    Innovation(R, rN, rB, Pn, V, C, z, S);

    // find Kalman Gain
    MatrixXd L(6,6);
    L = Pn * C.transpose() * S.inverse();

    // update step
    update(L,z,xn,Pn,V,C,xk,Pk);
    return Pk;
}


PYBIND11_MODULE(MEKF_cpp, m) {
    m.doc() = "MEKF propagate step"; // optional module docstring
    m.def("get_xk", &get_xk, "Propagate MEKF forward one step and return xk");
    m.def("get_Pk", &get_Pk, "Propagate MEKF forward one step and return Pk");
}



