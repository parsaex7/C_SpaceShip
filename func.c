#include "./func.h"


void clearScreen() {
    system("cls");
}

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void InitialEffectShape()
{
    EffectShape[0][0] = '%';
    EffectShape[0][1] = '#';
    EffectShape[0][2] = '#';
    EffectShape[1][0] = '&';
    EffectShape[1][1] = '#';
    EffectShape[1][2] = '@';
}



void InitialMin() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int ranX = (rand() % (94)) + 2;  // Adjusted to ensure enemy is fully visible
        EnemyMin[i].ax = ranX;
        EnemyMin[i].ay = 3;
        for (int j = 0; j < 3; j++) {
            if (j == 1)
                EnemyMin[i].look[j] = '*';
            else
                EnemyMin[i].look[j] = '|';
        }
    }
}

void InitialPlaneShape()
{
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0 ; i < 13; i++)
            plane[j].shap[0][i] = ' ';
        plane[j].shap[0][4] = '_'; plane[j].shap[0][5] = '_'; plane[j].shap[0][6] = '|'; plane[j].shap[0][7] = '_'; plane[j].shap[0][8] = '_';
        plane[j].shap[1][0] = '-'; plane[j].shap[1][1] = 'o'; plane[j].shap[1][2] = '-'; plane[j].shap[1][3] = 'o'; plane[j].shap[1][4] = '-'; plane[j].shap[1][5] = '('; plane[j].shap[1][6] = '_'; plane[j].shap[1][7] = ')';
        plane[j].shap[1][8] = '-'; plane[j].shap[1][9] = 'o'; plane[j].shap[1][10] = '-'; plane[j].shap[1][11] = 'o'; plane[j].shap[1][12] = '-';
    }
}

void InitialPlane()
{
    InitialPlaneShape();
    srand(time(NULL));
    for (int i = 0 ; i < 30; i++)
    {
        plane[i].hp1 = 3;
        plane[i].qx = (rand() % 85) + 2;
        plane[i].qy = 4;
    }
}

void InitialSpaceShip()
{
    fly.health = 100;
    fly.power = 1;
    fly.shape[2][2] = 'o'; fly.shape[2][1] = '-'; fly.shape[2][0] = '-'; fly.shape[2][3] = '-'; fly.shape[2][4] = '-'; //middle 3rd row
    fly.shape[1][1] = '.'; fly.shape[1][2] = '|'; fly.shape[1][3] = '.';// 2nd row
    fly.shape[3][1] = '\''; fly.shape[3][2] = '|'; fly.shape[3][3] = '\'';//4th row
    fly.shape[0][0] = '/'; fly.shape[0][4] = '\\'; //1st row
    fly.shape[0][1] = ' '; fly.shape[0][2] = ' '; fly.shape[0][3] = ' '; fly.shape[1][0] = ' '; fly.shape[1][4] = ' '; fly.shape[3][0] = ' '; fly.shape[3][4] = ' '; //other
}

void InitialHealShape()
{
    for (int i = 0; i < 50; i++)
    {
        heal[i].loo[0][0] = ' '; heal[i].loo[0][3] = ' '; heal[i].loo[0][1] = '_'; heal[i].loo[0][2] = '_';
        heal[i].loo[1][0] = '|'; heal[i].loo[1][1] = '+'; heal[i].loo[1][2] = '+'; heal[i].loo[1][3] = '|';
        heal[i].loo[2][0] = '|'; heal[i].loo[2][1] = '_'; heal[i].loo[2][2] = '_'; heal[i].loo[2][3] = '|';
    }
}

void InitialBombShape()
{
    for (int i = 0; i < 50; i++)
    {
        BOMb[i].shape2[0][0] = ' ';
        BOMb[i].shape2[0][1] = '_';
        BOMb[i].shape2[0][2] = '_';
        BOMb[i].shape2[0][3] = '_';
        BOMb[i].shape2[0][4] = '_';
        BOMb[i].shape2[0][5] = ' ';
        BOMb[i].shape2[1][0] = '|';
        BOMb[i].shape2[1][1] = 'B';
        BOMb[i].shape2[1][2] = 'O';
        BOMb[i].shape2[1][3] = 'M';
        BOMb[i].shape2[1][4] = 'b';
        BOMb[i].shape2[1][5] = '|';
    }
}




