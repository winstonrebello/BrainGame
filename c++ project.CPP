#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<bios.h>
#include<process.h>
#include<string.h>
void swap(char a[], char b[])
   {
   char c;
   c=a[0];
   a[0]=b[0];
   b[0]=c;
   }
void card()
	{ int card1[] = { 20,20 , 50,20 , 50,100 , 20,100 , 20,20 };
	 int card2[] = { 80,20 , 110,20 , 110,100 , 80,100 , 80,20 };
	 int card3[] = { 140,20 , 170,20 , 170,100 , 140,100 , 140,20 };
char val[3][2]={ "1" , "2", "3" };
{   char count[2]="0";
   int swapnum=0;         //for number of times to swap the cards
   int driver,mode;
   driver=DETECT;
   initgraph(&driver , &mode , "C:\\TurboC3\\BGI");
   setfillstyle(SOLID_FILL,YELLOW);
   fillpoly(5,card1);
   fillpoly(5,card2);
   fillpoly(5,card3);
   settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
   setcolor(BLUE);
   moveto(25,25);
   outtext(val[0]);
   moveto(85,25);
   outtext(val[1]);
   moveto(145,25);
   outtext(val[2]);
   do
   {int num=0;
      int choice[2];
      count[0]++;
      delay(1500);
      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
      moveto(20,150);
      outtext("No. of Times Cards have been swapped:");
      settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
      moveto(20 + swapnum*20,170);
      outtext(count);
      setfillstyle(SOLID_FILL,YELLOW);
      fillpoly(5,card1);
      fillpoly(5,card2);
      fillpoly(5,card3);
      do
      {  randomize();
	 choice[num]= (rand() + num) % 3;
	 switch(choice[num])
	    {
	    case 0:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card1);
	       break;
	    case 1:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card2);
	       break;
	    case 2:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card3);
	       break;
	    }
	 num++;
	 }while(num<2);
	 swap(val[(choice[0])],val[(choice[1])]);
	 }while(swapnum++ < 6);
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   moveto(20,200);
   outtext("What is card number 2");
   char ans;
   ans=getch();
   if(ans==val[1][0])
      {
      moveto(20,230);
      outtext("HURRAY");
      }
   else
      {
      moveto(20,230);
      outtext("DUMBO");
      }
   getch();
   closegraph();
   }
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


// Initialize the unknown word

void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}

void country()
{cleardevice();
 const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);
char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"india",
		"pakistan",
		"nepal",
		"malaysia",
		"philippines",
		"australia",
		"iran",
		"ethiopia",
		"oman",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	randomize();
	int n=random(10);
	strcpy(word,words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	getch();
}

