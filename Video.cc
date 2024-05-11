#include "Video.h"
#include <iostream>

Video::Video(const std::string& title, const std::string& content, const Date& date)
    : title(title), content(content), uploadDate(date) {
}
Video::Video(const Video& other)
    : title(other.title), content(other.content), uploadDate(other.uploadDate) {
}

Video::~Video() {
}
Video& Video::operator=(const Video& other) {
    if (this != &other) {
        title = other.title;
        content = other.content;
        uploadDate = other.uploadDate;
    }
    return *this;
}
std::string Video::getTitle() const {
    return title;
}

bool Video::lessThan(const Video& other) const {
    return uploadDate.lessThan(other.uploadDate);
}
void Video::print() const {
    std::cout << "Title: " << title << ", Date Uploaded: ";
    uploadDate.print();
    std::cout << std::endl;
}

void Video::play() const {
    print(); // Print video metadata
    std::cout << "Playing content: " << content << std::endl;
}