void InitialBombPlaneShape()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 1)
            {
                for (int k= 0; k < 9; k++)
                    BombPlane[i].shape1[j][k] = ' ';
            }
        }
        BombPlane[i].shape1[0][4] = '|';
        BombPlane[i].shape1[1][0] = '-';
        BombPlane[i].shape1[1][1] = '-';
        BombPlane[i].shape1[1][2] = '-';
        BombPlane[i].shape1[1][3] = '(';
        BombPlane[i].shape1[1][4] = '*';
        BombPlane[i].shape1[1][5] = ')';
        BombPlane[i].shape1[1][6] = '-';
        BombPlane[i].shape1[1][7] = '-';
        BombPlane[i].shape1[1][8] = '-';
        BombPlane[i].shape1[2][2] = '\"';
        BombPlane[i].shape1[2][4] = '\'';
        BombPlane[i].shape1[2][6] = '\"';
    }
}

void InitialBombPlane()
{
    srand(time(NULL));
    InitialBombPlaneShape();
    for (int i = 0; i < 50; i++)
    {
        BombPlane[i].dx = 90;
        BombPlane[i].dy = (rand() % 10) + 4;
        BombPlane[i].hp2 = 2;
    }
}

void InitalEntehariShape()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 5)
                entehari[i].shape3[0][j] = '|';
            else
                entehari[i].shape3[0][j]= ' ';
        }
        entehari[i].shape3[1][0] = '-';
        entehari[i].shape3[1][1] = '-';
        entehari[i].shape3[1][2] = '=';
        entehari[i].shape3[1][3] = 'o';
        entehari[i].shape3[1][4] = 'O';
        entehari[i].shape3[1][5] = 'o';
        entehari[i].shape3[1][6] = '=';
        entehari[i].shape3[1][7] = '-';
        entehari[i].shape3[1][8] = '-';
    }
}

void InitalEntehari()
{
    srand(time(NULL));
    InitalEntehariShape();
    for (int i = 0; i < 50; i++)
    {
        entehari[i].hp3 = 3;
        entehari[i].rx = (rand() % 85) + 2;
        entehari[i].ry = 2;
    }
}


void PrintSpaceShip() //up left corner = x,y
{
    for (int i = 0 ; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0 ; j < 5; j++)
        {
            printf("%c", fly.shape[i][j]);
        }
    }
}

void DeleteSpaceShip(int x, int y)
{
    for (int i = 0 ; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0 ; j < 5; j++)
        {
            printf(" ");
        }
    }
}

void PrintBorder() {
    for (int i = 0; i < 100; i++)
        printf("-");

    for (int i = 2; i < 33; i++) {
        gotoxy(0, i);
        printf("|");

        gotoxy(99, i);
        printf("|");
    }
    gotoxy(0, 33);
    for (int i = 0; i < 100; i++)
        printf("-");
    printf("\e[?25l");
}

void PrintEffect(int a, int b)
{
    setTextColor(RED);
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a,b + i);
        for (int j = 0; j < 3; j++)
            printf("%c", EffectShape[i][j]);
    }
    setTextColor(WHITE);
    usleep(80000);
}

void DeleteEffect(int a, int b)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a,b + i);
        for (int j = 0; j < 3; j++)
            printf(" ");
    }
}

void PrintShoot(shoot a)
{
    gotoxy(a.ex, a.ey);
    setTextColor(RED);
    printf("|");
    setTextColor(WHITE);
}       

void DeleteShoot(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}

void PrintMin(min a)
{
    gotoxy(a.ax, a.ay);
    setTextColor(BLUE);
    for (int i = 0 ; i < 3; i++)
        printf("%c", a.look[i]);
    setTextColor(WHITE);
}

void DeleteMin(min a)
{
    gotoxy(a.ax, a.ay);
    printf("   ");
}

void PrintPlane(bari a)
{
    if (a.hp1 == 2)
        setTextColor(BLUE);
    else if (a.hp1 == 1)
        setTextColor(RED);
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.qx,a.qy + i);
        for (int j = 0; j < 13; j++)
        {
            printf("%c", a.shap[i][j]);
        }
    }
    setTextColor(WHITE);
}

