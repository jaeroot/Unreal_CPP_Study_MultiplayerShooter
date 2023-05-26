// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

class UTextBlock;

UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetDisplayText(FString TextToDisplay1, FString TextToDisplay2);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);
	
	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APlayerState* PlayerState);

protected:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* LocalRoleText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RemoteRoleText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerNameText;
};
