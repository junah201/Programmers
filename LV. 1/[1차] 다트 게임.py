def solution(dartResult: str):
    start_idx = []
    idx: int = 0
    length = len(dartResult)
    while idx < length:
        if dartResult[idx].isdigit():
            start_idx.append(idx)
        if idx + 1 < length and dartResult[idx] == '1' and dartResult[idx + 1] == '0':
            idx += 1
        idx += 1

    game_idx: list = [None, None, None]
    game_idx[0] = (start_idx[0], start_idx[1] - 1)
    game_idx[1] = (start_idx[1], start_idx[2] - 1)
    game_idx[2] = (start_idx[2], length - 1)

    info = [
        {
            "S": 0,
            "B": None,
            "O": None
        } for _ in range(3)
    ]

    for idx, game in enumerate(game_idx):
        for i in range(game[0], game[1] + 1):
            if dartResult[i].isdigit():
                info[idx]["S"] = info[idx]["S"] * 10 + int(dartResult[i])
            elif dartResult[i] in set(['S', 'D', 'T']):
                info[idx]["B"] = dartResult[i]
            elif dartResult[i] in set(['*', '#']):
                info[idx]["O"] = dartResult[i]

    game_result: list = []

    for i in info:
        tmp: int = i['S']

        if i['B'] == 'S':
            pass
        elif i['B'] == 'D':
            tmp = tmp ** 2
        elif i['B'] == 'T':
            tmp = tmp ** 3

        game_result.append(tmp)

    for idx in range(len(game_result)):
        if info[idx]["O"] == None:
            continue
        elif info[idx]["O"] == "*":
            for i in range(max(0, idx - 1), idx + 1):
                game_result[i] *= 2
        elif info[idx]["O"] == "#":
            game_result[idx] *= -1

    return sum(game_result)


print(solution(input()))
