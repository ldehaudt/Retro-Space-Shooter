#include <ncurses.h>
#include "Unit.hpp"
#include "Player.hpp"
#include "EnemySpawner.hpp"
#include "ShootEnemySpawner.hpp"
#include "BounceEnemySpawner.hpp"
#include "Game.hpp"
#include <stdlib.h>
#include <ctime>

int main()
{
	initscr();
	
	int count;
	count = 0;

	int maxX;
	int maxY;

	srand(time(NULL));
	getmaxyx(stdscr, maxY, maxX);
	Game::sX = maxX;
	Game::sY = maxY;
	WINDOW* w = newwin(maxY - 2,maxX - 2,1,1);
	Game::win = w;
	timeout(1000/60);
	curs_set(0);
	refresh();
	start_color();
	init_color(1, 950, 800, 250);
	init_pair(1, 1, COLOR_BLACK);
	init_color(2, 250, 950, 300);
	init_pair(2, 2, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_color(3, 840, 320, 30);
	init_pair(4, 3, COLOR_BLACK);
	init_color(6, 900, 210, 90);
	init_pair(6, 6, COLOR_BLACK);
	wtimeout(w, 1000/60);
	keypad(w, true);
	int in;
	Player *p = new Player(10,Game::sY/2 - 1,0,'>', "Player");
	EnemySpawner *es1 = new EnemySpawner(30);
	BounceEnemySpawner *bes1 = new BounceEnemySpawner(70);
	ShootEnemySpawner *ses1 = new ShootEnemySpawner(120);
	Game::units = new Unit*[1];
	Game::units[0] = NULL;
	Game::addUnit(p);
	Game::addUnit(es1);
	Game::addUnit(bes1);
	Game::addUnit(ses1);
	mvwaddch(w, p->getY(), p->getX(), p->getChar());
	while (1){
		wattron(w, COLOR_PAIR(3));
		box(w, 0,0);
		mvwprintw(w, 0, 2, " SCORE - %d ", Game::score);
		mvwprintw(w, 0, 20, " LIVES - %d ", Game::lives);
		in = wgetch(w);
		for (int i = 0; Game::units[i]; i++)
		{
			if (Game::units[i]->frame(in) == 1)
			{
				mvwaddch(w, Game::units[i]->getY(), Game::units[i]->getX(), Game::units[i]->getChar());
			}
			else
			{
				Game::killUnit(Game::units[i]);
				i--;
			}
		}
		for (int i = 0; Game::units[i]; i++)
		{
			for (int j = i+1; Game::units[j]; j++)
			{
				if (Game::units[i]->getX() == Game::units[j]->getX() && 
					Game::units[i]->getY() == Game::units[j]->getY())
				{
					Game::units[i]->colide(Game::units[j]->getType());
					Game::units[j]->colide(Game::units[i]->getType());
				}
			}
		}
	}
	endwin();
}
