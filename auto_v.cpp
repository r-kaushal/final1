#include <iostream>
#include "auto_v.h"
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>



class auto_v {
    public:
        int numPassengers;
        double safetyScore;
        double avgAge;
        auto_v() {

        }
        auto_v(int n, double s) {
            numPassengers = n;
            safetyScore = s;
        }

        void setPassengers(int n) {
            numPassengers = n;
        }
        void setScore(double s) {
            safetyScore = s;
        }
        void setAge(double a) {
            avgAge = a;
        }
        int getPassengers() {
            return numPassengers;
        }
        double getScore() {
            return safetyScore;
        }
        double getAge() {
            return avgAge;
        }
        void printInfo() {
            std::cout << "passengers:" << numPassengers << "safety score:" << safetyScore << "\n";

        }

        auto_v chooseCrash(auto_v av1, auto_v av2) {
            double score1 = 0.0;
            double score2 = 0.0;

            score1 += av1.getScore();
            score2 += av2.getScore();

            score1 += (av1.getPassengers() * 20);
            score2 += (av2.getPassengers() * 20);

            score1 += (100 - av1.getAge());
            score2 += (100 - av2.getAge());

            if (score1 < score2) {
                return av1;
            }
            else {
                return av2;
            }

        }

        Json::Value auto_v::dump2JSON() {

            Json::Value result {};
            if(this->numPassengers!=NULL)
                result["Number of Passengers"] = this->numPassengers;
            if(this->safetyScore!=NULL)
                result["Safety Score"] = this->safetyScore;
            if(this->avgAge!=NULL)
                result["Average Age of Passengers"] = this->avgAge;
            // Json::Value jv_result;
            // if(this->owner.name!=""){
            // jv_result = (this->owner).dump2JSON();
            // result["Owner"] = jv_result;
            // }
            
            // jv_result = (this->location).dump2JSON();
            // result["Location"] = jv_result;

            // std::cout << jv_result.toStyledString() << std::endl;

            return result;
        }

        void auto_v:: JSON2Object(Json::Value jsonVal){
            this->setPassengers((jsonVal["Number of Passengers"].asInt()));
            this->setScore((jsonVal["Safety Score"].asDouble()));
            this->setAge((jsonVal["Average Age of Passengers"].asDouble()));

        }   
};