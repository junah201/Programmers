def solution(s):
    P = 0
    Y = 0

    for i in list(s):
        if i == 'p' or i == 'P':
            P += 1
        elif i == 'Y' or i == 'y':
            Y += 1

    return P == Y
