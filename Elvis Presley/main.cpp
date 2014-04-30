//
//  Main.cpp
//  Elvis Presley
//
//  Created by Jon Lowrey on 4/25/14.
//  Copyright (c) 2014 Jon Lowrey. All rights reserved.
//
/*
#include <iostream>
#include <fstream>

using namespace std;
struct song {
    char track;
    string title;
    string timemin,timesec;
    

};

struct album {
    char AlbName[50];
    char Date[50];
    song name[15];
    


}elvis[5];
int main(){
    ifstream input;
    input.open("smalld.dat");
    int i =0, n=0;
    
    while (input.get(elvis[0].AlbName, 20)){
        input.get( elvis[0].Date, 20);
        cout<<elvis[0].AlbName;
        cout<<elvis[0].Date;
        while (input >> (elvis[0].name[n].track)){
            if( elvis[0].name[0].track == '=') break;
            else{
                input >> elvis[0].name[n].title;
                cout<<elvis[0].name[n].title<<endl;
                input >> elvis[0].name[n].timemin;
                cout<<elvis[0].name[n].timemin<<endl;
                
            }
        }
    }
    
    
}*/
/*#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct song
{
    char track[2];
    char title[50];
    char timeMin[1];
    char timeSec[2];
};

struct album
{
    char albumName[20];
    char releaseDate[20];
    song songName[15];
};

int main()
{
    ifstream readFile;
    readFile.open("/Users/Jon/Desktop/albumData.txt");
    // read in data
    int i = 0, N = 0;
    album alb[5];
    while (readFile.is_open())
    {
        readFile.get(alb[i].albumName, 20);
        readFile.ignore(1, '\n');
        readFile.get(alb[i].releaseDate, 10);
        readFile.ignore(1, '\n');
        while ((readFile.get(&alb[i].songName[N].title[0],1)))
               {
                   if (alb[i].songName[N].title[0]== '=') break;
                   else{
                   int N = 0;
                   readFile.get(&alb[i].songName[N].track[0], 2);
                   //readFile.ignore(2);
                   readFile.get(&alb[i].songName[N].title[0], 37);
                   readFile.get(&alb[i].songName[N].timeMin[0], 1);
                   readFile.ignore(1);
                   readFile.get( &alb[i].songName[N].timeSec[0], 2);
                   readFile.ignore(2,'\n');
                       N++;}
               }
        if (readFile.eof()) readFile.close();
        i++;
    }
               // print the data
               for (i = 0; i < 5; i++)
               {
                   cout << alb[i].albumName << endl;
                   cout << alb[i].releaseDate << endl;
               }
               }*/

