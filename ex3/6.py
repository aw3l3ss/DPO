from urllib.request import urlopen
from bs4 import BeautifulSoup

url = "https://en.wikipedia.org/wiki/Main_Page"
response = urlopen(url)
html = response.read()
soup = BeautifulSoup(html, 'html.parser')

headers = soup.find_all(['h1', 'h2', 'h3', 'h4', 'h5', 'h6'])
for header in headers:
    print(header.name, header.text.strip())