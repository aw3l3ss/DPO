#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t writeCallback(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t total_size = size * nmemb;
    FILE *f = (FILE *)stream;
    fwrite(ptr, size, nmemb, f);
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *response_file;

    const char *url = "http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso";

    const char *soap_request =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
        "<soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" "
        "                xmlns:web=\"http://www.oorsprong.org/websamples.countryinfo\">"
        "    <soap:Body>"
        "        <web:ListOfContinentsByName />"
        "    </soap:Body>"
        "</soap:Envelope>";

    curl = curl_easy_init();
    
    if (curl) {
        response_file = fopen("response.xml", "wb");

        if (!response_file) {
            perror("Error opening file");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, soap_request);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(soap_request));
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_file);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: text/xml; charset=utf-8");
        headers = curl_slist_append(headers, "SOAPAction: \"http://www.oorsprong.org/websamples.countryinfo/ListOfContinentsByName\"");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);
        fclose(response_file);
        curl_easy_cleanup(curl);
    } 
    
    else {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 1;
    }

    printf("SOAP response saved to response.xml\n");
    return 0;
}