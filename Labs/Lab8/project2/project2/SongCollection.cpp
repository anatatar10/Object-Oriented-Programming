#include "SongCollection.h"
#include"Song.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

SongCollection::SongCollection(const std::string& file)
{
	std::ifstream in_file(file);
	if (!in_file.is_open())
	{
		throw invalid_argument("File could not be open");
	}
	else
	{
		string line, artist, title, lyrics;
		int ok = 0;
		while (getline(in_file, line))
		{
			if (line.find("ARTIST=") == 0)
			{
				int pos = line.find("\"") + 1;
				int posEnd = line.length() - 1;
				artist = line.substr(pos, posEnd - pos);
			}
			else if (line.find("TITLE=") == 0)
			{
				int pos = line.find("\"") + 1;
				int posEnd = line.length() - 1;
				title = line.substr(pos, posEnd - pos);
			}
			else
			{
				if (line.find("LYRICS=") == 0)
				{
					ok = 1;
					lyrics = "";
					int pos = line.find("\"") + 1;
					int posEnd = line.length();
					lyrics = line.substr(pos, posEnd - pos);

				}
				else if (line.find("\"") == 0)
				{
					ok = 0;
					Song s = Song(artist, title, lyrics);
					
					for (string word : s.getLyrics())
					{
						mapWordSongs[word].insert(s);
					}
					songs.push_back(s);
					//cout<< s.toString()<<endl;
				}
				else
				{
					if (ok == 1)
					{
						lyrics = lyrics + "\n" + line;
					}
				}
			}
		}
	}
	in_file.close();
}

set<string> SongCollection::uniqueArtists()
{
	set<string> result;
	for (int i = 0; i < songs.size(); i++)
	{
		result.insert(songs[i].getArtist());

	}
	return result;
}

map<string, vector<Song>> SongCollection::storeSongsByArtist()
{
	map<string, vector<Song>> result;
	for (int i = 0; i < songs.size(); i++)
	{
		result[songs[i].getArtist()].push_back(songs[i]);

	}
	return result;
}

void SongCollection::printTopArtistsByNumberOfSongs(int n)
{
	multimap<int, string, std::greater<int>> count;
	map<string, vector<Song>> result = storeSongsByArtist();
	
	for (auto& element : result)
	{
		count.insert({ element.second.size(), element.first });
	}
	int nr = 0;
	for (auto& element : count)
	{
		std::cout << element.second << " " << element.first << endl;
		nr++;
		if (nr == n)
		{
			break;
		}
	}
}

void SongCollection::sortByTitleNameDescending()
{
	std::sort(songs.begin(), songs.end(), [](const Song& song1, const Song& song2)
		{
			return song1.getTitle() > song2.getTitle();
		});
}

void SongCollection::sortByNoOfWordsInLyricsIncreasing()
{
	std::sort(songs.begin(), songs.end(), [](const Song& song1, const Song& song2)
		{
			return song1.getLyrics().size() < song2.getLyrics().size();
		});
}

void SongCollection::sortByArtistNameIncreasing()
{
	std::sort(songs.begin(), songs.end(), [](const Song& song1, const Song& song2)
		{
			return song1.getArtist() < song2.getArtist(); 
		});
	
}

vector<Song> SongCollection::searchSongs(const string word)
{
	vector<Song> result;
	for (auto& element : mapWordSongs[word])
	{
		result.push_back(element);
	}
	
	
	return result;
}

void SongCollection::printArtists()
{
	set<string> result = uniqueArtists();
	for (auto it = result.begin(); it!= result.end(); ++it)
	{
		cout << *it << endl;
	}
}

void SongCollection::printTitles()
{
	set<string> result;
	for (int i = 0; i < songs.size(); i++)
	{
		result.insert(songs[i].getTitle());
	}
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << endl;
	}
}


