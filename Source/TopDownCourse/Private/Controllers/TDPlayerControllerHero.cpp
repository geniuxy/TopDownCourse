// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TDPlayerControllerHero.h"

#include "InputActionValue.h"
#include "Characters/TDPaperZDCharacter.h"

void ATDPlayerControllerHero::HandleGroundMovementInput(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveVector = InputActionValue.Get<FVector2D>();

	// 获取角色控制器的偏航角（Yaw），并将其转换为一个旋转值（FRotator）。
	// 偏航角是角色在水平方向上的旋转角度，用于确定角色的朝向
	// const FRotator MovementRotation(0.f, GetControlRotation().Yaw, 0.f);

	ATDPaperZDCharacter* PaperCharacterBase = CastChecked<ATDPaperZDCharacter>(GetPawn());

	if (MoveVector.X != 0.f)
	{
		// const FVector RightVector = MovementRotation.RotateVector(FVector::RightVector);
		PaperCharacterBase->AddMovementInput(FVector(1.f, 0.f, 0.f), MoveVector.X);
	}
	if (MoveVector.Y != 0.f)
	{
		// const FVector RightVector = MovementRotation.RotateVector(FVector::RightVector);
		PaperCharacterBase->AddMovementInput(FVector(0.f, 1.f, 0.f), MoveVector.Y);
	}
}

void ATDPlayerControllerHero::HandleGroundMovementCompleted(const FInputActionValue& InputActionValue)
{
}
