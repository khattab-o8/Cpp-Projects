#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOpType = 5 };

string GetOpTypeSympol(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return "+";

	case enOperationType::Sub:
		return "-";

	case enOperationType::Mul:
		return "*";

	case enOperationType::Div:
		return "/";

	default:
		return "Mix";
	}
}

string GetQuestionLevelText(enQuestionsLevel QuestionsLevel)
{
	string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };

	return arrQuestionLevelText[QuestionsLevel - 1];

}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short HowManyQuestions()
{
	short NumberofQuestions = 0;
	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> NumberofQuestions;

	} while (NumberofQuestions < 1 || NumberofQuestions > 10);

	return NumberofQuestions;
}

enQuestionsLevel QuestionsLevel()
{
	short Level = 0;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Level;

	} while (Level < 1 || Level > 4);

	return (enQuestionsLevel) Level;
}

enOperationType OperationType()
{
	short OpType = 0;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return (enOperationType) OpType;
}

void SetScreenColor(bool Right)
{
	if (Right)
	{
		system("color 2f");
	}
	else
	{
		system("color 4f");
		cout << "\a";
	}
}

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionsLevel;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
	int CorrectAnswer = 0;
};

struct stQuiz
{
	stQuestion questionlist[100];
	bool IsPass = false;
	int NumberOfQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	int NumberOfRightAnswers = 0;
	int NumberOfWrongAnswers = 0;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::Sub:
		return Number1 - Number2;

	case enOperationType::Mul:
		return Number1 * Number2;

	case enOperationType::Div:
		return  Number1 / Number2;

	default:
		return Number1 + Number2;
	}
}

enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType) Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType OperationType)
{
	stQuestion Question;

	if (QuestionsLevel == enQuestionsLevel::Mix)
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);

	if (OperationType == enOperationType::MixOpType)
		OperationType = GetRandomOperationType();

	Question.OperationType = OperationType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::EasyLevel:

		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;

		return Question;

	case enQuestionsLevel::MedLevel:

		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;

		return Question;

	case enQuestionsLevel::HardLevel:

		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;

		return Question;
	}

	return Question;

}

void GenerateQuizQuestions(stQuiz& Quiz)
{
	for (int Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.questionlist[Question] = GenerateQuestion(Quiz.QuestionsLevel, Quiz.OpType);
	}
}

void PrintTheQuestion(stQuiz& Quiz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/"
	<< Quiz.NumberOfQuestions << "]\n\n";
	cout << Quiz.questionlist[QuestionNumber].Number1 << "\n";
	cout << Quiz.questionlist[QuestionNumber].Number2 << " " 
	<< GetOpTypeSympol(Quiz.questionlist[QuestionNumber].OperationType) << "\n";
	cout << "____________\n";
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber)
{
	if (Quiz.questionlist[QuestionNumber].PlayerAnswer != Quiz.questionlist[QuestionNumber].CorrectAnswer)
	{
		Quiz.questionlist[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "\nWrong Answer :-(\n";
		cout << "The right answer is: " << Quiz.questionlist[QuestionNumber].CorrectAnswer << endl;
	}
	else
	{
		Quiz.questionlist[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "\nRight Answer :-)\n";
	}

	cout << endl;
	SetScreenColor(Quiz.questionlist[QuestionNumber].AnswerResult);

}

void AskAndCorrectQuestionListAnswers(stQuiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);
		Quiz.questionlist[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.IsPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

void PrintQuizResults(stQuiz Quiz)
{
	cout << "\n\n_____________________________________\n";
	cout << "\n Final Results is " << GetFinalResultsText(Quiz.IsPass);
	cout << "\n_____________________________________\n";

	cout << "\nNumber of Questions: " << Quiz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionLevelText(Quiz.QuestionsLevel) << endl;
	cout << "OpType             : " << GetOpTypeSympol(Quiz.OpType) << endl;
	cout << "Number of Right Answers: " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers: " << Quiz.NumberOfWrongAnswers << endl;

	cout << "_____________________________________\n";
}

void PlayMathGame()
{
	stQuiz Quiz;

	Quiz.NumberOfQuestions = HowManyQuestions();
	Quiz.QuestionsLevel = QuestionsLevel();
	Quiz.OpType = OperationType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionListAnswers(Quiz);
	PrintQuizResults(Quiz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain;
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "\nDo you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}
