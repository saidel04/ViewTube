
#include "TestControl.h"


const vector<string> TestControl::menu ={
    "ChannelList test",
    "ViewTube channel test",
    "ViewTube video test",
    "Client download test",
    "Client memory test\n",
    "Test all and get mark\n"
};


void TestControl::launch(){
    //get input, launch the appropriate test
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: channelListTest(); break;
            case 2: viewTubeChannelTest(); break;
            case 3: viewTubeVideoTest(); break;
            case 4: clientDownloadTest(); break;
            case 5: clientMemoryTest(); break;
            case 6: int mark = 0;
                    mark += channelListTest();
                    mark += viewTubeChannelTest();
                    mark += viewTubeVideoTest();
                    mark += clientDownloadTest();
                    mark += clientMemoryTest();
                    cout<<endl<<"Your mark is "<<mark<<"/50"<<endl;
                    break;
        }
    }
}

void TestControl::initViewTube(ViewTube& viewTube){
    cout<<"Initializing ViewTube..."<<endl;
    for (int j = 0; j < 5; ++j){
        viewTube.addChannel(channelTitles[j],owners[j]);
    }
    //we add the channels first, then the videos for test purposes
     for(int j = 0; j < 5; ++j){  
        for (int i = 0; i <5; ++i){
            viewTube.addVideo(channelTitles[j],videoTitles[j][i], content[j][i], dates[j][i]);
        }
    }
}

