#include "Channel.h"

Channel::Channel(const std::string& title, const std::string& owner)
    : title(title), owner(owner) {
}

Channel::Channel(const Channel& other)
    : title(other.title), owner(other.owner), videoList(other.videoList) {
}

std::string Channel::getTitle() const {
    return title;
}

std::string Channel::getOwner() const {
    return owner;
}

bool Channel::lessThan(const Channel& other) const {
    return title < other.title;
}

bool Channel::addVideo(const std::string& title, const std::string& content, const Date& date) {
    Video* newVideo = new Video(title, content, date);
    bool added = videoList.addVideo(newVideo);
    if (!added) {
        delete newVideo;
    }
    return added;
}

bool Channel::removeVideo(int index) {
    return videoList.removeVideo(index) != nullptr;
}

int Channel::getNumVideos() const {
    return videoList.size();
}

void Channel::print() const {
    std::cout << "Channel: " << title << " Owner: " << owner << std::endl;
}

void Channel::printVideos() const {
    print();
    videoList.print();
}

void Channel::playVideo(int index) {
    Video* video = videoList.getVideo(index);
    if (video) {
        video->play();
    } else {
        std::cout << "Error: Invalid index, video cannot be played." << std::endl;
    }
}
