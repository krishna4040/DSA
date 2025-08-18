from typing import List


def snake_traversal(mat, R, C):
    for row in range(R):
        if row & 1:
            for col in range(C - 1, -1, -1):
                print(mat[row][col])
        else:
            for col in range(C):
                print(mat[row][col])


def boundary(mat, R, C):
    if R == 1:
        for i in range(C):
            print(mat[0][i], end=" ")
    elif C == 1:
        for i in range(R):
            print(mat[i][0], end=" ")
    else:
        for i in range(C):
            print(mat[0][i], end=" ")

        for i in range(1, R):
            print(mat[i][C - 1], end=" ")

        for i in range(C - 2, -1, -1):
            print(mat[R - 1][i], end=" ")

        for i in range(R - 2, 0, -1):
            print(mat[i][0], end=" ")


def spiralOrder(matrix: List[List[int]]) -> List[int]:
    res = []
    if not matrix:
        return res

    top, bottom = 0, len(matrix) - 1
    left, right = 0, len(matrix[0]) - 1

    while top <= bottom and left <= right:
        # 1. Traverse left → right
        for col in range(left, right + 1):
            res.append(matrix[top][col])
        top += 1

        # 2. Traverse top → bottom
        for row in range(top, bottom + 1):
            res.append(matrix[row][right])
        right -= 1

        # 3. Traverse right → left (check if row still valid)
        if top <= bottom:
            for col in range(right, left - 1, -1):
                res.append(matrix[bottom][col])
            bottom -= 1

        # 4. Traverse bottom → top (check if col still valid)
        if left <= right:
            for row in range(bottom, top - 1, -1):
                res.append(matrix[row][left])
            left += 1

    return res
