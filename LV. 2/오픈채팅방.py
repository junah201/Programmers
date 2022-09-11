def solution(record):
    answer = []
    users = {}

    for cmd in record:
        tmp_cmd = cmd.split()

        if tmp_cmd[0] == "Enter" or tmp_cmd[0] == "Change":
            users[tmp_cmd[1]] = tmp_cmd[2]

    for cmd in record:
        tmp_cmd = cmd.split()

        if tmp_cmd[0] == "Enter":
            answer.append(f"{users[tmp_cmd[1]]}님이 들어왔습니다.")
        elif tmp_cmd[0] == "Leave":
            answer.append(f"{users[tmp_cmd[1]]}님이 나갔습니다.")

    return answer
