#include "Music.h"
#include <string>

int main() {

	MusicStreamingService myService("MyMusic");

	myService.addMusic("Golden", "KDH", "KDH", 2025);
	myService.addMusic("Jump", "BlackPink", "album", 2025);
	

	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;

	Music* result = myService.searchByTitle(music_title);
	if (result != NULL) {
		cout << " Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else {
		cout << " Not found" << endl;
	}

	string artist_name;
	cout << "Enter the Artist Name : ";
	cin >> artist_name;
	vector<Music*> artistResult = myService.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << " Found" << artistResult.size() << " songs by " << artist_name << endl;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endl;
		}
	}
	else {

	}


	return 0;
}