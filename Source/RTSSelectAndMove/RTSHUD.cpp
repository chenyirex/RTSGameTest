// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSHUD.h"
#include "RTSSelectAndMove.h"

void ARTSHUD::DrawHUD() 
{
	if (bStartSelecting == true) {

		if (FoundActors.Num() >= 0) {
			for (ARTSSelectAndMoveCharacter* CharaterPtr : FoundActors) {
				CharaterPtr->SetDeselected();
			}
		}

		FoundActors.Empty();

		CurrentPoint = GetMousePos2D();
		DrawRect(FLinearColor(0, 0, 1, .15f), InitialPoint.X, InitialPoint.Y,
			CurrentPoint.X - InitialPoint.X, CurrentPoint.Y - InitialPoint.Y);
		GetActorsInSelectionRectangle<ARTSSelectAndMoveCharacter>(InitialPoint, CurrentPoint, FoundActors, false, false);

		if (FoundActors.Num() >= 0) {
			for (ARTSSelectAndMoveCharacter* CharaterPtr : FoundActors) {
				CharaterPtr->SetSelected();
			}
		}
	}
}
FVector2D ARTSHUD::GetMousePos2D()
{
	float PosX;
	float PosY;

	GetOwningPlayerController()->GetMousePosition(PosX, PosY);

	return FVector2D(PosX, PosY);
}
