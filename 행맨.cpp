#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

//단어장 구축
string dict[100] = { "ability", "able", "about", "above", "accept", "according", "account", "across", "act", "action", "baby", "back", "bad",
"bag", "ball", "believe", "benefit", "best", "better", "between", "camera", "campaign", "can", "cancer", "candidate", "choose", "church", "citizen",
"city", "civil", "daughter", "day", "dead", "deal", "death", "debate", "decade", "decide", "decision", "deep", "entire", "environment", "environmental", "especially",
"establish", "even", "evening", "event", "ever", "every", "feeling", "few", "field", "fight", "figure", "fill", "film", "final", "finally", "financial", "girl",
"give", "glass", "go", "goal", "good", "government", "great", "green", "ground", "hold", "home", "hope", "hospital", "hot", "hotel", "hour", "house", "how",
"however", "including", "increase", "indeed", "indicate", "individual", "industry", "information", "inside", "instead", "institution", "may", "maybe",
"me", "mean", "measure", "media", "medical", "meet", "meeting", "member" };

string answer; //정답 단어
char* board = NULL; //정답이 표시될 배열, 이하 '보드'
string attempt; //사용자가 시도한 알파벳을 저장할 배열
int cnt = 6; //남은 시도 횟수
char input; //사용자가 입력한 알파벳
bool gameover = false; //게임종료 boolean 변수
bool win = false; //게임승리 boolean 변수


void select_word(); //단어장에서 단어를 선택하는 함수
void set_board(); //보드 초기화 함수
void game(); //게임 진행 함수
void show_current_board(); //현재 보드상태를 출력하는 함수
void show_tries_letter(); //남은 횟수와 시도한 알파벳을 출력하는 함수
void guess_answer(); //사용자로부터 알파벳을 입력받는 함수
void check_word(); //입력받은 알파벳을 정답과 비교하는 함수
void check_gameover(); //게임이 끝났는지 판별하는 함수
void reset(); //게임에 필요한 변수들을 리셋하는 함수

int main(void)
{
	char again = 'N'; //게임 재시작 제어 변수

	do{
		select_word();
		set_board();

		while (gameover == false){
			game();
		}


		if (win == true){
			cout << endl << "You Win! : " << answer;
			show_tries_letter();
		}
		else{
			cout << endl << "You Failed.. : " << answer;
			show_tries_letter();
		}

		cout << "To be continue? (Y/N)";
		cin >> again;

		reset();

	} while (again == 'Y');

	cin.get();
	return 0;
}

void select_word()
{
	//난수를 발생시켜 단어를 선택한다
	srand(time(NULL));

	answer = dict[rand() % 101];
}

void set_board()
{
	board = new char[answer.size() + 1]; //보드 동적할당

	//보드 초기화
	for (int i = 0; i < answer.size(); i++)
		board[i] = '_';

}

void game()
{
	show_current_board();
	cout << "You have " << cnt << " guesses left ";
	show_tries_letter();
	guess_answer();
	check_word();
	check_gameover();
}

void show_current_board()
{
	cout << endl << "The word now looks like : ";

	for (int i = 0; i < answer.size(); i++)
		cout << board[i] << " ";

	cout << endl;
}

void show_tries_letter()
{
	//시도한적이 없다면
	if (attempt.size() == 0){
		cout << endl;
		return;
	}
	//그 외
	else{
		cout << "(tries letter : ";
		for (int i = 0; i < attempt.size(); i++)
			cout << attempt[i] << " ";
		cout << ")" << endl;
	}
}

void guess_answer()
{
	cnt--;

	cout << "Your guessed : ";
	cin >> input;

	attempt.append(1,input); //시도한 알파벳을 배열에 추가
}

void check_word()
{
	//정답과 알파벳을 비교하여 보드를 업데이트
	for (int i = 0; i < answer.size(); i++){
		if (answer[i] == input)
			board[i] = input;
	}
}

void check_gameover()
{
	int i;

	//정답과 보드의 단어를 하나씩 비교한다
	for (i = 0; i < answer.size(); i++)
		if (answer[i] != board[i])
			break;

	//게임에서 승리할 경우
	if (i == answer.size()){
		gameover = true;
		win = true;
		return;
	}

	//게임에서 패배할 경우
	if (cnt == 0){
		gameover = true;
		return;
	}

}

void reset()
{
	delete[] board;
	attempt.clear();
	gameover = false;
	win = false;
	cnt = 6;
}
