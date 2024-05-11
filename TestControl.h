#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "ViewTube.h"
#include "View.h"
#include "Client.h"
#include "Tester.h"

using namespace std;


class TestControl
{
  public:
    
    void launch();
    

  private:
    int channelListTest();
    int viewTubeChannelTest();
    int viewTubeVideoTest();
    int clientDownloadTest();
    int clientMemoryTest();

    //helper function
    void initViewTube(ViewTube& viewTube);

    View view;
    Tester tester;

    const static vector<string> menu;

    // Channel information
    const static string channelTitles[5];
    const static string owners[5];

    // Video information
    const static string videoTitles[5][5];
    const static string content[5][5];
    const static Date dates[5][5];


    
};

#endif
