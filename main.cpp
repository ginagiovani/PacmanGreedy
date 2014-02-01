#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;


const int MAXROWS = 32;
const int MAXCOLUMNS = 28;

char keyboardValue = 127;
int pacI = 15, pacJ = 0;
int ghostOneI = 16, ghostOneJ = 14;
int node1i = 16, node1j = 5;
int i = 0 , j = 0;
char key = 127;

// 20 = dinding
//111 = pil
// 99 = pil emas
//074 = pacman bergerak ke kanan
//076 = pacman bergerak ke kiri
//118 = pacman bergerak ke atas
//94 = pacman bergerak ke bawah
// 87 = ghost1
// 88 = ghost2
// 89 = ghost3


char levelMatrix[MAXROWS][MAXCOLUMNS] = 
    {
	   { 20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20},
	   { 20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20,  99,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20,  99,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20, 111, 111, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111, 111, 111,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 000,  20,  20, 000,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 000,  20,  20, 000,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20,  20, 000, 000, 000, 000,  20,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20, 000, 000, 000, 000, 000, 000,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20, 000, 000, 000, 000, 000, 000,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   {074, 000, 000, 000, 000, 000, 111, 000, 000, 000,  20, 000, 000, 000, 000, 000, 000,  20, 000, 000, 000, 111, 000, 000, 000, 000, 000, 000},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20, 000, 000, 000, 000, 000, 000,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20, 000, 000, 000, 000, 000, 000,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20,  20, 000, 000, 000, 000,  20,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20,  20,  20,  20,  20,  20, 111,  20,  20, 000,  20,  20,  20,  20,  20,  20,  20,  20, 000,  20,  20, 111,  20,  20,  20,  20,  20,  20},
	   { 20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20, 111,  20,  20,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20, 111,  20,  20,  20,  20, 111,  20},
	   { 20,  99, 111, 111,  20,  20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20,  20, 111, 111,  99,  20},
	   { 20,  20,  20, 111,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20, 111,  20,  20,  20},
	   { 20,  20,  20, 111,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20, 111,  20,  20,  20},
	   { 20, 111, 111, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111,  20,  20, 111, 111, 111, 111, 111, 111,  20},
	   { 20, 111,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20},
	   { 20, 111,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20,  20, 111,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20, 111,  20},
	   { 20, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  20},
	   { 20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20,  20}

    };

char ghostCurrent = levelMatrix[ghostOneI][ghostOneJ];
char ghostTrail = ghostCurrent[&ghostOneI][&ghostOneJ];

void getKeyPress(char key);
bool blockValid(int block);
void Ghost();
void GoToXY(int column, int line);
bool ghostMoveUp();
bool ghostMoveDown();
bool ghostMoveLeft();
bool ghostMoveRight();
int findNode();

int pillCount = 244;
int lives = 5;
clock_t startTime = 0, endTime= 0;
bool superPellet = false;
bool pill = false;

struct node {
	int x;
	int y;
	node *parent;
};

class Point {
public:
	int f;
	int g;
	int h;
	int x;
	int y;
	Point* parentPoint;
	node *position;

	Point() {
		g = 0;
		position = new node;
		position->parent = 0;
	}
	
	Point(int dx, int dy) {
		g = 0;
		this->set(dx, dy);
		position = new node;
		position->x = dx;
		position->y = dy;
		position->parent = 0;
	}
	
	void set(int dx, int dy){
		x = dx;
		y = dy;
	}
	
	int getX() {
		return x;
	}
	
	int getY() {
		return y;
	}
};


class Path {
public:
	int size;
	vector<Point> points;

	Path() {
		size = 0;
	}
	
	void addToStack(Point x) {
		points.push_back(x);
	}
	
	Point removeFromStack(Point x) {
		Point thePoint = Point();
		for(int i = 0; i < points.size(); i++) {
			Point z = points.at(i);
			if(z.x == x.x && z.y == x.y) {
				thePoint.set(points.at(i).x, points.at(i).y);
				points.erase(points.begin()+i);
				break;
			}
		}
		return thePoint;
	}
	
	int theSize() {
		return points.size();
	}
	
	void cekData() {
		cout << "DATA: \n";
		for(i = 0; i < points.size(); i++) {
			Point xx = points.at(i);
			cout << xx.x << ", " << xx.y << "\n";
		}
		cout << "\n";
	}
	
	Point removeFromFront() {
		Point rem = points.at(this->theSize() - 1);
		return this->removeFromStack(rem);
	}
	
	Point getLowest() {
		int zx = 0;
		int f;
		int pos;
		if(points.size() > 0) {
			do {
				Point z = points.at(zx);
				if(zx == 0){
					f = z.f;
					pos = zx;
				}
				else {
					if(f > z.f) {
						f = z.f;
						pos = zx;
					}
				}
				zx++;
			} while(zx < points.size());
		}
		return points.at(pos);
	}

