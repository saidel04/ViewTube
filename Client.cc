#include "Client.h"

Client::Client(const std::string& name)
    : name(name), channel(nullptr) {
}

Client::~Client() {
    delete channel; 
    channel = nullptr; 
}

bool Client::download(const ViewTube& viewTube, int channelIndex) {
    const Channel* originalChannel = viewTube.getChannel(channelIndex);
    if (originalChannel == nullptr) {
        std::cerr << "Error: Channel at index " << channelIndex << " does not exist." << std::endl;
        return false;
    }
    if (channel != nullptr) {
        delete channel; 
        channel = nullptr; 
    }
    channel = new Channel(*originalChannel); 
    return true;
}

void Client::print() const {
    std::cout << "Client Name: " << name << std::endl;
    if (channel != nullptr) {
        channel->print();
    } else {
        std::cout << "No channel downloaded." << std::endl;
    }
}

void Client::printChannel() const {
    if (channel != nullptr) {
        channel->printVideos();
    } else {
        std::cerr << "Error: No channel to print." << std::endl;
    }
}

void Client::play(int videoIndex) {
    if (channel != nullptr) {
        channel->playVideo(videoIndex);
    } else {
        std::cerr << "Error: No channel to play a video from." << std::endl;
    }
}
