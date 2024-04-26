#pragma once
#include<string>
#include<vector>
using namespace std;

class Song
{
public:
	Song(string artist, string title, string lyrics);
	string getArtist() const;
	string getTitle() const;
	vector<string> getLyrics() const;
	string toString();
	bool operator<(const Song& other) const;

protected:
	std::string artist;
	std::string title;

private:
	std::vector<std::string> lyrics;

};

