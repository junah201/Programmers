def solution(numbers, target):
    global ans
    ans = 0

    def dfs(idx: int, sum: int):
        global ans
        if idx == len(numbers):
            if sum == target:
                ans += 1
            return

        dfs(idx + 1, sum + numbers[idx])
        dfs(idx + 1, sum - numbers[idx])

    dfs(0, 0)

    return ans