/*#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
struct song{
    string tracknum;
    string title;
    int timemin;
    int timesec;
    
};
struct elvis {
    string Album;
    string Date;
    song songname [14];
    
    
}elvis[5];

int main () {
    int line, album=0,song = 0;
    char ch;
    string file[64],files;
    ifstream myFile;
    myFile.open("data.dat");
    for (line =0; line<64;line++){
       // if (getline (myFile,files,'=')){}
        getline (myFile,files);
        
        
        istringstream instr(files);
        
        instr >> elvis[album].songname[song].tracknum;
        
        instr.get(ch);
        
        if (ch == ':')
            instr>>elvis[album].songname[song].timemin;
        
        
    }
    for (line = 0; line<64; line++){
        if (line == 0){
            elvis[0].Album=file[line];
            cout<<"!!!"<<elvis[0].Album<<endl;
        }
        if (line ==1){
            elvis[0].Date = file[line];
            cout<<elvis[0].Date<<endl;
        }
    
    
    }
    
    
} */
//Jon Lowrey
//Programming I
//Bill Mcdaniel
//A Program to Sort Elvis Records
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct album{string name; string year; string song[14];string min[14];string sec [14]; string num [14]; int totalsong; int timeMin[14]; int timeSec[14];};
int main()
{
    ifstream myFile;
    myFile.open("data.dat");
    string st, l, r;
    int debug=1, debugvariable=0, swaps, type = 0, typenext, gap, totalalbum=0, currentalbum=0,currentsong=0;
    //create array of structs
    album albums[7];
    
    
    //getline input
    albums[currentalbum].totalsong=0;
    while(getline(myFile,st))
    {
        //determine input type
        if (st[1]>=63||st[1]==',')
        {
            type=1;
            albums[currentalbum].totalsong = -1;
            
        }
        if (st[1]=='a'||st[1]=='o'||st[1]=='c'||st[1]=='p') {
            type = 2;
        }
        if (st[1]<=58) {
            type = 3;
        }
        if (st[1]==61) {
            type = 4;
        }
        //Store Files
        if (type==1) {
            albums[currentalbum].name = st;
        }
        if (type==2) {
            albums[currentalbum].year = st;
        }
        if (type==3) {
            albums[currentalbum].song[currentsong] = st.substr(4,37);
             //cout<<albums[currentalbum].song[currentsong]<<endl;
            albums[currentalbum].min[currentsong] = st.substr(41,1);
            //cout<<albums[currentalbum].min[currentsong]<<endl;
            albums[currentalbum].sec[currentsong] = st.substr(43,2);
            // cout<<albums[currentalbum].sec[currentsong]<<endl;
            albums[currentalbum].num[currentsong]= st.substr(0,4);
            currentsong++;
            albums[currentalbum].totalsong++;
        }
        if (type==4) {
            currentalbum++;
            totalalbum++;
            currentsong=0;
        }
        
    }

    //Sort Baby Sort
    //Albums first
    for (currentalbum = 0; currentalbum<=totalalbum; currentalbum++){

    }
    currentalbum = 0;
    currentsong = 0;
    swaps = 1;
    while (swaps == 1) {
        swaps=0;
        for (currentalbum = 0; currentalbum<totalalbum; currentalbum++) {
            if (albums[currentalbum].name.substr(0,6)>albums[currentalbum+1].name.substr(0,6)) {
//                cout<<albums[currentalbum].name<<endl;
                swap(albums[currentalbum+1],albums[currentalbum]);
                swaps=1;
            }
        }
    }
    
    for (currentalbum=0;currentalbum<=totalalbum;currentalbum++)
    {
        swaps=1;
        while (swaps==1)
        {
            swaps=0;
            for (currentsong=0;currentsong<albums[currentalbum].totalsong;currentsong++)
            {
                l=albums[currentalbum].song[currentsong];
                
                r=albums[currentalbum].song[currentsong+1];
                if (l>r)
                {
                    swap(albums[currentalbum].song[currentsong],albums[currentalbum].song[currentsong+1]);
                    swap(albums[currentalbum].min[currentsong],albums[currentalbum].min[currentsong+1]);
                    swap(albums[currentalbum].sec[currentsong],albums[currentalbum].sec[currentsong+1]);
                    swap(albums[currentalbum].num[currentsong],albums[currentalbum].num[currentsong+1]);
                    swaps=1;
                }
            }
        }
    }
    
    //print
    for (currentalbum = 0; currentalbum <=totalalbum; currentalbum++){
        cout<<albums[currentalbum].name<<endl;
        cout<<albums[currentalbum].year<<endl;
        for(currentsong = 0; currentsong<=albums[currentalbum].totalsong;currentsong++){
            cout<<albums[currentalbum].num[currentsong]<<albums[currentalbum].song[currentsong]<<albums[currentalbum].min[currentsong]<<":"<<albums[currentalbum].sec[currentsong]<<endl;
            char ch = (albums[currentalbum].min[currentsong].at(0));
            albums[currentalbum].timeMin[currentsong] = ch-42;
            ch = (albums[currentalbum].sec[currentsong].at(0));
            //albums[currentalbum].timeSec[currentsong]=(albums[currentalbum].sec[currentsong]-0);
        
        }
        cout << "=============================================" << endl;
        
    }
    
}*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

struct university{
    string name;
    string city;
}Ok[41];

int main (){
    ifstream myFile;
    myFile.open("universities.txt");
    string st;
    int i;
    
    for (i=0;i<41;i++){
        while (getchar(myFile)!='-'){
            myFile>>st;
            Ok[i].name+=st;
            
        }
        myFile>>Ok[i].city;
        
    }
    
}
