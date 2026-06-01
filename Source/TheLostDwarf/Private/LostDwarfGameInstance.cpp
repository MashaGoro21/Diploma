// Fill out your copyright notice in the Description page of Project Settings.


#include "LostDwarfGameInstance.h"

#include "Engine/Engine.h"
#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"


void ULostDwarfGameInstance::Init() {
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULostDwarfGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULostDwarfGameInstance::EndLoadingScreen);

}
void ULostDwarfGameInstance::BeginLoadingScreen(const FString& MapName)
{
	
		//const auto LoadingWidget = CreateWidget<UUserWidget>(this, LoadingWidgetClass, TEXT("LoadingScreen"));
		//LoadingSWidgetPtr = LoadingWidget->TakeWidget();

		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		LoadingScreen.bAllowInEarlyStartup = false;
		LoadingScreen.PlaybackType = MT_Normal;
		LoadingScreen.bAllowEngineTick = false;
		LoadingScreen.bWaitForManualStop = false;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		LoadingScreen.MinimumLoadingScreenDisplayTime = 2.f;

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		//GetMoviePlayer()->PlayMovie();
	
}

void ULostDwarfGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
}

