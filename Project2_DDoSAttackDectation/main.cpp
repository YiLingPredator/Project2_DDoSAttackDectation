//
//  main.cpp
//  Project2_DDoSAttackDectation
//
//  Created by YI LING on 9/20/14.
//  Copyright (c) 2014 YI LING. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void split()
{
    fstream inout;
    //char line[1000];
    string line;
    vector<string>no;
    vector <string> time;
    vector<string>::iterator ptime;
    vector <string> source;
    vector<string>::iterator psource;
    vector <string> destination;
    vector<string>::iterator pdestination;
    vector <string> protocol;
    vector<string>::iterator pprotocol;
    vector <string> length;
    vector<string>::iterator plength;
    vector <string> info;
    vector<string>::iterator pinfo;
    int j=0;
    
    //inout.open("/Users/Alex/Desktop/icmptrace.txt",ios::in);
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/ddostrace.20070804_134936.txt",ios::in);
    
    if (inout.fail()) {
        cout<<"File does not exit";
    }
    
    while (!inout.eof()) {
        //inout.getline(line, 1000,'"');
        getline(inout,line,'\"');
        cout<<line<<endl;
        //if (strcmp(line, ",")*strcmp(line, "\0")*strcmp(line, "\n"))
        if(line.compare(",")&&line.compare("\0")&&line.compare("\n"))
        {
            string temp=line;
            //string temp=line+'\0';
            switch (j%7) {
                case 0:
                    no.push_back(temp);j++;break;
                case 1:
                    time.push_back(temp);j++;break;
                case 2:
                    source.push_back(temp);j++;break;
                case 3:
                    destination.push_back(temp);j++;break;
                case 4:
                    protocol.push_back(temp);j++;break;
                case 5:
                    length.push_back(temp);j++;break;
                case 6:
                    info.push_back(temp);j++;break;                    
                default:
                    break;
            }
        }
    }
    inout.close();
    
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/time.txt",ios::out);
    
    for (ptime=time.begin(); ptime!=time.end(); ptime++) {
        inout<<*ptime<<endl;
    }
    inout.close();
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/srouce.txt",ios::out);
    for (psource=source.begin(); psource!=source.end(); psource++) {
        inout<<*psource<<endl;
    }
    inout.close();
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/destination.txt",ios::out);
    for (pdestination=destination.begin(); pdestination!=destination.end(); pdestination++) {
        inout<<*pdestination<<endl;
    }
    inout.close();
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/protocol.txt",ios::out);
    for (pprotocol=protocol.begin(); pprotocol!=protocol.end(); pprotocol++) {
        inout<<*pprotocol<<endl;
    }
    inout.close();
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/length.txt",ios::out);
    for (plength=length.begin(); plength!=length.end(); plength++) {
        inout<<*plength<<endl;
    }
    inout.close();
    inout.open("/Users/Alex/Documents/MST STUDY/Project working material/Project 2 network attack detction/DDoS dataset/info.txt",ios::out);
    for (pinfo=info.begin(); pinfo!=info.end(); pinfo++) {
        inout<<*pinfo<<endl;
    }
    inout.close();
}

int main(int argc, const char * argv[])
{
    split();
    
    
}

