#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    const char *url = "https://example.com";

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            printf("Сайт %s имеет SSL-сертификат.\n", url);
        } 
        
        else if (res == CURLE_PEER_FAILED_VERIFICATION) {
            printf("Ошибка: SSL-сертификат не подтвержден или отсутствует.\n");
        } 
        
        else {
            printf("Ошибка подключения: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } 
    
    else {
        fprintf(stderr, "Ошибка инициализации CURL.\n");
        return 1;
    }

    return 0;
}
