#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    char **response = (char **)userp;

    *response = realloc(*response, strlen(*response) + totalSize + 1);

    if (*response == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 0;
    }

    strncat(*response, contents, totalSize);
    return totalSize;
}

int main() {
    CURL *curl;
    CURLcode res;
    char *url = "https://en.wikipedia.org/robots.txt";
    char *response = calloc(1, sizeof(char)); 

    if (response == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Ошибка curl: %s\n", curl_easy_strerror(res));
        } 
        
        else {
            printf("Содержимое robots.txt:\n%s\n", response);
        }

        curl_easy_cleanup(curl);
    }

    free(response);
    curl_global_cleanup();

    return 0;
}