	bool pointExist(Point x) {
		for(int i = 0; i < points.size(); i++) {
			Point z = points.at(i);
			if(z.x == x.x && z.y == x.y) {
				return true;
				break;
			}
		}
		return false;
	}

	void populateWithNeighbors(Point checked) {
		if(MAXROWS > (checked.y + 1) && levelMatrix[checked.y + 1][checked.x] != 20) {
			this->addToStack(Point(checked.x, checked.y + 1));
		}
		if(MAXCOLUMNS > (checked.x + 1) && levelMatrix[checked.y][checked.x + 1] != 20) {
			this->addToStack(Point(checked.x + 1, checked.y));
		}
		if(0 <= (checked.y - 1) && levelMatrix[checked.y - 1][checked.x] != 20) {
			this->addToStack(Point(checked.x, checked.y - 1));
		}
		if(0 <= (checked.x - 1) && levelMatrix[checked.y][checked.x - 1] != 20) {
			this->addToStack(Point(checked.x - 1, checked.y));
		}
	}

	void populateWithPath(Point popo, Point starttt) {
		this->addToStack(popo);
		int zz = 0;
		do{
			zz++;
			Point zx = popo;
			popo = Point(zx.position->x, zx.position->y);
			popo.position = zx.position->parent;
			this->addToStack(popo);
		} while(popo.position->parent != 0);
	}
};

bool isMatch(Point p1, Point p2) {
	if(p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
		return true;
	}
	return false;
}

int heuristic(Point a, Point b) {
	int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);
    int D = 1;
    return D * (dx + dy);
}

Path astar(Point start, Point goal) {
	Path opened = Path();
	Path closed = Path();
	opened.addToStack(start);
	int step = 0;

	while(!isMatch(opened.getLowest(), goal)) {
		Point current = opened.getLowest();
		opened.removeFromStack(current);
		closed.addToStack(current);
		Path neighbors = Path();
		neighbors.populateWithNeighbors(current);

		for(int x = 0; x < neighbors.theSize(); x++) {
			int cost = current.g + 1;			
			Point curNeighbor = neighbors.points.at(x);
			if(opened.pointExist(curNeighbor) && cost < curNeighbor.g) {
				opened.removeFromStack(curNeighbor);

			}
			if(closed.pointExist(curNeighbor) && cost < curNeighbor.g) {
				closed.removeFromStack(curNeighbor);
			}
			if(!opened.pointExist(curNeighbor) && !closed.pointExist(curNeighbor)) {
				curNeighbor.g = cost; 
				curNeighbor.f = cost + heuristic(curNeighbor, goal);
				curNeighbor.position->x = curNeighbor.x;
				curNeighbor.position->y = curNeighbor.y;
				curNeighbor.position->parent = current.position;
				opened.addToStack(curNeighbor);
			}
		}
		step++;
	}
	
	Point dgoal = opened.getLowest();
	Path walkthrough;
	walkthrough.populateWithPath(dgoal, start);
	return walkthrough;
}

Point cariBolaTarget(Point awalan) {
	int xs = awalan.y, ys = awalan.x; 
        
	for (int d = 1; d < MAXCOLUMNS; d++)
	{
	    for (int i = 0; i < d + 1; i++)
	    {
	        int x1 = xs - d + i;
	        int y1 = ys - i;
	        
	        if(x1 >= 0 && x1 < MAXCOLUMNS &&
					y1 >= 0 && y1 < MAXROWS) {
		        if(levelMatrix[y1][x1] == 111) {
		        	return Point(x1, y1);
		        }
			}
				
	        int x2 = xs + d - i;
	        int y2 = ys + i;
	        
	        if(x2 >= 0 && x2 < MAXCOLUMNS &&
					y2 >= 0 && y2 < MAXROWS) {
		        if(levelMatrix[y2][x2] == 111) {
		        	return Point(x2, y2);
		        }
			}
	    }
	    
	    for (int i = 1; i < d; i++)
	    {
	        int x1 = xs - i;
	        int y1 = ys + d - i;
	
	        if(x1 >= 0 && x1 < MAXCOLUMNS &&
					y1 >= 0 && y1 < MAXROWS) {
		        if(levelMatrix[y1][x1] == 111) {
		        	return Point(x1, y1);
		        }
			}
	
	        int x2 = xs + d - i;
	        int y2 = ys - i;
	        
	        if(x2 >= 0 && x2 < MAXCOLUMNS &&
					y2 >= 0 && y2 < MAXROWS) {
		        if(levelMatrix[y2][x2] == 111) {
		        	return Point(x2, y2);
		        }
			}
	    }
	}
	return Point(-1, -1);
}

