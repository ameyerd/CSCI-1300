#include <iostream>
#include <string>
#include <ctime>

using namespace std;


int handshakes(int n) {
    // simplest cases
	if (n <= 1) {
        return 0;
    }
	// reduction step
	return n-1 + handshakes(n-1);
}



int main() {

    int n;
    cout << "How many people at your meeting? n = ";
    cin >> n;

    cout << handshakes(n) << " handshakes for everyone to meet." << endl;

    return 0;
}