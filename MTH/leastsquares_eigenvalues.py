# lstsq_eigs.py
import numpy as np
from scipy import linalg as la
from matplotlib import pyplot as plt


# Problem 1
def least_squares(A, b):
    """Calculate the least squares solutions to Ax = b by using the QR
    decomposition.
    Parameters:
        A ((m,n) ndarray): A matrix of rank n <= m.
        b ((m, ) ndarray): A vector of length m.
    Returns:
        x ((n, ) ndarray): The solution to the normal equations.
    """
    Q, R = la.qr(A, mode='economic')
    qT = np.transpose(Q)
    qTb = np.matmul(qT, b)
    return la.solve(R, qTb)

    raise NotImplementedError("Problem 1 Incomplete")

# Problem 2
def line_fit():
    """Find the least squares line that relates the year to the housing price
    index for the data in housing.npy. Plot both the data points and the least
    squares line.
    """
    hdata = np.load('housing.npy')
    A = np.ones((33, 2))
    b = np.zeros((33, 1))
    for i in range(0, 33):
        A[i, 0] = hdata[i, 0]
        b[i] = hdata[i, 1]
    hsol = least_squares(A, b)
    x = np.zeros((33, 1))
    for i in range(0, 33):
        x[i] = A[i, 0]
    y = hsol[0]*x + hsol[1]
    plt.plot(x, b, '.', color = 'red')
    plt.plot(x, y, color = 'black')
    plt.show()
    return 0



# Problem 3
def polynomial_fit():
    """Find the least squares polynomials of degree 3, 6, 9, and 12 that relate
    the year to the housing price index for the data in housing.npy. Plot both
    the data points and the least squares polynomials in individual subplots.
    """
    hdata = np.load('housing.npy')
    A = np.zeros((33))
    b = np.zeros((33))
    s = np.zeros((33))
    for i in range(0, 33):
        A[i] = hdata[i, 0]
        b[i] = hdata[i, 1]
        s[i] = hdata[i, 0]
    x = la.lstsq(np.vander(A, 4), b)[0]
    n = np.linspace(0, 16, 33)
    y = x[0]*pow(n,3) + x[1]*pow(n, 2) + x[2]*pow(n,1) + x[3]*pow(n,0)
    ax1 = plt.subplot(221)
    ax1.plot(n, y)
    ax1.plot(s, b, '.', color = 'red')
    x6 = la.lstsq(np.vander(A, 7), b)[0]
    y6 = x6[0]*pow(n, 6)+x6[1]*pow(n, 5)+x6[2]*pow(n,4)+x6[3]*pow(n,3)+x6[4]*pow(n,2) + x6[5]*pow(n,1) + x6[6]*pow(n,0)
    ax2 = plt.subplot(222)
    ax2.plot(n, y6)
    ax2.plot(s, b, '.', color = 'red')
    x9 = la.lstsq(np.vander(A, 10), b)[0]
    y9 = np.zeros((33))
    for i in range(0, 10):
        y9 += x9[i]*pow(n, 9-i)
    ax3 = plt.subplot(223)
    ax3.plot(n, y9)
    ax3.plot(s, b, '.', color = 'red')
    
    x12 = la.lstsq(np.vander(A, 13), b)[0]
    y12 = np.zeros((33))
    for i in range(0, 13):
        y12 += x12[i]*pow(n, 12-i)
    ax4 = plt.subplot(224)
    ax4.plot(n, y12)
    ax4.plot(s, b, '.', color = 'red')
    plt.show()
    return 0
 

def plot_ellipse(a, b, c, d, e):
    """Plot an ellipse of the form ax^2 + bx + cxy + dy + ey^2 = 1."""
    theta = np.linspace(0, 2*np.pi, 200)
    cos_t, sin_t = np.cos(theta), np.sin(theta)
    A = a*(cos_t**2) + c*cos_t*sin_t + e*(sin_t**2)
    B = b*cos_t + d*sin_t
    r = (-B + np.sqrt(B**2 + 4*A)) / (2*A)

    plt.plot(r*cos_t, r*sin_t)
    plt.gca().set_aspect("equal", "datalim")
