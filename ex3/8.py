import requests

url = "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_month.csv"
response = requests.get(url)

if response.status_code == 200:
    data = response.text.splitlines()
    print(f"Количество строк: {len(data)}")
else:
    print("Не удалось загрузить CSV")
