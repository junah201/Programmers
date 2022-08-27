cacheCities = []


def updateCache(city: str, cacheSize: int, is_exist: bool):
    global cacheCities

    if cacheSize == 0:
        return

    elif is_exist:
        cacheCities.pop(cacheCities.index(city))
    elif len(cacheCities) == cacheSize:
        cacheCities.pop(0)

    cacheCities.append(city)


def solution(cacheSize, cities):
    answer = 0

    for city in cities:
        city = city.upper()
        if city in cacheCities:
            answer += 1
            updateCache(city, cacheSize, True)
        else:
            answer += 5
            updateCache(city, cacheSize, False)

    return answer