void DeletePlane(bari a)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.qx,a.qy + i);
        for (int j = 0; j < 13; j++)
        {
            printf(" ");
        }
    }
}

void PrintHeal(joon a)
{
    setTextColor(GREEN);
    for (int i = 0 ; i < 3; i++)
    {
        gotoxy(a.sx,a.sy + i);
        for (int j = 0 ; j < 4; j++)
            printf("%c", a.loo[i][j]);
    }
    setTextColor(WHITE);
}

void DeleteHeal(joon a)
{
    for (int i = 0 ; i < 3; i++)
    {
        gotoxy(a.sx,a.sy + i);
        for (int j = 0 ; j < 4; j++)
            printf(" ");
    }
}

void PrintBombPlane(bombAfkan a)
{
    if (a.hp2 == 1)
        setTextColor(RED);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(a.dx, a.dy + i);
        for (int j = 0; j < 9; j++)
            printf("%c", a.shape1[i][j]);
    }
}

void DeleteBombPlane(bombAfkan a)
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(a.dx, a.dy + i);
        for (int j = 0; j < 9; j++)
            printf(" ");
    }
}

void PrintBomb(Bomb1 a)
{
    setTextColor(RED);
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.zx,a.zy + i);
        for (int j = 0; j < 6; j++)
            printf("%c", a.shape2[i][j]);
    }
    setTextColor(WHITE);
}

void DeleteBomb(Bomb1 a)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.zx,a.zy + i);
        for (int j = 0; j < 6; j++)
            printf(" ");
    }
}

void PrintEntehari (enete a)
{
    if (a.hp3 == 2)
        setTextColor(BLUE);
    else if (a.hp3 == 1)
        setTextColor(RED);
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.rx, a.ry + i);
        {
            for (int j = 0; j < 9; j++)
                printf("%c", a.shape3[i][j]);
        }
    }
    setTextColor(WHITE);
}

void DeleteEntehari(enete a)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(a.rx, a.ry + i);
        {
            for (int j = 0; j < 9; j++)
                printf(" ");
        }
    }
}

void PrintTir(tti a)
{
    gotoxy(a.fx,a.fy);
    setTextColor(BLUE);
    printf("*");
    setTextColor(WHITE);
}

void DeleteTir(tti a)
{
    gotoxy(a.fx,a.fy);
    printf(" ");
}

void MoveSpaceShip()
{
        if (key == ' ' || key == 32)
        {
            fire[aa].ex = x + 2; fire[aa].ey = y - 1;
            PrintShoot(fire[aa]);
            aa++;
        }
        if (key == 'a' || key == 27)
        {
            if (x - 3 > 0)
                (x) -= 3;
        }
        else if (key == 'd'|| key == 24)
        {
            if (x + 8 < 100)
                x += 3;
        }
        else if (key == 'w' || key == 72)
        {
            if (y - 3 > 0)
                y -= 2;
        }
        else if (key == 's'|| key == 80)
        {
            if (y + 4 < 33)
                y += 2;
        }
}

void refreshPlane()
{
    static int l = 0;
    NowPlane = GetTickCount();
    if (NowPlane - BeforePlane > AIRPLANE_RELEASE_TIME)
    {
        PrintPlane(plane[MaxplaneCnt]);
        MaxplaneCnt++;
        BeforePlane = NowPlane;
    }
    if (l % 3 == 0)
    {
        for (int i = PlaneCnt; i < MaxplaneCnt; i++)
        {
            if (plane[i].qy > 30)
            {
                if (plane[i].qy == 35)
                    continue;
                DeletePlane(plane[i]);
                PlaneCnt++;
            }
            else
            {
                DeletePlane(plane[i]);
                plane[i].qy += 1;
                PrintPlane(plane[i]);
            }
            if ((plane[i].qx + 12 >= x && plane[i].qx <= x + 4) && (plane[i].qy >= y - 2 && plane[i].qy <= y + 3)) //hit of plane and spaceShip
            {
                DeletePlane(plane[i]);
                PrintSpaceShip();
                plane[i].qy = 35;
                fly.health -= 40;
            }
        }
        
    }
    if (l > 10000)
        l = 0;
    l++;
}

