#include "../includes/curl.hpp"
#include <cstdio>
#include <curl/curl.h>
#include <iostream>
#include <memory.h>

curl::curl() : session{0} { curl_global_init(CURL_GLOBAL_DEFAULT); }

curl::~curl() {
  free(last_message.data);
  curl_global_cleanup();
}

std::string curl::get(const char *url) noexcept {
  this->session = curl_easy_init();
  /* send all data to this function  */
  curl_easy_setopt(this->session, CURLOPT_WRITEFUNCTION, this->data_cb);

  /* we pass our 'chunk' struct to the callback function */
  curl_easy_setopt(this->session, CURLOPT_WRITEDATA, (void *)&last_message);
  if (this->session) {
    CURLcode res;
    curl_easy_setopt(this->session, CURLOPT_URL, url);
    res = curl_easy_perform(this->session);
    if (res == CURLcode::CURLE_OK) {
      if (this->last_message.data) {
        curl_easy_cleanup(this->session);
        return this->last_message.data;
      }
      printf("cURL error no string passtrough");
    }
  }
  curl_easy_cleanup(this->session);
  return std::string();
}