with open('c:\\Users\\Home\\Documents\\dataset_3363_3.txt', 'r') as fin:
    element = ''
    count = 0
    for line in fin:
        line = line.strip().lower().split()
        for i in set(line):
            cnti = line.count(i)
            if cnti > count:
                count = cnti
                element = i
            elif cnti == count:
                if i < element:
                    element = i

    with open('c:\\Users\\Home\\Documents\\output.txt', 'w') as fout:
        fout.write(element)
        fout.write(str(count))



