// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CustomAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTGAME_API UCustomAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	/*IS MOVING*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		bool IsMoving;
	
	/** Left Lower Leg Offset From Ground, Set in Character.cpp Tick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FVector SkelControl_LeftLowerLegPos;

	/** Left Foot Rotation, Set in Character.cpp Tick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FRotator SkelControl_LeftFootRotation;

	/** Left Upper Leg Offset, Set in Character.cpp Tick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FVector SkelControl_LeftUpperLegPos;


	/** Left Upper Arm Position and Rotation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FVector SkelControl_LeftUpperArmPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FRotator SkelControl_LeftUpperArmRot;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FVector Default_LeftUpperArmPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		FRotator Default_LeftUpperArmRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		bool LostArm = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FootPlacement")
		bool RestoreArm = false;
public:

	APawn * OwningPawn;

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTimeX) override;

	
};
