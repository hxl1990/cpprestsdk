#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace std;
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace web::json;

int main()
{
	http_client client(U("https://reqres.in"));

	// async
	client.request(methods::GET, U("/api/users")).then([](http_response response)
	{
		return response.extract_json();
	}).then([](value result)
	{
		ucout << result.serialize() << endl;
	}).wait();

	// GET
	auto response = client.request(methods::GET, U("/api/users")).get();

	auto result = response.extract_json().get();
	ucout << result.serialize() << endl;

	// POST
	value user;
	user[U("id")] = value(1);
	user[U("name")] = value(U("foo"));
	response = client.request(methods::POST, U("/api/users"), user).get();

	result = response.extract_json().get();
	ucout << result.serialize();
}