// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TestArenaGameMode.h"
#include "TestArenaHUD.h"
#include "TestArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestArenaGameMode::ATestArenaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestArenaHUD::StaticClass();
}
