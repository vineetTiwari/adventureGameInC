//
//  main.c
//  AdventureGame
//
//  Created by Vineet Tiwari on 2015-05-06.
//  Copyright (c) 2015 vinny.co. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct room Room;
struct room {

  Room *right;
  Room *left;
  Room *top;
  Room *bottom;
  int content;
  int xCordinate;
  int yCordinate;
};

typedef struct player Player;
struct player {

  int health;
  Room *inRoom;
};

void status (Player *player1);
void movePlayer(Player *player1, Room *room);
void readInput(Player *player1);

int isGameOver;

int main(int argc, const char * argv[]) {
  int monster = 2;
  int empty = 0;
  int tresure = 1;
  isGameOver = 0;

  Room room1;
  room1.xCordinate = 0;
  room1.yCordinate = 0;

  Room room2;
  room2.xCordinate = 0;
  room2.yCordinate = 1;

  Room room3;
  room3.xCordinate = 0;
  room3.yCordinate = 2;

  Room room4;
  room4.xCordinate = 0;
  room4.yCordinate = 3;

  Room room5;
  room5.xCordinate = 1;
  room5.yCordinate = 0;

  Room room6;
  room6.xCordinate = 1;
  room6.yCordinate = 1;

  Room room7;
  room7.xCordinate = 1;
  room7.yCordinate = 2;

  Room room8;
  room8.xCordinate = 1;
  room8.yCordinate = 3;

  Room room9;
  room9.xCordinate = 2;
  room9.yCordinate = 0;

  Room room10;
  room10.xCordinate = 2;
  room10.yCordinate = 1;

  Room room11;
  room11.xCordinate = 2;
  room11.yCordinate = 2;

  Room room12;
  room12.xCordinate = 2;
  room12.yCordinate = 3;

  Room room13;
  room13.xCordinate = 3;
  room13.yCordinate = 0;

  Room room14;
  room14.xCordinate = 3;
  room14.yCordinate = 1;

  Room room15;
  room15.xCordinate = 3;
  room15.yCordinate = 2;

  Room room16;
  room16.xCordinate = 3;
  room16.yCordinate = 3;

  room1.right = &room2;
  room1.left = NULL;
  room1.top = NULL;
  room1.bottom = &room5;
  room1.content = empty;

  room2.right = &room3;
  room2.left = &room1;
  room2.top = NULL;
  room2.bottom = &room6;
  room2.content = empty;

  room3.right = &room4;
  room3.left = &room2;
  room3.top = NULL;
  room3.bottom = &room7;
  room3.content = empty;

  room4.right = NULL;
  room4.left = &room3;
  room4.top = NULL;
  room4.bottom = &room8;
  room4.content = empty;

  room5.right = &room6;
  room5.left = NULL;
  room5.top = &room1;
  room5.bottom = &room9;
  room5.content = empty;

  room6.right = &room7;
  room6.left = &room5;
  room6.top = &room2;
  room6.bottom = &room10;
  room6.content = empty;

  room7.right = &room8;
  room7.left = &room6;
  room7.top = &room3;
  room7.bottom = &room11;
  room7.content = empty;

  room8.right = NULL;
  room8.left = &room7;
  room8.top = &room4;
  room8.bottom = &room12;
  room8.content = empty;

  room9.right = NULL;
  room9.left = &room10;
  room9.top = &room5;
  room9.bottom = &room13;
  room9.content = empty;

  room10.right = &room11;
  room10.left = &room9;
  room10.top = &room6;
  room10.bottom = &room14;
  room10.content = empty;

  room11.right = &room12;
  room11.left = &room10;
  room11.top = &room7;
  room11.bottom = &room15;
  room11.content = tresure;

  room12.right = NULL;
  room12.left = &room11;
  room12.top = &room8;
  room12.bottom = &room16;
  room12.content = empty;

  room13.right = &room14;
  room13.left = NULL;
  room13.top = &room9;
  room13.bottom = NULL;
  room13.content = empty;

  room14.right = &room15;
  room14.left = &room13;
  room14.top = &room10;
  room14.bottom = &room5;
  room14.content = monster;

  room15.right = &room16;
  room15.left = &room14;
  room15.top = &room11;
  room15.bottom = NULL;
  room15.content = empty;

  room16.right = NULL;
  room16.left = &room15;
  room16.top = &room12;
  room16.bottom = NULL;
  room16.content = empty;

  Player player1;
  player1.inRoom = &room1;
  player1.health = 100;
  status(&player1);

  while (!isGameOver) {
    status(&player1);
    readInput(&player1);
  }



//  printf("Hello, World!\n");
    return 0;
}

void status (Player *player1) {

  printf("You are in room %d,%d \nYour health: %d \nYour exits are: \n", player1->inRoom->xCordinate, player1->inRoom->yCordinate, player1->health);
  if (player1->inRoom->right != NULL) {
    printf("right\n");
  }
  if (player1->inRoom->left != NULL) {
    printf("left\n");
  }
  if (player1->inRoom->top != NULL) {
    printf("top\n");
  }
  if (player1->inRoom->bottom != NULL) {
    printf("bottom\n");
  }

}


void movePlayer(Player *player1, Room *room) {
//  if (room != NULL) {
//    if (room->content == monster) {
//
//    }
      player1->inRoom = room;

}

void readInput(Player *player1) {
  fpurge(stdin);
  char input[20];
  scanf("%20[^\n]", input);
  if (strcasecmp(input, "right" ) == 0) {
    movePlayer(player1, player1->inRoom->right);
  }
  if (strcasecmp(input, "left") == 0) {
    movePlayer(player1, player1->inRoom->left);
  }
  if (strcasecmp(input, "top") == 0) {
    movePlayer(player1, player1->inRoom->top);
  }
  if (strcasecmp(input, "bottom") == 0) {
    movePlayer(player1, player1->inRoom->bottom);
  }
}







