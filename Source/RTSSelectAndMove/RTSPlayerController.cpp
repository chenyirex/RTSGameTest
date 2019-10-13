// Fill out your copyright notice in the Description page of Project Settings.
#include "RTSPlayerController.h"
#include "RTSSelectAndMove.h"

ARTSPlayerController::ARTSPlayerController() {
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}


void ARTSPlayerController::BeginPlay()
{
	HUDPtr = Cast<ARTSHUD>(GetHUD());
}


void ARTSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ARTSPlayerController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ARTSPlayerController::SelectionReleased);

	InputComponent->BindAction("RightMouseClick", IE_Released, this, &ARTSPlayerController::MoveReleased);
}

void ARTSPlayerController::SelectionPressed() 
{
	HUDPtr->InitialPoint = HUDPtr->GetMousePos2D();
	HUDPtr->bStartSelecting = true;
}

void ARTSPlayerController::SelectionReleased() 
{
	HUDPtr->bStartSelecting = false;
}

void ARTSPlayerController::MoveReleased() {

}
