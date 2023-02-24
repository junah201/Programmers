def solution(n):
    inp = [[-1]*n for i in range(1, n+1)]

    """
    0 -1 -1 -1
    0  0 -1 -1
    0  0  0 -1
    0  0  0  0
    """

    max = 0
    for i in range(n):
        for j in range(i + 1):
            inp[i][j] = 0
            max += 1

    direction = "down"
    idx = 2
    inp[0][0] = 1
    x = 0
    y = 0

    while idx <= max:
        if direction == "down":
            if y == n-1 or inp[y+1][x] != 0:
                direction = "right"
                continue
            y += 1
        elif direction == "right":
            if x == n-1 or inp[y][x + 1] != 0:
                direction = "top"
                continue
            x += 1
        elif direction == "top":
            if x == 0 or inp[y - 1][x - 1] != 0:
                direction = "down"
                continue
            x -= 1
            y -= 1

        inp[y][x] = idx
        idx += 1

    ans = []
    # 	[1,2,9,3,10,8,4,5,6,7]
    for idx, value in enumerate(inp):
        ans.extend(inp[idx][:idx + 1])
    return ans
