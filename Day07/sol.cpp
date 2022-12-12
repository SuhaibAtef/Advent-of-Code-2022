#include "./../bits/stdc++.h"
using namespace std;
typedef long long ll;

struct FIL
{
        string name;
        long long size;
};

struct DIR
{
        string name;
        long long size;
        vector<FIL> Files;
        vector<DIR *> Directories;
        vector<string> DirNames;
        DIR *parentDirectory;
        DIR(string s)
        {
                name = s;
        }
};

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<DIR *> path;

        DIR *home = new DIR("/");
        home->size = 0;
        home->parentDirectory = NULL;
        path.push_back(home);

        DIR **Head = &home;
        string line;
        while (getline(cin, line))
        {
                if (line == "")
                        break;
                string word;
                stringstream iss(line);
                iss >> word;
                if (word == "$")
                {
                        // Instruction
                        iss >> word;
                        if (word == "cd")
                        {
                                iss >> word;
                                if (word == "/")
                                {
                                        // Home
                                        *Head = home;
                                }
                                else if (word == "..")
                                {
                                        if ((*Head)->parentDirectory != NULL)
                                                *Head = (*Head)->parentDirectory;
                                }
                                else
                                {
                                        for (auto it = (*Head)->Directories.begin(); it != (*Head)->Directories.end(); it++)
                                        {
                                                if (word == (*it)->name)
                                                {
                                                        *Head = (*it);
                                                        break;
                                                }
                                        }
                                }
                                cout << "Entered :" << (*Head)->name << endl;
                        }
                        else
                        {
                                // List Items
                                (*Head)->size = 0;
                        }
                }
                else
                {
                        if (word == "dir")
                        {
                                // directory
                                iss >> word;
                                DIR *d = new DIR(word);
                                d->size = 0;
                                d->parentDirectory = *Head;
                                (*Head)->Directories.push_back(d);
                                path.push_back(d);
                        }
                        else
                        {
                                // File
                                FIL newFile;
                                newFile.size = (long long)stoi(word);
                                (*Head)->size += newFile.size;
                                iss >> word;
                                newFile.name = word;
                                (*Head)->Files.push_back(newFile);
                        }
                }
        }
        ll sum = 0;

        for (auto it = path.rbegin(); it != path.rend(); it++)
        {

                for (auto i = (*it)->Directories.begin(); i != (*it)->Directories.end(); i++)
                {
                        (*it)->size += (*i)->size;
                }

                if ((*it)->size < 100000)
                        sum += (*it)->size;
                // cout << (*it)->name << " " << (*it)->size << endl;
        }

        cout << sum << endl;
        string nameofSmallest;
        ll valueofSmallest = 70000000;
        for (auto it = path.begin(); it != path.end(); it++)
        {
                cout << (70000000 - (*path.begin())->size) + (*it)->size << " " << (*it)->name << " " << (*it)->size << endl;
                if ((70000000 - (*path.begin())->size) + (*it)->size > 30000000)
                {
                        if ((*it)->size <= valueofSmallest)
                        {
                                valueofSmallest = (*it)->size;
                                nameofSmallest = (*it)->name;
                        }
                }
        }
        cout << valueofSmallest << endl;
}
