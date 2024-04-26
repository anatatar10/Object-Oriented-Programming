#include<iostream>
#include<ostream>
#include<exception>
#include"Song.h"
#include"SongCollection.h"

int main()
{
	try {
		SongCollection sc = SongCollection("songs1.txt.txt");
		/*std::cout << "Top 10 artists by number of songs" << endl;
		sc.printTopArtistsByNumberOfSongs(10);
		cout << "\n";
		cout << "Artists by name in increasing order";
		sc.sortByArtistNameIncreasing();
		sc.printArtists();*/
		cout << "Titles by name in decreasing order:" << endl;
		sc.sortByTitleNameDescending();
		sc.printTitles();
		std::vector<Song> searchedSongs = sc.searchSongs("no");
		cout << "Songs with the word " << "no " << "in it are" << endl;
		for (int i = 0; i < searchedSongs.size(); i++)
		{
			cout <<searchedSongs[i].getTitle() << " by "<<searchedSongs[i].getArtist()<<endl;
		}
	} 
	catch (const std::invalid_argument& expt)
	{
		std::cerr << "Error: " << expt.what();
	}

	
	return 0;
}