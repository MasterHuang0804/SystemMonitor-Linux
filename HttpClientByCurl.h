/*
 * HttpClientByCurl.h
 *
 *  Created on: 2015年6月12日
 *      Author: jxd
 */

#ifndef SRC_SRC_HTTPCLIENTBYCURL_H_
#define SRC_SRC_HTTPCLIENTBYCURL_H_

#include <iostream>
#include <curl/curl.h>
#include <curl/easy.h>
#include <json/json.h>
#include <json/value.h>
#include <string>

#include "GenerateJsonData.h"

using namespace std;

class HttpClientByCurl {
public:
	HttpClientByCurl();
	virtual ~HttpClientByCurl();

	static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

	FILE *fptr;
};

#endif /* SRC_SRC_HTTPCLIENTBYCURL_H_ */
