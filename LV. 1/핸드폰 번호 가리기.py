def solution(phone_number):
    return "".join(["*" for _ in [0]*(len(phone_number) - 4)]) + phone_number[-4:]
