import requests

response = requests.get("https://python.org")

print("Status Code:", response.status_code)
print("Headers:", response.headers)
print("URL:", response.url)
print("History:", response.history)
print("Encoding:", response.encoding)
print("Reason:", response.reason)
print("Cookies:", response.cookies)
print("Elapsed Time:", response.elapsed)
print("Request:", response.request)
print("Content (first 500 characters):", response.content[:500].decode(response.encoding or 'utf-8', errors='replace'))
