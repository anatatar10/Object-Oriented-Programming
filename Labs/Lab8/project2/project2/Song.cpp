#include "Song.h"
#include<string>
#include<sstream>
#include<cctype>
#include<algorithm>

Song::Song(string artist, string title, string lyrics)
{
	this->artist = artist;
	this->title = title;
	
	std::replace_if(lyrics.begin(), lyrics.end(), [](char c) {return std::ispunct(c);}, ' ');
	stringstream ss(lyrics);
	string word;
	while (getline(ss, word, ' '))
	{
		for (int i = 0; i < word.size(); i++)
		{
			word[i] = tolower(word[i]);
		}
		this->lyrics.push_back(word);
	}
}

string Song::getArtist() const
{
	return artist;
}

string Song::getTitle() const
{
	return title;
}

vector<string> Song::getLyrics() const
{
	return lyrics;
}

string Song::toString()
{
	string result = "";
	result = result + artist + " " + title + "\n";
	for (int i = 0; i < lyrics.size(); i++)
	{
		result = result + lyrics[i] + " ";
	}
	return result;
}

bool Song::operator<(const Song& other) const
{
	return title < other.title;
}
