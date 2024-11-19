1. Напишите скрипт, который будет показывать найдена ли указанная в
скрипте веб-страница на сервере.

2. Проверьте есть ли у сайта SSL сертификат с использованием модуля
requests.

3. Выведете при помощи модуля requests блоки
Status Code, Headers, Url, History, Encoding, Reason, Cookies,
Elapsed, Request и Content с сайта https://python.org.

4. Выгрузите и выведете содержимое файла robots.txt с сайта
https://en.wikipedia.org/

5. Извлеките заголовок h1 из сайта http://www.example.com/

6. Извлеките и выведете на экран все header теги со страницы
https://en.wikipedia.org/wiki/Main_Page с помощью urlopen и
BeautifulSoup

7. Выгрузите страницу https://en.wikipedia.org/wiki/Python и
сформируйте список ссылок, которые есть на этой странице.
Например:
#mw-head
#p-search
https://en.wiktionary.org/wiki/Python
https://en.wiktionary.org/wiki/python
#Snakes
#Ancient_Greece
#Media_and_entertainment
#Computing
#Engineering
#Roller_coasters
#Vehicles
#Weaponry
#See_also
/w/index.php?title=Python&action=edit§ion=1
…

8. Выгрузите вот эту CSV:
http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_mont
h.csv и посчитайте кол-во строк в ней.

9. Суммируя весь предыдущий опыт напишите программу, которая будет
скрейпить данные из imdb. Рекомендуемые библиотеки:
BeautifulSoup, requests и random. Программа должна выполнять
следующий функционал:
a. При запуске программа должна подключаться к странице
https://www.imdb.com/chart/top;
b. Собирать список фильмов (и по вашему желанию их описание)
c. Выводить 10 случайных фильмов
Пример вывода:
--------------------------------------------
Lock, Stock and Two Smoking Barrels (1998)
A botched card game in London triggers four friends, thugs,
weed-growers, hard gangsters, loan sharks and debt collectors to
collide with each other in a series of unexpected events, all for
the sake of weed, cash and two antique shotguns.
--------------------------------------------
Wild Strawberries (1957)
After living a life marked by coldness, an aging professor is
forced to confront the emptiness of his existence.
--------------------------------------------
M (1931)
When the police in a German city are unable to catch a
child-murderer, other criminals join in the manhunt.
--------------------------------------------
The Seventh Seal (1957)
A man seeks answers about life, death, and the existence of God
as he plays chess against the Grim Reaper during the Black
Plague.
--------------------------------------------

10. SOAP
Общее описание задачи - Продвинутый уровень
Требуется реализовать программу, которая будет получать данные при
помощи методов любого SOAP сервиса в данном списке. Обратите внимание,
что для каждого сервиса есть несколько POST методов. То есть ваша
программа должна полностью утилизировать весь функционал выбранного
вами SOAP сервиса. Например, в блоке Continents есть всего один метод CountryInfoService.wso, но во многих других блоках методов больше.
