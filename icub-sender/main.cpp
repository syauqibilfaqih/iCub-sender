#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <time.h>
#include <iostream>

using namespace yarp::os;
using namespace yarp::sig;

int main(int argc, char *argv[]) {
    Network yarp;
    RpcClient port;

    port.open("/icub-sender");
    yarp.connect("/icub-sender","/icubSim/head/rpc:i");

    for(int i=-30; i<31; i++){
        for(int j=0; j<6; j++){
            Bottle req;
            req.addString("set");
            req.addString("pos");
            req.addInt8(j);
            req.addInt8(i);
            port.write(req);
        }
        Time::delay(0.1);
    }

    

    port.close();

    return 0;
}
