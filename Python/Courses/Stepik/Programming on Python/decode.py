import os

with open(os.path.join('C:\\', 'Users', 'Home', 'Documents', 'dataset_3363_2.txt'), 'r') as fin:

    string = fin.readline().strip()
    num = ''
    newstr = ''
    discharges = 0

    for i in range(len(string)):
        if '0' <= string[i] <= '9':
            num += string[i]
            discharges += 1
            if i == (len(string) -  1):
                newstr += string[i - discharges] * int(num)
        elif i != 0:
            newstr += string[i - discharges - 1] * int(num)
            num = ''
            discharges = 0

    with open('c:\\Users\\Home\\Documents\\output.txt', 'w') as fout:
        fout.write(newstr)