void highscore()
{   cleardevice();
   // int gdriver = DETECT,gmode,i;
   // initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
    setbkcolor(BLUE);setcolor(WHITE);
    settextstyle(1, 0, 4);
    outtextxy(300,200,"FILE NOT FOUND!");
    getch();
}
void help()
{ cleardevice();
  setbkcolor(BLUE);setcolor(WHITE);
  settextstyle(1,0,3);
  outtextxy(250,25,"1)There are 3 cards on one card yellow ");
  outtextxy(250,45,"colour appears that card will shuffle 7");
  outtextxy(250,65,"times then at last you have to identify");
  outtextxy(250,85,"where it was.");
  outtextxy(250,125,"2)You have to guess a country name by");
  outtextxy(250,145,"number of letters.");
 getch();
}
void bullet(int x, int y, int p)
{
    if (p) {
	setfillstyle(1, 6);
	setcolor(6);
    }
    else {
	setfillstyle(1, BLACK);
	setcolor(BLACK);
    }
    bar(x + 0, y + 5, x + 3, y + 15);
    pieslice(x + 2, y + 4, 0, 180, 1);
}
void drawgun(int x, int y, int s, int menu)
{if (s) {
	setfillstyle(1, 8);
	bar(x + 72, y - 15, x + 265, y - 10);
	bar(x + 69, y - 14, x + 75, y + 18);
	bar(x + 70, y + 19, x + 265, y + 23);
	bar(x + 265, y - 14, x + 271, y + 22);
	char pa[] = { 0x3a, 0xb456 };
	setfillpattern(pa, 8);
	bar(x + 70, y - 14, x + 265, y - 10);
	bar(x + 70, y - 14, x + 75, y + 18);
	bar(x + 70, y + 18, x + 265, y + 22);
	bar(x + 265, y - 14, x + 270, y + 22);
	   for (int i = 300;;) {
	      delay(5);
	      if (kbhit())
	      break;
	    setfillstyle(9, 4);
	    bar(x + 75, y - 10, x + 265, y + 18);
	    i--;
	    setcolor(WHITE);
	    if (menu == 1) {
		if (y == 200) {
		    outtextxy(i, y, "FLIP CARD");
		    if (i <= 290)
			break;
		}
		else if (y == 250) {
		    outtextxy(i, y, "COUNTRY");
		    if (i <= 283)
			break;
		}
		else if (y == 300) {
		    outtextxy(i, y, "HIGHSCORE");
		    if (i <= 290)
			break;
		}
		else if (y == 350) {
		    outtextxy(i, y, "HELP");
		    if (i <= 290)
			break;
		}
		else if (y == 400) {
		    outtextxy(i, y, "EXIT");
		    if (i <= 280)
			break;
		}}}
	    if (kbhit()) {
	    setfillstyle(9, 4);
	    bar(x + 75, y - 10, x + 265, y + 18);
	    setcolor(WHITE);
	    if (menu == 1) {
		if (y == 200)
		    outtextxy(300, y, "CARD FLIP");
		else if (y == 250)
		    outtextxy(300, y, "COUNTRY");
		else if (y == 300)
		    outtextxy(300, y, "HIGHSCORE");
		else if (y == 350)
		    outtextxy(300, y, "HELP");
		else if (y == 400)
		    outtextxy(300, y, "EXIT");
	    }}}
    else {
	setfillstyle(9, 4);
	bar(x + 70, y - 15, x + 265, y - 10);
	bar(x + 69, y - 14, x + 75, y + 18);
	bar(x + 70, y + 18, x + 265, y + 23);
	bar(x + 265, y - 14, x + 271, y + 22);}}
void thgtxt(int x, int y, char* a) //to create a txt efect at x,y
  {  int col = getcolor(), t = 0;
    int width = textwidth("A"), height = textheight("A");
    char buf[2] = " \n";
    for (int i = 0; a[i]; i++) {
	buf[0] = a[i];
	if (buf[0] == 'i')
	    t = width / 3;
	else if (buf[0] == 'I')
	    t = width / 4.0;
	else
	    t = 0;
	for (int tx = x + width * i + width / 2.0 + t, ty = y - 2 * height; tx > x + width * i + t && ty < y + height;) {
	    setcolor(BLACK);
	    outtextxy(tx, ty, buf);
	    tx -= 2;
	    ty += 2;
	    setcolor(col);
	    outtextxy(tx, ty, buf);
	    delay(10);
	}}}
//class declarations
class thgkey //to store the controlls
    {
public:
    char left, right, up, shoot;
    thgkey(){
	right = 77;left = 75;up = 72;shoot = ' ';}
    void reset()
    {right = 77;left = 75;up = 72;shoot = ' ';
    }
} keys;
void mainmenu()
{fflush(stdin);int y = 200;
first:
    setfillstyle(9, 4);
    bar(0, 0, getmaxx(), getmaxy());
    for (int i = 0; i < getmaxy(); i++) {
	setfillstyle(i % 10, 8);bar(0, i, 5, i + 4);bar(getmaxx() - 5, i, getmaxx(), i + 4);
	bar(i + 2, 0, i + 5, 5);bar(getmaxx() - i, 0, getmaxx() - i - 5, 5);
	bar(i + 2, getmaxy(), i + 5, getmaxy() - 5);bar(getmaxx() - i, getmaxy(), getmaxx() - i - 5, getmaxy() - 5);}
    setcolor(WHITE); settextstyle(1, 0, 4);settextjustify(1, 1);
    outtextxy(300, 100, "CLASH OF BRAINS");
    outtextxy(300, 200, " CARD FLIP");
     outtextxy(300, 250, "COUNTRY");
    outtextxy(300,300, "HIGHSCORE");
    outtextxy(300,350, "HELP");
    outtextxy(300,400, "EXIT");
    char key;
    do {settextstyle(1, 0, 4);
	drawgun(130, y, 1, 1);
	key = getch();drawgun(130, y, 0, 1);
	if (key == 80) //down
	{if (y < 400)y += 50;
	    else y = 200;}
	else if (key == 72) //UP
	{if (y > 200) y -= 50;
	    else
		y = 400;}
	else if (key == 13) //Enter key
	{
	    if (y == 200) {card();goto first;}
	    else if (y == 250) {country();goto first;
	    }
	    else if (y == 300) {highscore();goto first;
	    }
	    else if (y == 350) {help(); goto first;
	    }
	    else if (y == 400) {
	       //	if (quit())
	    exit(0);}}} while (1);}
