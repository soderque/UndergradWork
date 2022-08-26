# cvxpy_intro.py
import cvxpy as cp
import numpy as np

def prob1():
    """Solve the following convex optimization problem:
    minimize        2x + y + 3z
    subject to      x  + 2y         <= 3
                         y   - 4z   <= 1
                    2x + 10y + 3z   >= 12
                    x               >= 0
                          y         >= 0
                                z   >= 0
    Returns (in order):
        The optimizer x (ndarray)
        The optimal value (float)
    """
    
    #initializing objective
    x = cp.Variable(3, nonneg = True)
    c = np.array([2, 1, 3])
    obj = cp.Minimize(c.T @ x)
    
    #Constraints
    A = np.array([1, 2, 0])
    R = np.array([0, 1, -4])
    G = np.array([2, 10, 3])
    H = np.eye(3)
    const = [A @ x <= 3]
    const.append(R @ x <= 1)
    const.append(G @ x >= 12)
    const.append(H @ x >= 0)
    
    #Assemble and Solve!
    prob = cp.Problem(obj, const)
    prob.solve()
    return x.value, prob.solve()

# Problem 2
def l1Min(A, b):
    """Calculate the solution to the optimization problem
        minimize    ||x||_1
        subject to  Ax = b
    Parameters:
        A ((m,n) ndarray)
        b ((m, ) ndarray)
    Returns:
        The optimizer x (ndarray)
        The optimal value (float)
    """
    #initialize objective based on matrix shape
    (m, n) = np.shape(A)
    x = cp.Variable(n, nonneg = True)
    lnorm = cp.norm(x,1)
    obj = cp.Minimize(lnorm)
    P = np.eye(n)
    
    #set constraints
    const = []
    for i in np.arange(0, m):
        const.append(A[i] @ x == b[i])
    const.append(P @ x >= 0)
    #assemble, solve
    prob = cp.Problem(obj, const)
    prob.solve()
    return x.value, prob.solve()

# Problem 3
def prob3():
    """Solve the transportation problem by converting the last equality constraint
    into inequality constraints.
    Returns (in order):
        The optimizer x (ndarray)
        The optimal value (float)
    """
    #The mega matrix
    A = np.array([[1, 1, 0, 0, 0, 0], [0, 0, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1], [1, 0, 1, 0, 1, 0], [0, 1, 0, 1, 0, 1]])
    b = np.array([7, 2, 4, 5, 8])
    
    #initializing objective
    c = np.array([4, 7, 6, 8, 8, 9])
    x = cp.Variable(6, nonneg = True)
    obj = cp.Minimize(c.T @ x)
    
    #set constraints
    const = [A @ x == b]
    
    #assemble and solve
    prob = cp.Problem(obj, const)
    prob.solve()
    return x.value, prob.solve()
    

# Problem 4
def prob4():
    """Find the minimizer and minimum of
    g(x,y,z) = (3/2)x^2 + 2xy + xz + 2y^2 + 2yz + (3/2)z^2 + 3x + z()
     Returns (in order):
        The optimizer x (ndarray)
        The optimal value (float)
    """
    #megamatrix 2.0
    Q = np.array([[3, 2, 1], [2, 4, 2], [1, 2, 3]])
    r = np.array([3, 0, 1])
    x = cp.Variable(3)
    
    #set the problem
    Qr = .5*cp.quad_form(x, Q) + r.T@x
    prob = cp.Problem(cp.Minimize(Qr))
    prob.solve()
    return x.value, prob.solve()
    
# Problem 5
def prob5(A, b):
    """Calculate the solution to the optimization problem
        minimize    ||Ax - b||_2
        subject to  ||x||_1 == 1
                    x >= 0
    Parameters:
        A ((m,n), ndarray)
        b ((m,), ndarray)
        
    Returns (in order):
        The optimizer x (ndarray)
        The optimal value (float)
    """
    (m, n) = np.shape(A)
    x = cp.Variable(n, nonneg = True)
    #finding the norm
    PN = cp.pnorm(A@x -b, 2)
    obj = cp.Minimize(PN)
    
    #forming constraints
    a = sum(x)
    constr = [a == 1]
    
    #solve and return
    prob = cp.Problem(obj, constr)
    prob.solve()
    return x.value, prob.solve()
