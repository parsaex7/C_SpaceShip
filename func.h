#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>

#define RED 12
#define WHITE 15
#define BLUE 1
#define GREEN 2
#define ORANGE 4
#define ENEMY_RELEASE_TIME 2000
#define AIRPLANE_RELEASE_TIME 10000
#define BOMB_RELEASE_TIME 15000
#define ENTEHARI_RELEASE_TIME 17000
#define SCREEN_HEIGHT 33
#define SCREEN_WIDTH 100
DWORD LastReleaseTime, Current; //for min
DWORD LastScoreUpdateTime, now; //for score
DWORD BeforePlane, NowPlane;
DWORD  BeforeBomb, NowBomb;
DWORD BeforeEntehari, NowEntehari;
int x = 47, y = 29; //middle
int score = 0;
char key; //opr
int SelectedOption;
int gamecnt;
char infoo[20][30];
int choose;
int aa;
int cnt; //max shoot
int ShootCnt; //min shoot
int mine = 0; //min mine
int nmine = 0; // max mine
int PlaneCnt; //min plane
int MaxplaneCnt;// max plane
int MinHealCnt;//min heal
int MaxHealCnt;//max heal
int MinBombCnt;// min bomb plane
int MaxBombCnt; // max bomb plane
int MinBombThrowCnt;//max bomb
int MaxBombThrowCnt;//min bomb
int MinEntehari;//min entehari
int MaxEntehari;// max entehari
int MinTir;//min tir
int MaxTir;//max tir
int tmp1, tmp2;

/* 123
   %## 1
   &#@ 2
*/

/*     12345
       \   / 1
        .|.  2
       --o-- 3
        '|'  4
*/

/* 123
   |*| 1
*/

/*    1234567891234
 1        __|__
 2    -o-o-(_)-o-o-
*/

/*
    1234
     __  1
    |++| 2
    |__| 3
*/

/*
    123456789
       _|_     1
    ---(*)---  2
      " ' "    3
*/

/*  123456
     ____  1
    |BOMb| 2
*/

/*  123456789
       | |    1
    --=oOo=-- 2
*/

/* 1
   * 1
*/

typedef struct sp
{
    int health;
    int power;
    char shape[4][5];
} spaceship;

typedef struct sh 
{
    int ex;
    int ey;
} shoot;

typedef struct mi
{
    int ax;
    int ay;
    char look[3];       
} min;

typedef struct bar
{
    int qx;
    int qy;
    int hp1;
    char shap[2][13];
} bari;

typedef struct he
{
    int sx;
    int sy;
    char loo[3][4];

} joon;

typedef struct bo
{
    int dx;
    int dy;
    int hp2;
    char shape1[3][9];
} bombAfkan;

typedef struct boo 
{
    int zx;
    int zy;
    char shape2[2][6];
} Bomb1;

typedef struct ent 
{
    int rx;
    int ry;
    int hp3;
    char shape3[2][9];
} enete;

typedef struct ti 
{
    int fx;
    int fy;
} tti;

shoot fire[1000];
min EnemyMin[100];
bari plane[50];
joon heal[50];
bombAfkan BombPlane[50];
Bomb1 BOMb[50];
enete entehari[50];
tti tir[200];
char EffectShape[2][3];
spaceship fly;


void clearscreen();
void setTextColor(int);
void gotoxy(int, int);
void InitialEffectShape();
void InitialMin();
void InitialSpaceShip();
void InitialPlane();
void InitialPlaneShape();
void InitialHealShape();
void InitialBombPlaneShape();
void InitialBombPlane();
void InitialBombShape();
void InitalEntehariShape();
void InitalEntehari();
void PrintSpaceShip();
void PrintEffect(int, int);
void DeleteEffect(int, int);
void DeleteSpaceShip(int, int);
void PrintBorder();
void PrintShoot(shoot);
void DeleteShoot(int, int);
void PrintMin(min);
void DeleteMin(min);
void PrintPlane(bari);
void DeletePlane(bari);
void PrintHeal(joon);
void DeleteHeal(joon);
void PrintBombPlane(bombAfkan);
void DeleteBombPlane(bombAfkan);
void PrintBomb(Bomb1);
void DeleteBomb(Bomb1);
void PrintEntehari(enete);
void PrintTir(tti);
void DeleteTir(tti);
void DeleteEntehari(enete);
void MoveSpaceShip();
void refreshShoot();
void refreshMin();
void refreshPlane();
void refreshTir();
void refreshAll();
void displayMainMenu(int);
void DisplayLevelMenu(int);
int MainMenu(int); // -1 = exit | 0 = easy | 1 = medium | 2 = hard | 3 = score
void EasyPlay();
void PrintFinishGameMenu(int);
int SelectedOptionFinishMenu(); //0 = rematch  1 = main menu
void PrintGameData(); // for file
void StoreGameData();
void PrintScoreMenu(int);
void ScoreMenu();
void GoodBye();


