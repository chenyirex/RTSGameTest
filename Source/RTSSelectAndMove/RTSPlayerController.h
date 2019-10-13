// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RTSHUD.h"
#include "DrawDebugHelpers.h"
#include "RTSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RTSSELECTANDMOVE_API ARTSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ARTSPlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	ARTSHUD* HUDPtr;

protected:	
	void SelectionPressed();
	void SelectionReleased();
	void MoveReleased();

	TArray <ARTSSelectAndMoveCharacter*> SelectedActors;
};
