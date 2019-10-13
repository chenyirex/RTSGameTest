// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSHUD.h"
#include "RTSSelectAndMove.h"

void ARTSHUD::DrawHUD() 
{
	if (bStartSelecting == true) {
		CurrentPoint = GetMousePos2D();
		DrawRect(FLinearColor(0, 0, 1, .15f), InitialPoint.X, InitialPoint.Y,
			CurrentPoint.X - InitialPoint.X, CurrentPoint.Y - InitialPoint.Y);
	}
}
FVector2D ARTSHUD::GetMousePos2D()
{
	float PosX;
	float PosY;

	GetOwningPlayerController()->GetMousePosition(PosX, PosY);

	return FVector2D(PosX, PosY);
}