/*
123456789123456789123456789123456789123456789123456789123456789123
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠒⠒⠢⢄⡀⠀⠀⢠⡏⠉⠉⠉⠑⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     1
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠀⠀⠀⠀⠀⠙⢦⠀⡇⡇⠀⠀⠀⠀⠀⠀⠈⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀       2
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠊⠉⠉⠙⠒⢤⡀⠀⣼⠀⠀⢀⣶⣤⠀⠀⠀⢣⡇⡇⠀⠀⢴⣶⣦⠀⠀⠀⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     3
⠀⠀⠀⢀⣠⠤⢄⠀⠀⢰⡇⠀⠀⣠⣀⠀⠀⠈⢦⡿⡀⠀⠈⡟⣟⡇⠀⠀⢸⡇⡆⠀⠀⡼⢻⣠⠀⠀⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     
⠀⢀⠖⠉⠀⠀⠀⣱⡀⡞⡇⠀⠀⣿⣿⢣⠀⠀⠈⣧⣣⠀⠀⠉⠋⠀⠀⠀⣸⡇⠇⠀⠀⠈⠉⠀⠀⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀    5
⣠⠏⠀⠀⣴⢴⣿⣿⠗⢷⡹⡀⠀⠘⠾⠾⠀⠀⠀⣿⣿⣧⡀⠀⠀⠀⢀⣴⠇⣇⣆⣀⢀⣀⣀⣀⣀⣤⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   6
⣿⠀⠀⢸⢻⡞⠋⠀⠀⠀⢿⣷⣄⠀⠀⠀⠀⠀⣠⡇⠙⢿⣽⣷⣶⣶⣿⠋⢰⣿⣿⣿⣿⣿⣿⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   
⡿⡄⠀⠈⢻⣝⣶⣶⠀⠀⠀⣿⣿⣱⣶⣶⣶⣾⡟⠀⠀⠀⢈⡉⠉⢩⡖⠒⠈⠉⡏⡴⡏⠉⠉⠉⠉⠉⠉⠉⠉⡇⠀⠀⢀⣴⠒⠢⠤⣀
⢣⣸⣆⡀⠀⠈⠉⠁⠀⠀⣠⣷⠈⠙⠛⠛⠛⠉⢀⣴⡊⠉⠁⠈⢢⣿⠀⠀⠀⢸⠡⠀⠁⠀⠀⠀⣠⣀⣀⣀⣀⡇⠀⢰⢁⡇⠀⠀⠀⢠
⠀⠻⣿⣟⢦⣤⡤⣤⣴⣾⡿⢃⡠⠔⠒⠉⠛⠢⣾⢿⣿⣦⡀⠀⠀⠉⠀⠀⢀⡇⢸⠀⠀⠀⠀⠀⠿⠿⠿⣿⡟⠀⢀⠇⢸⠀⠀⠀⠀⠘
⠀⠀⠈⠙⠛⠿⠿⠿⠛⠋⢰⡋⠀⠀⢠⣤⡄⠀⠈⡆⠙⢿⣿⣦⣀⠀⠀⠀⣜⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⢀⠃⠀⡸⠀⠇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢣⠀⠀⠈⠛⠁⠀⢴⠥⡀⠀⠙⢿⡿⡆⠀⠀⢸⠀⢸⢰⠀⠀⠀⢀⣿⣶⣶⡾⠀⢀⠇⣸⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡀⢇⠀⠀⠀⢀⡀⠀⠀⠈⢢⠀⠀⢃⢱⠀⠀⠀⡇⢸⢸⠀⠀⠀⠈⠉⠉⠉⢱⠀⠼⣾⣿⣿⣷⣦⠴⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⠘⡄⠀⠀⢹⣿⡇⠀⠀⠈⡆⠀⢸⠈⡇⢀⣀⣵⢨⣸⣦⣤⣤⣄⣀⣀⣀⡞⠀⣠⡞⠉⠈⠉⢣⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢃⠘⡄⠀⠀⠉⠀⠀⣠⣾⠁⠀⠀⣧⣿⣿⡿⠃⠸⠿⣿⣿⣿⣿⣿⣿⠟⠁⣼⣾⠀⠀⠀⠀⢠⠇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⠹⣀⣀⣤⣶⣿⡿⠃⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⢻⣿⣷⣦⣤⣤⠎⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣤⣿⡿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠀⠀⠀⠀⠀
*/