// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "LostDwarfGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class THELOSTDWARF_API ULostDwarfGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Screen")
	TSubclassOf<UUserWidget> LoadingWidgetClass;
	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);

	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);
private:
	TSharedPtr<SWidget> LoadingSWidgetPtr;


};