void refreshShoot()
{
    for (int i = ShootCnt; i < cnt; i++) {
        if (fire[i].ey > 3) {
            DeleteShoot(fire[i].ex, fire[i].ey);
            fire[i].ey--;
            PrintShoot(fire[i]);
        } else if (fire[i].ey == 3) {
            if (fire[i].ey == 2)
                continue;
            DeleteShoot(fire[i].ex, 3);
            ShootCnt++;
        }
        if ((fire[i].ey >= plane[MaxplaneCnt - 1].qy && fire[i].ey <= plane[MaxplaneCnt - 1].qy + 1) && (fire[i].ex >= plane[MaxplaneCnt - 1].qx && fire[i].ex <= plane[MaxplaneCnt - 1].qx + 12))//check for the hit of shoot and plane
        {
            DeleteShoot(fire[i].ex, fire[i].ey);
            fire[i].ey = 2;
            plane[MaxplaneCnt - 1].hp1--;
            score += 5;
            if (plane[MaxplaneCnt - 1].hp1 == 0)
            {
                heal[MaxHealCnt].sx = plane[MaxplaneCnt - 1].qx + 7;
                heal[MaxHealCnt].sy = plane[MaxplaneCnt - 1].qy + 2;
                DeletePlane(plane[MaxplaneCnt - 1]);
                PrintEffect(plane[MaxplaneCnt - 1].qx + 5, plane[MaxplaneCnt - 1].qy);
                DeleteEffect(plane[MaxplaneCnt - 1].qx + 5, plane[MaxplaneCnt - 1].qy);
                plane[MaxplaneCnt - 1].qy = 35; 
                PrintHeal(heal[MaxHealCnt]);
                MaxHealCnt++;
            }
        }
        if ((fire[i].ex >= BombPlane[MaxBombCnt - 1].dx && fire[i].ex <= BombPlane[MaxBombCnt - 1].dx + 8) && (fire[i].ey <= BombPlane[MaxBombCnt - 1].dy + 2 && fire[i].ey >= BombPlane[MaxBombCnt - 1].dy)) //check for the hit of shoot and bombPlane
        {
            if (BombPlane[MaxBombCnt - 1].hp2 == 2)
            {
                BombPlane[MaxBombCnt - 1].hp2--;
                score += 5;
            }
            else 
            {
                BombPlane[MaxBombCnt - 1].hp2--;
                DeleteBombPlane(BombPlane[MaxBombCnt - 1]);
                PrintEffect(BombPlane[MaxBombCnt - 1].dx+3, BombPlane[MaxBombCnt - 1].dy);
                DeleteEffect(BombPlane[MaxBombCnt - 1].dx+3, BombPlane[MaxBombCnt - 1].dy);
                BombPlane[MaxBombCnt - 1].dx = 0;
                score += 10;
            }
            DeleteShoot(fire[i].ex, fire[i].ey);
            fire[i].ey = 2;
        }
        if ((entehari[MaxEntehari - 1].rx >= fire[i].ex - 8 && entehari[MaxEntehari - 1].rx <= fire[i].ex) && (entehari[MaxEntehari - 1].ry >= fire[i].ey && entehari[MaxEntehari - 1].ry - 2 <= fire[i].ey))//check hit of shoot and entehari
        {
            entehari[MaxEntehari - 1].hp3 --;
            DeleteShoot(fire[i].ex, fire[i].ey);
            PrintEntehari(entehari[MaxEntehari - 1]);
            fire[i].ey = 2;
            if (entehari[MaxEntehari - 1].hp3 == 0)
            {
                DeleteEntehari(entehari[MaxEntehari - 1]);
                PrintEffect(entehari[MaxEntehari - 1].rx + 3,entehari[MaxEntehari - 1].ry + 1);
                DeleteEffect(entehari[MaxEntehari - 1].rx + 3,entehari[MaxEntehari - 1].ry + 1);
                entehari[MaxEntehari - 1].ry = 35;
            }
        }
    }
    for (int i = nmine; i < mine; i++)
        for (int j = ShootCnt; j < cnt; j++)
        {
            if((EnemyMin[i].ax <= fire[j].ex && fire[j].ex <= EnemyMin[i].ax + 2) && (EnemyMin[i].ay <= fire[j].ey && fire[j].ey <= EnemyMin[i].ay + 1)) //check for the hit of shoot and min
            {
                DeleteMin(EnemyMin[i]);
                DeleteShoot(fire[j].ex, fire[j].ey);
                PrintEffect(EnemyMin[i].ax, EnemyMin[i].ay);
                DeleteEffect(EnemyMin[i].ax, EnemyMin[i].ay);
                fire[j].ey = 2;
                EnemyMin[i].ay = 35;
                score += 10;
            }
        }
    
}


