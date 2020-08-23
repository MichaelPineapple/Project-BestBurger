#include "Hector.h"
#include "../Nexus/Nexus.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AHector::AHector()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(35.f, 80.0f);
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	//GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

// Called when the game starts or when spawned
void AHector::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Nexus::UPDATE_PLAYER_POS(this->GetActorLocation());
}

// Called to bind functionality to input
void AHector::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &AHector::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHector::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AHector::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AHector::LookUpAtRate);
}


void AHector::MoveForward(float Value)
{
	if (Value != 0.0f) AddMovementInput(GetActorForwardVector(), Value);
}

void AHector::MoveRight(float Value)
{
	if (Value != 0.0f) AddMovementInput(GetActorRightVector(), Value);
}

void AHector::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHector::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


