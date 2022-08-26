#drazin.py
import numpy as np
from scipy import linalg as la


# Helper function for problems 1 and 2.
def index(A, tol=1e-5):
    """Compute the index of the matrix A.
    Parameters:
        A ((n,n) ndarray): An nxn matrix.
    Returns:
        k (int): The index of A.
    """

    # test for non-singularity
    if not np.isclose(la.det(A), 0):
        return 0

    n = len(A)
    k = 1
    Ak = A.copy()
    while k <= n:
        r1 = np.linalg.matrix_rank(Ak)
        r2 = np.linalg.matrix_rank(np.dot(A,Ak))
        if r1 == r2:
            return k
        Ak = np.dot(A,Ak)
        k += 1

    return k

# Problem 1
def is_drazin(A, Ad, k):
    """Verify that a matrix Ad is the Drazin inverse of A.
    Parameters:
        A ((n,n) ndarray): An nxn matrix.
        Ad ((n,n) ndarray): A candidate for the Drazin inverse of A.
        k (int): The index of A.
    Returns:
        (bool) True of Ad is the Drazin inverse of A, False otherwise.
    """
    if(np.allclose(np.matmul(A, Ad), (np.matmul(Ad, A)))):
        if(np.allclose(np.matmul(np.linalg.matrix_power(A, k+1),Ad), (np.linalg.matrix_power(A,k)))):
            if(np.allclose(np.matmul(np.matmul(Ad, A), Ad), Ad)):
                return True
            else:
                return False
        else:
            return False
    else:
        return False
print(is_drazin(np.array([[1, 3, 0, 0],[0, 1, 3, 0], [0, 0, 1, 3], [0, 0, 0, 0]]),np.array([[1, -3, 9, 81],[0, 1, -3, -18],[0, 0, 1, 3], [0, 0, 0, 0]]),1))

# Problem 2
def drazin_inverse(A, tol=1e-4):
    """Compute the Drazin inverse of A.
    Parameters:
        A ((n,n) ndarray): An nxn matrix.
    Returns:
       ((n,n) ndarray) The Drazin inverse of A.
    """
    (n, n) = np.shape(A)
    U = np.zeros((n, n))
                                                    #Change of basis Z.
    Z = np.zeros((n, n))
                                                    #Sort e-values first.
    Evaluesfirst = lambda x: abs(x) > 0
    T1, Q1, k1 = la.schur(A, sort=Evaluesfirst)
    print(T1, Q1)
                                                    #Organizing M.
    M = np.zeros((k1, k1))
    for i in range(0, k1):
        M[i, i] = T1[i, i]
    for j in range(0, k1):
        for i in range(0, n):
                                                    #Setting k1 columns for U.
            U[i, j]=Q1[i, j]
    Evalueslast = lambda y: abs(y) <= 0
    T2, Q2, k2 = la.schur(A, sort=Evalueslast)
    print("                                      ", T2, "                                         ", Q2)
                                                    #Organizing N.
    N = np.zeros((n-k1, n-k1))
    for i in range(0, n-k1):
        N[i, i] = T2[i, i]
                                                    #Setting n-k1 columns for U starting at index k1.
    for j in range(0, n-k1):
        for i in range(0, n):
            U[i, j+k1]=Q2[i, j]
           # print(U)
    Minv = np.linalg.inv(M)
    for j in range(0, k1):
        for i in range(0, k1):
            Z[i,j] = Minv[i,j]
                                                    #Putting it all together...
    Ad = np.matmul(np.matmul(np.linalg.inv(U), Z), U)
    return Ad
    
print(drazin_inverse(np.array([[1, 1, 3], [5, 2, 6], [-2, -1, -3]])))
