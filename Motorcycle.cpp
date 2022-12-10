#include "Motorcycle.h"

// ecs36b


using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)
// std::map<std::string, Thing *> Thing_Map;
// std::map<std::string, Person *> Person_Map;

// my location




int main(){

Motorcycle motoRight(2,96.0);  // we will put some info in motoRight soon

HttpClient httpclient("http://127.0.0.1:7375");
finalClient myClient(httpclient, JSONRPC_CLIENT_V2);

  Json::Value myv, filler; filler["Location"] = "Home!"; // ignore, filler
  
  // moving "motorcycle object" to the car, but the car really just needs the dump2Json(), so that it can analyze the data of the motorcyle. 

  try {
    myv = myClient.move("move", "Motorcycle",
			motoRight.dump2JSON(),
			filler,
			"Motorcycle Right");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << "\n The data of the right motorcycle has been sent." << endl; // this is printing out the transfer motorcycle's data when it is run





Motorcycle motoLeft(1,85.0);  // we will put some info in motoLeft soon
motoLeft.setPassengers(1);
motoLeft.safetyScore(85.0); // just testing setters

 // HttpClient httpclient2("http://127.0.0.1:7375");
 // finalClient myClient2(httpclient2, JSONRPC_CLIENT_V2);
 hy               
  Json::Value myv2, filler2; filler2["Location"] = "Home!"; // ignore, filler
  
  // moving "motorcycle object" to the car, but the car really just needs the dump2Json(), so that it can analyze the data of the motorcyle. 
  try {
    myv2 = myClient.move("move", "Motorcycle",
			motoLeft.dump2JSON(),
			filler2,
			"Motorcycle Left");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << "\n The data of the left motorcycle has been sent." << endl; // this is printing out the transfer motorcycle's data when it is run


  Json::Value complete;

  try {
    complete = myClient.complete();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  // cout << complete.toStyledString() << endl; 
  

HttpServer httpserver(7374);
  
 MyFinalServer(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
 
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  
    return 0;

}
















// member functions


 








//  Json::Value
//  Myhw5Server::complete()
//  {
//    Json::Value result;
//    result["complete"] = "Data Transaction Complete";
//    completed = true;
//   std::cout << result.toStyledString() << std::endl; // Prints out the info transferred, or essentially just the json object that was passed in
//   return result;
//  }  





// int main()
// {
//   GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
//   GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
//   GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

//   // set location here
//   process_here = gps_TLC_UCDavis; // server, forrest
  
//   Person Felix { "987654321", "Felix", gps_Home_Woodland };
//   Felix.setLocation(gps_IKEA_Sacramento, (*getNowJvTime()));

//   IP_Address meatball_IP { 2850883174 };
//   IOT_Thing Swedish_Meatball { Felix , meatball_IP };
  
//   Swedish_Meatball.model = "HUVUDROLL";
//   Swedish_Meatball.sequence_num = "123456-0000";
//   Swedish_Meatball.description = "frozen";
//   Swedish_Meatball.location = gps_Home_Woodland;
//   Swedish_Meatball.purchased = *getNowJvTime();
//   Swedish_Meatball.sold = *getNowJvTime();
//   Swedish_Meatball.owner = Felix;

//   int rc;
//   char name_buf[256];
  
//   bzero(name_buf, 256);
//   snprintf(name_buf, 256, "./json_objects/%s_%s.json", "Thing", "000000001");
//   // "./json_objects/Thing_00000001.json"
//   Json::Value jv = Swedish_Meatball.dump2JSON();
//   rc = myJSON2File(name_buf, &jv); // char *, Json::Value *
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }

//   Thing_Map["00000001"] = (Thing *) (&Swedish_Meatball);
//   for (const auto& [key, value] : Thing_Map)
//     std::cout << '[' << key << "] = " << value << ";\n ";

// #define _GPS_STUFF_
// #ifdef _GPS_STUFF_
  
//   bzero(name_buf, 256);
//   snprintf(name_buf, 256, "./json_objects/%s_%s.json", "GPS", "000000001");
//   Json::Value gps_jv = gps_IKEA_Sacramento.dump2JSON();
//   rc = myJSON2File(name_buf, &gps_jv);
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }

//   Json::Value gps_jv_2;
//   rc = myFile2JSON(name_buf, &gps_jv_2);
//   if (rc != 0)
//     {
//       std::cout << "myJSON2File error " << rc << std::endl;
//       exit(-1);
//     }
//   GPS_DD new_one {};
//   new_one.JSON2Object(gps_jv_2);
//   std::cout << (new_one.dump2JSON()).toStyledString() << std::endl;

// #endif /* _GPS_STUFF_ */
  
//   HttpServer httpserver(7374);
//   Myhw5Server s(httpserver,
// 		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
//   s.StartListening();
//   std::cout << "Hit enter to stop the server" << endl;
//   getchar();

//   s.StopListening();
//  return 0;
// }














//   std::cout << "Move\n";
//   if (class_id != "Person")
//     {
//       result["status"] = "failed";
//       strJson = ( "class " + class_id + " unknown");
//       result["reason"] = strJson;
//       error_code = -1;
//     }

//   if (object_id.empty())
//     {
//       result["status"] = "failed";
//       strJson = ( "object_id null ");
//       result["reason"] = strJson;
//       error_code = -2;
//     }

//   GPS_DD incoming_location;
//   if ((location.isNull() == true) ||
//       (location.isObject() == false))
//     {
//       result["status"] = "failed";
//       strJson = ( "location parsing error " );
//       result["reason"] = strJson;
//       error_code = -3;
//     }

//   if ((json_object.isNull() == true) ||
//       (json_object.isObject() == false))
//     {
//       result["status"] = "failed";
//       strJson = ( "person parsing error " );
//       result["reason"] = strJson;
//       error_code = -4;
//     }