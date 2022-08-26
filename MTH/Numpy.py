# numpy_intro.py
def prob5():
    """Define the matrices A, B, and C as arrays. Return the block matrix
                                | 0 A^T I |
                                | A  0  0 |,
                                | B  0  C |
    where I is the 3x3 identity matrix and each 0 is a matrix of all zeros
    of the appropriate size.
    """
    A = np.zeros((2,3))
    #I realize for this problem, something much simpler now: 
    #A = np.arange(6) then A = A.T Oh well!
    i=0
    while i<3:
        e=0
        while e<2:
            A[e, i]=2*i+e
            e+=1
        i+=1
    B = np.full((3,3),3)
    B = np.tril(B)
    C = -2*((np.diag([1, 1, 1])))
    megaA = np.hstack((np.diag(np.zeros(3)),A.T, np.eye(3)))
    megaB = np.hstack((A,np.diag(np.zeros(2)), np.zeros((2,3))))
    megaC = np.hstack((B, np.zeros((3,2)),C))
    final = np.vstack((megaA, megaB, megaC))
    return final



def prob6(A):
    """Divide each row of 'A' by the row sum and return the resulting array.
    Example:
        >>> A = np.array([[1,1,0],[0,1,0],[1,1,1]])
        >>> prob6(A)
        array([[ 0.5       ,  0.5       ,  0.        ],
               [ 0.        ,  1.        ,  0.        ],
               [ 0.33333333,  0.33333333,  0.33333333]])
    """
    B = np.copy(A)
    rowsum = B.sum(axis=1)
    return B/rowsum.reshape(len(B),1)

def prob7():
    """Given the array stored in grid.npy, return the greatest product of four
    adjacent numbers in the same direction (up, down, left, right, or
    diagonally) in the grid.
    """
