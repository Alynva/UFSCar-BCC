#include <vector>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Ponto.h"

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif


using namespace std;

void getch(void) {
	system("read z");
}
int indexOfId(char word, auto base) {
	int k;
	for (k = 0; k < base.size(); k++) {
		if (base[k].getId() == word) {
			return k;
		}
	}
	return -1;
}

int main() {
//	cout << "\033[0m\033[2J\033[1;1H";
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	string MSGs[8];
	MSGs[0] = "This point can't to be in this coordinate X.";
	MSGs[1] = "This point can't to be in this coordinate Y.";
	MSGs[2] = "This point can't go more.";
	MSGs[3] = "This point don't exist.";
	MSGs[4] = "Please, don't put equal points.";
	MSGs[5] = "These points are in similar coordinates.";
	MSGs[6] = "Yes.";
	MSGs[7] = "No.";
	
	// BRANCO CLARO NO PRETO	SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
	
	// PRETO NO BRANCO CLARO	SetConsoleTextAttribute(hConsole, 240) || cout << "\033[30;107m";
	// PRETO NO AMARELO			SetConsoleTextAttribute(hConsole, 224) || cout << "\033[30;103m";
	// VERDE CLARO NO PRETO		SetConsoleTextAttribute(hConsole, 10) || cout << "\033[92;40m";
	// VERDE ESCURO NO PRETO	SetConsoleTextAttribute(hConsole, 2) || cout << "\033[32;40m";
	// CIANO CLARO NO PRETO		SetConsoleTextAttribute(hConsole, 11) || cout << "\033[96;40m";
	// CIANO ESCURO NO PRETO	SetConsoleTextAttribute(hConsole, 3) || cout << "\033[36;40m";
	// AZUL CLARO NO PRETO		SetConsoleTextAttribute(hConsole, 9) || cout << "\033[94;40m";
	// AZUL ESCURO NO PRETO		SetConsoleTextAttribute(hConsole, 1) || cout << "\033[34;40m";
	
	vector<Ponto> thePoints;
	vector<Ponto> tmpObjs;
	
	string cmd[5];
	
	int i, j, k, l, m, rows = thePoints[0].rows, cols = thePoints[0].cols, theIndex;
	bool isPoint;
	do {
//		system("CLS");
//		cout << "\033[2J\033[1;1H";
		if (system("CLS")) system("clear");
		
		for(i = 0; i < rows; i++) {
			for(j = 0; j < cols; j++) {
				isPoint = false;
				for (k = 0; k < thePoints.size(); k++) {
					if (thePoints[k].getX() == j - cols / 2 && thePoints[k].getY() == -(i - rows / 2)) {
						isPoint = true;
						break;
					}
				}
				if (isPoint) {
				
					SetConsoleTextAttribute(hConsole, 10) || cout << "\033[92;40m";
					cout << thePoints[k].getId();
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else if (i == 0 && j == cols / 2) {
				
					SetConsoleTextAttribute(hConsole, 11) || cout << "\033[94m";
					cout << "^";
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else if (i == rows / 2 && j == cols - 1) {
				
					SetConsoleTextAttribute(hConsole, 11) || cout << "\033[96;40m";
					cout << ">";
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else if (i == rows / 2 && j == cols / 2) {
				
					SetConsoleTextAttribute(hConsole, 2) || cout << "\033[32;40m";
					cout << "+";
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else if (i == rows / 2) {
				
					SetConsoleTextAttribute(hConsole, 3) || cout << "\033[36;40m";
					cout << "-";
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else if (j == cols / 2) {
				
					SetConsoleTextAttribute(hConsole, 1) || cout << "\033[34;40m";
					cout << "|";
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
				
				} else {
					
					SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
					cout << " ";
				
				}
			}
			cout << endl;
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, 240) || cout << "\033[30;107m";
		cout << "TIPY YOUR COMMAND: ";
		
		cin >> cmd[0];
		SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";

		if (cmd[0] == "exit");
		else if (cmd[0] == "help") {
			
			cout << endl;
			SetConsoleTextAttribute(hConsole, 224) || cout << "\033[30;103m";
			cout << "exit                                 >> To exit" << endl;
			cout << "help                                 >> To show the commands" << endl;
			cout << endl << "// Where have '[id]', is the identificator of the point'" << endl;
			cout <<			"// Where have '[X]'/'[Y]' is the coordinate X/Y" << endl << endl;
			cout << "new [X] [Y]                          >> To create a new point in X and Y" << endl;
			cout << "[id] to [X] [Y]                      >> To move the point to X and Y" << endl;
			cout << "[id] ['up'/'right'/'down'/'left']    >> To move the point a unit to up/right/down/left" << endl;
			cout << "midd [id] [id]                       >> To calculate the middle point between two points" << endl;
			cout << "[id] = midd [id] [id]                >> To put a point in the middle between two points" << endl;
			cout << "collin [id] [id] [id]                >> To check if tree points are collinears" << endl;
			cout << "dist points [id] [id]                >> To calculate the distance between two points" << endl;
			cout << "del [id]                             >> To delete the point";
			SetConsoleTextAttribute(hConsole, 15) || cout << "\033[0m";
			cout << endl << endl;
			
			getch();
		} else if (cmd[0] == "new") {
			cin >> cmd[1] >> cmd[2];

			thePoints.push_back(Ponto());
			
			if (!thePoints.back().setX(atoi(cmd[1].c_str()))) {
				cout << MSGs[0] << endl;
				getch();
			}
			if (!thePoints.back().setY(atoi(cmd[2].c_str()))) {
				cout << MSGs[1] << endl;
				getch();
			}
			
		} else if (cmd[0] == "del") {
			
			cin >> cmd[1];
			theIndex = indexOfId(*cmd[1].c_str(), thePoints);
			if (theIndex != -1) {
				
				thePoints.erase(thePoints.begin() + theIndex);
				
			} else {
				
				cout << MSGs[3] << endl;
				getch ();
			}
			
		} else if (cmd[0] == "midd") {
			
			cin >> cmd[1] >> cmd[2];
			if (cmd[1] != cmd[2]) {
				
				k = indexOfId(*cmd[1].c_str(), thePoints);
				l = indexOfId(*cmd[2].c_str(), thePoints);

				if (thePoints[k].getX() != thePoints[l].getX() || thePoints[k].getY() != thePoints[l].getY()) {
					
					cout << "~";
					middPoint(thePoints[k], thePoints[l]).print();
					
				} else {
					
					cout << MSGs[5] << endl;
				}
				
			} else {
				
				cout << MSGs[4] << endl;
			}
			
			getch();
		} else if (cmd[0] == "collin") {
			
			cin >> cmd[1] >> cmd[2] >> cmd[3];
			if (cmd[1] != cmd[2] && cmd[2] != cmd[3] && cmd[3] != cmd[1]) {
				
				if (isColli(thePoints[indexOfId(*cmd[1].c_str(), thePoints)], thePoints[indexOfId(*cmd[2].c_str(), thePoints)], thePoints[indexOfId(*cmd[3].c_str(), thePoints)])) {
					
					cout << MSGs[6] << endl;
				} else {
					
					cout << MSGs[7] << endl;
				}
				
				getch();
			} else {
				
				cout << MSGs[5] << endl;
				getch();
			}
			
		} else if (cmd[0] == "dist") {
			cin >> cmd[1];
			if (cmd[1] == "points") {
				cin >> cmd[2] >> cmd[3];
				if (cmd[2] != cmd[3]) {
					if (indexOfId(*cmd[2].c_str(), thePoints) != -1 && indexOfId(*cmd[3].c_str(), thePoints) != -1) {
						
						tmpObjs.push_back(thePoints[indexOfId(*cmd[2].c_str(), thePoints)]);
						tmpObjs.push_back(thePoints[indexOfId(*cmd[3].c_str(), thePoints)]);

						cout << distPoints(tmpObjs[0], tmpObjs[1]) << endl;

						tmpObjs.clear();
					} else {
						cout << MSGs[3] << endl;
					}
				} else {
					cout << MSGs[4] << endl;
				}
				getch();
			} else if (cmd[1] == "segms") {
			} else if (cmd[1] == "pointSegm") {
			}
		}else {
			
			isPoint = false;
			k = indexOfId(*cmd[0].c_str(), thePoints);
			if (k != -1) {
				
				cin >> cmd[1];
				if (cmd[1] == "=") {
					
					cin >> cmd[2];
					if (cmd[2] == "midd") {
						
						cin >> cmd[3] >> cmd[4];
						if (cmd[3] != cmd[4]) {
							
							l = indexOfId(*cmd[3].c_str(), thePoints);
							m = indexOfId(*cmd[4].c_str(), thePoints);

							if (thePoints[l].getX() != thePoints[m].getX() || thePoints[l].getY() != thePoints[m].getY()) {
								
								thePoints[k] = middPoint(thePoints[l], thePoints[m]);
							} else {
								
								cout << MSGs[5] << endl;
								getch();
							}
							
						} else {
							
							cout << MSGs[4] << endl;
							getch();
						}
						
					}
					
				} else if (cmd[1] == "to") {
					
					cin >> cmd[2] >> cmd[3];
					if (!thePoints[k].setX(atoi(cmd[2].c_str()))) {
						
						cout << MSGs[0] << endl;
						getch();
					}
					
					if (!thePoints[k].setY(atoi(cmd[3].c_str()))) {
						
						cout << MSGs[1] << endl;
						getch();
					}
					
				} else if (cmd[1] == "up") {
					
					if (!thePoints[k].setY(thePoints[k].getY()+1)) {
						
						cout << MSGs[2] << endl;
						getch();
					}
					
				} else if (cmd[1] == "right") {
					
					if (!thePoints[k].setX(thePoints[k].getX()+1)) {
						
						cout << MSGs[2] << endl;
						getch();
					}
					
				} else if (cmd[1] == "down") {
					
					if (!thePoints[k].setY(thePoints[k].getY()-1)) {
						
						cout << MSGs[2] << endl;
						getch();
					}
					
				} else if (cmd[1] == "left") {
					
					if (!thePoints[k].setX(thePoints[k].getX()-1)) {
						
						cout << MSGs[2] << endl;
						getch();
					}
					
				}
				
			}
			
		}
		
	} while (cmd[0] != "exit");
	
	return 7;
}
