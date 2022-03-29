#pragma once
#include <curl/curl.h>
#include <memory>
#include <string.h>
#include <string>

struct response {
  char *data;
  size_t size;
};

class curl {
  CURL *session;
  response last_message{0, 0};
  static size_t data_cb(void *data, size_t size, size_t nmemb, void *userptr) {
    size_t realsize = size * nmemb;

    response *last_msg = (response *)userptr;
    char *ptr = (char *)realloc(last_msg->data, last_msg->size + realsize + 1);
    if (!ptr) {
      printf("No memory\n");
      exit(1);
    }
    last_msg->data = ptr;
    memcpy(&(last_msg->data[last_msg->size]), data, realsize);
    last_msg->size += realsize;
    last_msg->data[last_msg->size] = 0;
    // printf("Writing %s...\n", last_msg->data);
    printf("Valid user pointer?: %s\n", userptr ? "Yes" : "No");

    return realsize;
  }

public:
  curl();
  ~curl();
  std::string get(const char *) noexcept;
};