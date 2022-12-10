#include "Car.h"

// ecs36b


using namespace jsonrpc;
using namespace std;


int main(){

 HttpServer httpserver(7375);
  
 MyFinalServer s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
 
  while(!s.completed){
    s.StartListening();
  }
      s.StopListening();

  // getchar();

Motorcycle motoLeft();
Motorcycle motoRight();  // we will put some info in motoLeft soon


    motoRight= motoLeft.JSON2Object(s.Motorcycle_Map[1]->dump2JSON())
    motoLeft = motoLeft.JSON2Object(s.Motorcycle_Map[2]->dump2JSON())
		 
			
  
  


    return 0;

}
