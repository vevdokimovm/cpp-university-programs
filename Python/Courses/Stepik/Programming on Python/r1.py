from requests import get

url = 'https://stepic.org/media/attachments/course67/3.6.2/555.txt'
r = get(url)
text = r.text.strip().splitlines()
print(len(text))

