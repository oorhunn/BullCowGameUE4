// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include<iostream>


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	HiddenWord = HiddenWords[FMath::RandHelper(5)];
	PrintLine("Welcome to bulls and cows \n");
	PrintLine(FString::Printf(TEXT("I have %d letters word"),HiddenWord.Len()));
	PrintLine(FString::Printf(TEXT("You have %i guesses for guess  my word"),GuessCount));


}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	if (Input.Len() ==HiddenWord.Len()) {
		int WordLenght = HiddenWord.Len();
		int BullCount = 0;
		int CowCount = 0;
		

		if (Input == HiddenWord)
			PrintLine(TEXT("You win"));
		else {
			PrintLine(TEXT("you guess wrongly"));
			for (int i = 0; i <WordLenght; i++) {
				for (int j = 0; j < WordLenght;j++) {
					if(Input[i]==HiddenWord[j]){
						if (i == j) {
							BullCount = BullCount + 1;
						}
						else
							CowCount = CowCount + 1;

					}

				}

			}

			PrintLine(TEXT("%d bulls \n"), BullCount);
			PrintLine(TEXT("%d cow \n"), CowCount);
			GuessCount = GuessCount - 1;
			PrintLine(FString::Printf(TEXT("You have %i guesses for guess  my word"), GuessCount));
			if (GuessCount == 0) {
				PrintLine("You have lose the game");
				return;
			}


		}






	}
	else
		PrintLine("you have to enter 4 letters ");

}