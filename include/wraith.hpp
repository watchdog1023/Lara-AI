#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/reader.h>
#include<jsoncpp/json/writer.h>
#include<jsoncpp/json/value.h>
#include "HTTPRequest.hpp"

using namespace std;
using namespace http;
using namespace Json;

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos = data.find(toSearch, pos + replaceStr.size());
	}
}
void sat_image_getter(double lon,double lat,int multiplier = 0)
{
    if(multiplier == 0)
        {
            multiplier = 10;
        }

    //string sats[4] = {"Sentinel-1A","Sentinel-2A","Sentinel-2B","Sentinel-3A","Landsat-8"};
    string str3;
    string str4;
    string str5;
	string str6;
    string urlf;
    string strJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;
    Json::Value root;
    string key = "9b31e44b8a5bf243941e70c62aadbb142cc86ce427ec124b0214b02048fa9020";
    for(int i = 1;i < 2;i++)
    {
        string url = "http://api.spectator.earth/imagery/?api_key=" + key + "&bbox=19.59,49.90,20.33,50.21&satellites=Landsat-8";
        try
            {
                // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
                http::Request request(url);
                // send a get request
                const http::Response response = request.send("GET");
                //std::cout << std::string(response.body.begin(), response.body.end()) << '\n'; // print the result
                strJson = string(response.body.begin(), response.body.end());
            }
        catch(const std::exception& e)
            {
                cerr << "Request failed, error: " << e.what() << '\n';
            }    
        bool parsingSuccessful = reader.parse(strJson.c_str(), root);     //parse process
        if (!parsingSuccessful)
            {
                cout  << "Failed to parse" << reader.getFormattedErrorMessages();
                return 0;
            }
        str3 = fastWriter.write(root["results"][0]["download_url"]);
        str4 = fastWriter.write(root["results"][0]["scene_id"]);
        findAndReplaceAll(str3, "\"", "");
        findAndReplaceAll(str4, "\"", "");
        findAndReplaceAll(str3, "\n", "");
        findAndReplaceAll(str4, "\n", "");
        str5 = str3 + str4 + "_thumb_large.jpg" + "?api_key=" + key;
		str6 = str4 + "_thumb_large.jpg";
        cout << str5;
        system(("wget -c " + str5 + " -O " + str6).c_str());
    }
}