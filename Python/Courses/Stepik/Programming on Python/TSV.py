stats = {i: [0, 0] for i in range(1, 12)}

with open('c:\\users\\home\\documents\\dataset_3380_5.txt', 'r') as fin, open('output.txt', 'w') as fout:
    for line in fin:
        line = line.strip().split()
        stats[int(line[0])][0] += int(line[2])
        stats[int(line[0])][1] += 1

    for i in range(1, 12):
        if stats[i][0] == 0:
            stats[i] = '-'
        else:
            stats[i][0] /= stats[i][1]
        fout.write(str(i))
        fout.write(' ')
        fout.write(str(stats[i][0]))
        fout.write('\n')
