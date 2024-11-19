#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct Memory {
    char *response;
    size_t size;
};

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct Memory *mem = (struct Memory *)userp;

    char *ptr = realloc(mem->response, mem->size + realsize + 1);

    if (ptr == NULL) {
        fprintf(stderr, "Not enough memory for response\n");
        return 0;
    }

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}

size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata) {
    size_t realsize = size * nitems;
    printf("Header: %.*s", (int)realsize, buffer);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    struct Memory chunk = {NULL, 0}; 
    curl = curl_easy_init();        

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://python.org");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            long response_code;
            double elapsed_time;
            char *content_type;
            char *final_url;
            struct curl_slist *cookies;

            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("\nStatus Code: %ld\n", response_code);

            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed_time);
            printf("Elapsed Time: %.2f seconds\n", elapsed_time);

            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

            if (content_type)
                printf("Content-Type: %s\n", content_type);

            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &final_url);

            if (final_url)
                printf("Final URL: %s\n", final_url);

            curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &cookies);

            if (cookies) {
                printf("Cookies:\n");
                struct curl_slist *nc = cookies;
                
                while (nc) {
                    printf("  %s\n", nc->data);
                    nc = nc->next;
                }

                curl_slist_free_all(cookies);
            }

            printf("Content (first 500 characters):\n");

            if (chunk.response) {
                printf("%.*s\n", 500, chunk.response);
            } 
            
            else {
                printf("No Content.\n");
            }

        } 
        
        else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        free(chunk.response);
        curl_easy_cleanup(curl);
    }

    return 0;
}
