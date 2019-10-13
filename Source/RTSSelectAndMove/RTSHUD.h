// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RTSSelectAndMoveCharacter.h"
#include "RTSHUD.generated.h"

/**
 * 
 */
UCLASS()
class RTSSELECTANDMOVE_API ARTSHUD : public AHUD
{
	GENERATED_BODY()
	

public:
	virtual void DrawHUD() override;
	// initial position of vector while we press
	FVector2D InitialPoint;

	// while we hold
	FVector2D CurrentPoint;

	FVector2D GetMousePos2D();

	bool bStartSelecting = false;

	TArray <ARTSSelectAndMoveCharacter*> FoundActors;
};
