def solution(s):
    answer = ''
    idx = 0
    for letter in list(s):
        if letter == " ":
            answer += letter
            idx = 0
        else:
            if idx == 0:
                answer += letter.upper()
            else:
                answer += letter.lower()
            idx += 1

    return answer
