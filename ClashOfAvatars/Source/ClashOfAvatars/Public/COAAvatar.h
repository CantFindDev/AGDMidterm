// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "COABaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "COAAvatar.generated.h"

/**
 * 
 */
UCLASS()
class CLASHOFAVATARS_API ACOAAvatar : public ACOABaseCharacter
{
	GENERATED_BODY()

public:

	ACOAAvatar();

	UPROPERTY(EditAnywhere,Category = "COA")
	float RunSpeed;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Character")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Character")
	USpringArmComponent* mSpringArm;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:

	void MoveForward(float value);
	void MoveRight(float value);

	void RunPressed();
	void RunReleased();

	//Helper methods :)
	FRotator GetYaw();
	FVector GetMovmentDirectionBasedOnAxis(EAxis::Type dir);
};
