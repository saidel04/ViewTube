#ifndef CLIENT_H
#define CLIENT_H

#include "Channel.h"
#include <string>
#include <iostream>
#include "ViewTube.h"

class Client {
public:
    Client(const std::string& name);
    ~Client();

    bool download(const ViewTube& viewTube, int channelIndex);
    void print() const;
    void printChannel() const;
    void play(int videoIndex);

private:
    std::string name;
    Channel* channel;
};

#endif 
