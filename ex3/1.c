#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    const char *url = "http://example.com";

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            long response_code = 0;

            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if (response_code == 200) {
                printf("Страница найдена: %s\n", url);
            } 
            
            else {
                printf("Страница не найдена. Код ответа: %ld\n", response_code);
            }
        } 
        
        else {
            fprintf(stderr, "Ошибка выполнения запроса: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } 
    
    else {
        fprintf(stderr, "Ошибка инициализации CURL.\n");
        return 1;
    }

    return 0;
}
