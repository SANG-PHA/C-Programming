#include "pgm.h"
#include "play_hangman.h"

void play_hangman()
{
	srand(time(NULL));
	int want_play = TRUE, num_of_win = 0, total_game_play = 0, total_correct = 0, total_try = 0; //통계를 위한 변수 선언

	do{
		total_game_play++;

		//남은 횟수 디스플레이를 위한 배열
		char tmp_character[8] = { "0|//T//" };
		char display_character[8] = { " ",};


		char display_arr[DICT_SIZE] = { "______________________________", };
		char chosen_arr[DICT_SIZE];
		memset(chosen_arr, 0, 30); //배열 초기화를 위한 함수
		char guess_char; //사용자로 부터 입력받을 알파벳
		int randint = rand() % 100; //단어배열에서 선택할 단어 인덱스 번호 생성
		int chance = 7, num_of_correct = 0;

		strcpy(chosen_arr, dict[randint]);

		while (1){
			int is_correct = FALSE; //정답 확인을 위한 변수 선언

			//현재 단어 상태 출력
			print_current_word(chosen_arr, display_arr);

			//남은 횟수 디스플레이
			printf("You have %d guesses left.\n", chance);
			print_current_table(display_character);
			
			//사용자로 부터 단어 입력
			printf("Your guess : ");
			scanf("%c", &guess_char);
			getchar(); //버퍼제거
			total_try++;

			//입력한 문자가 단어에 포함되어 있는 문자인지 검사
			for (int i = 0; i < strlen(chosen_arr); i++){
				if (chosen_arr[i] == guess_char){
					display_arr[i] = guess_char;
					num_of_correct++;
					total_correct++;
					is_correct = TRUE;
				}
			}

			//검사결과가
			if (is_correct == FALSE){ //틀렸을 때
				printf("That guess is not correct.\n\n");
				display_character[7 - chance] = tmp_character[7 - chance];
				chance--;
			}
			else{ //맞췄을 때
				printf("That guess is correct.\n\n");
			}

			//게임 종료 조건 검사
			if (num_of_correct == strlen(chosen_arr)){
				print_current_word(chosen_arr, display_arr);
				printf("You Win!\n\n");
				num_of_win++;
				break;
			}
			else if (chance == 0){
				print_current_table(display_character);
				printf("You Lose!\n");
				printf("정답은 : %s\n\n", chosen_arr);
				break;
			}

		}

		printf("계속 플레이 하시겠습니까? (예 : 1, 아니오 : 0)");
		scanf("%d", &want_play);
		getchar(); //버퍼제거
	} while (want_play == TRUE);

	printf("\n총 게임 수 : %d\n승리 횟수 : %d\n맞힌 알파벳 횟수 : %d\n알파벳 추측 성공률 : %.2f%", total_game_play, num_of_win ,total_correct, 100 * ((double)total_correct / (double)total_try));
}

void print_current_word(char chosen_arr[], char display_arr[])
{
	printf("The word now look like this : ");
	for (int i = 0; i < strlen(chosen_arr); i++)
		printf("%c ", display_arr[i]);
	printf("\n");
}

void print_current_table(char display_character[])
{
	printf(" ㅡㅡㅡㅡㄱ\n");
	printf("ㅣ        %c\n", display_character[0]);
	printf("ㅣ        %c%c\n", display_character[1], display_character[2]);
	printf("ㅣ       %c%c\n", display_character[3], display_character[4]);
	printf("ㅗ       %c %c\n", display_character[5], display_character[6]);
}