int TestControl::channelListTest(){
    // Add Channels to the list.
    // Print the list.
    // Check the size
    // Remove two channels.
    // Print the list. Check the size
    // Add a channel
    // Print the list. Check the size
    // Remove all channels
    // Print the list. Check the size

    cout<<"ChannelList test"<<endl;
    Channel* channels[5];
    ChannelList channelList;
    cout<<"Adding channels"<<endl;
    for (int i = 0; i < 5; ++i){
        channels[i] = new Channel(channelTitles[i], owners[i]);
        channelList.addChannel(channels[i]);
    }
    cout<<"Printing channels"<<endl;
    tester.initCapture();
    for (int i = 0; i < channelList.size(); ++i){
        channelList.getChannel(i)->print();
    }
    tester.endCapture();

    int marks = 0;

    cout<<"Checking size"<<endl;
    if (channelList.size() != 5){
        cout<<"Error: size should be 5, but is "<<channelList.size()<<endl;
    }else{
        marks += 1;
    }

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.find({0,1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    cout<<"Removing two channels"<<endl;
    channelList.removeChannel(0);
    channelList.removeChannel(2);
    channelList.removeChannel(3);

    cout<<"Checking size"<<endl;
    if (channelList.size() != 3){
        cout<<"Error: size should be 3, but is "<<channelList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    for (int i = 0; i < channelList.size(); ++i){
        channelList.getChannel(i)->print();
    }
    tester.endCapture();

    

    cout<<"Checking output for"<<endl;
    cout<<channelTitles[1]<<endl;
    cout<<channelTitles[2]<<endl;
    cout<<channelTitles[4]<<endl;

    tester.find({1,2,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    tester.confirmAbsent({0,3}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: removed channels found"<<endl;
    }else{
        cout<<"No removed channels found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"Adding a channel"<<endl;
    channelList.addChannel(channels[3]);

    cout<<"Checking size"<<endl;
    if (channelList.size() != 4){
        cout<<"Error: size should be 4, but is "<<channelList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    for (int i = 0; i < channelList.size(); ++i){
        channelList.getChannel(i)->print();
    }
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    tester.confirmAbsent({0}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: removed channels found"<<endl;
    }else{
        cout<<"No removed channels found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"Removing all channels"<<endl;
    channelList.removeChannel(0);
    channelList.removeChannel(0);
    channelList.removeChannel(0);
    channelList.removeChannel(0);
    
    cout<<"Checking size"<<endl;
    if (channelList.size() != 0){
        cout<<"Error: size should be 0, but is "<<channelList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    for (int i = 0; i < channelList.size(); ++i){
        channelList.getChannel(i)->print();
    }
    tester.endCapture();
    
    cout<<"Checking output"<<endl;
    tester.confirmAbsent({0,1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: removed channels found"<<endl;
    }else{
        cout<<"No removed channels found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"ChannelList test complete, deleting Channels"<<endl;

    for (int i = 0; i < 5; ++i){
        delete channels[i];
    }
    cout<<"Marks: "<<marks<<"/10"<<endl;
    return marks;
}

int TestControl::viewTubeChannelTest(){
    
    cout<<"ViewTube channel test"<<endl;
    ViewTube viewTube;
    initViewTube(viewTube);
    int marks = 0;

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    viewTube.printChannels();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.find({0,1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Deleting channel 0"<<endl;
    viewTube.deleteChannel(0);

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    viewTube.printChannels();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Deleting channel 2"<<endl;
    viewTube.deleteChannel(2);

    cout<<"Printing channels"<<endl;
    tester.initCapture();
    viewTube.printChannels();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Printing the Channel at index 1 (should be "<<channelTitles[2]<<")"<<endl;
    tester.initCapture();
    viewTube.printChannel(1);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }
    tester.confirmAbsent({0,1,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: other channels found"<<endl;
    }else{
        cout<<"No removed channels found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"viewTube channel test complete"<<endl;   
    cout<<"Marks: "<<marks<<"/10"<<endl;

    return marks;
}


int TestControl::viewTubeVideoTest(){
    cout<<"ViewTube channel test"<<endl;
    ViewTube viewTube;
    initViewTube(viewTube);
    int marks = 0;

    // print out and capture the relevant dates
    // so that we can search for them in the output
    string dates[5][5];
    cout<<"Capturing Date data, please ignore"<<endl;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; j++){
            tester.initCapture();
            TestControl::dates[i][j].print();
            tester.endCapture();
            dates[i][j] = tester.getOutput();
        }
    }

    cout<<endl<<endl<<"Printing channel at index 2"<<endl;
    tester.initCapture();
    viewTube.printChannel(2);
    tester.endCapture();

    cout<<"Checking output for correct Videos and Dates"<<endl;
    int errors = 0, errors2 = 0;
    tester.find({0,1,2,3,4}, videoTitles[2], errors);
    tester.find({0,1,2,3,4}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: dates not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }   

    cout<<"Deleting video 2 and 3 from channel 2"<<endl;
    viewTube.deleteVideo(2,2);
    viewTube.deleteVideo(2,2);

    cout<<"Printing channel at index 2"<<endl;
    tester.initCapture();
    viewTube.printChannel(2);
    tester.endCapture();

    cout<<"Checking output for correct Videos and Dates"<<endl;
    errors = 0, errors2 = 0;
    tester.find({0,1,4}, videoTitles[2], errors);
    tester.find({0,1,4}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: dates not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    tester.confirmAbsent({2,3}, videoTitles[2], errors);
    tester.confirmAbsent({2,3}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: removed videos found"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: removed dates found"<<endl;
    }else{
        cout<<"No removed videos or dates found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Testing play video"<<endl;
    cout<<"Playing video 1 from channel 2"<<endl;
    tester.initCapture();
    viewTube.playVideo(2,1);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({4}, content[2], errors);
    if (errors != 0){
        cout<<"Error: video content not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }


    cout<<"Removing all videos from channel 2"<<endl;
    viewTube.deleteVideo(2,0);
    viewTube.deleteVideo(2,0);
    viewTube.deleteVideo(2,0);

    cout<<"Printing channel at index 2"<<endl;
    tester.initCapture();
    viewTube.printChannel(2);
    tester.endCapture();

    cout<<"Checking output for correct Videos and Dates (should be none)"<<endl;

    errors = 0, errors2 = 0;
    tester.confirmAbsent({0,1,2,3,4}, videoTitles[2], errors);

    if (errors != 0 || errors2 != 0){
        cout<<"Error: something was found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"viewTube video test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    return marks;
}

int TestControl::clientDownloadTest(){
    cout<<"Client download test"<<endl;
    ViewTube viewTube;
    initViewTube(viewTube);
    Client client("Your name here");
    int marks = 0;

    cout<<"Attempting to print Channel"<<endl;
    tester.initCapture();
    client.printChannel();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.confirmAbsent({0,1,2,3,4}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: something was found"<<endl;
    }else{
        cout<<"No channels found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Downloading Channel 3"<<endl;
    client.download(viewTube, 3);

    cout<<"Printing Channel"<<endl;
    tester.initCapture();
    client.printChannel();
    tester.endCapture();

    cout<<"Checking for Channel title"<<endl;
    errors = 0;
    tester.find({3}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: channel not found"<<endl;
    }else{
        cout<<"Channel title found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Checking for Video titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, videoTitles[3], errors);
    if (errors != 0){
        cout<<"Error: video titles not found"<<endl;
    }else{
        cout<<"Video titles found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Playing video 2"<<endl;
    tester.initCapture();
    client.play(2);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, content[3], errors);
    if (errors != 0){
        cout<<"Error: video content not found"<<endl;
    }else{
        cout<<"Video content found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Downloading Channel 1"<<endl;
    client.download(viewTube, 1);

    cout<<"Printing Channel"<<endl;
    client.printChannel();


    cout<<"Playing Video 4"<<endl;
    tester.initCapture();
    client.play(4);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, content[1], errors);
    if (errors != 0){
        cout<<"Error: video content not found - are your videos in order by Date?"<<endl;
    }else{
        cout<<"Video content found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Client download test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    // for (int i = 0; i < 5; ++i){
    //     cout<<i<<") "<<videoTitles[1][i]<<endl;
    //     cout<<content[1][i]<<endl;
    // }

    return marks;


}


int TestControl::clientMemoryTest(){
    cout<<"Client memory test"<<endl;
    ViewTube viewTube;
    initViewTube(viewTube);
    Client client("Your name here");
    int marks = 0;

    
    cout<<endl<<"Downloading Channel 3"<<endl;
    client.download(viewTube, 3);

    cout<<endl<<"Deleting Channel 3 from ViewTube"<<endl;

    viewTube.deleteChannel(3);

    cout<<endl<<"Printing Channel 3 from Client"<<endl;
    tester.initCapture();
    client.printChannel();
    tester.endCapture();

    cout<<endl<<"Checking for Channel title"<<endl;
    int errors = 0;
    tester.find({3}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: channel not found"<<endl;
    }else{
        cout<<"Channel title found, output is correct"<<endl;
        marks += 3;
    }

    cout<<endl<<"Checking for Video titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, videoTitles[3], errors);
    if (errors != 0){
        cout<<"Error: video titles not found"<<endl;
    }else{
        cout<<"Video titles found, output is correct"<<endl;
        marks += 3;
    }

    cout<<endl<<"Downloading Channel 1, then Channel 0"<<endl;
    client.download(viewTube, 1);
    client.download(viewTube, 0);

    cout<<endl<<"Printing Channel 1 from ViewTube"<<endl;
    tester.initCapture();
    viewTube.printChannel(1);
    tester.endCapture();

    cout<<endl<<"Checking for Channel title"<<endl;
    errors = 0;
    tester.find({1}, channelTitles, errors);
    if (errors != 0){
        cout<<"Error: channel not found"<<endl;
    }else{
        cout<<"Channel title found, output is correct"<<endl;
        marks += 2;
    }

    cout<<endl<<"Checking for Video titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, videoTitles[1], errors);
    if (errors != 0){
        cout<<"Error: video titles not found"<<endl;
    }else{
        cout<<"Video titles found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Client memory test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    // for (int i = 0; i < 5; ++i){
    //     cout<<i<<") "<<videoTitles[1][i]<<endl;
    //     cout<<content[1][i]<<endl;
    // }

    return marks;
}



const string TestControl::channelTitles[5] = {
    "TechTrendsUnleashed",
    "CulinaryExplorerHQ",
    "LaughLagoonNetwork",
    "FitnessFiestaChannel",
    "MindfulMysteriesShow"};

const string TestControl::owners[5] = {"Bob", "Sue", "Joe", "Mary", "Bill"};

// These do not make any sense - just for testing
const string TestControl::videoTitles[5][5] = {
    {"Lion", "Lion 2", "Fishbowl", "Alien", "Castle"},
    {"Love", "Anonymous", "Games","Music","Welcome"},
    {"Monkey", "Stranger","Ant","Turtle","Smile"},
    {"Crab","City","Apple","Pig","Dog"},
    {"Helicopter","Unlock","Santa's Sleigh", "Guitar","Whale"}
};

// some of these dates are out of order - on purpose for testing
 const Date TestControl::dates[5][5]={
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2023, 4, 15), Date(2024, 11, 7), Date(2023, 8, 22), Date(2024, 5, 12), Date(2023, 6, 30)},
    {Date(2023, 7, 18), Date(2024, 3, 12), Date(2023, 11, 5), Date(2024, 2, 20), Date(2023, 9, 9)},
    {Date(2024, 7, 25), Date(2023, 2, 14), Date(2024, 10, 8), Date(2023, 5, 28), Date(2024, 1, 19)},
 };

const string TestControl::content[5][5] = {
R"(
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
─▀▀▌───────▐▀▀
─▄▀░◌░░░░░░░▀▄
▐░░◌░▄▀██▄█░░░▌
▐░░░▀████▀▄░░░▌
═▀▄▄▄▄▄▄▄▄▄▄▄▀═
)",

R"(
▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒
▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒
▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒
▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒
▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒
)",
R"(
─────────█▄██▄█
█▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█
███┼█████▐████▌█████┼███
█████████▐████▌█████████
)",
R"(
█───▄▀▀▀▀▄─▐█▌▐█▌▐██
█──▐▄▄────▌─█▌▐█─▐▌─
█──▐█▀█─▀─▌─█▌▐█─▐██
█──▐████▄▄▌─▐▌▐▌─▐▌─
███─▀████▀───██──▐██
)",
R"(
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
█░░░█░░░░░░░░░░▄▄░██░█
█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
█░░░▀░░░▄▄▄▄▄░░██░▀▀░█
─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀
)",
R"(
║░█░█░║░█░█░█░║░█░█░║
║░█░█░║░█░█░█░║░█░█░║
║░║░║░║░║░║░║░║░║░║░║
╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝
)",
R"(
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█
█░░║║║╠─║─║─║║║║║╠─░░█
█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

)",
R"(
───▄██▄─────────────▄▄
──█████▄▄▄▄───────▄▀
────▀██▀▀████▄───▄▀
───▄█▀▄██▄████▄─▄█
▄▄█▀▄▄█─▀████▀██▀
)",
R"(
█▓▒▓█▀██▀█▄░░▄█▀██▀█▓▒▓█
█▓▒░▀▄▄▄▄▄█░░█▄▄▄▄▄▀░▒▓█
█▓▓▒░░░░░▒▓░░▓▒░░░░░▒▓▓█
)",
R"(
──▄──▄────▄▀
───▀▄─█─▄▀▄▄▄
▄██▄████▄██▄▀█▄
─▀▀─█▀█▀▄▀███▀
──▄▄▀─█──▀▄▄
)",
R"(
─▄▀▀▀▄────▄▀█▀▀█▄
▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄
█▄▀█───█─█▄▄▀─▄▀─▄▀▄
──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█
─────▄████▀▀▀▀████─▀▄
)",
R"(
╔══╗░░░░╔╦╗░░╔═════╗
║╚═╬════╬╣╠═╗║░▀░▀░║
╠═╗║╔╗╔╗║║║╩╣║╚═══╝║
╚══╩╝╚╝╚╩╩╩═╝╚═════╝
)",
R"(
░░▄█▀▀▀░░░░░░░░▀▀▀█▄
▄███▄▄░░▀▄██▄▀░░▄▄███▄
▀██▄▄▄▄████████▄▄▄▄██▀
░░▄▄▄▄██████████▄▄▄▄
░▐▐▀▐▀░▀██████▀░▀▌▀▌▌
)",
R"(
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒
▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒
░█▀█▀█░█▀██░█▀█░█▄█▄█░
░█▀█▀█░█▀████▀█░█▄█▄█░
████████▀█████████████
)",
R"(
┊┊┊┊┊┊┊╱▏┊┊┊┊┊┊┊
┊┊┊┊┊┊▕╱┊┊┊┊┊┊┊┊
┊┊┊╱▔▔╲┊╱▔▔╲┊┊┊┊
┊┊▕┈┈┈┈▔┈┈┈╱┊┊┊┊
┊┊▕┈┈┈┈┈┈┈┈╲┊┊┊┊
┊┊┊╲┈┈┈┈┈┈┈╱┊┊┊┊
┊┊┊┊╲▂▂▂▂▂╱┊┊┊┊┊
)",
R"(
▂╱▔▔╲╱▔▔▔▔╲╱▔▔╲▂
╲┈▔╲┊╭╮┈┈╭╮┊╱▔┈╱
┊▔╲╱▏┈╱▔▔╲┈▕╲╱▔┊
┊┊┊┃┈┈▏┃┃▕┈┈┃┊┊┊
┊┊┊▏╲┈╲▂▂╱┈╱▕┊┊┊
)",
R"(
╥━━━━━━━━╭━━╮━━┳
╢╭╮╭━━━━━┫┃▋▋━▅┣
╢┃╰┫┈┈┈┈┈┃┃┈┈╰┫┣
╢╰━┫┈┈┈┈┈╰╯╰┳━╯┣
╢┊┊┃┏┳┳━━┓┏┳┫┊┊┣
╨━━┗┛┗┛━━┗┛┗┛━━┻
)",
R"(
▀▀▀▀█▀▀▀▀
─▄▀█▀▀█──────▄
█▄▄█▄▄██████▀
▀▀█▀▀▀█▀▀
─▀▀▀▀▀▀▀
)",
R"(
──▄▀▀▀▄───────────────
──█───█───────────────
─███████─────────▄▀▀▄─
░██─▀─██░░█▀█▀▀▀▀█░░█░
░███▄███░░▀░▀░░░░░▀▀░░
)",
R"(
░╔╔╩╩╝
▄██▄
░░██████▄░░░░░░▄▄▄▄▄▄█
░░█▀█▀█▀█░░▄░▄████████
░▄▌▄▌▄▌▄▌░▀▄▄▄▄█▄▄▄▄█▄
)",
R"(
░▄▀▀▀▀▄░░▄▄
█░░░░░░▀▀░░█░░░░░░▄░▄
█░║░░░░██░████████████ 
█░░░░░░▄▄░░█░░░░░░▀░▀
░▀▄▄▄▄▀░░▀▀
)",
R"(
─────▀▄▀─────▄─────▄
──▄███████▄──▀██▄██▀
▄█████▀█████▄──▄█
███████▀████████▀
─▄▄▄▄▄▄███████▀
)"
};

