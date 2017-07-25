// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAnimInstance.h"



//////////////////////////////////////////////////////////////////////////
// UVictoryAnimInstance

//This function is like PostInitAnimtree in UE3
void UCustomAnimInstance::NativeInitializeAnimation()
{
	//Very Important Line
	Super::NativeInitializeAnimation();

	//Cache the owning pawn for use in Tick
	OwningPawn = TryGetPawnOwner();
}

//Tick
void UCustomAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	//Very Important Line
	Super::NativeUpdateAnimation(DeltaTimeX);

	//Always Check Pointers
	if (!OwningPawn)
	{
		return;
	}

	//Set whether moving or not
	IsMoving = (OwningPawn->GetVelocity().SizeSquared() > 25);
}
