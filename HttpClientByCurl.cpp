/*
 * HttpClientByCurl.cpp
 *
 *  Created on: 2015年6月12日
 *      Author: jxd
 */

#include "HttpClientByCurl.h"

//size_t write_data(void* buffer,size_t size,size_t nmemb,void* userp);

HttpClientByCurl::HttpClientByCurl() {
	// TODO Auto-generated constructor stub

	GenerateJsonData *jsonData = new GenerateJsonData();
	Json::Value performance = jsonData->GetSystemPerformanceInfo();

	CURL *curl ;
	CURLcode res ;

	//if((fptr = fopen("/tmp/postresult","w")) == NULL)
	//	cout<<"open file failed"<<endl;

	string url = "http://192.168.1.200:8000/postNodeStatus.php";

	curl = curl_easy_init();

	if(curl)
	{
		string data = "data=" + performance.toStyledString();

		struct curl_slist *headers = NULL;

		headers = curl_slist_append(headers,"Content-Type:application/x-www-form-urlencoded");

		curl_easy_setopt(curl,CURLOPT_POST,1);
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
		curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,data.c_str());
		//curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
		//curl_easy_setopt(curl,CURLOPT_WRITEHEADER,fptr);

		res = curl_easy_perform(curl);

		if(res != CURLE_OK)
			cout<<"Perfom Failed: "<<curl_easy_strerror(res)<<endl;
	}

	curl_easy_cleanup(curl);
}

size_t HttpClientByCurl::write_data(void * buffer,size_t size,size_t nmemb,void *userp)
{
//	cout<<"1"<<endl;

	FILE *fptr = (FILE *)userp;

	fwrite(buffer,size,nmemb,fptr);
}


HttpClientByCurl::~HttpClientByCurl() {
	// TODO Auto-generated destructor stub
}

