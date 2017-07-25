// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RobotGameCharacter.h"
#include "Components/StaticMeshComponent.h"

#include "RobotCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ROBOTGAME_API ARobotCharacter : public ARobotGameCharacter
{
	GENERATED_BODY()
	
public:
	ARobotCharacter();

	UFUNCTION(BlueprintCallable, Category = "Bones")
		void ReleaseBone(FName bone);
	UFUNCTION(BlueprintCallable, Category = "Bones")
		void ReleaseArms();
	UFUNCTION(BlueprintCallable, Category = "Bones")
		void ReleaseLegs();

	UFUNCTION(BlueprintCallable, Category = "Bones")
		void RestoreAllBones();
	UFUNCTION(BlueprintCallable, Category = "Bones")
		void RestoreBone(FName bone);

	UFUNCTION(BlueprintCallable, Category = "Bones")
		void RestoreArms();
	UFUNCTION(BlueprintCallable, Category = "Bones")
		void RestoreArmTick(FName bone, float fDeltaTickX);

	UFUNCTION(BlueprintCallable, Category = "Bones")
		void RestoreLegs();


	UPROPERTY(BlueprintReadWrite, Category = "Bones")
		FName UpperArm_L;
	UPROPERTY(BlueprintReadWrite, Category = "Bones")
		FName UpperArm_R;
	UPROPERTY(BlueprintReadWrite, Category = "Bones")
		FName Leg_L;
	UPROPERTY(BlueprintReadWrite, Category = "Bones")
		FName Leg_R;


	UFUNCTION(BlueprintCallable, Category = "CustomAnim")
		void ResetFootPlacement();

	UFUNCTION(BlueprintCallable, Category = "CustomAnim")
		void DoLeftFootAngleAdjustment(FRotator& FootRot);

	/*
	Parent bone names, find them on begin play to restoring bones.
	*/
	FName UpArmL_Parent;
	FName UpArmR_Parent;
	FName LegL_Parent;
	FName LegR_Parent;


	bool Broken = false;
	bool Reconstructable = false;
	bool AlmostFinished = false;
	bool GravityWasEnabled;
	UPROPERTY(BlueprintReadWrite, Category = "Bones")
	bool IsRestoring = false;

	float TimeSinceRagdoll = 0.0f;
	float RestoreArmTime = 0.0f;
	float VaryingTolerance = 100.0f;

	TArray<FTransform> OriginTransforms;
	TArray<FTransform> ReconstructTransforms;

	FTransform UpArmL_Origin;

	FTimerHandle CustomHitDelay;
	FTimerHandle DestroyActorDelay;
};
