

// first v at end 
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include <time.h>
#include "auto_v.cpp"
#include "Motorcycle.cpp"
#include "Motorcycle.h"
#include "finalServer.h"

using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)
// std::map<std::string, Thing *> Thing_Map;
// std::map<std::string, Person *> Person_Map;

// my location

class MyFinalServer : public finalServer
{
public:
   MyFinalServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);

virtual Json::Value complete(); bool completed = false;

    std::map<std::string, Motorcycle *> Motorcycle_Map;
};

MyFinalServer::MyFinalServer(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "MyFinalServer Object created" << std::endl;
}

// member functions

 Json::Value
 MyFinalServer::move (const std::string& action, const std::string& class_id,
  const Json::Value& json_object, const Json::Value& location,
  const std::string& object_id)
 {
//   int error_code = 0;
   Json::Value result;

	
	  Motorcycle * lv_Motorcycle_ptr;
	  if (Motorcycle_Map.find(object_id) != Motorcycle_Map.end())
	    {
	      lv_Motorcycle_ptr = Motorcycle_Map[object_id];
	    }
	  else
	    {
	      lv_Motorcycle_ptr = new Motorcycle {};
	      Motorcycle_Map[object_id] = lv_Motorcycle_ptr;
	    }
    lv_Motorcycle_ptr->JSON2Object(json_object);
	



    result = json_object;

  std::cout << result.toStyledString() << std::endl; // Prints out the info transferred, or essentially just the json object that was passed in
  return result;
 }

 

 Json::Value
 finalServer::complete()
 {
   Json::Value result;
   result["complete"] = "Data Transaction Complete";
   completed = true;
  std::cout << result.toStyledString() << std::endl; // Prints out the info transferred, or essentially just the json object that was passed in
  return result;
 }  





/**
 * @file main.cpp
 * @date 01.08.2011
 * @author Peter Spiess-Knafl
 * @brief main.cpp
 */
/*
#include <iostream>
#include <jsonrpccpp/server.h>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>
#include <string>
#include "finalserver.h"

using namespace jsonrpc;
using namespace std;

class SampleServer : public AbstractServer<SampleServer> {
public:
  SampleServer(HttpServer &server) : AbstractServer<SampleServer>(server) {
    this->bindAndAddMethod(Procedure("sayHello", PARAMS_BY_NAME, JSON_STRING, "name", JSON_STRING, NULL), &SampleServer::sayHello);
    this->bindAndAddNotification(Procedure("notifyServer", PARAMS_BY_NAME, NULL), &SampleServer::notifyServer);
  }

  // method
  void sayHello(const Json::Value &request, Json::Value &response) { response = "Hello: " + request["name"].asString(); }

  // notification
  void notifyServer(const Json::Value &request) {
    (void)request;
    cout << "server received some Notification" << endl;
  }
};

int main() {
  try {
    HttpServer server(8383);
    SampleServer serv(server);
    if (serv.StartListening()) {
      cout << "Server started successfully" << endl;
      getchar();
      serv.StopListening();
    } else {
      cout << "Error starting Server" << endl;
    }
  } catch (jsonrpc::JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  // curl --data
  // "{\"jsonrpc\":\"2.0\",\"method\":\"sayHello\",\"id\":1,\"params\":{\"name\":\"peter\"}}"
  // localhost:8383  curl --data
  // "{\"jsonrpc\":\"2.0\",\"method\":\"notifyServer\", \"params\": null}"
  // localhost:8383
}
*/

