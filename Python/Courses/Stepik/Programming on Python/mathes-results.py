n = int(input())

info = {}

for i in range(n):
    result = input().split(';')
    team1 = result[0]
    team2 = result[2]
    score1 = result[1]
    score2 = result[3]
    loser = ''
    winner = ''

    if team1 not in info.keys():
        info[team1] = [0 for i in range(5)]
    if team2 not in info.keys():
        info[team2] = [0 for i in range(5)]

    if score1 == score2:
        winner = team1
        loser = team2
        info[winner][2] += 1
        info[loser][2] += 1
        info[winner][4] += 1
        info[loser][4] += 1
    else:
        if score1 > score2:
            winner = team1
            loser = team2
        elif score1 < score2:
            winner = team2
            loser = team1
        info[winner][1] += 1
        info[winner][4] += 3
        info[loser][3] += 1

    info[winner][0] += 1
    info[loser][0] += 1

for key, items in info.items():
    print(key + ':' + str(items[0]), *items[1:])