void refreshMin() {
    static int l = 0;
    srand(time(NULL));
    Current = GetTickCount();
    if (l % 2 == 0)
    {
        if (Current - LastReleaseTime > ENEMY_RELEASE_TIME) {
            PrintMin(EnemyMin[mine]);
            mine++;
            LastReleaseTime = Current;
            tmp1++;
        }
        for (int i = nmine; i < mine; i++) {
            if (EnemyMin[i].ay < 32) {
                DeleteMin(EnemyMin[i]);
                EnemyMin[i].ay += 1;
                PrintMin(EnemyMin[i]);
            } 
            else 
            {
                if (EnemyMin[i].ay == 35)
                    continue;
                DeleteMin(EnemyMin[i]);
                nmine++;
            }
            if ((EnemyMin[i].ay == y || EnemyMin[i].ay == y + 1 || EnemyMin[i].ay == y + 2) && (EnemyMin[i].ax >= x-1 && EnemyMin[i].ax <= x + 4)) 
            {
                fly.health -= 25;
                DeleteMin(EnemyMin[i]);
                EnemyMin[i].ay = 35;
                PrintSpaceShip(x,y);
            }
        }
    }
    if (l > 10000)
        l = 0;
    l++;
}

void refreshHeal()
{
    static int k = 0;
    if (k % 4 == 0)
    {
        for (int i = MinHealCnt ; i < MaxHealCnt; i++)
        {
            if (heal[i].sy < 30)
            {
                DeleteHeal(heal[i]);
                heal[i].sy++;
                PrintHeal(heal[i]);
            }
            else
            {
                if (heal[i].sy == 35)
                    continue;
                DeleteHeal(heal[i]);
                MinHealCnt++;
            }
            if ((heal[i].sx >= x - 3 && heal[i].sx <= x + 4) && (heal[i].sy >= y - 2 && heal[i].sy <= y + 3))
            {
                fly.health += 20;
                if (fly.health > 100)
                    fly.health = 100;
                DeleteHeal(heal[i]);
                heal[i].sy = 35;
                PrintSpaceShip();
            }
        }
    }
    if (k > 10000)
        k = 0;
    k++;
}

void refreshBombPlane()
{
    srand(time(NULL));
    static int f = 0, u = 1;
    NowBomb = GetTickCount();
    if (NowBomb - BeforeBomb > BOMB_RELEASE_TIME && tmp1 > 1)
    {
        PrintBombPlane(BombPlane[MaxBombCnt]);
        MaxBombCnt++;
        BeforeBomb = NowBomb;
        u--;
        tmp2++;
    }
    if (f % 6 == 0)
    {
        for (int i = MinBombCnt; i < MaxBombCnt; i++)
        {
            if (BombPlane[i].dx < 5 || BombPlane[i].dy > 29)
            {
                if (BombPlane[i].dx == 0)
                    continue;
                DeleteBombPlane(BombPlane[i]);
                MinBombCnt++;
            }
            else
            {
                DeleteBombPlane(BombPlane[i]);
                BombPlane[i].dx -= 3;
                BombPlane[i].dy++;
                PrintBombPlane(BombPlane[i]);
            }
            if ((BombPlane[i].dx >= x - 8 && BombPlane[i].dx <= x + 4) && (BombPlane[i].dy >= y - 2 && BombPlane[i].dy <= y + 3))//hit of spaceShip and bombPlane
            {
                DeleteBombPlane(BombPlane[i]);
                BombPlane[i].dx = 0;
                PrintSpaceShip();
                fly.health -= 20;
            }
        }
    }
    if (BombPlane[MaxBombCnt - 1].dx >= 5 && BombPlane[MaxBombCnt - 1].dy == 20 && u == 0)
    {
        BOMb[MaxBombThrowCnt].zx = BombPlane[MinBombCnt].dx + 4;
        BOMb[MaxBombThrowCnt].zy = BombPlane[MinBombCnt].dy + 3;
        PrintBomb(BOMb[MaxBombThrowCnt]);
        MaxBombThrowCnt++;
        u++;
    }
    f++;
}

