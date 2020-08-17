// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Hector.generated.h"

UCLASS()
class LTORG_API AHector : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHector();

protected:
	virtual void BeginPlay() override;
	void MoveForward(float Val);
	void MoveRight(float Val);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;
	float BaseTurnRate;
	float BaseLookUpRate;
	class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	class UCameraComponent* FirstPersonCameraComponent;
};
