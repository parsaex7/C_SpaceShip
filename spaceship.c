#include "./func.c"

int main() 
{
    printf("\e[?25l");
    clearScreen();
    while (SelectedOption != -1)
    {
        SelectedOption = MainMenu(SelectedOption);
        if (SelectedOption == 0)
            EasyPlay();
        else if (SelectedOption == 3)
        {
            clearScreen();
            ScoreMenu();
            SelectedOption = 0;
        }
    }
    GoodBye();
}