void refreshBomb()
{
    static int h = 0;
    if (h % 8 == 0)
    {
        for (int i = MinBombThrowCnt; i < MaxBombThrowCnt; i++)
        {
            if (BOMb[i].zy > 30)
            {
                if (BOMb[i].zy == 35)
                    continue;
                DeleteBomb(BOMb[i]);
                MinBombThrowCnt++;
            }
            else
            {
                DeleteBomb(BOMb[i]);
                BOMb[i].zy++;
                PrintBomb(BOMb[i]);
            }
            if ((BOMb[i].zy >= y - 1 && BOMb[i].zy <= y + 3) && (BOMb[i].zx  >= x - 5 && BOMb[i].zx <= x + 4)) //hit of bomb and spaceShip
            {
                fly.health -= 25;
                DeleteBomb(BOMb[i]);
                BOMb[i].zy = 35;
                PrintSpaceShip();
            }
        }
    }
    if (h > 10000)
        h = 0;
    h++;
}

void refreshEntehari()
{
    static int v = 0;
    if (v % 10 == 0)
    {
        NowEntehari = GetTickCount();
        if (NowEntehari - BeforeEntehari > ENTEHARI_RELEASE_TIME && tmp2 > 1)
        {
            PrintEntehari(entehari[MaxEntehari]);
            MaxEntehari++;
            BeforeEntehari = NowEntehari;
        }
        for (int i = MinEntehari; i < MaxEntehari; i++)
        {
            if (entehari[i].ry < 29)
            {
                DeleteEntehari(entehari[i]);
                entehari[i].ry++;
                PrintEntehari(entehari[i]);
            }
            else
            {
                if (entehari[i].ry == 35)
                    continue;
                DeleteEntehari(entehari[i]);
                MinEntehari++;
            }
            if ((entehari[i].rx >= x - 8 && entehari[i].rx <= x + 4) && (entehari[i].ry >= y - 2 && entehari[i].ry <= y + 3))//check hit of spaceShip and Entehari
            {
                DeleteEntehari(entehari[MaxEntehari - 1]);
                entehari[MaxEntehari - 1].ry = 35;
                PrintSpaceShip();
                fly.health -= 25;
            }
            
                tir[MaxTir].fx = entehari[i].rx + 4;
                tir[MaxTir].fy = entehari[i].ry + 3;
                PrintTir(tir[MaxTir]);
                MaxTir++;
            
        }
    }
    if (v > 10000)
        v = 0;
    v++;
}

void refreshTir()
{
    static int g = 0;
    if (g % 3 == 0)
    for (int i = MinTir; i < MaxTir; i++)
    {
        if (tir[i].fy < 30)
        {
            DeleteTir(tir[i]);
            tir[i].fy++;
            PrintTir(tir[i]);
        }
        else
        {
            if (tir[i].fy == 35)
                continue;
            DeleteTir(tir[i]);
            MinTir++;
        }
        if ((tir[i].fx >= x && tir[i].fx <= x + 4) && (tir[i].fy <= y + 3 && tir[i].fy >= y))//hit of tir and spaceShip
        {
            DeleteTir(tir[i]);
            tir[i].fy = 35;
            PrintSpaceShip();
            fly.health -= 15;
        }
    }
    g++;
    if (g == 10000)
        g = 0;
}

void refreshScore()
{
    now = GetTickCount();
    if (now - LastScoreUpdateTime >= 1000)
    {
        score += 10;
        LastScoreUpdateTime = now;
    }
    gotoxy(2,34);
    setTextColor(RED);
    printf("SCORE : %d", score);
    gotoxy(14,34);
    printf("                      ");
    gotoxy(17,34);
    printf("\tHEALTH : %d", fly.health);
    setTextColor(WHITE);
}

void refreshAll() {
    cnt = aa;
    while (!_kbhit()) 
    {
        refreshMin();
        refreshPlane();
        refreshHeal();
        refreshBombPlane();
        refreshShoot();
        refreshBomb();
        refreshEntehari();
        refreshTir();
        usleep(50000);
        if (fly.health < 1)
            return;
        refreshScore();
    }
}

