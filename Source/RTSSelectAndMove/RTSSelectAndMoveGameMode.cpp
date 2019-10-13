// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RTSSelectAndMoveGameMode.h"
#include "RTSSelectAndMovePlayerController.h"
#include "RTSSelectAndMoveCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARTSSelectAndMoveGameMode::ARTSSelectAndMoveGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARTSSelectAndMovePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}