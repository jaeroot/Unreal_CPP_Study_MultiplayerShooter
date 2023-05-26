// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString LocalRoleString, FString RemoteRoleString)
{
	if (LocalRoleText)
	{
		LocalRoleText->SetText(FText::FromString(LocalRoleString));
	}
	
	if (RemoteRoleText)
	{
		RemoteRoleText->SetText(FText::FromString(RemoteRoleString));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role1, Role2;
	
	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
		Role1 = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role1 = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role1 = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role1 = FString("None");
		break;
	}

	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role2 = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role2 = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role2 = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role2 = FString("None");
		break;
	}

	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role1);
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role2);
	SetDisplayText(LocalRoleString, RemoteRoleString);
}

void UOverheadWidget::ShowPlayerName(APlayerState* PlayerState)
{
	FString Name;
	if (PlayerState)
	{
		Name = PlayerState->GetPlayerName();
	}
	FString PlayerNameString = FString::Printf(TEXT("Player Name: %s"), *Name);

	if (PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(PlayerNameString));
	}
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
