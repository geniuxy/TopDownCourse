// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TDPlayerControllerBase.h"

#include "DebugHelper.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PaperFlipbookComponent.h"
#include "Characters/TDPaperCharacterBase.h"

void ATDPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
		                                   &ATDPlayerControllerBase::HandleGroundMovementInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this,
										   &ATDPlayerControllerBase::HandleGroundMovementCompleted);
	}
	else
	{
		Debug::Print(TEXT("没有配置 Enhanced Input Component!"));
	}
}

void ATDPlayerControllerBase::HandleGroundMovementInput(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveVector = InputActionValue.Get<FVector2D>();

	// 获取角色控制器的偏航角（Yaw），并将其转换为一个旋转值（FRotator）。
	// 偏航角是角色在水平方向上的旋转角度，用于确定角色的朝向
	// const FRotator MovementRotation(0.f, GetControlRotation().Yaw, 0.f);

	ATDPaperCharacterBase* PaperCharacterBase = CastChecked<ATDPaperCharacterBase>(GetPawn());
	if (MoveVector.Y != 0.f)
	{
		// MovementRotation.RotateVector() 被用来将标准方向向量（如 FVector::ForwardVector 或 FVector::RightVector）旋转到角色的当前朝向。
		// const FVector ForwardVector = MovementRotation.RotateVector(FVector::ForwardVector);
		PaperCharacterBase->AddMovementInput(FVector(0.f, 1.f, 0.f), MoveVector.Y);
	}

	if (MoveVector.X != 0.f)
	{
		// const FVector RightVector = MovementRotation.RotateVector(FVector::RightVector);
		PaperCharacterBase->AddMovementInput(FVector(1.f, 0.f, 0.f), MoveVector.X);

		if (MoveVector.X > 0.f)
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(RightWalkFlipBook);
		}
		else
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(LeftWalkFlipBook);
		}
	}
	else if (MoveVector.Y != 0.f)
	{
		// const FVector RightVector = MovementRotation.RotateVector(FVector::RightVector);
		PaperCharacterBase->AddMovementInput(FVector(1.f, 0.f, 0.f), MoveVector.X);

		if (MoveVector.Y > 0.f)
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(DownWalkFlipBook);
		}
		else
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(UpWalkFlipBook);
		}
	}

	LastMoveVector = MoveVector;
}

void ATDPlayerControllerBase::HandleGroundMovementCompleted(const FInputActionValue& InputActionValue)
{
	if (LastMoveVector.IsNearlyZero()) return;

	ATDPaperCharacterBase* PaperCharacterBase = CastChecked<ATDPaperCharacterBase>(GetPawn());
	if (LastMoveVector.X != 0.f)
	{
		if (LastMoveVector.X > 0.f)
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(RightIdleFlipBook);
		}
		else
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(LeftIdleFlipBook);
		}
	}
	else if (LastMoveVector.Y != 0.f)
	{
		if (LastMoveVector.Y > 0.f)
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(DownIdleFlipBook);
		}
		else
		{
			PaperCharacterBase->GetSprite()->SetFlipbook(UpIdleFlipBook);
		}
	}
}