void displayMainMenu(int selectedOption) {
    clearScreen();
    gotoxy(50,1);
    setTextColor(RED);
    printf("MENU");
    setTextColor(WHITE);
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            gotoxy(44,2);
            if (i == selectedOption)
            {
                gotoxy(42,2);
                setTextColor(RED);
                printf("-->Play");
            }
            else
                printf("Play");
            setTextColor(WHITE);

        }
        if (i == 1)
        {
            gotoxy(44,3);
            if (i == selectedOption)
            {
                gotoxy(42,3);
                setTextColor(RED);
                printf("-->Scores And Records\n");
            }
            else
                printf("Scores And Records");
            setTextColor(WHITE);
        }
        if (i == 2)
        {
            gotoxy(44,4);
            if (i == selectedOption)
            {
                setTextColor(RED);
                gotoxy(42,4);
                printf("-->Exit");
            }
            else
                printf("Exit");
            setTextColor(WHITE);
        }
    }

}

void DisplayLevelMenu(int selectedOption)
{
    setTextColor(RED);
    gotoxy(50,1);
    printf("LEVEL");
    setTextColor(WHITE);
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            gotoxy(44,2);
            if (i == selectedOption)
            {
                setTextColor(RED);
                gotoxy(42,2);
                printf("-->Easy");
            }
            else
                printf("Easy");
            setTextColor(WHITE);
        }
        else if (i == 1)
        {
            gotoxy(44,3);
            if (i == selectedOption)
            {
                gotoxy(42,3);
                setTextColor(RED);
                printf("--> Medium");
            }
            else
                printf("Medium");
            setTextColor(WHITE);
        }
        else if (i == 2)
        {
            gotoxy(44,4);
            if (i == selectedOption)
            {
                gotoxy(42,4);
                setTextColor(RED);
                printf("-->Hard");
            }
            else
                printf("Hard");
            setTextColor(WHITE);
        }
    }
}

int MainMenu(int selectedOption)
{
    while (1) {
        displayMainMenu(selectedOption);
        int key = getch();
        if (key == 'w' || key == 72) //"w" or up arrow
        {
            if (selectedOption > 0)
                selectedOption--;
        }
        else if (key == 's' || key == 80) //"s" or down arrow
        {
            if (selectedOption < 2)
                selectedOption++;
        }
        else if (key == 13) //enter
        {
            if (selectedOption == 0)//play
            {
                selectedOption = 0;
                while (1)
                {
                    clearScreen();
                    DisplayLevelMenu(selectedOption);
                    int key = getch();
                    if (key == 'w' || key == 72) //"w" or up arrow
                    {
                        if (selectedOption > 0)
                            selectedOption--;
                    }
                    else if (key == 's' || key == 80) //"s" or down arrow
                    {
                        if (selectedOption < 2)
                            selectedOption++;
                    }
                    else if (key == 13) //enter
                    {
                        return selectedOption; //0 = easy - 1 = medium - 2 = hard
                    }
                }
            }
            else if (selectedOption == 1) // go to record screen
            {
                return 3; // 3 = record menu
            }
            else//exit option -1 = exit
            {
                return -1;
            }
        }

    }

}

void PrintFinishGameMenu(int select)
{
    clearScreen();
    gotoxy(50,1);
    printf("SCORE : %d", score);
    for (int i = 0 ; i < 2; i++)
    {
        if (i == 0)
        {
            gotoxy(47,2);
            if (i == select)
            {
                setTextColor(RED);
                gotoxy(44,2);
                printf("-->REMATCH");
                setTextColor(WHITE);
            }
            else
                printf("REMATCH");
        }
        else
        {
            gotoxy(47,3);
            if (i == select)
            {
                setTextColor(RED);
                gotoxy(44,3);
                printf("-->MAIN MENU");
                setTextColor(WHITE);
            }
            else
                printf("MAIN MENU");
        }
    }
}

int SelectedOptionFinishMenu()
{
    int select = 0;
    char but;
    while (1)
    {
        PrintFinishGameMenu(select);
        but = getch();
        if (but == 'w' || but == 72) //"w" or up arrow
        {
            if (select > 0)
                select--;
        }
        else if (but == 's' || but == 80) //"s" or down arrow
        {
            if (select < 1)
                select++;
        }
        else if (but == 13) //enter
        {
            return select;
        }
    }
} // 0 = REMATCH | 1 = Main Menu
void StoreGameData() {
    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo = localtime(&currentTime);
    sprintf(infoo[gamecnt], "TIME : %02d:%02d:%02d SCORE : %d",timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, score);
}

