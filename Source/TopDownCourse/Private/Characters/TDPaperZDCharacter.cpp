// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TDPaperZDCharacter.h"

#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATDPaperZDCharacter::ATDPaperZDCharacter()
{
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = false; // 当视角需要跟着鼠标走时，才需要为true
	CameraBoom->SetUsingAbsoluteRotation(true); // 角色旋转时，Camera不会随之旋转
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->SetRelativeRotation(FQuat(FRotator(-90.f, 0.f, -90.f)));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	TopDownCameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	TopDownCameraComponent->SetOrthoWidth(500.f);

	GetSprite()->SetUsingAbsoluteRotation(true);

	HitBox = CreateDefaultSubobject<UBoxComponent>("HitBox");
	HitBox->SetupAttachment(GetRootComponent());
	HitBox->SetRelativeLocation(FVector(30.0f, 0.f, 0.0f));

	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 10000.f, 0.f);
}
