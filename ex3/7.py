from urllib.request import urlopen
from bs4 import BeautifulSoup

url = "https://en.wikipedia.org/wiki/Python"
response = urlopen(url)
html = response.read()
soup = BeautifulSoup(html, 'html.parser')

links = soup.find_all('a', href=True)
for link in links:
    print(link['href'])
