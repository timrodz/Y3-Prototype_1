// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotCharacter.h"
#include "CustomAnimInstance.h"

ARobotCharacter::ARobotCharacter()
	: Super()
{

}

void ARobotCharacter::ReleaseBone(FName bone)
{
	USkeletalMeshComponent* Skeleton = GetMesh();

	if (bone == "upperarm_l")
	{

	}

	UpArmL_Origin = Skeleton->GetSocketTransform(bone);
		
	UE_LOG(LogTemp, Warning, TEXT("Origin of upperarm_l = %s"), *UpArmL_Origin.ToString());

	UCustomAnimInstance * Animation =
		Cast<UCustomAnimInstance>(Skeleton->GetAnimInstance());

	//No Anim Instance Acquired?
	if (!Animation) return;

	Animation->LostArm = true;

	//Skeleton->SetAllBodiesSimulatePhysics(true);
	Skeleton->SetAllBodiesBelowSimulatePhysics(bone, true, true);
	Skeleton->BreakConstraint(FVector::ZeroVector, FVector::ZeroVector, bone);

}

void ARobotCharacter::ReleaseArms()
{
}

void ARobotCharacter::ReleaseLegs()
{

}

void ARobotCharacter::RestoreAllBones()
{
}

void ARobotCharacter::RestoreBone(FName bone)
{
	IsRestoring = true;

	USkeletalMeshComponent* Skeleton = GetMesh();

	USkeletalMeshComponent* Mesh = GetMesh();
	//No Mesh?
	if (!Mesh) return;

	UCustomAnimInstance * Animation =
		Cast<UCustomAnimInstance>(Mesh->GetAnimInstance());

	//No Anim Instance Acquired?
	if (!Animation) return;

	//UNCOMMENT LATER!!!!!!!!!!!!!!!!!!!!
	//Animation->SkelControl_LeftUpperArmPos = Animation->Default_LeftUpperArmPos;
	//Animation->SkelControl_LeftUpperArmRot = Animation->Default_LeftUpperArmRot;


	
	FTransform before = Skeleton->GetSocketTransform(bone, RTS_ParentBoneSpace);

	Skeleton->GetRelativeTransform();

	FVector bPos = before.GetLocation();
	FQuat bQuat = before.GetRotation();
	//Animation->LostArm = false;

	Skeleton->SetAllBodiesBelowSimulatePhysics(bone, false, true);

	Animation->SkelControl_LeftUpperArmPos = bPos;
	Animation->SkelControl_LeftUpperArmRot = bQuat.Rotator();
	UpArmL_Origin = before;

	Animation->RestoreArm = true;
	//~~

	//Animation->SkelControl_LeftUpperLegPos = Mesh->GetSocketTransform(bone).GetLocation();

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Animation->SkelControl_LeftUpperArmPos.ToString());



	//Skeleton->SetAllBodiesSimulatePhysics(true);


	//FTransform transform = Skeleton->GetSocketTransform(bone);

	
	//FMath::Lerp(transform.GetLocation(), FVector::ZeroVector, 0.001f);

	//
	//
	//

}

void ARobotCharacter::RestoreArms()
{
}

void ARobotCharacter::RestoreArmTick(FName bone, float fDeltaTickX)
{
	IsRestoring = true;

	USkeletalMeshComponent* Skeleton = GetMesh();

	USkeletalMeshComponent* Mesh = GetMesh();
	//No Mesh?
	if (!Mesh) return;

	UCustomAnimInstance * Animation =
		Cast<UCustomAnimInstance>(Mesh->GetAnimInstance());

	//No Anim Instance Acquired?
	if (!Animation) return;

	RestoreArmTime += fDeltaTickX;

	RestoreArmTime = FMath::Clamp(RestoreArmTime, 0.0f, 1.0f);

	FVector pos = FMath::Lerp(UpArmL_Origin.GetLocation(), FVector::ZeroVector, RestoreArmTime);
	FRotator rot = FMath::Lerp(UpArmL_Origin.GetRotation().Rotator(), FRotator::ZeroRotator, RestoreArmTime);

	Animation->SkelControl_LeftUpperArmPos = pos;
	Animation->SkelControl_LeftUpperArmRot = rot;


	if (RestoreArmTime >= .98f)
	{
		Animation->RestoreArm = false;
		Skeleton->SetAllBodiesBelowSimulatePhysics(bone, false, true);
		IsRestoring = false;

		Animation->SkelControl_LeftUpperArmPos = FVector::ZeroVector;
		Animation->SkelControl_LeftUpperArmRot = FRotator::ZeroRotator;
		Animation->RestoreArm = false;
		Animation->LostArm = false;
		RestoreArmTime = 0.0f;

		UE_LOG(LogTemp, Warning, TEXT("Finished"));

	}


	//~~
}

void ARobotCharacter::RestoreLegs()
{
}


//Never assume the mesh or anim instance was acquired, always check, 
//or you can crash your game to desktop

void ARobotCharacter::ResetFootPlacement()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	//No Mesh?
	if (!Mesh) return;

	UCustomAnimInstance * Animation =
		Cast<UCustomAnimInstance>(Mesh->GetAnimInstance());

	//No Anim Instance Acquired?
	if (!Animation) return;

	//~~

	Animation->SkelControl_LeftUpperArmPos = Animation->Default_LeftUpperArmPos;
	Animation->SkelControl_LeftUpperArmRot = Animation->Default_LeftUpperArmRot;
	//Animation->SkelControl_LeftLowerLegPos = FVector(0, 0, 0);
	//Animation->SkelControl_LeftUpperLegPos = FVector(0, 0, 0);
	//Animation->SkelControl_LeftFootRotation = FRotator(0, 0, 0);
}

void ARobotCharacter::DoLeftFootAngleAdjustment(FRotator& FootRot)
{
	USkeletalMeshComponent* Mesh = GetMesh();
	
	//No Mesh?
	if (!Mesh) return;

	UCustomAnimInstance * Animation =
		Cast<UCustomAnimInstance>(Mesh->GetAnimInstance());

	//No Anim Instance Acquired?
	if (!Animation) return;

	//

	//Set Animblueprint node rot
	Animation->SkelControl_LeftFootRotation = FootRot;
}