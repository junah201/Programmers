def solution(citations):
    ans = 0
    citations.sort(reverse=True)

    for i in range(len(citations)):
        if i + 1 <= citations[i]:
            ans = i + 1
        if i + 1 > citations[i]:
            break
    return ans
