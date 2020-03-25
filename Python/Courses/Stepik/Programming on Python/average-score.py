with open('C:\\users\\home\\documents\\dataset_3363_4.txt', 'r') as fin, open('c:\\users\\home\\documents\\output.txt', 'w') as fout:
    list_of_marks = []
    for line in fin:
        line = line.strip().split(';')
        marks = [int(line[i]) for i in range(1, 4)]
        average = sum(marks) / 3
        list_of_marks.append(marks)
        fout.write(str(average))
        fout.write('\n')


    av_math = 0
    av_physics = 0
    av_russian = 0
    for marks in list_of_marks:
        av_math += marks[0]
        av_physics += marks[1]
        av_russian += marks[2]

    length = len(list_of_marks)
    av_math /= length
    av_physics /= length
    av_russian /= length
    fout.write(str(av_math))
    fout.write(' ')
    fout.write(str(av_physics))
    fout.write(' ')
    fout.write(str(av_russian))