void PrintGameData()
{
    FILE *fp;
    int j = 1;
    fp = fopen("C:\\Users\\hamid\\Desktop\\Project\\test\\records.txt", "w");
    for (int i = gamecnt - 1; i >= 0; i--)
    {
        fprintf(fp, "%d : %s\n", j, infoo[i]);
        j++;
    }
    fclose(fp);
}

void ScoreMenu()
{
    while (1) {
        clearScreen();
        PrintScoreMenu(choose);
        int key = getch();
        if (key == 'w' || key == 72) //"w" or up arrow
        {
            if (choose > 0)
                choose--;
        }
        else if (key == 's' || key == 80) //"s" or down arrow
        {
            if (choose < gamecnt)
                choose++;
        }
        else if (key == 13) //enter
        {
            return;
        }
    }
}
// cnt = 2  
void PrintScoreMenu(int choose)
{
    choose++;
    int j = 1;
    for (int i = gamecnt - 1; i >= 0; i--)
    {
        if (choose == gamecnt - i)
            setTextColor(RED);
        gotoxy(44,gamecnt - i + 1);
        printf("%d : %s", j, infoo[i]);
        j++;
        setTextColor(WHITE);
    }
    gotoxy(44,gamecnt+2);
    if (choose == gamecnt + 1)
    {
        gotoxy(42,gamecnt+2);
        setTextColor(RED);
        printf("-->BACK TO MENU");
    }
    else
    {
        printf("BACK TO MENU");
    }
    setTextColor(WHITE);
}

void EasyPlay()
{
    //reset game counters
    cnt = 0; 
    ShootCnt = 0; 
    mine = 0;
    nmine = 0; 
    PlaneCnt = 0; 
    MaxplaneCnt = 0;
    MaxBombCnt = 0;
    MinBombCnt = 0;
    MaxBombThrowCnt = 0;
    MinBombThrowCnt = 0;
    MinEntehari = 0;
    MaxEntehari = 0;
    MinTir = 0;
    MaxTir = 0;
    tmp1 = 0; 
    tmp2 = 0;
    score = 0;
    fly.health = 100;
    clearScreen();
    PrintBorder();
    InitialMin();
    InitialPlane();
    InitialHealShape();
    InitialBombPlane();
    InitialBombShape();
    InitialEffectShape();
    InitalEntehari();
    InitialSpaceShip(&fly);
    x = 47; y = 29;
    PrintSpaceShip(x, y);
    LastScoreUpdateTime = GetTickCount();
    while (fly.health > 0) {
        refreshAll();
        if (fly.health < 1)
            break;
        key = getch();
        int tmpX = x, tmpY = y;
        MoveSpaceShip();
        if (x == tmpX && y == tmpY)
            continue;
        DeleteSpaceShip(tmpX, tmpY);
        PrintSpaceShip();
    }
    clearScreen();
    int select = SelectedOptionFinishMenu();
    StoreGameData();
    PrintGameData();
    gamecnt++;
    if (select == 0)
    {
        score = 0;
        EasyPlay();
    }
    else
    {
        SelectedOption = 0;
        return;
    }
}

void GoodBye()
{
    clearScreen();
    setTextColor(RED);
    gotoxy(30, 0);
    printf("   _____  ____   ____  _____    ______     ________ ");
    gotoxy(30, 1);
    printf("  / ____|/ __ \\ / __ \\|  __ \\  |  _ \\ \\   / /  ____|");
    gotoxy(30, 2);
    printf(" | |  __| |  | | |  | | |  | | | |_) \\ \\_/ /| |__   ");
    gotoxy(30, 3);
    printf(" | | |_ | |  | | |  | | |  | | |  _ < \\   / |  __|  ");
    gotoxy(30, 4);
    printf(" | |__| | |__| | |__| | |__| | | |_) | | |  | |____ ");
    gotoxy(30, 5);
    printf("  \\_____|\\____/ \\____/|_____/  |____/  |_|  |______|");
    setTextColor(WHITE);
    sleep(5);
}