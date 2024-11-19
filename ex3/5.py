from urllib.request import urlopen
from bs4 import BeautifulSoup

url = "http://www.example.com/"
response = urlopen(url)
html = response.read()
soup = BeautifulSoup(html, 'html.parser')

h1_tag = soup.find('h1')
print(h1_tag.text if h1_tag else "h1 not found")