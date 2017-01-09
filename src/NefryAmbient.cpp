/*
 * NefryAmbient.cpp - Library for sending data to Ambient
 * Created by Takehiko Shimojima, April 21, 2016
 */
#include "NefryAmbient.h"

NefryAmbient::NefryAmbient() {
	_ambient =Ambient();
}
WiFiClient _client;
bool NefryAmbient::begin(unsigned int channelId, const char * writeKey) {
	
	Nefry.setConfHtmlValue("ChannelID", 0);
	Nefry.setConfHtmlStr("WriteKey",  0);
	_conectionFlag = true;
	if (channelId == 0 || strcmp(writeKey, "") == true) {
		Nefry.println(F("Ambient Connection INFO Lack"));
		Nefry.println(F("(接続に必要な情報が不足しています)"));
		_conectionFlag = false;
		return false;
	}
	else return _ambient.begin(channelId,writeKey, &_client);
}

bool NefryAmbient::set(int field,const char * data) {
	if (_conectionFlag==false)return false;
	else return _ambient.set(field, data);
}

bool NefryAmbient::set(int field, double data){
	if (_conectionFlag==false)return false;
	else return _ambient.set(field, data);
}

bool NefryAmbient::set(int field, int data){
	if (_conectionFlag==false)return false;
	else return _ambient.set(field, data);
}

bool NefryAmbient::clear(int field) {
	if (_conectionFlag==false)return false;
	else return _ambient.clear(field);
}

bool NefryAmbient::send() {
	Nefry.ndelay(10);
	if (_conectionFlag == false)return false;
	else return _ambient.send();
}

int NefryAmbient::bulk_send(char *buf) {
	if (_conectionFlag==false)return false;
	else return _ambient.bulk_send(buf);
}

bool NefryAmbient::delete_data(const char * userKey) {
	if (_conectionFlag==false)return false;
	else return _ambient.delete_data(userKey);
}
