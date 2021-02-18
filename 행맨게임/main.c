#include "pgm.h"
#include "get_dict.h"
#include "play_hangman.h"

int main(void)
{
	get_dict();
	play_hangman();

	getch();
	return 0;
}
