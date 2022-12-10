#ifndef AUTO_V_H
#define AUTO_V_H
class auto_v {
    private:
    protected:
    public:
        int numPassengers;
        int safetyScore;
        auto_v();
        auto_v(int n, int s);
        void setPassengers(int n) { }
        void setScore(int s) { }
        int getPassengers() { }
        int getScore() { }
        void printInfo() { }
        

};
#endif