int main()
{
  HANDLE  hConsole;
  int k =10;
  
  Path perjalanan = Path();
  Point bola = Point();
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);

  cout << "\n\n\n\n\t\t\tAnalisis Algoritma\n";
  cout << "\t\t       Pacman dengan greedy\n";
  cout << "\t\t---------------------------------\n";
  cout << "\t\t\t* Gina Giovani\n";
  cout << "\t\t\t* Naufal Mahardika\n";
  cout << "\t\t\t* Yanwar P. Wanasuka\n\n\n\n";
  cout << "\t\t"; 
  system("PAUSE");
	    
  char key = 0;
  system("mode 80, 50");
  int pills = 30;
  bool stopCounting  = false;

    int xyz = 0;
   cout <<"\n\n"; 
    do
    {
       cout <<"\n\n"; 
	   GoToXY(0, 0);
	   if(xyz == 2) {
	   	xyz = 0;
	   	Ghost();
	   }
	   xyz++;
	   for (i = 0; i <= 31; i++)
	   {
		  for (j = 0; j <= 27; j++)
		  {
			 if (levelMatrix[i][j] == 20)
			 {
				k = 1;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 else if (levelMatrix[i][j] == 074 || levelMatrix[i][j] == 076 || levelMatrix[i][j] == 118 ||levelMatrix[i][j] == 94)
			 {
				k = 14;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 else if (levelMatrix[i][j] == 000)
			 {
				k = 0;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 else if (levelMatrix[i][j] == 87)
			 {
				if (superPellet)
				{
				    k = 7;
				    SetConsoleTextAttribute(hConsole, k);
				}
				else
				{
				    k = 4;
				    SetConsoleTextAttribute(hConsole, k);
				}
			 }
			 else if (levelMatrix[i][j] == 111)
			 {
				k = 15;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 else if (levelMatrix[i][j] == 99)
			 {
				k = 14;
				SetConsoleTextAttribute(hConsole, k);
			 }

			 cout << levelMatrix[i][j];
			 if ( j == 27)
				cout << endl;

			 if ( j == 27 && i == 31)
				stopCounting = true;
		  }  
	   }

		if(perjalanan.theSize() <= 1) {
			perjalanan = Path();
			bola = cariBolaTarget(Point(pacI, pacJ));

			if(!isMatch(Point(-1, -1), bola)) {
				perjalanan = astar(Point(pacJ, pacI), bola);
			}
		}

		if(perjalanan.theSize() <= 0) {
			break;
		} else { 
			Point nextPath = perjalanan.removeFromFront();
			if(nextPath.x > pacJ) {
				getKeyPress(77);
			} else if(nextPath.x < pacJ) {
				getKeyPress(75);
			}
			if(nextPath.y > pacI) {
				getKeyPress(80);
			} else if(nextPath.y < pacI) {
				getKeyPress(72);
			}
		}
	   
	   k = 15;
	   SetConsoleTextAttribute(hConsole, k);
	   cout << "\n\n";
	   cout << "Nyawa Tersisa : " << lives << endl;
	   endTime = clock();
	   int elapsed = int((endTime - startTime) / CLOCKS_PER_SEC);
	   

	   if (elapsed > 5)
	   {
		  superPellet = false;
		  elapsed = 0;
	   }
	   Sleep(0);
    }
    while (lives >= 0 || pillCount != 0);
      k = 14;
      SetConsoleTextAttribute(hConsole, k);
      system("cls");
      cout << "\n\n\n\t\t\tSelamat Kita Menaaaang!\n";
      cout << "\n\n\t\t";
      system("pause");
	return 0;
};

bool ghostMoveUp()
{
    char ghostNextUp = levelMatrix[ghostOneI - 1][ghostOneJ];
    if ( ghostNextUp != 20)
    {
	   if ( ghostNextUp == 111 || ghostNextUp == 117 )
	   {
		  levelMatrix[ghostOneI - 1][ghostOneJ] = 87;
		  levelMatrix[ghostOneI][ghostOneJ] = ghostTrail;
		  ghostOneI--;
	   }
	   else
	   {
		  pill = false;
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI - 1][ghostOneJ] = 87;
		  ghostOneI--;
	   }
	   return true;
    }
    else
    {
	   return false;
    }
}

bool ghostMoveDown()
{

    char ghostNextDown = levelMatrix[ghostOneI + 1][ghostOneJ];
    if ( ghostNextDown != 20)
    {
	   if ( ghostNextDown == 111 || ghostNextDown ==117)
	   {
		  levelMatrix[ghostOneI + 1][ghostOneJ] = 87;
		  levelMatrix[ghostOneI][ghostOneJ] = ghostNextDown;
		  ghostOneI++;
	   }
	   else
	   {
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI + 1][ghostOneJ] = 87;
		  ghostOneI++;
	   }
	   return true;
    }
    else
    {
	   return false;
    }
}

bool ghostMoveLeft()
{
    char ghostNextLeft = levelMatrix[ghostOneI][ghostOneJ - 1];
    if ( ghostNextLeft != 20)
	   {
		  if ( ghostNextLeft == 111 || ghostNextLeft ==117)
		  {
			 levelMatrix[ghostOneI][ghostOneJ - 1] = 87;
			 levelMatrix[ghostOneI][ghostOneJ] = ghostNextLeft;
			 ghostOneJ--;
		  }
		  else
		  {
			 levelMatrix[ghostOneI][ghostOneJ] = 000;
			 levelMatrix[ghostOneI][ghostOneJ - 1] = 87;
			 ghostOneJ--;
		  }
		   return true;
	   }
        else
	   {
		  return false;
	   }

}

bool ghostMoveRight()
{
    char ghostNextRight = levelMatrix[ghostOneI][ghostOneJ + 1];
    if ( ghostNextRight != 20)
    {
	  
	   if ( ghostNextRight == 111 || ghostNextRight ==117)
	   {
		  levelMatrix[ghostOneI][ghostOneJ + 1] = 87;
		  levelMatrix[ghostOneI][ghostOneJ] = ghostNextRight;
		  ghostOneJ++;
	   }
	   else
	   {
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI][ghostOneJ + 1] = 87;
		  ghostOneJ++;
	   }
	   return true;
    }
    else
    {
	   return false;
    }

}

