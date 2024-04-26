#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"Song.h"
#include<set>
#include<map>
using namespace std;
class SongCollection
{
public:
	SongCollection(const std::string& file);
	set<string> uniqueArtists();
	map<string, vector<Song>> storeSongsByArtist();
	void printTopArtistsByNumberOfSongs(int n);
	void sortByArtistNameIncreasing();
	void sortByTitleNameDescending();
	void sortByNoOfWordsInLyricsIncreasing();
	vector<Song> searchSongs(const string word);
	void printArtists();
	void printTitles();
	
private:
	vector<Song> songs;
	map<string, set<Song>> mapWordSongs;
};

