#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <vector>


#define SPEED 10


enum Direction {
	STOP = 0, LEFT, RIGHT, UP, DOWN
};

class Position {
	private:
		int x;
		int y;

	public:
		Position(int x, int y) {
			this->x = x;
			this->y = y;
		}
		
	void setX(int x) {
		this->x = x;
	}
	void incrementX() {
		this->x++;
	}
	void decrementX() {
		this->x--;
	}
	
	void setY(int y) {
		this->y = y;
	}
	void incrementY() {
		this->y++;
	}
	void decrementY() {
		this->y--;
	}
	
	int getX() const {
		return this->x;
	}
	int getY() const {
		return this->y;
	}	
};

class Game {
	
	private:
		bool gameOver;
		int width;
		int height;
		Position *fruits;
		Position *player;
		std::vector<Position*> tail;
		int score;
		Direction direction;
	
	public:
		Game(int width, int height) {
			this->width = width;
			this->height = height;
			
			this->score = 0;
			
			this->fruits = new Position(0, 0);
			this->player = new Position(0, 0);
			
		}
		
		void addTail(int x, int y) {
			Position p = Position(x, y);
			this->tail.push_back(&p);
		}
		
		void setup() {
			srand(time(NULL));
			
			this->gameOver = false;
			
			this->direction = STOP;
			
			this->player->setX(this->width / 2);
			this->player->setY(this->height / 2);
			
			this->respawnFruit();
		}
		
		void respawnFruit() {
			int w = rand() % this->width;
			int h = rand() % this->height;
			
			if (w <= 1) {
				w++;
			}
			if (w >= this->width-1) {
				w--;
			}
			if (h <= 1) {
				h++;
			}
			if (h >= this->height-1) {
				h--;
			}
			
			this->fruits->setX(w);
			this->fruits->setY(h);
			if(this->score > 0) {
				this->addTail(w, h);
			}
		}
		
		void renderBar() {
			for(int i = 0; i < this->width; i++) {
				std::cout << "#";
			}
			std::cout << std::endl;
		}
		
		void renderGame() {
			
			for(int i = 0; i < this->height; i++) {
				for (int j = 0; j < this->width; j++) {
					
					if (j == 0 || j == this->width - 1) {
						std::cout << "#";
					}
					else if (!this->renderPlayer(i, j) && !this->renderFruit(i, j)) {
						
						bool print = false;
						for(int k = 0; k < this->tail.size(); k++) {
				
							if(this->canRenderTail(k, j, i)) {
								std::cout << "o";
								
								print = true;			
							}				
						}
						if (!print) {
							std::cout << " ";
						}
						
					}
				}
				std::cout << std::endl;
			}	
		}
		
		bool canRenderTail(int k, int j, int i) {
						
			if((j == this->tail[k]->getX() && j < this->width-1) && i == this->tail[k]->getY()) {
				return true;
			}
			
			return false;
		}
				
		bool renderPlayer(int i, int j) {
			if(i == this->player->getY() && j == this->player->getX()) {
				std::cout << "O";
				return true;
			}
			return false;
		}
		
		bool renderFruit(int i, int j) {
			if(i == this->fruits->getY() && j == this->fruits->getX()) {
				std::cout << "F";
				return true;
			}
			return false;
		}
		
		bool hasAteFruit() {
			if (this->player->getX() != this->fruits->getX()) {
				return false;
			}
			if (this->player->getY() != this->fruits->getY()) {
				return false;
			}

			return true; 
		}
		
		void draw() {
			system("cls");

			this->renderBar();
			this->renderGame();
			this->renderBar();
			std::cout << "SCORE: " << this->score << std::endl;
			Sleep(SPEED);
		}
		
		void input() {
			if(_kbhit()) {
				
				switch(_getch()) {
					case 'a': {
						this->direction = LEFT;
						break;
					}
					case 'w': {
						this->direction = UP;
						break;
					}
					case 'd': {
						this->direction = RIGHT;
						break;
					}
					case 's': {
						this->direction = DOWN;
						break;
					}
					case 'x': {
						this->gameOver = true;
						break;
					}
				}
			}
		}
		
		
		
		void logic() {
			int nTail = this->tail.size();
				
			if(nTail > 0) {
				
				Position prev = Position(0, 0);
				
				Position *first = this->tail.front();
				
				prev.setX(first->getX());
				prev.setY(first->getY()); 
				
				Position prev2 = Position(0, 0);
				
				Position *p = new Position(0, 0);
				p->setY(this->player->getY());
				p->setX(this->player->getX());
				this->tail[0] = p;
			
			
				for(int i = 1; i < nTail; i++) {
					
					Position *second = this->tail[i];
					prev2.setX(second->getX());
					prev2.setY(second->getY());
					
					Position *p2 = new Position(0, 0);
					p2->setX(prev.getX());
					p2->setY(prev.getY());
					this->tail[i] = p2;
					
					prev = prev2;
				}
			}
						
			switch(this->direction) {
				case UP: {
					this->player->decrementY();
					break;
				}
				case LEFT: {
					this->player->decrementX();
					break;
				}
				case RIGHT: {
					this->player->incrementX();
					break;
				}
				case DOWN: {
					this->player->incrementY();
					break;
				}
				case STOP: {
					
					break;
				}
			}
			
			if (this->hasAteFruit()) {
				this->score += 10;
				this->respawnFruit();
			}
		}
		
		void run() {
			this->setup();
			
			while(!this->gameOver) {
				this->draw();
				this->input();
				this->logic();
			}
		}
};