void logo()
{int gdriver = DETECT,gmode,i;
    initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
    setbkcolor(BROWN);setcolor(WHITE);
    settextstyle(1, 0, 4);
    outtextxy(220, 60, "CG");delay(500);
    outtextxy(280, 60, "PROJECT");delay(500);
    setcolor(WHITE);settextstyle(1, 0, 4);
    outtextxy(140, 150, "VIVEK");delay(500);
    outtextxy(230, 190, "WINSTON");delay(500);
    outtextxy(350, 230, "ROHAN");delay(500);
    setcolor(WHITE);settextstyle(4, 0, 4);
    delay(5000);}
void Intro()
{int i;
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
   char pattern[8] ={0x11,0xFF,0x11,0xFF,0x11,0xFF,0x11,0xFF};
   setfillpattern(pattern,LIGHTBLUE);bar(0,0,640,480);
   settextstyle(1,0,5);setcolor(10);
   getch();
   setcolor(BLUE);for(i=0;i<=320;i++){
   rectangle(0+i,0,640-i,480);delay(8);}
}
void printMsg()
{// auto detection
    int gdriver = DETECT,gmode,i;
// initialize graphics mode
    initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
    setbkcolor(BLUE);
    char pattern[8] ={0xfe,0xbc,0xda,0xe4,0xe2,0xc0,0x88,0x0};
    setfillpattern(pattern,LIGHTBLUE);
    bar(0,0,640,480);
    for (i=3; i<4; i++)
    {// setcolor of cursor
	setcolor(WHITE);settextstyle(1,0,5);
// print text at coordinate x,y;
	outtextxy(145,10*i,"C"); delay(100);
	outtextxy(165,10*i,"L"); delay(100);
	outtextxy(187,10*i,"A"); delay(100);
	outtextxy(210,10*i,"S"); delay(100);
	outtextxy(230,10*i,"H"); delay(100);
	outtextxy(290,10*i,"O"); delay(100);
	outtextxy(310,10*i,"F"); delay(100);
	outtextxy(370,10*i,"B"); delay(100);
	outtextxy(392,10*i,"R"); delay(100);
	outtextxy(417,10*i,"A"); delay(100);
	outtextxy(445,10*i,"I"); delay(100);
	outtextxy(457,10*i,"N"); delay(100);
	outtextxy(482,10*i,"S"); delay(100);
	delay(500);}}
void load()                //LOADING SWORD
{
    cleardevice();
    setfillstyle(1, WHITE);
    setcolor(WHITE);
    outtextxy(280, 230, "LOADING...");
    line(170, 300, 410, 300);
    arc(410, 309, 50, 90, 8);
    line(430, 320, 415, 302);
    line(170, 320, 430, 320);
    rectangle(170, 270, 160, 340);
    bar(100, 303, 160, 315);
    delay(600);
    setfillstyle(1, RED);
    for (int i = 0, y = 302; i < 250; i += 2) {
	delay(20);
	if (i >= 234)
	    y += 2;
	bar(i + 170, y, i + 180, 318);
    }
    delay(100);
}
// driver program
int main()
{ int i,gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"C://TurboC3//BGI");
load();logo();Intro();  printMsg(); mainmenu();
 return 0;
}