void Ghost()
{
    if (superPellet)
    {
	   if ( pacI > ghostOneI)
	   {
		  if (!ghostMoveUp())
		  { 

		  }
	   }
	   else if (pacI < ghostOneI)
	   {
		  if (!ghostMoveDown())
		  {

		  }
	   }
       if (pacJ > ghostOneJ)
	   {
		  if (!ghostMoveLeft())
		  {

		  }
	   }
	   else if (pacJ < ghostOneJ)
	   {
		  if (!ghostMoveRight())
		  {

		  }
	   }
    }
    else
    {
	   if ( pacI < ghostOneI)
	   {
		  if (!ghostMoveUp())
		  { 

		  }
	   }
	   else if (pacI > ghostOneI)
	   {
		  if (!ghostMoveDown())
		  {

		  }
	   }
	   if (pacJ < ghostOneJ)
	   {
		  if (!ghostMoveLeft())
		  {

		  }
	   }
	   else if (pacJ > ghostOneJ)
	   {
		  if (!ghostMoveRight())
		  {

		  }
	   }
    }
    if (pacJ == ghostOneJ && pacI == ghostOneI && superPellet)
    {
	   levelMatrix[ghostOneI][ghostOneJ] = 074;
	   ghostOneI = 16;
	   ghostOneJ = 14;
	   levelMatrix[16][14] = 87;
    }
    else if (pacJ == ghostOneJ && pacI == ghostOneI)
    {
	   lives--;
	   levelMatrix[pacI][pacJ] = 000;
	   levelMatrix[ghostOneI][ghostOneJ] = 000;
	   pacI = 15;
	   pacJ = 0;
	   ghostOneI = 16;
	   ghostOneJ = 14;
	   levelMatrix[15][0] = 074;
	   levelMatrix[16][14] = 87;
    }
}

void getKeyPress(char dkey)
{
	key = -32;
    char pacTemp = '<';
	if (key == 0 || key == -32)
	{
		key = dkey;

		if (key == 72)
		{
		   if ( levelMatrix[pacI- 1][pacJ] != 20)
		   {
			 if (levelMatrix[pacI- 1][pacJ] == 99)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI - 1][pacJ] = 118;
			 pacI--;
		   }
		}
		else if (key == 75)
		{
		    if ( levelMatrix[pacI][pacJ- 1] != 20)
		    {
			 if (levelMatrix[pacI][pacJ - 1] == 99)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI][pacJ - 1] = 076;
			 pacJ--;
		    }
		}
		else if (key == 77)
		{
		    if ( levelMatrix[pacI][pacJ+ 1] != 20)
		    {
			 if (levelMatrix[pacI][pacJ + 1] == 99)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI][pacJ + 1] = 074;
			 pacJ++;
		    }
		}
		else if (key == 80)
		{
		   if ( levelMatrix[pacI + 1][pacJ] != 20)
		   {
			 if (levelMatrix[pacI + 1][pacJ] == 99)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI + 1][pacJ] = 94;
			 pacI++;
		   }
	   }
    }
}

void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    if (!SetConsoleCursorPosition(hConsole, coord))
    {

    }
}

